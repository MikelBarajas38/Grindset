#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int dayA, monthA, yearA, dayB, monthB, yearB, weekA;

    cin >> dayA >> monthA >> yearA >> weekA >> dayB >> monthB >> yearB;

    ll longDayA = dayA + 30 * monthA + 360 * yearA;
    ll longDayB = dayB + 30 * monthB + 360 * yearB;

    ll diff = longDayB - longDayA;

    ll res = (diff % 7 + weekA) % 7;

    cout << (res == 0 ? 7 : res) << '\n';

    return 0;
}