#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool comp_sets(const vi &a, const vi &b) {
    return a.size() > b.size();
}

void solve() {
    
    int n;
    cin >> n;

    map<int, int> union_set;

    vector<set<int>> sets;
    for(int i=0; i<n; ++i) {
        int k;
        cin >> k;

        set<int> set;
        for(int j=0; j<k; ++j) {
            int x;
            cin >> x;
            union_set[x]++;
            set.insert(x);
        }

        sets.push_back(set);
    }

    int best_diff = 51;
    for(int i=1; i<=50; ++i) {
        int diff = 0;
        map<int, int> test = union_set;
        for(set<int> &set : sets) {
            if(set.count(i)) {
                for(const int &element : set) {
                    test[element]--;
                    if(test[element] == 0) {
                        diff++;
                    }
                }
            }
        }
        if(diff > 0) {
            best_diff = min(best_diff, diff);
        }
        
    }

    cout << union_set.size() - best_diff << "\n";

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