#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pair<int, int>>;



int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<double> v(n);

    for (double &i : v) {
        cin >> i;
    }

    sort(v.begin(),v.end(), greater<double>());

    double total = accumulate(v.begin(), v.end(), 0.0);
    double res = accumulate(v.begin(), v.begin()+m+k, 0.0);

    double p = res * 100.0 / total;

    cout << fixed << setprecision(5) << p << '\n';

    return 0;
}