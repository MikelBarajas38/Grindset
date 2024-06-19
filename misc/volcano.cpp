/*
Problem description/source
date: yyyy-mm-dd
*/

#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef struct {
    int max;
    int min;
}max_t;

int get_distance(int x1, int y1, int x2, int y2)
{
    return abs(x2 - x1) + abs(y2 - y1);
}

void get_best_paths(vector<int> &xs, map<int, max_t> &coords, 
                    vector<pair<int,int>> &best, int index) 
{
    if(index == xs.size() - 1) {
        int len = coords[xs[index]].max - coords[xs[index]].min;
        best[index].first = best[index].second = len;
        return;
    }

    if(best[index + 1].first == -1 || best[index + 1].second == -1) {
        get_best_paths(xs, coords, best, index+1);
    }

    int path = coords[xs[index]].max - coords[xs[index]].min;
    int next_up = best[index + 1].first;
    int next_down = best[index + 1].second;

    int up = path + min(get_distance(xs[index], coords[xs[index]].min, xs[index + 1], coords[xs[index + 1]].min) + next_down,
                        get_distance(xs[index], coords[xs[index]].min, xs[index + 1], coords[xs[index + 1]].max) + next_up);
    
    int down = path + min(get_distance(xs[index], coords[xs[index]].max, xs[index + 1], coords[xs[index + 1]].min) + next_down,
                        get_distance(xs[index], coords[xs[index]].max, xs[index + 1], coords[xs[index + 1]].max) + next_up);

    best[index].first = up;
    best[index].second = down;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, x, y;

    cin >> n;

    map<int, max_t> coords;
    vector<int> xs;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;

        if(coords.find(x) == end(coords)) {
            coords[x] = {y,y};
            xs.push_back(x);
            continue;
        }

        if (coords[x].max < y) {
            coords[x].max = y;
        } 
        
        if (coords[x].min > y) {
            coords[x].min = y;
        }
    }
        
    // Process
    sort(all(xs));
    
    vector<pair<int,int>> best_paths(xs.size(), {-1,-1});
    get_best_paths(xs, coords, best_paths, 0);

    int total = min(best_paths[0].first, best_paths[0].second);

    // Print result
    cout << total << '\n';

    return 0;
}

/*
. . x
. . .
. x x
. . .
. . x
*/