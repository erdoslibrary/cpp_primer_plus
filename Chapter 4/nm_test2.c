#include <string.h>
#include <stdio.h>

size_t ft_strlen(const char *str);

int main(void)
{
    static int  initialized_static = 42;
    static int  uninitialized_static;
    char        *str = "NAGINAGI";
    
    printf("%lu %lu\n", strlen(str), ft_strlen(str));
    printf("%d %d\n", uninitialized_static, initialized_static);
    return (0);
}

size_t ft_strlen(const char *str)
{
	size_t i = 0;

	if(!str)
		return 0;
	while(str[i])
		i++;
	return i;
}