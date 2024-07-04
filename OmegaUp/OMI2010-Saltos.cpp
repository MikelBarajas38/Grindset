#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    ll M, N, A, D, Y, X;
    cin >> M >> N >> A >> D >> Y >> X;
    
    ll Y_jumps = M / gcd(A, M);
    ll X_jumps = N / gcd(D, N);
    
    ll jumps = lcm(Y_jumps, X_jumps);
    
    cout << jumps << '\n';
    return 0;
}