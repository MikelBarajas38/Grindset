#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int get_fibonacciness(vector<int> a) {
    int n = a.size();
    int fibo_count = 0;
    for(int i = 2; i < n; i++) {
        if(a[i] == a[i-1] + a[i-2]) {
            fibo_count++;
        }
    }
    return fibo_count;
}

void solve() {
    
    vector<int> a(5);
    cin >> a[0] >> a[1] >> a[3] >> a[4];

    int max_fibo_count = 0;

    a[2] = a[0] + a[1];
    max_fibo_count = max(max_fibo_count, get_fibonacciness(a));

    a[2] = a[3] - a[1];
    max_fibo_count = max(max_fibo_count, get_fibonacciness(a));

    a[2] = a[4] - a[3];
    max_fibo_count = max(max_fibo_count, get_fibonacciness(a));

    cout << max_fibo_count << '\n';

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