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

    int n, k;
    cin >> n >> k;

    string roulette;
    cin >> roulette;

    int l = 0, r = 0;
    int p_count = 0, s_count = 0, best_p_count = -1;


    while(r != (l - 1 + n) % n && l != n - 1) {

        if(roulette[r] == 'P') {
            p_count++;
        } else {
            s_count++;
        }

        while(l != r && l != n - 1 && s_count >= k) {
            if(roulette[l] == 'P') {
                p_count--;
            } else {
                s_count--;
            }
            l = (l + 1) % n;
        }

        best_p_count = max(best_p_count, p_count);

        r = (r + 1) % n;

    }

    cout << best_p_count << '\n';

    return 0;
}