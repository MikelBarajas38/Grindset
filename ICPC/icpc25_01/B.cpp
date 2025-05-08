#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define readv(_v) for (auto &_i : _v) cin >> i

ll sum1(vector<vector<ll>> map, int corner) {

    int n = map.size();

    vector<vector<bool>> visited(n, vector<bool>(n));

    vector<int> di = {1, 0, -1, 0};
    vector<int> dj = {0, 1, 0, -1};
    
    int i, j;
    if(corner == 0){
        i = 0; j = 0;
    } else if(corner == 1) {
        i = n - 1; j = 0;
    } else if(corner == 2) {
        i = n - 1; j = n - 1;
    } else {
        i = 0; j = n - 1;
    }

    int visited_count = 0;
    ll max_sum = 0, curr_sum = 0;
    while(visited_count < n * n) {

        if(i >= n || i < 0 || j >= n || j < 0 || visited[i][j]) {
            i -= di[corner];
            j -= dj[corner];
            corner = (corner + 1) % 4;
            i += di[corner];
            j += dj[corner];
        }


        curr_sum += map[i][j];
        curr_sum = max(0ll, curr_sum);
        max_sum = max(curr_sum, max_sum);
        visited[i][j] = true;

        i += di[corner];
        j += dj[corner];

        visited_count++;

    }


    return max_sum;

}

ll sum2(vector<vector<ll>> map, int corner) {

    int n = map.size();

    vector<vector<bool>> visited(n, vector<bool>(n));

    vector<int> di = {0, 1, 0, -1};
    vector<int> dj = {1, 0, -1, 0};
    
    int i, j;
    if(corner == 0){
        i = 0; j = 0;
    } else if(corner == 1) {
        i = 0; j = n - 1;
    } else if(corner == 2) {
        i = n - 1; j = n - 1;
    } else {
        i = n - 1; j = 0;
    }

    int visited_count = 0;
    ll max_sum = 0, curr_sum = 0;
    while(visited_count < n * n) {

        if(i >= n || i < 0 || j >= n || j < 0 || visited[i][j]) {
            i -= di[corner];
            j -= dj[corner];
            corner = (corner + 1) % 4;
            i += di[corner];
            j += dj[corner];
        }


        curr_sum += map[i][j];
        curr_sum = max(0ll, curr_sum);
        max_sum = max(curr_sum, max_sum);
        visited[i][j] = true;

        i += di[corner];
        j += dj[corner];

        visited_count++;

    }


    return max_sum;

}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    vector<vector<ll>> map(n, vector<ll>(n));
    for(vector<ll> &line: map) {
        for(ll &c : line) {
            cin >> c;
        }
    }

    ll best_sum = 0;
    
    for(int k = 0; k < 4; ++k) {
        best_sum = max(sum1(map, k), best_sum);
        best_sum = max(sum2(map, k), best_sum);
    }

    cout << best_sum << '\n';

    return 0;
}