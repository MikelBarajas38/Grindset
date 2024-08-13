class Solution {

    void generate_sum_combinations(vector<int>& candidates, vector<int> &curr_combination, 
                                   vector<vector<int>> &combinations, int target, int p) {

        if(target == 0) {
            combinations.push_back(curr_combination);
            return;
        }

        unordered_set<int> used;
        for(int i = p; i < candidates.size(); ++i) {

            if(candidates[i] > target || used.count(candidates[i])) {
                continue;
            }

            used.insert(candidates[i]);
            curr_combination.push_back(candidates[i]);
            generate_sum_combinations(candidates, curr_combination, combinations, target - candidates[i], i + 1);
            curr_combination.pop_back();

        }

    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> curr_combination;
        vector<vector<int>> combinations;
        generate_sum_combinations(candidates, curr_combination, combinations, target, 0);

        return combinations;
        
    }
};