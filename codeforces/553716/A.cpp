#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int block_size;
map<int, int> match;
vector<int> freq(20001);
set<pair<int,int>> MQ;
vector<int> arr;
vector<int> ans(200000);

void remove(int x) {
    MQ.erase({freq[x], x});
    freq[x]--;
    MQ.insert({freq[x], x});
}

void add(int x) {
    MQ.erase({freq[x], x});
    freq[x]++;
    MQ.insert({freq[x], x});
}

int get_answer() {
    auto it = MQ.rbegin();
    return (*it).first;
}

struct Query {
    int l, r, i;
};

bool cmp(Query &p, Query &q) {
    if (p.l / block_size != q.l / block_size)
        return p.l == q.l ? p.r < q.r : p.l < q.l;
    return (p.l / block_size & 1) ? (p.r < q.r) : (p.r > q.r);
}

void mo_s_algorithm(vector<Query> &queries) {

    sort(queries.begin(), queries.end(), cmp);

    int cur_l = 0;
    int cur_r = -1;

    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(arr[cur_l]);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(arr[cur_r]);
        }
        while (cur_l < q.l) {
            remove(arr[cur_l]);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(arr[cur_r]);
            cur_r--;
        }
        ans[q.i] = q.r - q.l - get_answer() + 1;
    }

}

void solve() {

    int n, q;
    cin >> n >> q;

    block_size = sqrt(n);

    vector<int> a(n);
    for(int &x : a) {
        cin >> x;
    }

    vector<int> diff(n);
    for(int i = 0; i < n; ++i) {
        diff[i] = a[i] - i;
    }

    arr = diff;
    vector<int> b = arr;
    sort(all(b));

    for(int i = 0; i < n; ++i) {
        match[b[i]] = i;
    }

    for(int i = 0; i < n; ++i) {
        arr[i] = match[arr[i]];
    }

    vector<Query> queries;
    for(int i = 0; i < q; ++i) {
        Query q;
        cin >> q.l >> q.r;
        q.l--; q.r--;
        q.i = i;
        queries.push_back(q);
    }

    mo_s_algorithm(queries);

    for(int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T = 1;
    //cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}