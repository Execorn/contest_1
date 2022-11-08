#include <stdio.h>
#include <stdlib.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

#define MAX_N 10001

int comp(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

int main() {
    size_t N = 0; 
    scanf("%zu", &N);

    int  X[MAX_N] = {0};
    int dp[MAX_N] = {0};
    
    for (size_t i = 1; i <= N; ++i) scanf("%i", X + i);
    qsort(X + 1, N, sizeof(int), comp);

    dp[2] = X[2] - X[1];
    dp[3] = X[3] - X[1];

    for (size_t i = 4; i <= N; ++i) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + X[i] - X[i - 1];
    }

    printf("%i\n", dp[N]);

    return 0;
}