#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    int n, s, m;
    cin >> n >> s >> m;

    vector<pair<int, int>> tasks(n);
    for(int i = 0; i < n; ++i) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    tasks.push_back({m, m});
    tasks.push_back({0, 0});

    sort(all(tasks));

    for(int i = 1; i < n + 2; ++i) {
        int time_inbetween = tasks[i].first - tasks[i - 1].second;
        if(time_inbetween >= s) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";

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