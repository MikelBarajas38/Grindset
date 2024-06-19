#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,
             tree_order_statistics_node_update> indexed_multiset;

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

    vector<int> elements(n);
    for(int &i : elements) {
        cin >> i;
    }

    int mid = k/2 + k%2 - 1;
    indexed_multiset s;

    for(int j = 0; j < k; j++){
        s.insert(elements[j]);
    }

    for(int i = 0; i < n - k + 1; i++) {

        cout << *s.find_by_order(mid) << " "; 

        s.erase(s.find_by_order(s.order_of_key(elements[i])));
        s.insert(elements[i + k]);

    }

    return 0;
}