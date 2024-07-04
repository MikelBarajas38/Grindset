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

    int n, k;
    cin >> n >> k;

    vector<int> views(n);
    for(int &v : views) {
        cin >> v;
    }

    int total_emotion = 0;
    for(int i = 1; i < k; ++i) {
        total_emotion += (views[i] - views[i - 1]);
    }

    int max_emotion = total_emotion;
    for(int i = k; i < n; ++i) {
        total_emotion -= (views[i - k + 1] - views[i - k]);
        total_emotion += (views[i] - views[i - 1]);
        max_emotion = max(max_emotion, total_emotion);
    }

    cout << max_emotion << '\n';
    
    return 0;
}