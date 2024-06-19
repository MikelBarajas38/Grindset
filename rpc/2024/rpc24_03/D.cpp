#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<ll, ll> prime_factors(ll n) 
{ 
    map<ll, ll> factors;
    while (n % 2ll == 0) 
    { 
        factors[2ll]++;
        n = n/2ll; 
    } 
 
    for (ll i = 3ll; i <= sqrt(n); i = i + 2ll) 
    { 
        while (n % i == 0) 
        { 
            factors[i]++;
            n = n/i; 
        } 
    } 

    if (n > 2ll) 
        factors[n]++;

    return factors;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    ll n;
    cin >> n;

    map<ll, ll> factors = prime_factors(n);

    ll num_of_factors = 1;
    for(auto &factor: factors){
        num_of_factors *= (factor.second + 1);
    }

    if(num_of_factors % 2) {
        cout << "N\n";
        return 0;
    }

    if(factors.size() > 2){
        cout << "N\n";
        return 0;
    }

    if(factors.size() == 2){
        if(factors.begin()->second > 1 || factors.rbegin()->second > 1){
            cout << "N\n";
            return 0;
        }
    }

    cout << "Y\n";
    return 0;
}