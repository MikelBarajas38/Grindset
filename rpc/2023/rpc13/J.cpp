#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

#define all(v) v.begin(), v.end()
#define loop while(true)
#define readv(v) for (auto &i : v) cin >> i
#define printv(v) for (auto &i : v) cout << i

string figs[6][3] = {
    // 1
    {"A--",
     "B--",
     "CD-"},
    
    // 2
    {"--A",
     "--B",
     "-DC"},

    // 3
    {"---",
     "AB-",
     "-CD"},

    // 4
    {"---",
     "-CD",
     "AB-"},

    // 5
    {"---",
     "-D-",
     "ABC"},
    
    // 6
    {"---",
     "AB-",
     "CD-"}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int f, n, r = 0;
    cin >> f >> n;
    f--;

    while (n--)
    {
        int x;
        cin >> x;

        r += x;
    }
    
    r %= 360;
    if (r < 0) r+= 360;

    switch (r)
    {
    case 0:
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << figs[f][i][j];
            }
            cout << '\n';
        }
        
        break;
    
    case 90:
        for (int i = 0; i < 3; i++)
        {
            for (int j = 2; j >= 0; j--)
            {
                cout << figs[f][j][i];
            }
            cout << '\n';
        }

        break;

    case 180:
        for (int i = 2; i >= 0; i--)
        {
            for (int j = 2; j >= 0; j--)
            {
                cout << figs[f][i][j];
            }
            cout << '\n';
        }

        break;

    case 270:
        for (int i = 2; i >= 0; i--)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << figs[f][j][i];
            }
            cout << '\n';
        }
        
        break;

    default:
        break;
    }

    return 0;
}
