#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int subsets = 0;
bool possible = true;

void generate_subsets(int s, int k, int i, vector<ll> &problems, vector<ll> &current) {
    if(s == k) {
        if(current[k-1] <= current[k-2] + current[k-3]) {
            subsets++;
        }
        return;
    }

    if(i >= problems.size()) {
        return;
    }

    if(s < 1) {
        current.push_back(problems[i]);
        generate_subsets(s+1, k, i + 1, problems, current);
        current.pop_back();

        possible = true;
        generate_subsets(s, k, i + 1, problems, current);
        return;
    }

    if(s < 2) {
        current.push_back(problems[i]);
        if(i + 1 < problems.size() && problems[i+1] <= current[0] + current[1]) {
            generate_subsets(s+1, k, i + 1, problems, current);
        }
        current.pop_back();
        return;
    }

    int a = current[s-1];
    int b = current[s-2];
    if(problems[i] <= a + b) {
        current.push_back(problems[i]);
        generate_subsets(s + 1, k, i + 1, problems, current);
        current.pop_back();

        if(i + 1 < problems.size() && problems[i+1] <= a + b) {
            generate_subsets(s, k, i + 1, problems, current);
        }
    } 
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, k;
    cin >> n >> k;

    vector<ll> p(n);
    for(ll &i : p) {
        cin >> i;
    }

    sort(all(p));

    vector<ll> current;
    generate_subsets(0, k, 0, p, current);

    cout << subsets << "\n";

    return 0;
}