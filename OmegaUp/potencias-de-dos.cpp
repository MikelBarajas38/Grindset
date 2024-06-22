#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string next(string s) {

    string result = '0' + s;
    int carry = 0;

    for(int i = s.size() - 1; i >= 0; i--) {
        int digit = s[i] - '0';
        digit = digit * 2 + carry;
        if(digit >= 10) {
            digit = digit - 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result[i + 1] = digit + '0';
    }

    if(carry) {
        result[0] = '1';
    } else {
        result = result.substr(1);
    }

    return result;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    string power = "1";
    for(int i = 0; i < n; i++) {
        power = next(power);
    }

    cout << power << '\n';
    
    return 0;
}