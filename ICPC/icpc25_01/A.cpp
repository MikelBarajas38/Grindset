#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define readv(_v) for (auto &_i : _v) cin >> i


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string ptrn;
    cin >> ptrn;

    int n;
    cin >> n;

    while (n--) {
        string w;
        cin >> w;

        if (w.size() % ptrn.size() != 0) {
            cout << "No\n";
            continue;
        }

        bool bad = false;
        for (int i = 0; i < w.size(); i++)  {
            if (w[i] != ptrn[i%ptrn.size()]) {
                cout << "No\n";
                bad = true;
                break;
            }
        }

        if(bad) continue;

        cout << "Yes\n";
    }

    return 0;
}