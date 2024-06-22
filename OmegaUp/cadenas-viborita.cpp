#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n_strings = 0;

void snake_strings(string s, int n) {

    if(n == 0) {
        n_strings++;
        return;
    }

    char last = s.back();

    if(last + 1 <= '9' && last - s[0] + 1 < n) {
        snake_strings(s + char(last + 1), n - 1);
    }

    if(last - 1 >= '0' && s[0] - last + 1 < n) {
        snake_strings(s + char(last - 1), n - 1);
    }   
    
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    if(n % 2) {
        for(char d = '0'; d <= '4'; d++) {
            snake_strings(string(1, d), n - 1);
        }
        n_strings *= 2;
    }

    cout << n_strings << '\n';

    return 0;
}