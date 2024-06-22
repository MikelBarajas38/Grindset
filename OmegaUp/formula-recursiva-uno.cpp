#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int formula_recursiva(int n) {
    if(n <= 5) {
        return 1;
    } 
    return 5 * formula_recursiva(n - 2);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n; 

    cout << formula_recursiva(n) << '\n';

    return 0;
}