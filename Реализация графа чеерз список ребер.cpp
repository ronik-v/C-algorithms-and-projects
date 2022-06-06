#include <iostream>
#include <set>
#include <map>
#include <vector>

typedef int32_t vertex_t;
typedef std::set<vertex_t> setofvertex;


class Graph_1 {
public:
	int vertexses_number = 0;
	int edges_number = 0;
	std::set <std::pair<vertex_t, vertex_t>> setofeges;

	void input() {
		//std::cout << "Enter vertexses number: ";
		std::cin >> vertexses_number;
		std::cin >> edges_number;
		for (vertex_t i = 0; i < edges_number; i++) {
			vertex_t a, b;
			std::cin >> a >> b;
			setofeges.insert(std::make_pair(a, b));

		}
	}

	void print() const  
	{
		std::cout << "Vertexses number is: " << vertexses_number << std::endl;
		for (auto edge : setofeges) {
			std::cout << "(" << edge.first << ", " << edge.second << ") ";
		}
		std::cout << std::endl;
	}
};



int main() {
	Graph_1 g_1;
	g_1.input();
	g_1.print();

	return 0;
}

