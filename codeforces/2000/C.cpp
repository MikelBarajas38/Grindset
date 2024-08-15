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

    vector<ll> a(n);
    for(ll &x : a) {
        cin >> x;
    }

    int m;
    cin >> m;

    map<char, ll> match_num;
    map<ll, char> match_char;

    for(int i = 0; i < m; i++) {
        
        string s;
        cin >> s;

        if(s.size() != n) {
            cout << "NO\n";
            continue;
        }

        int matches = true;

        for(int j = 0; j < n; j++) {

            char c = s[j];

            if((match_num.count(c) && match_num[c] != a[j]) || 
               (match_char.count(a[j]) && match_char[a[j]] != c)) {
                matches = false;
                break;
            }

            match_num[c] = a[j];
            match_char[a[j]] = c;

        }

        cout << (matches ? "YES" : "NO") << '\n';
        
        match_num.clear();
        match_char.clear();

    }
    
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