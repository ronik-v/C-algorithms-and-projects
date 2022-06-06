// Обход в ширину dfs
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
	// списки смежности для каждой вершины графа
	std::vector<std::set<vertex_t>> list_of_a;

	void input() {
		//std::cout << "Enter vertexses number: ";
		std::cin >> vertexses_number;
		std::cin >> edges_number;
		list_of_a.clear();
		list_of_a.resize(vertexses_number);
		
		for (int i = 0; i < edges_number; i++) {
			vertex_t a, b;
			std::cin >> a >> b;
			list_of_a[a].insert(b);
			list_of_a[b].insert(a);

		}
	}
	void print() const
	{
		std::cout << "Vertexses number is: " << vertexses_number << std::endl;
		for (vertex_t vertex = 0; vertex < vertexses_number; vertex++) {
			std::cout << vertex << ": [";
			for (auto neib : list_of_a[vertex]) {
				std::cout << neib << ", ";
			}
			std::cout << "]";
			std::cout << '\b\b\n';
			std::cout << '\n';
		}
	
	}
};

int main() {
	Graph_1 g;
	g.input();
	g.print();

	return 0;
}