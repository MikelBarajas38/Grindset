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

    vector<pair<int,int>> students(n);
    for(auto &student : students) {
        cin >> student.first >> student.second;
    }

    sort(all(students));

    vector<int> sum(n+1, 0);
    vector<int> count(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        sum[i] = sum[i-1] + students[i-1].second;
        count[i] = count[i - 1] + 1;
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;

        int index_l = lower_bound(all(students), pair<int,int>({l, 0})) - begin(students);
        int index_r = upper_bound(all(students), pair<int,int>({r, 11})) - begin(students) - 1;

        if(index_l > index_r) {
            cout << "-1\n";
            continue;
        }

        index_l = max(0, index_l);

        int range_sum = sum[index_r + 1] - sum[index_l];
        int range_count = count[index_r + 1] - count[index_l];

        cout << range_sum / range_count << "\n";
    }


    return 0;
}