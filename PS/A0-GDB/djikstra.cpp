#include "heap.hpp"
#include <initializer_list>
#include <unordered_map>
#include <list>
#include <limits>
#include <iostream>


/**
 * @brief Class containing the graph information
 */
class Graph
{
public:

	/**
	 * @brief Constructor
	 * @param edges Edge list in the format { {{A, B}, C}, {{A, B}, C}, ...} where A, B are node numbers and C is weight
	 */
	Graph(std::initializer_list<std::pair<std::pair<int, int>,int>> edges)
	{

		for(const auto& edge : edges)
		{
			adj_list[edge.first.first].push_back({edge.first.second, edge.second});
			adj_list[edge.first.second].push_back({edge.first.first, edge.second});
		}

		vheap = new VertexHeap(adj_list.size());

		for(const auto& node : adj_list)
		{
			if(node.first == 0)
			{
				vheap->addVertex(node.first,0);
			}
			else
			{
				vheap->addVertex(node.first,std::numeric_limits<int>::max());
			}
		}
	}

	/**
	 * @brief Constructs the SPT for the graph with vertex 0 as root
	 */
	void construct_spt()
	{
		while (!vheap->isEmpty())
		{
			auto[minNode, minDist] = vheap->popMin();

			if(minDist == std::numeric_limits<int>::max())
				continue;

			spt_set[minNode] = minDist;

			for(auto node : adj_list[minNode])
			{
				if(vheap->find(node.first) && minDist +  node.second < vheap->getDistance(node.first))
				{
					vheap->decreaseDistance(node.first, minDist +  node.second);
					back_pt[node.first] = minNode;
				}
			}
		}
		
	}

	/**
	 * @brief Prints the shortest path to given vertex from vertex 0
	 * @param idx Vertex to which shortest path is printed
	 */
	void display_path(int idx)
	{
		while(idx != 0)
		{
			std::cout << idx << " <- ";
			idx = back_pt[idx];
		}
		std::cout << "0" << std::endl;
	}

private:
	VertexHeap* vheap;
	std::unordered_map<int, int> spt_set;
	std::unordered_map<int, std::list<std::pair<int,int>>> adj_list;
	std::unordered_map<int, int> back_pt;
};

int main()
{
	Graph g = {
		{ {0, 1},	4},
		{ {0, 7},	8},
		{ {1, 2},	8},
		{ {1, 7},	11},
		{ {2, 3},	7},
		{ {2, 8},	2},
		{ {2, 5},	4},
		{ {3, 4},	8},
		{ {3, 5},	14},
		{ {4, 5},	10},
		{ {5, 6},	2},
		{ {6, 7},	1},
		{ {6, 8},	6},
		{ {7, 8},	7}
	};

	g.construct_spt();
	for(int i = 1; i < 9; i++)
		g.display_path(i);
}