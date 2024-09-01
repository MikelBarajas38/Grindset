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

ll mut(const vi &v, ll m, ll Mut) {
    for (ll j = 0; j < v.size(); j++) {
        if (Mut & (1 << j)) {
            m |= (1<<v[j]);
        } else {
            m &= ~(1<<v[j]);
        }
    }

    return m;
}

void printb(ll n) {
    string bin = "";

    while (n) {
        if (n%2 == 0) {
            bin += '0';
        } else {
            bin += '1';
        }

        n/=2;
    }

    reverse(all(bin));

    cout << bin << '\n';
}

/// @brief 
/// @return 
int main() {
    string a, b;
    cin >> a >> b;

    ll N, M, n, m;
    vi A, B;

    ll p = a.size() - 1;
    for (char &i : a) {
        if (i == '*') {
            i = '0';
            A.push_back(p);
        }
        p--;
    }

    p = b.size() - 1;
    for (char &i : b) {
        if (i == '*') {
            i = '0';
            B.push_back(p);
        }
        p--;
    }

    reverse(all(A));
    reverse(all(B));

    n = stoll(a, (size_t*) 0, 2);
    m = stoll(b, (size_t*) 0, 2);

    for (ll M = 0; M < (2 << B.size()); M++) {
        for (ll N = 0; N < (2 << A.size()); N++) {
            if (n % m == 0) {
                printb(n);
                return 0;
            }

            n = mut(A, n, N);
        }
        
        m = mut(B, m, M);
    }
    
    if (n % m == 0) {
        printb(n);
        return 0;
    }

    return 1;
}
