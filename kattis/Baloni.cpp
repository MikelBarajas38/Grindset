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

    int N;
    cin >> N;

    map<int,int> balloons;

    int shots = 0;
    for(int i = 0; i < N; ++i) {

        int h;
        cin >> h;

        if(balloons[h+1] > 0) {
            balloons[h+1]--;
        } else {
            shots++;
        }

        balloons[h]++;

    }

    cout << shots << '\n';

    return 0;
}