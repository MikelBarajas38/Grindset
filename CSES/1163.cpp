#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int x, n;

    cin >> x >> n;

    set<int> lights;
    lights.insert(0);
    lights.insert(x);

    multiset<int> distances;
    distances.insert(x);

    for(int i = 0; i < n; ++i) {
        int pos;
        cin >> pos;

        auto right = lights.upper_bound(pos);
        auto left = right; left--;

        distances.erase(distances.find(*right - *left));
        distances.insert(pos - *left);
        distances.insert(*right - pos);
        lights.insert(pos);

        cout << *(--distances.end()) << " ";
    }    

    return 0;
}