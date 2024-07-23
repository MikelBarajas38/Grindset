#include <bits/stdc++.h>
using namespace std;

class MaxHeap { 

    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }; 
    int right(int i) { return 2 * i + 2; };

    void heapify(int i) {

        int l = left(i);
        int r = right(i);
        int largest = i;

        if(l < heap.size() && heap[l] > heap[i]) {
            largest = l;
        }

        if(r < heap.size() && heap[r] > heap[largest]) {
            largest = r;
        }

        if(largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }

    }

public:

    MaxHeap() {}

    MaxHeap(vector<int> &v) {

        heap = v;
        int n = heap.size();

        for(int i = (n - 1) / 2; i >= 0; i--) {
            heapify(i);
        }

    }

    void insert(int k) {

        heap.push_back(k);
        int i = heap.size() - 1;

        while(i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }

    }

    void print() {
        for(int i : heap) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    int pop() {

        if(heap.size() == 0) {
            return -1;
        }

        int root = heap[0];

        heap[0] = heap[heap.size() - 1];
        heap.pop_back();

        heapify(0);

        return root;

    }

};

int main() {

    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    MaxHeap heap(vec);

    heap.insert(11);

    heap.print();

}