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

	vector<int> a(n);
	for(int &x : a) {
		cin >> x;
	}

	int first = a[0];

	int pos = 0;
	for(int i = 1; i < n; i++) {
		if(a[i] < first) {
			pos++;
		}
	}

	cout << pos << '\n';	

    return 0;

}