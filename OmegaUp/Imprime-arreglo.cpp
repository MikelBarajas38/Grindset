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

    vector<int> array(n);
    for(int &x : array) {
        cin >> x;
    }

    for(int i = n - 1; i >= 0; --i) {
        cout << array[i] << '\n';
    }

    return 0;
}