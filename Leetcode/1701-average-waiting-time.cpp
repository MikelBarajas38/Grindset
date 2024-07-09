class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        int closest_available_time = 0;
        double total_wait_time = 0;

        for(auto customer : customers) {

            int arrival = customer[0];
            int prep_time = customer[1];

            closest_available_time = max(closest_available_time, arrival);

            total_wait_time += (closest_available_time - arrival + prep_time);

            closest_available_time += prep_time;
        }

        return total_wait_time / customers.size();

    }
};