#include <stdio.h>
#include <time.h>

/* 단일 루프*/

// void benchmark(long long n) {
//     long long sum = 0;
//     struct timespec start, end;
    
//     clock_gettime(CLOCK_MONOTONIC, &start);
    
//     // 실제 연산 루프
//     for (long long i = 0; i < n; i++) {
//         if (i % 3 == 0) sum += i;
//     }
    
//     clock_gettime(CLOCK_MONOTONIC, &end);
    
//     // 소요 시간 계산 (초 단위)
//     double diff = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    
//     // 초당 연산 횟수 (Operations Per Second) 계산
//     double ops_per_sec = (double)n / diff;

// 	printf("Total Iterations : %lld\n", n);
//     printf("Elapsed Time     : %.6f sec\n", diff);
//     printf("-----------------------------------\n");
//     printf("Throughput       : %.2f ops/sec\n", ops_per_sec);
//     printf("Throughput (억)  : %.2f 억 ops/sec\n", ops_per_sec / 1e8); // 1e8(1억)로 나눔
//     printf("-----------------------------------\n");
    
//     // 최적화 방지용 출력 (주석 처리 가능하나 성능에 영향 없음)
//     if (sum == 0) printf("Check: %lld\n", sum); 
// }

// int main() {
//     // 1억 번 수행
//     benchmark(100000000LL); 
//     return 0;
// }

/* 이중 루프 */

#include <stdio.h>
#include <time.h>
#include <math.h>

void benchmark_double_loop(long long total_n) {
    long long sum = 0;
    struct timespec start, end;
    
    // total_n이 1억이면, limit은 10,000
    long long limit = (long long)sqrt(total_n);
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    // 이중 루프 시작 (10,000 * 10,000 = 1억)
    for (long long i = 0; i < limit; i++) {
        for (long long j = 0; j < limit; j++) {
            // 단일 루프와 유사한 연산량을 맞추기 위해 인덱스 계산 포함
            long long current = i * limit + j;
            if (current % 3 == 0) {
                sum += current;
            }
        }
    }
    
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    double diff = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    double ops_per_sec = (double)total_n / diff;

    printf("[Double Loop Benchmark]\n");
    printf("Total Iterations : %lld (%lld x %lld)\n", total_n, limit, limit);
    printf("Elapsed Time     : %.6f sec\n", diff);
    printf("-----------------------------------\n");
    printf("Throughput (억)  : %.2f 억 ops/sec\n", ops_per_sec / 1e8);
    printf("-----------------------------------\n");

    if (sum == 0) printf("Check: %lld\n", sum);
}

int main() {
    benchmark_double_loop(100000000LL); // 1억 번 기준
    return 0;
}