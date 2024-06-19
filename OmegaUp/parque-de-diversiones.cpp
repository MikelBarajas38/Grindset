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

    int n;
    while(cin >> n) {

        vector<int> sequence(n);
        for(int &i : sequence) {
            cin >> i;
        } 

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j += 2) {
                dp[i][j] = sequence[i] - sequence[j];
            }
        }


    }
    return 0;
}