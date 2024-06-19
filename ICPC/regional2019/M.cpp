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

    int N, X;

    cin >> N >> X;

    vector<int> altitude(N);
    for(int &i : altitude) {
        cin >> i;
    }

    int viewpoints = 1, max_viewpoints = 1;
    for(int i=1; i<N; ++i) {
        if(altitude[i] - altitude[i-1] <= X) {
            viewpoints++;
        } else {
            max_viewpoints = max(max_viewpoints, viewpoints);
            viewpoints = 1;
        }
    }

    max_viewpoints = max(max_viewpoints, viewpoints);
    cout << max_viewpoints << "\n";

    return 0;
}