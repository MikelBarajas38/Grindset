#include <bits/stdc++.h>
using namespace std;

class KthLargestMS {

    int k;
    multiset<int, greater<int>> collection;

public:
    KthLargestMS(int k, vector<int>& nums) {

        this->k = k;
        for(int &x : nums) {
            collection.insert(x);
            if(collection.size() > k) {
                collection.erase(prev(collection.end()));
            }
        }
        
    }
    
    int add(int val) {

        collection.insert(val);
        if(collection.size() > k) {
            collection.erase(prev(collection.end()));
        }
        return *prev(collection.end());
        
    }
};

class KthLargest {

    int k;
    priority_queue<int> stream; 

public:
    KthLargest(int k, vector<int>& nums) {

        this->k = k;
        for(int &x : nums) {
            stream.push(-x);
            if(stream.size() > k) {
                stream.pop();
            }
        }
        
    }
    
    int add(int val) {

        stream.push(-val);
        if(stream.size() > k) {
            stream.pop();
        }
        return -stream.top();
        
    }
};

int main() {

    vector<int> nums = {4,5,8,2};
    KthLargest* obj = new KthLargest(3, nums);
    cout << obj->add(3) << endl;
    cout << obj->add(5) << endl;
    cout << obj->add(10) << endl;
    cout << obj->add(9) << endl;
    cout << obj->add(4) << endl;

    return 0;
}