#include <iostream>
#include <cstdlib>

void solve(size_t N, size_t M, ssize_t** coords, ssize_t* result) {
    for (size_t current_N = 0; current_N < N; ++current_N) {
        for (size_t current_M = 0; current_M < M; ++current_M) {
            if (!current_N && !current_M) continue;
            else if (current_N && current_M) coords[current_N][current_M] +=    coords[current_N][current_M - 1] + 
                                                                                coords[current_N - 1][current_M] - 
                                                                                coords[current_N - 1][current_M - 1];
            else if (!current_N) coords[current_N][current_M] += coords[current_N][current_M - 1];
            else if (!current_M) coords[current_N][current_M] += coords[current_N - 1][current_M];
        }
    }

    for (size_t m1 = 0; m1 < M; ++m1) {
        for (size_t n1 = 0; n1 < N; ++n1) {
            for (size_t m2 = m1; m2 < M; ++m2) {
                for (size_t n2 = n1; n2 < N; ++n2) {
                    ssize_t current_weight = 0;
                    if (!m1 && !n1) current_weight = coords[n2][m2];
                    else if (!m1) current_weight   = coords[n2][m2] - coords[n1 - 1][m2];
                    else if (!n1) current_weight   = coords[n2][m2] - coords[n2][m1 - 1];
                    else current_weight = coords[n2][m2] - coords[n2][m1 - 1] - coords[n1 - 1][m2] + coords[n1 - 1][m1 - 1];
                    *result = std::max(*result, current_weight);
                }
            }
        }
    }
}

int main() {
    size_t N = 0, M = 0;
    std::cin >> N >> M;

    ssize_t** coords = new ssize_t*[N]();
    ssize_t   result = 0;

    for (size_t current_N = 0; current_N < N; ++current_N) {
        coords[current_N] = new ssize_t[M]();

        for (size_t current_M = 0; current_M < M; ++current_M) {
            std::cin >> coords[current_N][current_M];
        }
    }

    solve(N, M, coords, &result);

    std::cout << result << std::endl;

    for (size_t current_N = 0; current_N < N; ++current_N) delete[] coords[current_N];
    delete[] coords;
}