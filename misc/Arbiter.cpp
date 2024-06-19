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

    int n;
    cin >> n;

    vector<pair<int,int>> scores(n);
    for(int i = 0; i < n; ++i) {
        scanf("%d-%d", &(scores[i].first), &(scores[i].second));
    }

    bool possible = true, game_ended = false;
    pair<int,int> last;
    int A = 0, B = 0, i;
    for(i = 0; i < n; ++i) {

        if(game_ended) {
            if(scores[i] != last) {
                possible = false;
                break; 
            } else {
                continue;
            }
        }

        int round = scores[i].first + scores[i].second;

        if(round > 21) {
            possible = false;
            break;
        }

        if(round % 4 == 3 || round % 4 == 0) {

            if(scores[i].first < A || scores[i].second < B){
                possible = false;
                break;
            }

            A = scores[i].first;
            B = scores[i].second;

        } else {

            if(scores[i].first < B || scores[i].second < A){
                possible = false;
                break;
            }
            
            B = scores[i].first;
            A = scores[i].second;

        }

        if(A == 11 || B == 11) {
            game_ended = true;
            last = scores[i];
        }

    }

    if(possible) {
        cout << "ok\n";
    } else {
        cout << "error " << i + 1 << '\n';
    }
    
    return 0;
}

/*

0 1 2 3 4 5 6
A B B A A B B
*/