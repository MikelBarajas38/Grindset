#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct cell {
    ll x, y;
};

void solve() {
    
    ll n, m;
    cin >> n >> m;

    vector<cell> cells(m);
    for(cell &c : cells) {
        cin >> c.y >> c.x;
    } 

    ll max_distance = 0;

    for(int i = 0; i < m; ++i) {

        ll tl = max(cells[i].x, cells[i].y) - 1;
        ll tr = max(n - cells[i].x + 1, cells[i].y) - 1;
        ll bl = max(cells[i].x, n - cells[i].y + 1) - 1;
        ll br = max(n - cells[i].x + 1, n - cells[i].y + 1) - 1;

        for(int j = 0; j < m; ++j) {

            if(i == j) continue;

            if(cells[j].x <= cells[i].x && cells[j].y <= cells[i].y) {
                ll dist = max(cells[i].x - cells[j].x, cells[i].y - cells[j].y);
                dist = dist / 2 + dist % 2; 
                tl = min(tl, dist);
            } else if(cells[j].x >= cells[i].x && cells[j].y <= cells[i].y) {
                ll dist = max(cells[i].x - cells[j].x, cells[j].y - cells[i].y);
                dist = dist / 2 + dist % 2; 
                tr = min(tr, dist);
            } else if(cells[j].x <= cells[i].x && cells[j].y >= cells[i].y) {
                ll dist = max(cells[j].x - cells[i].x, cells[i].y - cells[j].y);
                dist = dist / 2 + dist % 2; 
                bl = min(bl, dist);
            } else if(cells[j].x >= cells[i].x && cells[j].y >= cells[i].y) {
                ll dist = max(cells[j].x - cells[i].x, cells[j].y - cells[i].y);
                dist = dist / 2 + dist % 2; 
                br = min(br, dist);
            }

        }

        max_distance = max({max_distance, tl, tr, bl, br});
    }

    cout << max_distance << '\n';

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T = 1;
    //cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}