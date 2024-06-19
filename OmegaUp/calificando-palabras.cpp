#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int get_score(string a) {
    int score = 0;
    for(char &c : a) {
        if(c >= '0' && c <= '9') {
            score = score + (c - '0');
        } else if (c >= 'A' && c <= 'Z') {
            score = score + ((c - 'A' + 10) * 2);
        } else if (c >= 'a' && c <= 'z') {
            score = score + (c - 'a' + 10);
        }
    }
    return score;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    string a, c;
    cin >> a >> c;

    int score_a = get_score(a);
    int score_c = get_score(c);

    if(score_a > score_c) {
        cout << "Ana" << ' ' << score_a << '\n';
    } else{
        cout << "Carolina" << ' ' << score_c << '\n';
    } 
    
    return 0;
}