#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<string, int> power_levels = {
    {"Shadow", 6},
    {"Gale", 5},
    {"Ranger", 4},
    {"Anvil", 7},
    {"Vexia", 3},
    {"Guardian", 8},
    {"Thunderheart", 6},
    {"Frostwhisper", 2},
    {"Voidclaw", 3},
    {"Ironwood", 3},
    {"Zenith", 4},
    {"Seraphina", 1}
};

int get_power(multiset<string> &P, int location) {
    
    int power = 0;
    
    for(const string &s : P) {
        power += power_levels[s];
    }

    for(const string &s : P) {
        if(s == "Thunderheart" && P.size() >= 4) {
            power += power_levels["Thunderheart"];
        }
    }

    for(const string &s : P) {
        if(s == "Zenith" && location == 1) {
            power += 5;
        }
    }

    for(const string &s : P) {
        if(s == "Seraphina") {
            power += P.size() - 1;
        }
    }
    
    return power;
}

void solve() {
    
    vector<multiset<string>> P1(3);
    vector<multiset<string>> P2(3);

    int p1_wins = 0;
    int p2_wins = 0;

    int p1_total_power = 0;
    int p2_total_power = 0;

    for(int i = 0; i < 3; i++) {
        
        int n1;
        cin >> n1;

        for(int j = 0; j < n1; j++) {
            string s;
            cin >> s;
            P1[i].insert(s);
        }

        int n2;
        cin >> n2;

        for(int j = 0; j < n2; j++) {
            string s;
            cin >> s;
            P2[i].insert(s);
        }

        int power_1 = get_power(P1[i], i);
        int power_2 = get_power(P2[i], i);

        if (power_1 > power_2) {
            p1_wins++;
        } else if (power_2 > power_1) {
            p2_wins++;
        }

        p1_total_power += power_1;
        p2_total_power += power_2;

    }

    if(p1_wins == p2_wins) {
        if(p1_total_power > p2_total_power) {
            cout << "Player 1\n";
        } else if(p2_total_power > p1_total_power) {
            cout << "Player 2\n";
        } else {
            cout << "Tie\n";
        }
    } else if(p1_wins > p2_wins) {
        cout << "Player 1\n";
    } else {
        cout << "Player 2\n";
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