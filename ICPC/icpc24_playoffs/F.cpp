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

    set<int> alice;
    for(int i = 0; i < 5; ++i) {
        int x;
        cin >> x;
        alice.insert(x);
    }

    for(int i = 0; i < 4; ++i) {
        int x;
        cin >> x;
        alice.erase(x);
    }

    cout << *(alice.begin()) << '\n';
    
    return 0;
}
