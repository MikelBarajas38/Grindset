#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    map<int, int> indexes;
    for(int i = 0; i < m; ++i){
        int index;
        cin >> index;
        indexes[index]++;
    }

    string c;
    cin >> c;

    sort(all(c));

    int extra_chars = 0;
    for(auto &index : indexes){
        extra_chars += index.second - 1;
    }

    c = c.substr(0, m - extra_chars);

    int j = 0;
    for(auto &index : indexes){
        s[index.first - 1] = c[j];
        j++;
    }

    cout << s << '\n';
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