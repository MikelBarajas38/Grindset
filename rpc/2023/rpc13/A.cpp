#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string a, b, c;
    cin >> a >> b >> c;

    vector<string> v = {a+b+c, a+c+b, b+a+c, b+c+a, c+a+b, c+b+a};

    sort(v.begin(), v.end());

    cout << v[5] << '\n';

    return 0;
}
