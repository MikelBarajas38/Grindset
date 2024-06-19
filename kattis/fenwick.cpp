#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

class SegmentTree {                              // OOP style
private:
  int n;                                         // n = (int)A.size()
  vl A, st, lazy;                                // the arrays

  int l(int p) { return  p<<1; }                 // go to left child
  int r(int p) { return (p<<1)+1; }              // go to right child

  ll conquer(int a, int b) {
    if (a == -1) return b;                       // corner case
    if (b == -1) return a;
    return a + b;                            // RMQ
  }

  void build(int p, int L, int R) {              // O(n)
    if (L == R)
      st[p] = A[L];                              // base case
    else {
      int m = (L+R)/2;
      build(l(p), L  , m);
      build(r(p), m+1, R);
      st[p] = conquer(st[l(p)], st[r(p)]);
    }
  }

  void propagate(int p, int L, int R) {
    if (lazy[p] != -1) {                         // has a lazy flag
      st[p] = lazy[p];                           // [L..R] has same value
      if (L != R)                                // not a leaf
        lazy[l(p)] = lazy[r(p)] = lazy[p];       // propagate downwards
      else                                       // L == R, a single index
        A[L] = lazy[p];                          // time to update this
      lazy[p] = -1;                              // erase lazy flag
    }
  }

  ll RSQ(int p, int L, int R, int i, int j) {   // O(log n)
    propagate(p, L, R);                          // lazy propagation
    if (i > j) return 0;                        // infeasible
    if ((L >= i) && (R <= j)) return st[p];      // found the segment
    int m = (L+R)/2;
    ll c = conquer(RSQ(l(p), L  , m, i          , min(m, j)),
                   RSQ(r(p), m+1, R, max(i, m+1), j        ));
    return c;
  }

  void update(int p, int L, int R, int i, int j, ll val) { // O(log n)
    propagate(p, L, R);                          // lazy propagation
    if (i > j) return;
    if ((L >= i) && (R <= j)) {                  // found the segment
      lazy[p] = val;                             // update this
      propagate(p, L, R);                        // lazy propagation
    }
    else {
      int m = (L+R)/2;
      update(l(p), L  , m, i          , min(m, j), val);
      update(r(p), m+1, R, max(i, m+1), j        , val);
      ll lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
      ll rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
      st[p] = st[l(p)] + st[r(p)];
    }
  }

public:
  SegmentTree(int sz) : n(sz), A(n), st(4*n), lazy(4*n, -1) {}

  void update(int i, int j, ll val) { update(1, 0, n-1, i, j, val); }

  ll RSQ(int i, int j) { return RSQ(1, 0, n-1, i, j); }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int N, Q;
    cin >> N >> Q;

    SegmentTree st(N);

    for(int i = 0; i < Q; ++i) {
        char query;
        ll a, b;
        cin >> query;

        if(query == '+') {
            cin >> a >> b;
            st.update(a+1, a+1, b);
        } else {
            cin >> a;
            cout << st.RSQ(1, a) << "\n";
        }
    }

    return 0;
}