#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_multiset;

/*

1 4 3 2 5 3 3

4,3
4,2
4,3
4,3

3,2

5,3
5,3

0 1 2 3 4 5
1 4 3 2 5 3

1
4,3 - 2
4,2 - 3
4,3 - 5

2
3,2 - 3

4
5,3 - 5


4 3 2 5 7 8 9 2

0
4

*/

void solve() {

    int n;
    cin >> n;

    vector<int> A(n);

    for(int &x : A) {
        cin >> x;
    }

    /*
    indexed_multiset rhs;
    for(int &x : A) {
        rhs.insert(x);
    }

    int max_inversions = 0;
    vector<int> test_ls;

    for(int i = 0; i < n; ++i) {

        int x = A[i];
        int inversions = rhs.order_of_key(x);

        if(inversions > max_inversions) {
            max_inversions = inversions;
            test_ls.clear();
            test_ls.push_back(i);
        } else if(inversions == max_inversions) {
            test_ls.push_back(i);
        }

        rhs.erase(rhs.find_by_order(inversions));
    }
    */

    int global_best_inversions = n;
    int gl = 0, gr = 0;

    for(int l = 0; l < n; ++l){

        int r = l;
        int best_inversions = n;
        int current_inversions = best_inversions;

        for(int i = l + 1; i < n; ++i) {

            if(A[i] < A[l]) {
                current_inversions--;
            } else if(A[i] > A[l]) {
                current_inversions++;
            }

            if(current_inversions < best_inversions) {
                best_inversions = current_inversions;
                r = i;
            }
        }

        if(best_inversions < global_best_inversions) {
            global_best_inversions = best_inversions;
            gl = l;
            gr = r;
        }

    }

    cout << gl + 1 << ' ' << gr + 1 << '\n';

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
