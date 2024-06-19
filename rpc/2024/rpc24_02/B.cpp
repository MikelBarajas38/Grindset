#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pair<int, int>>;

int main() {
    
    long double n;
    cin >> n;

    long long attacks = ceill(log2l(n)) + 1ll;

    cout << attacks << "\n";

    return 0;
}