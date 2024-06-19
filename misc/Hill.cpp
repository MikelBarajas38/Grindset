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

    int n;
    cin >> n;

    vector<ll> points(n);

    for(ll &i : points){
        cin >> i;
    }

    ll smallest = points[0];

    vector<ll> ltr(n);
    ltr[0] = smallest;

    for(int i = 1; i < n; ++i) {
        if(points[i] < points[i-1]){
            smallest = points[i];
        }
        ltr[i] = smallest;
    }

    smallest = points[n-1];

    vector<ll> rtl(n);
    rtl[n-1] = smallest;

    for(int i = n-2; i >= 0; --i) {
        if(points[i] < points[i+1]){
            smallest = points[i];
        }
        rtl[i] = smallest;
    }

    ll peak = 0ll;
    for(int i = 1; i < n - 1; ++i) {
        peak = max(peak, min(points[i] - ltr[i], points[i] - rtl[i]));
    }

    cout << peak << '\n';

    return 0;
}