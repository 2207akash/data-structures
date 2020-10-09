#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class MinHeap {
	private:
		int heapSize;
		vector<int> heap;
	public:
		MinHeap() {
			heapSize = 0;
		}
		MinHeap(int heapSize, vector<int> heap) {
			this->heapSize = heapSize;
			this->heap = heap;
		}
		// Utility functions
		int parent(int i);
		int leftChild(int i);
		int rightChild(int i);
		void heapify(int i);
		// Operations on heap
		void buildHeap();
		void printHeap();
		void insertKey(int key);
		int getMin();
		int extractMin();
};

// Parameters: (Index of current element)
int MinHeap::parent(int i) {
	return (i-1)/2;	// returns index of parent of current element
}

// Parameters: (Index of current element)
int MinHeap::leftChild(int i) {
	return 2*i+1;	// returns index of left child of current element
}

// Parameters: (Index of current element)
int MinHeap::rightChild(int i) {
	return 2*i+2;	// returns index of right child of current element
}

// Parameters: (Index where heapify is to be called)
void MinHeap::heapify(int i) {
	int l = leftChild(i);
	int r = rightChild(i);
	int min;

	if(l < heapSize && heap[l] < heap[i])	// if left child < parent
		min = l;
	else
		min = i;
	if(r < heapSize && heap[r] < heap[min]) // if right child < parent
		min = r;
	if(i != min) {
		swap(heap[i], heap[min]);
		heapify(min);
	}
}

void MinHeap::buildHeap() {
	for(int i = (heapSize/2)-1; i >= 0; --i)
		heapify(i);
}

// Parameters: (Element to insert into heap)
void MinHeap::insertKey(int key) {
	++heapSize;
	heap.push_back(key);
	int i = heapSize-1;
	while(i > 0 && heap[i] < heap[parent(i)]) {
		swap(heap[i], heap[parent(i)]);	// swap current element with it's parent
		i = parent(i);	// switch to index of parent of current element
	}
}

int MinHeap::getMin() {
	if(heapSize == 0) {
		cout << "\nHeap is empty!";
		return INT_MIN;
	}
	return heap[0];
}

int MinHeap::extractMin() {
	if(heapSize == 0) {
		cout << "\nHeap is empty. Exraction operation leads to underflow.";
		return INT_MIN;
	}

	int item = heap[0];
	swap(heap[heapSize-1], heap[0]);	// swap min element with last element in heap
	--heapSize;
	heap.pop_back();
	heapify(0);

	return item;
}

void MinHeap::printHeap() {
	cout << "\nMinHeap elements are: ";
	for(auto x:heap)
		cout << x << " ";
}

int main() {
	MinHeap heap(10, {10, 9, 8, 7, 6, 5, 4, 3, 2, 1});

	heap.buildHeap();

	heap.insertKey(20);
	cout << "Minimum element present in heap = " << heap.getMin();	// prints min-element (1)

	heap.extractMin();	// removes min-element (1) from heap

	heap.printHeap();	// prints elements in heap in level-order

	return 0;
}