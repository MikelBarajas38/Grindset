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

    string citizens;
	cin >> citizens;

	vector<ll> roots;
	for(int i = 1; i < citizens.length(); ++i) {
		if(citizens[i] != citizens[i-1]) {
			roots.push_back(2 * i + 1);
		}
	}

	ll degree = roots.size();

	if(degree == 0) {
		if(citizens[0] == 'A') {
			cout << "0\n-1\n";
		} else {
			cout << "0\n1\n";
		}
		return 0;
	}

	vector<ll> coefficients(degree + 1);
	coefficients[0] = 1;
	coefficients[1] = -roots[0];

	for(int i=1; i < degree; i++) {
		vector<ll> temp = coefficients;
		for(int j=1; j < degree + 1; ++j) {
			coefficients[j] = coefficients[j] - temp[j-1] * roots[i];
		}
	}

	bool invert = (degree % 2 == 1 && citizens[0] == 'H')
				  || (degree % 2 == 0 && citizens[0] == 'A');
				  
	cout << degree << "\n";
	for(ll &coeff: coefficients) {
		if(invert) coeff *= -1;
		cout << coeff << " ";
	}
	cout << "\n";

    return 0;
}