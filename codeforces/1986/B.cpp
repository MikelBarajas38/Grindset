#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool is_valid(int i, int j, int n, int m){
    return i >= 0 && i < n && j >= 0 && j < m;
}

bool is_peak(vector<vector<int>> &matrix, int i, int j, int n, int m){

    int dy[] = {0, 0, 1, -1};
    int dx[] = {1, -1, 0, 0};

    for(int k = 0; k < 4; k++){
        int di = i + dy[k];
        int dj = j + dx[k];

        if(is_valid(di, dj, n, m) && matrix[di][dj] >= matrix[i][j]){
            return false;
        }
    }

    return true;
}

int closest_neighbor(vector<vector<int>> &matrix, int i, int j, int n, int m){

    int dy[] = {0, 0, 1, -1};
    int dx[] = {1, -1, 0, 0};

    int min_dist = INT_MAX, closest_neighbor = -1;
    for(int k = 0; k < 4; k++){
        int di = i + dy[k];
        int dj = j + dx[k];

        if(is_valid(di, dj, n, m) && matrix[i][j] - matrix[di][dj] < min_dist){
            min_dist = matrix[i][j] - matrix[di][dj];
            closest_neighbor = matrix[di][dj];
            
        }
    }

    return closest_neighbor;
}


void solve() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(is_peak(matrix, i, j, n, m)){
                matrix[i][j] = closest_neighbor(matrix, i, j, n, m);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T;
    cin >> T;

    while(T--){
        solve();
    }

    return 0;
}