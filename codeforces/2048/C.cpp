#include <bits/stdc++.h>
using namespace std;
    
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
    
int get_similarity_score(string &s, string &p, int l, int r) {
    int score = 0;
    int pi = 0;
    for(int i = l; i <= r; ++i) {
        if(s[i] == p[pi]) {
            score++;
        } else {
            break;
        }
        pi++;
    }
    return score;
}
    
void solve() {
    
    string s;
    cin >> s;
    
    int n = s.size();
    
    string best_substring = "";
    
    int i = 0;
    while(i < n && s[i] == '1') {
        i++;
    }
    
    if(i == n) {
        cout << 1 << ' ' << n << ' ' << n << ' ' << n << '\n';
        return;
    }
    
    int best_l = i, best_r = i;
    
    for(; i < n; i++) {
        best_substring += (s[i] == '0' ? '1' : '0');
    }
    
    int m = best_substring.size();
    
    int best_score = 0;
    for(int i = 0; i < n - m + 1; i++) {
        int score = get_similarity_score(s, best_substring, i, i + m - 1);
        if(score > best_score) {
            best_score = score;
            best_l = i;
            best_r = i + m - 1;
        }
    }
    
    cout << 1 << ' ' << n << ' ' << best_l + 1 << ' ' << best_r + 1 << '\n';
    
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