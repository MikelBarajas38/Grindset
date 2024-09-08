#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int max_distance = 0;

struct State {
    int i;
    int j;
};

bool is_valid(int i, int j, int M, int N) {
    return i >= 0 && i < M && j >= 0 && j < N;
}

void flood_distance(vector<string> &grid, vector<vector<int>> &distance_map, queue<State> &q) {

    int N = grid.size(), M = grid[0].size();

    while(!q.empty()) {

        State s = q.front();
        q.pop();

        max_distance = max(max_distance, distance_map[s.i][s.j]);

        int di[] = {0, 0, 1, -1};
        int dj[] = {1, -1, 0, 0};

        for(int k = 0; k < 4; k++) {
            int ni = s.i + di[k];
            int nj = s.j + dj[k];

            if(is_valid(ni, nj, N, M) && grid[ni][nj] == '.' && distance_map[ni][nj] == -1) {
                distance_map[ni][nj] = distance_map[s.i][s.j] + 1;
                q.push({ni, nj});
            }
        }

    }

}

int main() {

	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int M, N;
    cin >> M >> N;

    vector<string> grid(M);
    for(string &line : grid) {
        cin >> line;
    }

    vector<vector<int>> distance_map(M, vector<int>(N, -1));
    queue<State> q;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if (grid[i][j] == 'G') {
                distance_map[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    flood_distance(grid, distance_map, q);

    cout << max_distance << '\n';

    return 0;
}