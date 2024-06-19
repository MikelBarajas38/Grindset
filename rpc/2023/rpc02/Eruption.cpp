#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(0);

    double area;

    cin >> area;

    double perimeter = 2 * M_PI * sqrt(area/M_PI);

    cout << fixed << setprecision(9) << perimeter << '\n';

    return 0;
}