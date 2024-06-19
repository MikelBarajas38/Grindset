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

    string num;
    cin >> num;

    bool contains_seven = false;
    for(char &c : num) {
        if(c == '7') {
            contains_seven = true;
        }
    }

    ll n = stoll(num);
    if(!contains_seven && n % 7 != 0) {
        cout << "0\n";
    } else if (!contains_seven && n % 7 == 0) {
        cout << "1\n";
    } else if (contains_seven && n % 7 != 0) {
        cout << "2\n";
    } else if (contains_seven && n % 7 == 0) {
        cout << "3\n";
    }

    return 0;
}