#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> parent;
vector<int> ranks;

void make_set(int v) {
    parent[v] = v;
    ranks[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ranks[a] < ranks[b])
            swap(a, b);
        parent[b] = a;
        if (ranks[a] == ranks[b])
            ranks[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, k;
    cin >> n >> k;

    map<int, string> words;
    for(int i=0; i<n; ++i) {
        cin >> words[i];
    }
    
    vector<Edge> edges;

    for(auto &s: words) {
        for(auto &t: words) {
            if(s.second == t.second) {
                continue;
            }

            int weight = 0;
            for(int i=0; i<k; ++i) {
                weight += abs(s.second[i] - t.second[i]);
            }

            edges.push_back({s.first, t.first, weight});
        }
    }

    int cost = 0;
    vector<Edge> result;
    parent.resize(n);
    ranks.resize(n);
    for (int i = 0; i < n; i++)
        make_set(i);

    sort(all(edges));

    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }

    Edge max_edge = *max_element(all(result));

    cout << max_edge.weight << "\n";
}