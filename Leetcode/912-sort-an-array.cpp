#include <bits/stdc++.h>
using namespace std;

class MinHeap {

    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; };
    int left(int i) { return 2 * i + 1; };
    int right(int i) { return 2 * i + 2; };

    void heapify(int i) {

        int smallest = i;
        int l = left(i);
        int r = right(i);

        if(l < heap.size() && heap[l] < heap[smallest]) {
            smallest = l;
        }

        if(r < heap.size() && heap[r] < heap[smallest]) {
            smallest = r;
        }

        if(smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }

    }

public:

    MinHeap() {};

    MinHeap(vector<int> v) {

        heap = v;
        int n = heap.size();

        for(int i = (n - 1) / 2; i >= 0; i--) {
            heapify(i);
        }

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

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();
        MinHeap heap(nums);

        vector<int> ans;
        for(int i = 0; i < n; ++i) {
            ans.push_back(heap.pop());
        }

        return ans;
        
    }
};

int main() {

    Solution s;
    vector<int> nums = {5, 2, 3, 1};
    vector<int> ans = s.sortArray(nums);

    for(int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;    


}
