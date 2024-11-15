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

    map<ll, ll> total_sold;
    for(int i = 0; i < k; i++) {
        ll b, c;
        cin >> b >> c;
        total_sold[b] += c;
    }

    priority_queue<ll> pq;
    for(auto &[b, p] : total_sold) {
        pq.push(-p);
        if(pq.size() > n) {
            pq.pop();
        }
    }

    ll total = 0;
    while(!pq.empty()) {
        total -= pq.top();
        pq.pop();
    }

    cout << total << '\n';

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