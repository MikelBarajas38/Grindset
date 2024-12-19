/*

1 2 3 4 5 6 7 8

1 2 7 8 3 4 5 6


1 
  2 
    7 - - - -
      8 - - - -
    - - 3
      - - 4       
        - - 5
          - - 6 

*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int n = arr.size();
        vector<pair<int, int>> ranges;
        for(int i = 0; i < n; i++) {
            int start = min(arr[i], i);
            int end = max(arr[i], i);
            ranges.push_back({start, end});
        }

        sort(ranges.begin(), ranges.end());

        int unique_range_count = 1;
        int current_end = ranges[0].second;
        for(int i = 1; i < n; i++) {
            if(ranges[i].first > current_end) {
                unique_range_count++;
            } 
            current_end = max(current_end, ranges[i].second);
        }

        return unique_range_count;
        
    }
};