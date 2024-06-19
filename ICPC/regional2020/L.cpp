#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int N, X;
	cin >> N >> X;

	vector<pair<ll,ll>> events;
	for(int i = 0; i < N; ++i) {
		ll start, duration;
		cin >> start >> duration;
		events.push_back({start, start+duration});
	}

	sort(all(events));

	int lim = events[N-1].second;
	int min_conflicts = INT_MAX;
	int time = -1;

	for(int i = 0; i <= 480; ++i) {
		
		int conflicts = 0;
		int eventcounter = 0;

		for(int j = i; j <= lim; j += X) {

			if(j < events[eventcounter].first) {
				continue;
			}

			if(j > events[eventcounter].second) {
				eventcounter++;
				j -= X;
				continue;
			}

			conflicts++;
		}

		if(conflicts < min_conflicts) {
			min_conflicts = conflicts;
			time = i;
		}
	}

	cout << time << " " << min_conflicts << "\n";

    return 0;
}