#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    ll weapon_classes, metal_classes;
    cin >> weapon_classes >> metal_classes;

    vector<ll> required_ingots(weapon_classes);
    for(ll &ingots: required_ingots) {
        cin >> ingots;
    }

    vector<ll> returned_ingots(weapon_classes);
    for(ll &ingots: returned_ingots) {
        cin >> ingots;
    }

    priority_queue<ll> metal_ingots;
    map<int,int> repeated_ingots_map;
    for(int i = 0; i < metal_classes; i++) {
        ll ingots;
        cin >> ingots;
        if(repeated_ingots_map[ingots] == 0) {
            metal_ingots.push(ingots);
            repeated_ingots_map[ingots] = 1;
        } else {
            repeated_ingots_map[ingots]++;
        }
    }

    vector<pair<ll, ll>> weapon_cost(weapon_classes);
    for(int i = 0; i < weapon_classes; i++) {
        weapon_cost[i] = {required_ingots[i] - returned_ingots[i], i};
    }

    sort(all(weapon_cost));

    ll experience_points = 0;
    for(int i = 0; i < weapon_classes; i++) {
        while(!metal_ingots.empty()) {
            ll ingots = metal_ingots.top();
            if(required_ingots[weapon_cost[i].second] <= ingots) {
                ll craftable_weapons = ingots / required_ingots[weapon_cost[i].second];
                experience_points += craftable_weapons * 2 * repeated_ingots_map[ingots];
                ll recycled_ingots = ingots - (weapon_cost[i].first * craftable_weapons);
                if(recycled_ingots > 0) {
                    metal_ingots.push(recycled_ingots);
                    repeated_ingots_map[recycled_ingots] = repeated_ingots_map[ingots];
                } 
                repeated_ingots_map[ingots] = 0;
                metal_ingots.pop();
            } else {
                break;
            }
        }

    }

    cout << experience_points << "\n";
    
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T = 1;
    // cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}