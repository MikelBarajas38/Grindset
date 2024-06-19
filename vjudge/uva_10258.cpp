#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct contestant {
    int id;
    int problems;
    int time;
    set<int> solved;
    map<int,int> wa;
};

bool comp_contestant(const contestant &a, const contestant &b) {
    if(a.problems != b.problems) {
        return b.problems < a.problems;
    }

    if(a.time != b.time) {
        return a.time < b.time;
    }

    return a.id < b.id;
}

void solve() {
    int i, p, t;
    char veredict;

    map<int,int> participants;
    vector<contestant> scoreboard;

    string line;
    while(getline(cin, line) && line.length() != 0) {

        istringstream iss(line);
        iss >> i >> p >> t >> veredict;

        if(participants.find(i) == participants.end()) {
            scoreboard.push_back({i, 0, 0});
            participants[i] = scoreboard.size() - 1;
        }

        if(scoreboard[participants[i]].solved.count(p)){
            continue;
        }

        if(veredict == 'C') {
            scoreboard[participants[i]].solved.insert(p);
            scoreboard[participants[i]].problems++;
            scoreboard[participants[i]].time += (t + scoreboard[participants[i]].wa[p] * 20);
        } else if (veredict == 'I') {
            scoreboard[participants[i]].wa[p]++;
        }

    }

    sort(all(scoreboard), comp_contestant);

    for(contestant &c : scoreboard) {
        cout << c.id << " " << c.problems << " " << c.time << "\n";
    }

}

int main() {

    int T;
    cin >> T;

    string space;
    getline(cin, space);
    getline(cin, space);

    while(T--) {
        solve();
        if(T > 0) {
            cout << "\n";
        }
    }
    

    return 0;
}