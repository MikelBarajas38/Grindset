#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

set<ll> explored;

void dfs(map<ll, vi> &adj_list, vector<set<ll>> &groups, ll id) {
    if (explored.count(id)) return;

    explored.insert(id);

    for (int adj : adj_list[id]) {
        groups[adj].insert(all(groups[id]));
        dfs(adj_list, groups, adj);
    }
}

int main() {

    ll n;
    cin >> n;

    map<ll, vi> adj_list;
    vector<set<ll>> groups(n+1, set<ll>());

    for (ll i = 1; i <= n; i++)
    {
        int parent;
        cin >> parent;

        adj_list[parent].push_back(i);
    }

    for (ll i = 1; i <= n; i++)
    {
        int group;
        cin >> group;

        groups[i].insert(group);
    }    

    dfs(adj_list, groups, 0ll);

    for (ll i = 1; i <= n; i++)
    {
        cout << groups[i].size() << ' ';
    }

    cout << '\n';
    

    return 0;
}