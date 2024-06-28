#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


void solve()
{

    int n, l, r;
    cin >> n >> l >> r;

    int current_hand = 0, winning_hands = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        current_hand += x;

        if(current_hand >= l && current_hand <= r){
            winning_hands++;
            current_hand = 0;
        } else if(current_hand > r){
            if(x >= l && x <= r)  {
                winning_hands++;
                current_hand = 0;
            } else if(x > r) {
                current_hand = 0;
            } else {
                current_hand = x;
            }
        }
    }

    cout << winning_hands << '\n';
    
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T;
    cin >> T;

    while(T--){
        solve();
    }

    return 0;
}