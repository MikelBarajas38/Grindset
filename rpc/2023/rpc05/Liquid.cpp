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

    double n;
    cin >> n;

    vector<double> c(n);
    for(double &d : c){
        cin >> d;
    }

    double total = 0;
    for(double d : c){
        total += d * d * d;
    }
    

    cout << fixed << setprecision(7) << cbrt(total) << " ";

    return 0;
}