#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void print_binary(int n, int len) {
    for(int i = len - 1; i >= 0; --i) {
        cout << (n & (1 << i) ? 1 : 0);
    }
    cout << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    int lim = 1 << n; 
    for(int i = 0; i < lim; i++) {
        int s = i ^ i >> 1;
        print_binary(s, n);
    }

    return 0;
}