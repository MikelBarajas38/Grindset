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

    string a, b;
    cin >> a >> b;

    set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    string na, nb;

    na += a[0];
    int i = 1;
    while(i < a.length() && vowels.count(a[i]) == 0) {
        na += a[i];
        i++;
    }

    char v1;
    if(i == a.length()) {
        v1 = 0;
    } else {
        v1 = a[i];
    }

    nb += b[b.length() - 1];
    i = b.length() - 2;
    while(i >= 0 && vowels.count(b[i]) == 0) {
        nb += b[i];
        i--;
    }

    char v2;
    if(i == -1) {
        v2 = 0;
    } else {
        v2 = b[i];
    }

    reverse(all(nb));

    char merge = 'o';
    if(v2) {
        merge = v2;
    } else if(v1) {
        merge = v1;
    }

    cout << na << merge << nb << "\n";

    return 0;
}