class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int n = arr.size();

        vector<pair<int, int>> initial_state;
        for(int i = 0; i < n; i++) {
            initial_state.push_back({arr[i], i});
        }

        sort(initial_state.begin(), initial_state.end());

        vector<pair<int, int>> ranges;
        for(int i = 0; i < n; i++) {
            int start = min(initial_state[i].second, i);
            int end = max(initial_state[i].second, i);
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