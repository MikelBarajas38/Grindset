#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define INF 1000000000
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

/*
counterexample:

sort in ascending order
4
1 2 2 3

sort in descending order
5
8 7 6 5 4

*/

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    vll nums(n);
    ll sum = 0;

    for(ll &x : nums) {
        cin >> x;
        sum += x;
    }

    if (sum % 2) {
        cout << "-1\n";
        return 0;
    }

    sort(nums.rbegin(), nums.rend());

    ll target = sum / 2;
    
    ll alice_sum = 0, bob_sum = 0;
    for(int i = 0; i < n; ++i) {
        if(alice_sum <= bob_sum) {
            alice_sum += nums[i];
        } else {
            bob_sum += nums[i];
        }
    }

    if(alice_sum == bob_sum) {
        for(ll &x : nums) {
            cout << x << " ";
        }
        cout << "\n";

    } else {
        cout << "-1\n";
        return 0;
    }

    return 0;
}
