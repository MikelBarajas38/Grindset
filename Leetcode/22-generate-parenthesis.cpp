class Solution {
public:

    void generate_combinations(vector<string> &combinations, string combination, int l, int r) {

        if(r == 0 && l == 0) {
            combinations.push_back(combination);
            return;
        }

        if(r < l) {
            return;
        }

        if(l > 0) {
            generate_combinations(combinations, combination + '(', l - 1, r);
        }

        if(r > 0) {
            generate_combinations(combinations, combination + ')', l, r - 1);
        }
        
    }

    vector<string> generateParenthesis(int n) {
        vector<string> combinations;
        generate_combinations(combinations, "", n, n);
        return combinations;
    }
};