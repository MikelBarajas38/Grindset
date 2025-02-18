#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool scrcmp(const pair<int, vector<int>> &A, const pair<int, vector<int>> &B) {
    vi a = A.second;
    vi b = B.second;
    for (int i = 0; i < a.size(); i ++) {
        if (a[i] < b[i]) {
            return true;
        } else if (a[i] > b[i]) {
            return false;
        }
    }

    return true;
}

bool solve() {

    int n, k;
    cin >> n >> k;

    vector<vector<int>> score(n, vector<int>(k));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            cin >> score[i][j];
        }
    }

    vector<pair<int, vector<int>>> s;
    for (int i = 1; i <= n; i++)
        s.push_back({i, score[i-1]});

    stable_sort(all(s), scrcmp);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (s[i].second[j] < s[i-1].second[j]) {
                cout << "NO\n";
                return false;
            }
        }
    }

    cout << "YES\n";

    for (auto &i : s)
        cout << i.first << ' ';

    cout << '\n';
    return true;
}

int main() {

cin.tie(0)->sync_with_stdio(0);
cin.exceptions(cin.failbit);

    int T = 1;
    //cin >> T;

    while(T--) {
        solve();
    }

    return 0;

}

// evelyn