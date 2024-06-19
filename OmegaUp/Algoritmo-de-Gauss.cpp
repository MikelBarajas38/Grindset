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

    int A;
    cin >> A;

    int B = A / 100 + 1;
    int C = 3*B / 4 - 12;
    int E = A % 19 + 1;
    int F = (8*B + 5)/25 - (5 + C);
    int G = 5*A / 4 - (C + 10);
    int H = (11*E + 20 + F) % 30;

    if(H == 25 && E > 11) {
        H++;
    }

    if(H == 24) {
        H++;
    }

    int I = 44 - H;

    if(I < 21) {
        I += 30;
    }

    int J = I + 7 - (G + I) % 7;

    if(J <= 31) {
        cout << J << " 3\n";
    }
    else {
        cout << J - 31 << " 4\n";
    }

    return 0;
}