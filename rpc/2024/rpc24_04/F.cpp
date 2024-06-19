#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

double find_area(vector<pair<double, double>> &points) {
    double area = 0;

    for(int i = 0; i < points.size(); ++i) {
        double x1 = points[i].first;
        double y1 = points[i].second;
        double x2 = points[(i + 1) % points.size()].first;
        double y2 = points[(i + 1) % points.size()].second;
        area += (x1 * y2) - (x2 * y1);
    }

    return abs(area) / 2;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    vector<pair<double, double>> points;
    for(int i = 0; i < 3*n; ++i) {
        double x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    double min_diff = 1e9;

      

    cout << fixed << setprecision(1) << min_diff << "\n";
    
    return 0;
}