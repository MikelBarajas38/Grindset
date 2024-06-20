#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<char, int> dominant_val = {
    {'A', 11},
    {'K', 4},
    {'Q', 3},
    {'J', 20},
    {'T', 10},
    {'9', 14},
    {'8', 0},
    {'7', 0}
};

map<char, int> non_dominant_val = {
    {'A', 11},
    {'K', 4},
    {'Q', 3},
    {'J', 2},
    {'T', 10},
    {'9', 0},
    {'8', 0},
    {'7', 0}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int N;
    char B;

    cin >> N >> B;

    int total = 0;

    for(int i = 0; i < 4*N; i++){

        string card;
        cin >> card;

        if(card[1] == B){
            total += dominant_val[card[0]];
        } else {
            total += non_dominant_val[card[0]];
        }
        
    }

    cout << total << "\n";

    return 0;
}