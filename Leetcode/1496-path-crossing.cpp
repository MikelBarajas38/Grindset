class Solution {
public:
    bool isPathCrossing(string path) {
        
        pair<int,int> p;
        set<pair<int,int>> visited;
        visited.insert(p);

        for(char &c : path) {

            if(c == 'N') {
                p.second++;
            }else if(c == 'S') {
                p.second--;
            } else if(c == 'E') {
                p.first++;
            } else {
                p.first--;
            }

            if(visited.count(p)) {
                return true;
            }

            visited.insert(p);

        }

        return false;

    }
};