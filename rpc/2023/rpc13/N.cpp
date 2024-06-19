#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

#define all(v) v.begin(), v.end()
#define loop while(true)
#define readv(v) for (auto &i : v) cin >> i
#define printv(v) for (auto &i : v) cout << i

// how many candles are needed for x triangles
ull f(ull x) {
    return ((x+1)*(x+2)*(x+3))/6 - 1;
}

void solve(ull n) {
    ull total = 0;

    while (n >= 3) {
        ull lower = 1;
        ull upper = 1836093; // highest possible result
        ull mid;

        while (lower < upper) {
            mid = (lower + upper) / 2;

            if (f(mid) > n) {
                upper = mid - 1;
            } else {
                lower = mid + 1;
            }
        }
        // lower pyramids can be made with f(lower) candles
        if (f(lower) > n) {
            lower --;
        }

        total += lower;
        n -= f(lower);
    }

    cout << total << ' ' << n << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ull n;

    cin >> n;

    solve(n);

    return 0;
}
