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

    set<ll> s;
    
    for(int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        s.insert(x);
    }

    bool turn = 1;
    if(n % 2) {
        turn = 0;
    }

    ll past = 0;
    for(const ll &i : s) {
        if((i - past) % 2 == 0) {
            turn = !turn;   
        }

        past = i;
    }

    if(turn) {
        cout << "Alicius\n";
    } else {
        cout << "Bobius\n";
    }

    return 0;
}