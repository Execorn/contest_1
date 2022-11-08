#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

#pragma GCC optimize ("O3")

void restore_solution(size_t S, size_t* coins, size_t N, size_t* sums, size_t* solution) {
    for (int k = sums[S]; k >= 0; --k) {
        for (size_t i = 0; i < N; ++i) {
            int r = S - coins[i];
            if (r >= 0) {
                if (sums[r] == k - 1) {
                    S = r;
                    printf("%zu ", coins[i]);
                    break;
                }    
            } 
        }
    }
}   


int main() {
    size_t N = 0;
    scanf("%zu", &N);

    size_t* coins = (size_t*) calloc(N, sizeof(size_t));
    if (coins == NULL) {
        return 0;
    }

    for (size_t i = 0; i < N; ++i) scanf("%zu", coins + i);

    size_t S = 0;
    scanf("%zu", &S);

    size_t* sums = (size_t*) calloc(S + 1, sizeof(size_t));
    if (sums == NULL) {
        free(coins);
        return 0;
    }
    for (size_t i = 0; i < S + 1; ++i) sums[i] = INT_MAX;

    sums[0] = 0;
    for (size_t i = 0; i < S + 1; ++i) {
        for (size_t j = 0; j < N; ++j) {
            if (i + coins[j] < S + 1) {
                if (sums[i] + 1 < sums[i + coins[j]]) {
                    sums[i + coins[j]] = sums[i] + 1;
                }
            }
        }
    }

    printf("%i\n", sums[S] == INT_MAX ? -1 : sums[S]);

    if (sums[S] != INT_MAX) {
        int* solution = (size_t*) calloc(S + 1, sizeof(size_t));
        if (solution == NULL) {
            free(coins);
            free(sums);
            return 0;
        }

        restore_solution(S, coins, N, sums, solution);

        free(solution);
    }

    free(coins);
    free(sums);
    return 0;
}