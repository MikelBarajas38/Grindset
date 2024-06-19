#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi parent;

int find_set(int x) {

    if(parent[x] == x) {
        return x;
    }

    parent[x] = find_set(parent[x]);
    return parent[x];

}

bool is_same_set(int x, int y) {
    return find_set(x) == find_set(y);
}

void union_set(int x, int y) {
    if(!is_same_set(x, y)) {
        parent[parent[x]] = parent[y];
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int N, Q;
    cin >> N >> Q;

    parent.resize(N+1);
    for(int i = 1; i <= N; ++i) {
        parent[i] = i;
    }

    for(int i = 1; i<=Q; ++i) {
        char query;
        int x, y;

        cin >> query >> x >> y;

        if(query == '?') {
            string ans = (is_same_set(x, y)) ? "yes" : "no";
            cout << ans << "\n";
        } else {
            union_set(x, y);
        }
    }

    return 0;
}