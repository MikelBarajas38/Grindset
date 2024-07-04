#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

double get_force(double M, vector<double> &planets) {
    double force = 0;
    for(double x : planets) {
        force += 1 / (x - M);
    }
    return force;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    vector<double> planets(n);
    for(double &x : planets) {
        cin >> x;
    }

    sort(all(planets));

    vector<double> valid_positions;
    for(int i = 1; i < n; ++i) {

        double l = planets[i - 1], r = planets[i];

        while(r - l > 1e-9) {
            double m = (l + r) / 2;
            double force = get_force(m, planets);
            if(force < 0) {
                l = m;
            } else {
                r = m;
            }
        }

        valid_positions.push_back(l);

    }

    cout << valid_positions.size() << '\n';
    for(double &M : valid_positions) {
        cout << fixed << setprecision(3) << M << ' ';
    }

    return 0;
}