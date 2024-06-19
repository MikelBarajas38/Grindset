#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pair<int, int>>;



int main() {
    string s;
    cin >> s;

    long long int v[] = {0, 0, 0};

    long long int r = 0;
    for (char c : s) {
        if (c == '0') {
            r += v[1] + v[2];
        } else if (c == '1') {
            r += v[2];
        }
        v[c - '0'] ++;
    }

    cout << r << '\n';

    return 0;
}