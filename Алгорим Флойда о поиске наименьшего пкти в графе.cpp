#include <iostream>
#include <math.h>
#include <vector>

// Отлично работает... но записывает в текущую матрицу... 
void Floud(int N, std::vector<std::vector<int>> G) {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				G[i][j] = std::min(G[i][j], G[i][k] + G[k][j]);
			}
		}
	}
	for (int out_1 = 0; out_1 < N; out_1++) {
		for (int out_2 = 0; out_2 < N; out_2++) {
			std::cout << G[out_1][out_2] << " ";
		}
		std::cout << '\n';
	}
}

int main() {
	int N = 6;
	std::vector<std::vector<int>> G = { {0, 5, 4, 1, 100, 100},
											  {5, 0, 0, 100, 4, 100},
											  {4, 0, 0, 2, 6, 100},
											  {1, 100, 2, 0, 10 ,15},
											  {100, 4, 6, 10, 0, 3},
											  {100, 100, 100, 15, 3, 0} };

	for (int iteration = 0; iteration < N; iteration++) {
		std::cout << '\n';
		Floud(N, G);
	}
	std::cout << "Check last matrix" << std::endl;
	return 0;
}