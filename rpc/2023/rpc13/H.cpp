#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

#define all(v) v.begin(), v.end()
#define loop while(true)
#define readv(v) for (auto &i : v) cin >> i
#define printv(v) for (auto &i : v) cout << i

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int num_months;
    cin >> num_months;

    vector<ull> days_prefix_sum = {0};

    for (int i = 0; i < num_months; i++)
    {
        ull x;
        cin >> x;

        days_prefix_sum.push_back(days_prefix_sum[i]+x);
    }
    
    int d0, m0, y0, d1, m1, y1;

    cin >> d0 >> m0 >> y0 >> d1 >> m1 >> y1;
    m0 --; m1 --;

    ull total = (y1 - y0)*days_prefix_sum.back() + (days_prefix_sum[m1]+d1) - (days_prefix_sum[m0]+d0);

    cout << total << '\n';

    return 0;
}
