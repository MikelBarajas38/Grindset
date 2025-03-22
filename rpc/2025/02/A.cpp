#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct result {
    int id;
    int pending;
};

void move_up(vector<result> &score, int start, int places) {
    for(int i = start; i > start - places; --i) {
        swap(score[i], score[i-1]);
    }
}

void solve() {

    int n, m, r;
    cin >> n >> m >> r;

    r--;

    vector<result> score(n);
    for(int i = 0; i < n; ++i) {
        string submissions;
        cin >> submissions;
        score[i].id = i;
        score[i].pending = count(all(submissions), 'P');
    }

    for(int i = n-1; i > 0; ++i) {

        while(!score[i].pending && i > 0) {
            i--;
        }

        score[i].pending--;

        if(i == 0) {
            break;
        }

        string chant1, chant2;
        cin >> chant1 >> chant2;

        int places_moved = count(all(chant2), 'y') - 3;

        if(places_moved) {
            move_up(score, i, places_moved);
            i--;
        }

    }

    for(int i = 0; i < n; ++i) {
        if(score[i].id == r) {
            cout << i + 1 << '\n';
            return;
        }
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