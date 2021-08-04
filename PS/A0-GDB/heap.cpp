#include "heap.hpp"
#include <stdexcept>

void VertexHeap::addVertex(int idx, int distance) 
{
	if(size == capacity)
	{
		throw std::runtime_error("Heap capacity exceeded");
	}

	if(index2HeapIdx.find(idx) != index2HeapIdx.end())
	{
		throw std::runtime_error("Index already exists");
	}

	size++;
	int i = size - 1;
	heap[i] = distance;
	heapIdx2index[i] = idx;
	index2HeapIdx[idx] = i;

	while (i != 0 && heap[HEAP_PARENT(i)] > heap[i])
	{
		swap(i, HEAP_PARENT(i));
		i = HEAP_PARENT(i);
	}
}

bool VertexHeap::isEmpty() 
{
	return size == 0;
}

std::pair<int, int> VertexHeap::popMin() 
{
	if(size <= 0)
	{
		throw std::runtime_error("Trying to pop empty heap");
	}

	if(size == 1)
	{
		size--;
		int retNode = heapIdx2index[0];
		int retDist = heap[0];
		index2HeapIdx.clear();
		heapIdx2index.clear();
		return {retNode, retDist};
	}

	int retNode = heapIdx2index[0];
	int retDist = heap[0];
	swap(0, size-1);
	size--;
	heapify(0);

	return {retNode, retDist};
}

int VertexHeap::getDistance(int idx) 
{
	if(index2HeapIdx.find(idx) == index2HeapIdx.end())
	{
		throw std::runtime_error("idx out of heap range");
	}
	return heap[index2HeapIdx[idx]];
}

void VertexHeap::decreaseDistance(int idx, int distance) 
{
	int i = index2HeapIdx[idx];

	heap[i] = distance;
	while(i != 0 && heap[HEAP_PARENT(i)] > heap[i])
	{
		swap(i, HEAP_PARENT(i));
		i = HEAP_PARENT(i);
	}
}

bool VertexHeap::find(int idx) 
{
	if(index2HeapIdx.find(idx) == index2HeapIdx.end())
		return false;
	return index2HeapIdx[idx] < size;
}

void VertexHeap::heapify(int heapidx) 
{
	int l = HEAP_LEFT(heapidx);
	int r = HEAP_RIGHT(heapidx);

	int smallest = heapidx;

	if(l < size && heap[l] < heap[heapidx])
		smallest = l;
	if(r < size && heap[r] < heap[smallest])
		smallest = r;

	if(smallest != heapidx)
	{
		swap(smallest, heapidx);
		heapify(smallest);
	}
}

void VertexHeap::swap(int heapidx1, int heapidx2) 
{
	index2HeapIdx[heapIdx2index[heapidx2]] = heapidx1;
	int temp = heapIdx2index[heapidx2];
	heapIdx2index[heapidx2] = heapIdx2index[heapidx1];

	index2HeapIdx[heapIdx2index[heapidx1]] = heapidx2;
	heapIdx2index[heapidx2] = temp;

	temp = heap[heapidx2];
	heap[heapidx2] = heap[heapidx1];
	heap[heapidx1] = temp;
}


