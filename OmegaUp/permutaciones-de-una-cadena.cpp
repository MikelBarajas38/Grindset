#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n_permutations = 0;

vector<char> used;
string permutation = "";

void permutations(string &s, int n) {
    
    if(n == 0) {
        cout << permutation << '\n';
        n_permutations++;
        return;
    }

    for(int i = 0; i < s.length(); i++) {
        if (used[i]) continue;

        used[i] = true;
        permutation += s[i];

        permutations(s, n - 1);
        
        permutation.pop_back();
        used[i] = false;

    }
}

void permutations2(string s) {
    sort(all(s));
    do {
        cout << s << '\n';
        n_permutations++;
    } while(next_permutation(all(s)));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    string s;
    cin >> s;

    permutations2(s);

    //used.assign(s.length(), false);

    //permutations(s, s.length());
    cout << n_permutations << '\n';

    return 0;
}