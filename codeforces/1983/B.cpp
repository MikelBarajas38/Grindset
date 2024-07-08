#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void horizontal_flip(vector<vector<int>>& A) {
    int n = A.size();
    for(int i = 0; i < n; i++) {
        reverse(all(A[i]));
    }
}

void vertical_flip(vector<vector<int>>& A) {
    int n = A.size();
    int m = A[0].size();
    for(int i = 0; i < n/2; i++) {
        for(int j = 0; j < m; j++) {
            swap(A[i][j], A[n-i-1][j]);
        }
    }
}

bool is_valid(vector<vector<int>>& matrix) {
    
    int n = matrix.size();
    int m = matrix[0].size();

    vector<char> used(n, 0);
    
    for(int k = 0; k < n-1; k++) {

        if(used[k]) continue;

        for(int i = 0; i < n-1; i++) {

            if(used[i]) continue;
            if(i == k) continue;

            bool match = false;
            for(int j = 0; j < m; j++) {
                
                if(matrix[k][j] != matrix[i][m-j-1]) {
                    break;
                } else if(j == m-1) {
                    match = true;
                }
                
            }

            if(match) {
                used[k] = 1;
                used[i] = 1;
                break;
            }

        }

        if(!used[k]) return false;
    }

    return true;
}

void solve() {

    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<string> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<vector<int>> diff(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int ad = a[i][j] - '0';
            int bd = b[i][j] - '0';
            diff[i][j] = (bd - ad)%3;
            if(diff[i][j] < 0) diff[i][j] += 3;
        }
    }

    if(is_valid(diff)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T;
    cin >> T;

    while(T--) {
        solve();
    }
    return 0;
}