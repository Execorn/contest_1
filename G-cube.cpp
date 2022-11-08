#include <cstdio>
#include <cstdint>
#include <cmath>

const int MAX_CUBE = 6;

void get_ans(size_t actual, size_t droppings, size_t N, size_t M) {
    long double** dynamic = new long double* [N + 1]();

    for (size_t arridx = 1; arridx <= N; ++arridx) dynamic[arridx] = new long double [MAX_CUBE * arridx + 1]();
    for (size_t current = 1; current <= MAX_CUBE; current++) dynamic[1][current] = 1.0L;
    
    for (size_t dropping_idx = 1; dropping_idx < droppings; ++dropping_idx) {
        for (size_t current = dropping_idx; current <= (MAX_CUBE * dropping_idx); ++current) {
            dynamic[dropping_idx][current] /= MAX_CUBE;

            for (size_t new_score = 1; (new_score <= MAX_CUBE) && ((current + new_score) <= (MAX_CUBE * (dropping_idx + 1))); ++new_score) {
                dynamic[dropping_idx + 1][current + new_score] += dynamic[dropping_idx][current];
            }
        }
    }

    printf("%.18Lf", dynamic[N][M] / 6.0L);

    for (size_t arridx = 1; arridx <= N; ++arridx) delete[] dynamic[arridx];
    delete[] dynamic;
}

int main() {
    size_t N = 0, M = 0;
    scanf("%zu %zu", &N, &M);

    if (M <= MAX_CUBE * N && M >= N) { get_ans(M, N, N, M);
    } else printf("%.10Lf", 0.0L);
}