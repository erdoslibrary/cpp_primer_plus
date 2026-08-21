#include <iostream>
#include <cstring>

// Full Specialization
// [기본 템플릿]
template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

// [문자열 포인터를 위한 전체 특수화]
template <>
const char* maxValue<const char*>(const char* a, const char* b) {
    return (std::strcmp(a, b) > 0) ? a : b;
}

int main() {
    std::cout << maxValue(10, 20) << std::endl;
    const char *str1 = "apple";
    const char *str2 = "banana";
    std::cout << maxValue(str1, str2) << std::endl;
    return 0;
}