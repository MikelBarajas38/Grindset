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

    vector<int> og(3);
    
    for(int &x : og) {
        cin >> x;
    }

    vector<int> sorted = og;
    sort(all(sorted));

    int swaps = 0;
    for(int i = 0; i < 3; i++) {
        if(og[i] != sorted[i]) {
            swaps++;
        }
    }

    if(swaps) swaps--;
    cout << swaps << '\n';

    return 0;
}