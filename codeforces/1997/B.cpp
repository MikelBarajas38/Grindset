#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    int n;
    cin >> n; 

    vector<string> grid(2);

    for(int i = 0; i < 2; i++) {
         cin >> grid[i];
    }

    int ans = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 1; j < n - 1; j++) {

            if(grid[i][j] != 'x') {

                /*
                .o.  x.x
                x.x  .o.

                */

                if(i == 0) {
                    
                    if(grid[i][j-1] == '.' && 
                       grid[i][j+1] == '.' && 
                       grid[i+1][j] == '.' &&
                       grid[i+1][j-1] == 'x' &&
                       grid[i+1][j+1] == 'x') {
                        
                        ans++;

                    }

                } else {
                        
                    if(grid[i][j-1] == '.' && 
                    grid[i][j+1] == '.' && 
                    grid[i-1][j] == '.' &&
                    grid[i-1][j-1] == 'x' &&
                    grid[i-1][j+1] == 'x') {
                        
                        ans++;
                    }               

                }

            }
        }
    }

    cout << ans << '\n';

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