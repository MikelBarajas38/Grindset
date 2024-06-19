#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi cities;
vi towers;

int get_distance(int a, int b) {
    return abs(a - b);
}


bool illuminates_all(int r) {
    
    for(int &c : cities) {

        bool is_illuminated = false;

        auto right_tower = upper_bound(all(towers), c);
        auto left_tower = right_tower - 1;
        
        if(left_tower >= begin(towers) && get_distance(c, *(left_tower)) <= r) {
            is_illuminated = true;
        } 

        if(right_tower != end(towers) && get_distance(c, *right_tower) <= r) {
            is_illuminated = true;
        }

        if(!is_illuminated) return false;
        
    }

    return true;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;

    cities.resize(n);
    for(int &c : cities) {
        cin >> c;
    }

    towers.resize(m);
    for(int &t : towers) {
        cin >> t;
    }

    int l = 0;
    int r = max(get_distance(cities[0], towers[m-1]), 
                get_distance(cities[n-1], towers[0]));

    while(l < r) {

        int mid = l + (r-l)/2;

        if(illuminates_all(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }

    }

    cout << r << "\n";

    return 0;
}