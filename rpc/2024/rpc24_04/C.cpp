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

    int n;
    cin >> n;

    int last = 0;
    int count = 0;
    int max_len = 0;

    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;

        if(x > last){
            count++;
            last = x;
        } else {
            max_len = max(max_len, count);
            count = 1;
            last = x;
        }

    }

    max_len = max(max_len, count);

    cout << max_len << "\n";

    return 0;
}