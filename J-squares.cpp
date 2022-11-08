#include <string.h>
#include <iostream>

void square(bool** matrix, int N) {
	int* S[2];
	S[0] = new int[N];
	S[1] = new int[N];

	int ans = 0;
	for (size_t i = 0; i < 2; ++i) {
		memset(S[i], 0, N * sizeof(int));
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int match = matrix[i][j];
			if (match) {
				if (j) {
					match = 1 + std::min(S[1][j - 1], std::min(S[0][j - 1], S[1][j]));
				}	
			}
			S[0][j] = S[1][j];
			S[1][j] = match;	
			ans = std::max(ans, match);
		}
	}	
	std::cout << ans << std::endl;

	delete S[1];
	delete S[0];
}


int main() {
	size_t N = 0;
	scanf("%zu", &N);

	bool** matrix = new bool*[N];
	for (size_t i = 0; i < N; ++i) {
		matrix[i] = new bool[N];
	}	

	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < N; ++j) {
			std::cin >> matrix[i][j];
		}
	}	

	square(matrix, N);

	for (size_t i = 0; i < N; ++i) {
		delete matrix[i];
	}	

	return 0;
}