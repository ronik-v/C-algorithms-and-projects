// Задача о покрытии множеств...
#include <iostream>
#include <vector>
void print(std::vector<std::vector<int>> A);

void covering_problem(std::vector<std::vector<int>> A) {
	std::vector<int> C;
	C.resize(A[0].size());
	std::vector<int> contein;
	contein.resize(A.size());
	int min = 0;
	for (auto i = 0; i < A.size(); i++) {
		for (auto j = 0; j < A[0].size(); j++) {
			C[j] += A[0][j];
			if (A[i][j] == 1) {
				std::cout << "Column " << j+1 << " covers " << i+1 << " row." << '\n';
				contein.push_back(C[j] * A[0][j]);
				if (min < C[j]) {
					min = C[j];
				}
			}
		}
	}
	std::cout << "MIN (z_k) = " << min << '\n';
	
}

int main() {
	int N;
	int M;
	std::cout << "Enter N = ";
	std::cin >> N;
	std::cout << '\n';
	std::cout << "Enter M = ";
	std::cin >> M;
	std::cout << '\n';
	std::vector<std::vector<int>> A;
	A.resize(N);
	std::cout << "Enter tmp" << '\n';
	for (int i = 0; i < N; i++) {
		A[i].resize(M);
		for (int j = 0; j < M; j++) {
			int tmp;
			std::cin >> tmp;
			A[i][j] = tmp;
		}
		std::cout << '\n';
	}
	try {
		print(A);
		covering_problem(A);
		throw 2;
	}
	catch (int error) {
		if (error == 2) {
			std::cout << "It is normal" << '\n';
		}
		else
		{
			std::cout << "Fatal Error!" << '\n';
		}
	}
	return 0;
}

void print(std::vector<std::vector<int>> A) {
	for (int n = 0; n < A.size(); n++) {
		for (int m = 0; m < A.size(); m++) {
			std::cout << A[n][m] << " ";
		}
		std::cout << '\n';
	}
}