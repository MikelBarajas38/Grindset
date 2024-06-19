// https://codeforces.com/contest/1869/problem/B
// 2d traveling

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct point {
    ll x;
    ll y;
};

ll manhattan(point a, point b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t;
    cin >> t;

    while(t--){
        ll n, k, a, b;
        cin >> n >> k >> a >> b;

        vector<point> cities(n);
        for(point &p : cities){
            cin >> p.x >> p.y;
        }      

        point start = cities[a-1];
        point end = cities[b-1];

        point closest_start = end;
        point closest_end = start;

        bool major_city_exists = false;

        for(int i = 0; i < k; ++i){
            if(manhattan(start, cities[i]) < manhattan(start, closest_start)){
                closest_start = cities[i];
                major_city_exists = true;
            }
            if(manhattan(end, cities[i]) < manhattan(end, closest_end)){
                closest_end = cities[i];
                major_city_exists = true;
            }
        }

        ll ans;
        
        if(a-1 < k && b-1 < k) {
            ans = 0;
        } else if (a-1 < k){
            ans = manhattan(end, closest_end);
        } else if ( b-1 < k) {
            ans = manhattan(start, closest_start);
        } else {
            ans = min(manhattan(start, end), manhattan(start, closest_start) + manhattan(end, closest_end));
        }

        cout << ans << '\n';
    }

    return 0;
}