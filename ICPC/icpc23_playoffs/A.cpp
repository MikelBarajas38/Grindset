#include<iostream>

using namespace std;

int main() {
    int n, h, c = 0, x;

    cin >> n >> h;

    while (n--) {
        cin >> x;

        if (x <= h) c++;
    }

    cout << c << '\n';

    return 0;
}