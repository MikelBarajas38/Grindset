#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<char> keypad = {
    '2', '2', '2',
    '3', '3', '3',
    '4', '4', '4',
    '5', '5', '5',
    '6', '6', '6',
    '7', '7', '7', '7',
    '8', '8', '8',
    '9', '9', '9', '9'
};

string get_keypresses(string &s) {
    string keys = "";
    for(char &c : s) {
        keys += keypad[c - 'a'];
    }
    return keys;
}

void solve() {

    int n, m;
    cin >> n >> m;

    map<string, vector<string>> key_phrases;

    for(int i = 0; i < n; ++i) {
        string phrase;
        cin >> phrase;
        key_phrases[get_keypresses(phrase)].push_back(phrase);
    }

    for(int i = 0; i < m; ++i) {
        string digits;
        cin >> digits;
        cout << key_phrases[digits].size();
        for(string &phrase : key_phrases[digits]) {
            cout << ' ' << phrase;
        }
        cout << '\n';
    }

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T = 1;
    //cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}