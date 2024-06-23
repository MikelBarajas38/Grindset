#include <bits/stdc++.h>
using namespace std;

int linear_search(vector<int> &vec, int x) {
    int n = vec.size();
    for(int i = 0; i < n; i++) {
        if(vec[i] == x) {
            return i;
        }
    }
    return -1;
}

int binary_search(vector<int> &vec, int x) {
    int n = vec.size();
    int l = 0, r = n - 1;
    while(l <= r) {
        int m = (l + r) / 2;
        if(vec[m] == x) {
            return m;
        } else if(vec[m] > x) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    } 
    return -1;
}

int main() {
	//cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    vector<int> vec(n);
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    cout << "Vector original: ";
    for(int i = 0; i < n; i++) {
        cout << vec[i] << ' ';
    }
    cout << '\n';

    // ordenar
    sort(vec.begin(), vec.end());

    cout << "Vector ordenado: ";
    for(int i = 0; i < n; i++) {
        cout << vec[i] << ' ';
    }
    cout << '\n';

    int x;
    cin >> x;

    cout << "índice de " << x << ": " << binary_search(vec, x) << "\n";

    auto it = lower_bound(vec.begin(), vec.end(), x);
    cout << "índice de " << x << ": " << it - vec.begin() << "\n";

    return 0;
}