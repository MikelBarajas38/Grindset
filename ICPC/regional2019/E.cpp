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

    string Bs;
    ll s;

    cin >> Bs >> s;

    int B = Bs.length();

    ll total_subcakes = B * s;

    ll i=0;
    while(i < B && Bs[i] != 'E') i++;

    if(i == B) {
        cout << "0\n";
        return 0;
    } 

    ll n = 0;
    for(ll j = (i + 1)%B; j != i; j = (j+1)%B) {
        if(Bs[j] == 'E') {
            if(n > s) {
                total_subcakes -= ( n*s - (s*(s+1)/2) + s);
            } else {
                total_subcakes -= (n*(n+1)/2);
            }
            n = 0;
        } else {
            n++;
        }
    }

    if(n > s) {
        total_subcakes -= ( n*s - (s*(s+1)/2) + s);
    } else {
        total_subcakes -= (n*(n+1)/2);
    }

    cout << total_subcakes << "\n";

    return 0;
}