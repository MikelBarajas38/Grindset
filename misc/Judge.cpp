#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool check_down(int i, int j, vector<vector<int>> &tilemap, int size){
    for(int )
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    vector<pair<int,int>> moves;
    int n;
    cin >> n;

    int lim = pow(2,n);
    
    vector<vector<int>> tilemap(lim, vector<int> (lim));
    for(int i = 0; i < lim; ++i) {
        for(int j = 0; j < lim; ++j) {
            cin >> tilemap[i][j];
        }
    }

    vector<vector<char>> visited(lim, vector<char> (lim, false));
    for(int i = 0; i < lim; ++i) {
        for(int j = 0; j < lim; ++j) {
            cin >> tilemap[i][j];
        }
    }
    return 0;
}