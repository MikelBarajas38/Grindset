#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    
    int n, q;
    cin >> n >> q;

    vector<int> perm(n);
    for(int i = 0; i < n; i++) {
        cin >> perm[i];
    }

    vector<int> unsorted_sections(n);
    for(int i = 0; i < n; i++) {
        if(perm[i] != i + 1) {
            int start = min(perm[i] - 1, i);
            int end = max(perm[i] - 1, i);
            unsorted_sections[start]++;
            unsorted_sections[end]--;
        }
    }

    set<pair<int, int>> unsorted_ranges;
    int seg = 0;
    for(int i = 0; i < n; i++) {
        seg += unsorted_sections[i];
        if(seg > 0) {
            int start = i;
            while(i < n && seg > 0) {
                i++;
                seg += unsorted_sections[i];
            }
            unsorted_ranges.insert({start, i});
        }
    }

    string s;
    cin >> s;

    set<int> problematic_pos;
    for(auto &[start, end] : unsorted_ranges) {
        for(int i = start + 1; i <= end; i++) {
            if(s[i] == 'R' && s[i-1] == 'L') {
                problematic_pos.insert(i-1);
            }
        }
    }

    while(q--) {
        
        int i;
        cin >> i;
        i--;

        char old_char = s[i];
        s[i] = (s[i] == 'R') ? 'L' : 'R';

        for(auto &[start, end] : unsorted_ranges) {
            if(start <= i && i <= end) {

                if(i > start && s[i-1] == 'L' && old_char == 'R') {
                    problematic_pos.erase(i-1);
                }

                if(i > start && s[i-1] == 'L' && s[i] == 'R') {
                    problematic_pos.insert(i-1);
                }
                
                if(i < end-1 && old_char == 'L' && s[i+1] == 'R') {
                    problematic_pos.erase(i);
                }
                if(i < end-1 && s[i] == 'L' && s[i+1] == 'R') {
                    problematic_pos.insert(i);
                }

            }
        }

        if(problematic_pos.empty()) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }

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