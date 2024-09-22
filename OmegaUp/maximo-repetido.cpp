
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

    vector<int> freq(101);

    int n;
    cin >> n;

    int max_freq = 0, max_num = 0;

    for(int i = 0; i < n; i++) {

        int x;
        cin >> x;
        freq[x]++;

        if(freq[x] > max_freq) {
            max_freq = freq[x];
            max_num = x;
        }

    }

    cout << max_freq << '\n';

    return 0;
}