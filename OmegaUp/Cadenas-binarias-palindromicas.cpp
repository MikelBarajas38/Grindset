#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool odd = true;

void print_palindromic_binary(string s) {
    
    int n = s.size();

    if(odd) {

        for(int i = 0; i < n; ++i) {
            cout << s[i];
        }
        cout << '0';
        for(int i = n - 1; i >= 0; --i) {
            cout << s[i];
        }
        cout << '\n';

        for(int i = 0; i < n; ++i) {
            cout << s[i];
        }
        cout << '1';
        for(int i = n - 1; i >= 0; --i) {
            cout << s[i];
        }
        cout << '\n';

    } else {

        for(int i = 0; i < n; ++i) {
            cout << s[i];
        }
        for(int i = n - 1; i >= 0; --i) {
            cout << s[i];
        }
        cout << '\n';

    }

}

void palindromic_binary(string s, int n) {
    
    if(n == 0) {
        print_palindromic_binary(s);
        return;
    }

    palindromic_binary(s + '0', n - 1);
    palindromic_binary(s + '1', n - 1);

}

void palindromic_binary_better(int n) {
    for(int b = 0; b < (1 << n); ++b) {
        string s;
        for(int i = n - 1; i >= 0; i--) {
            s += (b & (1 << i)) ? '1' : '0';
        }
        print_palindromic_binary(s);
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    cin.ignore();

    if(n % 2 == 0) {
        odd = false;
    }

    int lim = n / 2;
    //palindromic_binary("", lim);
    palindromic_binary_better(lim);

    return 0;
}