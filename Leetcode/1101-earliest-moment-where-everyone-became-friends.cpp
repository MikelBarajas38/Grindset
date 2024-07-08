#include <bits/stdc++.h>
using namespace std;

class Solution { 
public:
  
    int earliestAcq1(vector<vector<int>>& logs, int n) { 
      
      	sort(logs.begin(), logs.end());
      
    	int current_set = 1; 
        int number_of_sets = n;
      	vector<int> sets(n, -1); 
      
      	for(auto log : logs) {
          
          	int timestamp = log[0]; 
          	int user_a = log[1]; 
          	int user_b = log[2];

            if(sets[user_a] == sets[user_b] && sets[user_a] != -1) {
                continue;
            }
                    
          	if(sets[user_a] == -1 && sets[user_b] == -1) { 
              	sets[user_a] = current_set; 
              	sets[user_b] = current_set;  
                current_set++;
            } else if (sets[user_a] == -1) {
                sets[user_a] = sets[user_b]; 
            } else if (sets[user_b] == -1) {
            	sets[user_b] = sets[user_a]; 
            } else {
                int absorved = sets[user_b];
              	for(int &set : sets) {
                  if(set == absorved) {
                    set = sets[user_a]; 
                  }
                }
            }

            number_of_sets--;
          
          	if(number_of_sets == 1) {
            	return timestamp;
            } 
          	
        }
        return -1;      
    }

    int find(vector<int> &parent, int v) {
        if(parent[v] == v) {
            return v;
        }
        return parent[v] = find(parent, parent[v]);
    }

    void unite(vector<int> &parent, int a, int b, int &number_of_sets) {
        a = find(parent, a);
        b = find(parent, b);
        if(a != b) {
            parent[a] = b;
            number_of_sets--;
        }
    }

    int earliestAcq(vector<vector<int>>& logs, int n) {
      
        sort(logs.begin(), logs.end());
      
        // Union Find (Disjoint Set Union)
        int number_of_sets = n;
        vector<int> parent(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(auto &log : logs) {

            int timestamp = log[0];
            int user_a = log[1];
            int user_b = log[2];

            unite(parent, user_a, user_b, number_of_sets);

            if(number_of_sets == 1) {
                return timestamp;
            }

        }
      
        return -1;
    }
};

int main() {
  
    Solution s;

    int n = 6;
    vector<vector<int>> logs = {{20190101, 0, 1}, {20190104, 3, 4}, {20190107, 2, 3}, 
                                {20190211, 1, 5}, {20190224, 2, 4}, {20190301, 0, 3}, 
                                {20190312, 1, 2}, {20190322, 4, 5}};
    cout << s.earliestAcq(logs, n) << endl;
  
    return 0;
  
}