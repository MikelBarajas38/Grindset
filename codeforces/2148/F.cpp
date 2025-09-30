#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/*

3
3
4 4 9
7
7 6 5 4 3 2 1
4
2 4 5 1



*/

bool vec_cmp(vector<int> &a, vector<int> &b, int i) {
    while(i < a.size() && i < b.size() && a[i] == b[i]) {
        i++;
    }
    if(i >= a.size()) return true;
    else if(i >= b.size()) return false;
    else return a[i] < b[i];
}

void solve() {

    int n;
    cin >> n;

    vector<vector<int>> vec(n);
    int max_size = -1, max_i = 0;

    for(int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for(int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            vec[i].push_back(x);
        }
        if(k > max_size) {
            max_size = k;
            max_i = i;
        }
    }

    vector<int> min_pos(max_size, max_i);
    for(int j = 0; j < max_size;) {
        for(int i = 0; i < n; ++i) {
            if(j >= vec[i].size()) continue;
            if(vec_cmp(vec[i], vec[min_pos[j]], j)) {
                min_pos[j] = i;
            }
        }
        j = vec[min_pos[j]].size();
    }

    for(int j = 0; j < max_size;) {
        int i = min_pos[j];
        while(j < vec[i].size()) {
            cout << vec[i][j] << ' ';
            j++;
        }
    }
    cout << '\n';

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