#include <stdio.h>
#include <stdlib.h>
#include <math.h>

size_t is_square(size_t number) {
    size_t square_root = sqrt(number);
    return (square_root * square_root == number);
}

size_t count_squares(size_t number) {
    if (is_square(number)) return 1;
    for (size_t i = 1; i <= (size_t) sqrt(number) + 1; ++i) if (is_square(number - (i * i))) return 2;
    while (number % 4 == 0) number >>= 2;
    if (number % 8 == 7) return 4;
    return 3;
}

int main() {
    size_t N = 0;
    scanf("%zu", &N);
    printf("%zu\n", count_squares(N));
    return 0;
}