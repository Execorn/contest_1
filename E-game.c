#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main() {
    size_t N = 0;
    scanf("%zu", &N);

    size_t tmp = 2;
    while (tmp < N) {
        tmp += sqrt(tmp + sqrt(tmp) + 1) + 1;
        if (tmp == N) {
            printf("Second\n");
            return 0;
        }
    }    
    printf("First\n");

    return 0;
}