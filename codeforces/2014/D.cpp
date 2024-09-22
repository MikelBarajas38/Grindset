#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    int n, d, k;
    cin >> n >> d >> k;

    vector<int> job_control(n + 1);
    for(int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        job_control[l]++;
        job_control[r + 1]--;
    }

    vector<int> job(n + 1);
    for(int i = 1; i <= n; i++) {
        job[i] = job[i - 1] + job_control[i];
    }

    int max_overlap = -1, min_overlap = k + 1;
    int max_l = 0, min_l = 0;

    for(int i = 1; i <= n - d + 1; i++) {
        
        int overlap_i = 0;

        for(int j = i; j < i + d; j++) {
            overlap_i = max(overlap_i, job[j]);
        }

        if(overlap_i > max_overlap) {
            max_overlap = overlap_i;
            max_l = i;
        }

        if(overlap_i < min_overlap) {
            min_overlap = overlap_i;
            min_l = i;
        }

    }

    cout << max_l << " " << min_l << "\n";

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