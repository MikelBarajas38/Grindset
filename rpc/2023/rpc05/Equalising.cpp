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

    double n, x;
    cin >> n >> x;

    vector<double> a(n);
    for(double &d : a){
        cin >> d;
    }

    double avg = 0;
    for(double d : a){
        avg += d * d;
    }
    avg /= n;

    double factor = x / avg;

    for(double d : a){
        cout << fixed << setprecision(7) << d * sqrt(factor) << " ";
    }

    return 0;
}