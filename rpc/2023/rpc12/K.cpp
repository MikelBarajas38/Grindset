#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef struct {
    int x;
    int y;
} point;

double dist(point &a, point &b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    
    vector<point> coords(n);
    for(point &p : coords) {
        cin >> p.x >> p.y;
    }

    double min_avg_dist = 1e9;
    for(int i=0; i<n; ++i) {
        double avg_dist = 0;
        for(int j=0; j<n; ++j) {
            if(i != j) {
                avg_dist += dist(coords[i], coords[j]);
            }
        }
        avg_dist /= (n-1);
        min_avg_dist = min(min_avg_dist, avg_dist);
    }

    cout << fixed << setprecision(10) << min_avg_dist << "\n";

    return 0;
}