#include <bits/stdc++.h>
using namespace std;

/*

Notes:

    robots moving in the same direction cant collide
    compare all right robots with left robots, 

*/

struct Robot {
    int id;
    int pos;
    int health;
    char dir;
    bool alive;

    Robot(int id, int pos, int health, bool alive) : id(id), pos(pos), health(health), dir('*'), alive(alive) {}

    Robot(int id, int pos, int health, char dir, bool alive) : id(id), pos(pos), health(health), dir(dir), alive(alive) {}
};

class Solution {
public:
    vector<int> survivedRobotsHealths1(vector<int>& positions, vector<int>& healths, string directions) {
        
        int n = positions.size();

        vector<Robot> right;
        vector<Robot> left;

        for(int i = 0; i < n; i++) {
            if(directions[i] == 'R') {

                right.emplace_back(i+1, positions[i], healths[i], true);
            } else {
                left.emplace_back(i+1, positions[i], healths[i], true);
            }
        }

        sort(right.begin(), right.end(), [] (Robot const& a, Robot const& b){ return a.pos > b.pos; });
        sort(left.begin(), left.end(), [] (Robot const& a, Robot const& b){ return a.pos < b.pos; });

        for(Robot &r : right) {
            
            auto closest_l = lower_bound(left.begin(), left.end(), r.pos, [] (Robot const& a, int b) { return a.pos < b; });

            if(closest_l != left.end()) {

                while(r.alive && closest_l != left.end()) {

                    if(closest_l->alive) {

                        if(r.health == closest_l->health) {
                            r.alive = false;
                            closest_l->alive = false;
                        } else if(r.health > closest_l->health) {
                            closest_l->alive = false;
                            r.health--;
                        } else {
                            r.alive = false;
                            closest_l->health--;
                        }

                    }

                    closest_l++;

                }

            }

        }

        vector<Robot> alive;

        for(Robot &r : right) {
            if(r.alive) {
                alive.push_back(r);
            }
        }

        for(Robot &r : left) {
            if(r.alive) {
                alive.push_back(r);
            }
        }

        sort(alive.begin(), alive.end(), [] (Robot const& a, Robot const& b) { return a.id < b.id; });

        vector<int> res;
        for(Robot &r : alive) {
            res.push_back(r.health);
        }

        return res;

    }

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
            
        int n = positions.size();

        vector<Robot> robots;

        for(int i = 0; i < n; i++) {
            robots.emplace_back(i+1, positions[i], healths[i], directions[i], true);
        }

        sort(robots.begin(), robots.end(), [] (Robot const& a, Robot const& b){ return a.pos < b.pos; });

        stack<Robot*> right_robots;

        for(Robot &r : robots) {

            if(r.dir == 'R') {
                right_robots.push(&r);
            } else {

                while(!right_robots.empty() && r.alive) {
                    Robot* right = right_robots.top();
                    right_robots.pop();

                    if(right->health == r.health) {
                        right->alive = false;
                        r.alive = false;
                    } else if(right->health > r.health) {
                        r.alive = false;
                        right->health--;
                        right_robots.push(right);
                    } else {
                        right->alive = false;
                        r.health--;
                    }
                }
            }

        }

        sort(robots.begin(), robots.end(), [] (Robot const& a, Robot const& b) { return a.id < b.id; });

        vector<int> res;
        for(Robot &r : robots) {
            if(r.alive) {
                res.push_back(r.health);
            }
        }

        return res;

    }
};

int main() {
    Solution s;
    vector<int> positions = {3,5,2,6};
    vector<int> healths = {10,10,15,12};

    string directions = "RLRL";

    vector<int> res = s.survivedRobotsHealths(positions, healths, directions);
    for(int &x : res) {
        cout << x << " ";
    }
    cout << '\n';
}