#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    string s;
    int pos;

    cin >> s >> pos;

    int n = s.size();

    int offset = n, diff = 1, past_offset;
    while(pos > offset) {
        past_offset = offset;
        offset += (n - diff);
        diff++;
    }

    string sorted_s = s;
    sort(sorted_s.rbegin(), sorted_s.rend());

    set<char> nonos;
    for(int i=0; i<diff-1; ++i) {
        nonos.insert(sorted_s[i]);
    }

    int j = 0;
    while(j < pos - past_offset - 1) {
        if(nonos.count(s[j])) {
            while(nonos.count(s[j])) j++;
        } else {
            j++;
        }
    }

    while(nonos.count(s[j])) j++;
    cout << s[j];

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