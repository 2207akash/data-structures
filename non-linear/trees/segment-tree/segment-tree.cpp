#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
    vector<int> segmentTree;

    void buildSegmentTree(vector<int> &originalArray, int root, int l, int r) {
        if(l == r) {
            segmentTree[root] = originalArray[l];
            return;
        }
        int mid = (l+r)/2;
        buildSegmentTree(originalArray, 2*root + 1, l, mid);
        buildSegmentTree(originalArray, 2*root + 2, mid+1, r);

        // Custom logic to combine the results of the two children
        segmentTree[root] = segmentTree[2*root + 1] + segmentTree[2*root + 2];
    }
public:
    SegmentTree(vector<int> &originalArray) {
        int size = originalArray.size();
        if(size == 0) {
            cout << "Array is empty, cannot build segment tree.";
            return;
        }
        segmentTree.resize(2*size-1);
        buildSegmentTree(originalArray, 0, 0, size - 1);
    }

    void printAsArray() {
        for(int i = 0; i < segmentTree.size(); i++) {
            cout << segmentTree[i] << " ";
        }
    }
};

int main() {
    vector<int> originalArray = {1, 2, 3, 4};

    SegmentTree st(originalArray);
    st.printAsArray();
    
    return 0;
}