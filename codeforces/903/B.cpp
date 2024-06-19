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

double distance(point a, point b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int point_equals(point a, point b) {
    return(a.x == b.x && a.y == b.y);
}

void solve() {

    point p0 = {0, 0};
    point pf, a, b;

    cin >> pf.x >> pf.y >> a.x >> a.y >> b.x >> b.y;

    double dist_a_p0 = distance(a, p0);
    double dist_b_p0 = distance(b, p0);

    double dist_a_pf = distance(a, pf);
    double dist_b_pf = distance(b, pf);

    point closest_p0, closest_pf;

    if(dist_a_p0 < dist_b_p0) {
        closest_p0 = a;
    } else {
        closest_p0 = b;
    }

    if(dist_a_pf < dist_b_pf) {
        closest_pf = a;
    } else {
        closest_pf = b;
    }

    double ans = max(distance(closest_p0, p0), distance(closest_pf, pf));

    if(!point_equals(closest_pf, closest_p0)) {
        ans = max(ans, distance(closest_p0, closest_pf) / 2);
    }

    cout << fixed << setprecision(10) << ans << "\n";

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