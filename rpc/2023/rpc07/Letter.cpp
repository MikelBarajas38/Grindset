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

    vector<map<char,int>> pos(30);

    int n;
    cin >> n;

    for(int i=0; i<n; ++i) {
        string s;
        cin >> s;

        for(int j=0; j<s.length(); ++j) {
            pos[j][s[j]]++;
        }
    }

    for(int i=0; i<30; ++i) {

        if(pos[i].empty()) {
            break;
        }

        cout << i+1 << ":";

        auto max = max_element
        (
            all(pos[i]),
            [] (const pair<char,int> &p1, const pair<char,int> &p2) {
                return p1.second < p2.second;
            }
        );

        for(auto p : pos[i]) {
            if(p.second == (*max).second) {
                cout << " " << p.first ;
            }
        }

        cout << "\n";
        
    }

    return 0;
}