#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    vector<vector<int>> games;

    games.push_back({a1, b1, a2, b2});
    games.push_back({a1, b2, a2, b1});
    games.push_back({a2, b1, a1, b2});
    games.push_back({a2, b2, a1, b1});

    int games_won = 0;

    for(vector<int> &game : games) {
        
        int suneet_wins = 0;
        int slavic_wins = 0;
        
        if (game[0] > game[1]) suneet_wins++;
        else if (game[1] > game[0]) slavic_wins++;
        
        if (game[2] > game[3]) suneet_wins++;
        else if (game[3] > game[2]) slavic_wins++;
        
        if (suneet_wins > slavic_wins) games_won++;

    }

    cout << games_won << '\n';

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T;
    cin >> T;

    while(T--) {
        solve();
    }
    return 0;
}