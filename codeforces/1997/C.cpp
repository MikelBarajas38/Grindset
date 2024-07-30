#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    int n;
    cin >> n; 

    string brackets;
    cin >> brackets;

    stack<pair<char, int>> s;
    int cost = 0;

    for(int i = 0; i < n; i++) {
        if(brackets[i] == '(') {
            s.push({'(', i});
        } else if (brackets[i] == ')') {
            if(!s.empty()) {
                cost += i - s.top().second;
                s.pop();
            } else {
                s.push({')', i});
            }
        } else {
            if(!s.empty()) {
                cost += i - s.top().second;
                s.pop();
            } else {
                s.push({'(', i});
            }
        }
    }

    cout << cost << '\n';

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