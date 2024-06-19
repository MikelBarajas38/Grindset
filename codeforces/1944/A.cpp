#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(2*n);
    for(int i=0; i<2*n; ++i) {
        cin >> a[i];
    }

    map<int,int> freq;
    int needed = k * 2;
    int i_r;
    set<int> l;

    for(int i=0; i<2*n; ++i) {
        freq[a[i]]++;
        if(freq.size() == n || needed <= 0) {
            i_r = i + 1; 
            break;
        }
        if(freq[a[i]] >= 2) {
            l.insert(a[i]);
            needed -= 2;
        }
    }

    if(needed > 0) {
        int lim = 2*k;
        for(int i = 1; i <= n; ++i) {
            if(lim <= 0) break;
            if(l.count(i)) continue;
            cout << i << ' ';
            lim--;
        }
        cout << '\n';
        lim = 2*k;
        for(int i = 1; i <= n; ++i) {
            if(lim <= 0) break;
            if(l.count(i)) continue;
            cout << i << ' ';
            lim--;
        }
        cout << '\n';
    } else {
        set<int> r;
        needed = k * 2;
        freq.clear();

        for(int i=i_r; i<2*n; ++i) {
            freq[a[i]]++;
            if(freq[a[i]] >= 2) {
                r.insert(a[i]);
                needed -= 2;
            }
            if(freq.size() == n || needed <= 0) {
                break;
            }
        }
        for(const int &i : l) {
        cout << i << ' ' << i << ' ';
        }
        cout << '\n';
        for(const int &i : r) {
            cout << i << ' ' << i << ' ';
        }
        cout << '\n';
    }

}

int main()
{
    int T;
    cin >> T;

    while(T--) {
        solve();
    }
    return 0;
}