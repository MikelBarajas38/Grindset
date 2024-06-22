#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void coin_toss(int n, string s) {
    if(n == 0) {
        cout << s << '\n';
        return;
    }
    coin_toss(n - 1, s + "A");
    coin_toss(n - 1, s + "X");
}

void coin_toss_2(int n) {
    
    for(int i = 0; i < (1 << n); i++) {
        string s = "";
        for(int j = n - 1; j >= 0; j--) {
            if(i & (1 << j)) {
                s += "X";
            } else {
                s += "A";
            }
        }
        cout << s << '\n';
    }

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n; 

    coin_toss_2(n);
    //coin_toss(n, "");

    return 0;
}