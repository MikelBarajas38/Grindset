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

    int Ca, Ba, Pa, Cr, Br, Pr;
    cin >> Ca >> Ba >> Pa >> Cr >> Br >> Pr;

    int notS = 0;
    notS += (Ca > Cr ? 0 : Cr - Ca); 
    notS += (Ba > Br ? 0 : Br - Ba); 
    notS += (Pa > Pr ? 0 : Pr - Pa); 

    cout << notS << "\n";

    return 0;
}