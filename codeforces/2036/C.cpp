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
    cin >> s;

    vector<int> bin;
    for(char &c : s) {
        bin.push_back(c - '0');
    }

    int count = 0;
    set<int> poi;
    for(int i = 0; i < bin.size() - 3; i++) {
        int sum_a = bin[i] + bin[i+1];
        int sum_b = bin[i+2] + bin[i+3];
        if(sum_a == 2 && sum_b == 0) {
            count++;
            poi.insert(i);
        }
    }

    int q;
    cin >> q;

    while(q--) {
        
        int i, v;
        cin >> i >> v;

        i--;

        if(v != bin[i]) {
            for(int j = i - 3; j <= i; j++) {
                
                if(j < 0 || j + 3 >= bin.size()) {
                    continue;
                }

                if(poi.count(j)) {
                    count--;
                    poi.erase(j);
                }
            
            }
        }

        if(bin[i] != v) {

            bin[i] = v;

            for(int j = i - 3; j <= i; j++) {

                if(j < 0 || j + 3 >= bin.size()) {
                    continue;
                }

                int sum_a = bin[j] + bin[j+1];
                int sum_b = bin[j+2] + bin[j+3];
                if(sum_a == 2 && sum_b == 0) {
                    count++;
                    poi.insert(j);
                }

            }
        }

        if(count) {
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