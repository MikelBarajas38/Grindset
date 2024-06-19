#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n, f, k;
    cin >> n >> f >> k;

    vector<int> a(n);
    for(int &i: a){
        cin >> i;
    }

    int favorite_cube = a[f-1];

    sort(all(a), greater<int>());

    if(a[k-1] <= favorite_cube){
        if(a[k-1] == favorite_cube && k < a.size() && a[k-1] == a[k]) {
            cout << "MAYBE\n";
        }
        else {
            cout << "YES\n";
        }
    } else {
        cout << "NO\n";
    }

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T;
    cin >> T;

    while(T--){
        solve();
    }

    return 0;
}