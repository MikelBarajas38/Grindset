#include<iostream>
#include<vector>

using namespace std;

int main() {
    int d, c, r, t;

    cin >> d >> c >> r;
    t = r;

    vector<int> cs(c);
    vector<int> rs(r);

    for (int &i : cs) cin >> i;
    for (int &i : rs) {
        cin >> i;
        d += i;
    }

    for (int i : cs) {
        if (i > d) break;
        d -= i;
        t ++;
    }

    cout << t << '\n';

    return 0;
}