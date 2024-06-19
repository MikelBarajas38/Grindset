// AC

#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(0);

    string rivers;

    cin >> rivers;

    int distance = 0, max_distance = -1;
    for (char c : rivers) {
        if (c == '1') {
            max_distance = max(distance, max_distance);
            distance = 0;
        } else {
            distance ++;
        }
    }

    cout << max_distance/2 + max_distance%2 << '\n';

    return 0;
}
