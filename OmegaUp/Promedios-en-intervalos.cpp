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

    vector<pair<int,int>> students(n + 1);
    for(int i = 1; i <= n; ++i) {
        cin >> students[i].first >> students[i].second;
    }

    sort(all(students));

    vector<int> sum(n + 1);
    vector<int> count(n + 1);
    for(int i = 1; i <= n; ++i){
        sum[i] = sum[i - 1] + students[i].second;
        count[i] = count[i - 1] + 1;
    }

    map<int, int> lista_match;
    for(int i = 1; i <= n; ++i){
        lista_match[students[i].first] = i;
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; ++i){
        int l, r;
        cin >> l >> r;

        int index_l = -1;
        if(lista_match.lower_bound(l) != lista_match.end()) {
            index_l = lista_match.lower_bound(l)->second;
        }

        if(index_l == -1) {
            cout << "-1\n";
            continue;
        }

        int index_r = n;
        if(lista_match.upper_bound(r) != lista_match.end()){
            index_r = lista_match.upper_bound(r)->second - 1;
        }

        int suma = sum[index_r] - sum[index_l - 1];
        int cantidad = count[index_r] - count[index_l - 1];

        if(cantidad == 0) {
            cout << "-1\n";
            continue;
        }

        cout << suma / cantidad << "\n";

    }

    return 0;
}