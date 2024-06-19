#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi parent;
vi parent_size;

void make_set(int x) {
    parent[x] = x;
    parent_size[x] = 1;
}

int find_set(int x) {

    if(parent[x] == x) {
        return x;
    }

    parent[x] = find_set(parent[x]);
    return parent[x];

}

bool is_same_set(int x, int y) {
    return find_set(x) == find_set(y);
}

void union_set(int x, int y) {
    int a = find_set(x);
    int b = find_set(y);
    if(a != b) {
        if (parent_size[a] < parent_size[b])
            swap(a, b);
        parent[b] = a;
        parent_size[a] += parent_size[b];
    }
}

int get_size(int x) {
    return parent_size[find_set(x)];
}

int check_potion() {
    int m;
    cin >> m;

    map<int,int> current_size;
    vi recipe(m);
    for(int j = 0; j < m; ++j) {
        cin >> recipe[j];
        current_size[find_set(recipe[j])]++;
    }

    bool can_be_done = true;
    for(auto p : current_size) {
        if(p.second != get_size(p.first)) {
            can_be_done = false;
            break;
        }
    }

    if(can_be_done) {
        int new_set = find_set(recipe[0]);
        for(auto p : current_size) {
            union_set(new_set, p.first);
        }
        return 1;
    }

    return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    parent.resize(500000);
    parent_size.resize(500000);
    for(int i = 0; i <= 500000; ++i) {
        make_set(i);
    }

    int total = 0;
    for(int i = 0; i < n; ++ i) {
        total += check_potion();
    }   
    cout << total << "\n";

    return 0;
}