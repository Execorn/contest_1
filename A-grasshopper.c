#include <stdio.h>
#include <stdlib.h>


int main() {
    size_t N = 0, M = 0;
    scanf("%zu %zu", &N, &M);

    size_t* steps = (size_t*) calloc(N + 1, sizeof(size_t));
    if (steps == NULL) {
        return 0;
    }

    steps[0] = 1;

    for (size_t current = 1; current <= N; ++current) {
        size_t before_jump = (current > M ? current - M : 0);
        for (size_t i = before_jump; i < current; ++i) {
            steps[current] += steps[i];
        } 
    }    

    printf("%zu\n", steps[N]);

    free(steps);
    return 0;
}