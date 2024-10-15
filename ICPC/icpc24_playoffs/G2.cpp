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

    vector<int> nums(n);
    for(int &x: nums){
        cin >> x;
    }

    int maxn = *max_element(all(nums));
    vector<int> f(maxn + 1);

    for(int &x : nums) {

        for(int i = 1; i * i <= x; ++i) {
            if(x % i == 0) {
                f[i]++;
                if(x / i != i) {
                    f[x / i]++;
                }
            }
        }

    }

    for(int i = maxn; i >= 1; i--) {
        if(f[i] > 1) {
            if(f[i] == n) {
                cout << "YES\n";
            } else { 
                cout << "NO\n";
            }
            break;
        }
    }
    
    return 0;
}
