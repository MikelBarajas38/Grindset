#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define readv(_v) for (auto &_i : _v) cin >> _i
#define printv(_v) for (auto &_i : _v) cout << _i << ' '
#define rep(i, a, b) for (int i = a; i < (b); ++i)


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    string s;
    cin >> n;
    cin >> s;

    set <char> ltrs;
    s = '^' + s;
    vector<vi> ps(26, vi(s.size(), 0));
    for (char i = 'a'; i <= 'z'; i++) {
        for (int j = 1; j < s.size(); j++) {
            ps[i-'a'][j] = ps[i-'a'][j-1];
            if (i == s[j]) ps[i-'a'][j] ++; 
        }
    }

    map<int, int> vals;
    vi x(s.size(), 0);
    for (int i = 1; i < s.size(); i++)
    {
        ltrs.insert(s[i]);
        for (int j = 0; j < 26; j++)
        {
            x[i] |= ((ps[j][i] % 2 == 0) << j);
        }
        vals[x[i]] = i;
    }
    
    int diff = 0;
    for (int i = 1; i < s.size(); i++)
    {
        for (char c : ltrs) {
            int y = x[i] ^ (1<<(c - 'a'));
            if (!vals.count(y)) continue;
            diff = max(diff, vals[y] - i);
        }
    }
    
    cout << diff << '\n';

    return 0;
}
