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

void path(const vll &nums, vector<bool> &used, vll &first, int target) {
    
    if (target == 0) return;
    ll to_find = target - first[target];
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == first[target] && !used[i]) {
            used[i] = 1;
            break;
        }
    }
    path(nums, used, first, to_find);
}

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

    sort(all(nums));

    ll target = sum / 2;
    vll possible(sum + 1, 0);
    vll first(sum + 1, 0);

    possible[0] = true;

    for(ll k = 0; k < n; k++) {
        for(ll x = target; x >= 0; x--) {
            if(possible[x] && !possible[x+nums[k]]) { 
                possible[x+nums[k]] = true;
                first[x+nums[k]] = nums[k];
            }
        }
    }

    if(possible[target]) {

        vector<bool> used(n);
        path(nums, used, first, target);
        
        vll alice, bob;
        for(int i = nums.size() - 1; i >= 0; --i) {
            if(used[i]) {
                alice.push_back(nums[i]);
            } else {
                bob.push_back(nums[i]);
            }
        }
        
        ll alice_sum = 0, bob_sum = 0;
        int ap = 0, bp = 0;
        
        vector<ll> solution;
        
        while(ap < alice.size() || bp < bob.size()) {
            if(alice_sum <= bob_sum) {
                alice_sum += alice[ap];
                solution.push_back(alice[ap]);
                ap++;
            } else {
                bob_sum += bob[bp];
                solution.push_back(bob[bp]);
                bp++;
            }
        }

        for(ll &x : solution) {
            cout << x << " ";
        }
        cout << "\n";

    } else {
        cout << "-1\n";
        return 0;
    }

    return 0;
}
