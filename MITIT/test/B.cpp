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

    vector<double> grades(5*n);
    for(double &grade : grades) {
        cin >> grade;
    }

    sort(all(grades));

    double mean = 0;
    for(int i = n; i < 4*n; ++i) {
        mean += grades[i];
    }

    cout << fixed << setprecision(6) << mean / (3*n) << '\n';

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