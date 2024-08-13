#include <bits/stdc++.h>
using namespace std;
    
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
    
struct Point {
    ll x, y;
};
    
ll dist(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
    
void solve() {
    
    int n;
    cin >> n;
    
    vector<Point> centers(n); 
    for(Point &p : centers) {
        cin >> p.x >> p.y;
    }
    
    Point start, end;
    cin >> start.x >> start.y >> end.x >> end.y;
    
    ll original_dist = dist(start, end);
    
    for(Point &p : centers) {

        ll circle_dist = dist(p, end);
    
        if(circle_dist <= original_dist) {                                    
            cout << "NO\n";
            return;
        }
    
    }
    
    cout << "YES\n";
    
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