#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {

	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    int Ai, Aj, Bi, Bj;
    cin >> Ai >> Aj >> Bi >> Bj;

    queue<pair<int, int>> q;
    vector<vector<int>> dist(N, vector<int>(M, -1));

    q.push({Ai, Aj});
    dist[Ai][Aj] = 0;

    int di[] = {0, 0, 1, -1};
    int dj[] = {1, -1, 0, 0};

    while(!q.empty()) {

        auto [i, j] = q.front();
        q.pop();

        if(i == Bi && j == Bj) {
            break;
        }

        for(int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];

            if(ni >= 0 && ni < N && nj >= 0 && nj < M &&
               grid[ni][nj] == 0 && 
               dist[ni][nj] == -1) 
            {
                dist[ni][nj] = dist[i][j] + 1;
                q.push({ni, nj});
            }
        }

    }

    cout << dist[Bi][Bj] + 1 << '\n';

    return 0;

}