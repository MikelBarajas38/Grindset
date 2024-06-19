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
    for(ll &i: a){
        cin >> i;
    }

    map<ll, int> diff;
    for(int i = 0; i < n; i++){
        ll bi;
        cin >> bi;

        if(bi != a[i]){
            diff[bi]++;
        }
    }

    bool done = false;
    if(diff.size() == 0){
        done = true;
    }

    int m;
    cin >> m;

    int extra = 0, finished = 0;
    for(int i = 0; i < m; i++){
        ll di;
        cin >> di;

        if(done){
            continue;
        }

        if(diff.find(di) == diff.end()){
            extra = 1;
            continue;
        }

        if(diff[di] == 0){
            extra = 0;
            continue;
        }

        diff[di]--;
        extra = 0;

        if(diff[di] == 0){
            finished++;
        }

    }

    if(done || (diff.size() == finished && extra == 0)){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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