#ifndef __HEAP_H__
#define __HEAP_H__

#define HEAP_PARENT(i) ((i-1)/2) 
#define HEAP_LEFT(i) (2*i)
#define HEAP_RIGHT(i) (2*i+1)

#include <unordered_map>

/**
 * Class containing Min-heap for vertices, ordered by distance
 */
class VertexHeap
{
public:

	/**
	 * @param capacity Capacity of which min heap is constructed
	 */
	VertexHeap(int capacity): capacity(capacity), size(0)
	{
		heap = new int[capacity];
	}

	/**
	 * @brief Adds a vertex with given distance to the heap
	 * @param idx Vertex number
	 * @param distance Distance of vertex. Min heap is ordered by this value
	 */
	void addVertex(int idx, int distance);

	/**
	 * @brief Check if heap is empty
	 * @returns true if the heap is empty, false otherwise
	 */
	bool isEmpty();

	/**
	 * @brief Removes the minimum element of heap and returns it
	 * @returns Pair of ints containing [Vertex number, Distance of vertex] for the minimum distance vertex
	 */
	std::pair<int, int> popMin();

	/**
	 * @brief Get the distance value of given vertex number
	 * @param idx Vertex number to check for
	 * @returns distance value of vertex
	 */
	int getDistance(int idx);

	/**
	 * @brief Decrease the distance value of a given vertex number
	 * @param idx Vertex number
	 * @param distance New distance value (must be < current distance value)
	 */
	void decreaseDistance(int idx, int distance);

	/**
	 * @brief Checks if a given vertex number is present on the heap
	 * @param idx Vertex number to check for
	 * @returns true if vertex exists on heap, false if not
	 */
	bool find(int idx);

private:
	/**
	 * @brief Map from vertex number to index of that vertex on the heap
	 * @details
	 * index2HeapIdx[2] = 3 suggests that heap[3] contains distance of vertex number 2
	 */
	std::unordered_map<int, int> index2HeapIdx;

	/**
	 * @brief Map from vertex index on heap to vertex number
	 * @details
	 * heapIdx2index[3] = 2 suggests that heap[3] contains distance of vertex number 2
	 */
	std::unordered_map<int, int> heapIdx2index;

	/**
	 * @brief Heap data, to be dynamically allocated
	 */
	int* heap;

	/**
	 * @brief Capacity of heap
	 */
	int capacity;

	/**
	 * @brief Current size of heap. Any data on heap[a] for a >= size is useless
	 */
	int size;

private:

	/**
	 * @brief Min-heapify the subheap with given root
	 * @param heapidx Index on heap[] of the subheap root to min-heapify
	 */
	void heapify(int heapidx);

	/**
	 * @brief Swap two vertices and their distances with given indices on heap
	 * @param heapidx1 Index on heap[] of first vertex to swap
	 * @param heapidx2 Index on heap[] of second vertex to swap
	 * @note Will also take care of changing vertex number mappings on index2HeapIdx[] and heapIdx2index
	 */
	void swap(int heapidx1, int heapidx2);
};

#endif // __HEAP_H__