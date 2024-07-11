class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int depth = 0;
        
        for(string &log : logs) {

            if(log == "../") {
                depth--;
                depth = max(depth, 0);
            } else if(log != "./") {
                depth++;
            }

        }

        return depth;
    }
};