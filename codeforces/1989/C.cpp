#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    int n;
    cin >> n;

    vector<int> first_movie_score(n);
    vector<int> second_movie_score(n);

    for(int &score: first_movie_score) {
        cin >> score;
    }

    for(int &score: second_movie_score) {
        cin >> score;
    }


    int total_score_1 = 0, total_score_2 = 0;
    vector<int> repeated(3);
    for(int i = 0; i < n; i++) {
        if(first_movie_score[i] == second_movie_score[i]) {
            if(first_movie_score[i] == 1) {
                repeated[2]++;
            } else if(first_movie_score[i] == 0) {
                repeated[1]++;
            } else {
                repeated[0]++;
            }
        } else if (first_movie_score[i] > second_movie_score[i]) {
            total_score_1 += first_movie_score[i];
        } else {
            total_score_2 += second_movie_score[i];
        }
    }

    for(int i = 0; i < repeated[0]; i++) {
        if(total_score_1 > total_score_2) {
            total_score_1 -= 1;
        } else {
            total_score_2 -= 1;
        }
    }

    for(int i = 0; i < repeated[2]; i++) {
        if(total_score_1 < total_score_2) {
            total_score_1 += 1;
        } else {
            total_score_2 += 1;
        }
    }

    cout << min(total_score_1, total_score_2) << "\n";
    
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