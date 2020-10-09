#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class MaxHeap {
	private:
		int heapSize;
		vector<int> heap;
	public:
		MaxHeap() {
			heapSize = 0;
		}
		MaxHeap(int heapSize, vector<int> heap) {
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
		int getMax();
		int extractMax();
};

// Parameters: (Index of current element)
int MaxHeap::parent(int i) {
	return (i-1)/2;	// returns index of parent of current element
}

// Parameters: (Index of current element)
int MaxHeap::leftChild(int i) {
	return 2*i+1;	// returns index of left child of current element
}

// Parameters: (Index of current element)
int MaxHeap::rightChild(int i) {
	return 2*i+2;	// returns index of right child of current element
}

// Parameters: (Index where heapify is to be called)
void MaxHeap::heapify(int i) {
	int l = leftChild(i);
	int r = rightChild(i);
	int max;

	if(l < heapSize && heap[l] > heap[i])	// if left child > parent
		max = l;
	else
		max = i;
	if(r < heapSize && heap[r] > heap[max]) // if right child > parent
		max = r;
	if(i != max) {
		swap(heap[i], heap[max]);
		heapify(max);
	}
}

void MaxHeap::buildHeap() {
	for(int i = (heapSize/2)-1; i >= 0; --i)
		heapify(i);
}

// Parameters: (Element to insert into heap)
void MaxHeap::insertKey(int key) {
	++heapSize;
	heap.push_back(key);
	int i = heapSize-1;
	while(i > 0 && heap[i] > heap[parent(i)]) {
		swap(heap[i], heap[parent(i)]);	// swap current element with it's parent
		i = parent(i);	// switch to index of parent of current element
	}
}

int MaxHeap::getMax() {
	if(heapSize == 0) {
		cout << "\nHeap is empty!";
		return INT_MIN;
	}
	return heap[0];
}

int MaxHeap::extractMax() {
	if(heapSize == 0) {
		cout << "\nHeap is empty. Exraction operation leads to underflow.";
		return INT_MIN;
	}

	int item = heap[0];
	swap(heap[heapSize-1], heap[0]);	// swap max element with last element in heap
	--heapSize;
	heap.pop_back();
	heapify(0);

	return item;
}

void MaxHeap::printHeap() {
	cout << "\nMaxHeap elements are: ";
	for(auto x:heap)
		cout << x << " ";
}

int main() {
	MaxHeap heap(10, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

	heap.buildHeap();

	heap.insertKey(-20);
	cout << "Maximum element present in heap = " << heap.getMax();	// prints max-element (10)

	heap.extractMax();	// removes max-element (10) from heap

	heap.printHeap();	// prints elements in heap in level-order

	return 0;
}