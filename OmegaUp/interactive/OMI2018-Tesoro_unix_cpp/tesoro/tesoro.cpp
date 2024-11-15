#include <bits/stdc++.h>
#include "tesoro.h"

using namespace std;

// Main
//	int Preguntar(int i, int j)
//	bool Cavar(int i, int j)

int get(int n, int m, vector<vector<int>> &preguntar_cache) {
	int area;
	if(preguntar_cache[n + 1][m + 1] != -1) {
		area = preguntar_cache[n + 1][m + 1];
	} else {
		area = Preguntar(n + 1, m + 1);
		preguntar_cache[n + 1][m + 1] = area;
	}
	return area;
}

int get_region(int n0, int m0, int n1, int m1, vector<vector<int>> &preguntar_cache, set<pair<int, int>> &treasure_coords) {

	int full = get(n1, m1, preguntar_cache);
	int A = get(n0 - 1, m1, preguntar_cache);
	int B = get(n1, m0 - 1, preguntar_cache);
	int AnB = get(n0 - 1, m0 - 1, preguntar_cache);

	int region = full - A - B + AnB;

	for(auto &coord: treasure_coords) {
		if(coord.first >= n0 && coord.first <= n1 && coord.second >= m0 && coord.second <= m1) {
			region--;
		}
	}

	return region;

}

void BuscaTesoros(int n, int m, int k) {

	vector<vector<int>> map(n, vector<int>(m, 0));
	vector<vector<int>> preguntar_cache(n + 1, vector<int>(m + 1, -1));
	set<pair<int, int>> treasure_coords;

	for(int i = 0; i <= n; i++) {
		preguntar_cache[i][0] = 0;
	}

	for(int i = 0; i <= m; i++) {
		preguntar_cache[0][i] = 0;
	}

	int first_half, second_half, start;
	int nl = 0, nr = n - 1, ml = 0, mr = m - 1;
	int half;

	while(k) {

		int ni = nr - nl + 1;
		int mi = mr - ml + 1;

		if(ni == 1 && mi == 1) {
			treasure_coords.insert({nl, ml});
			nl = 0; nr = n - 1; ml = 0; mr = m - 1;
			k--;
			continue;
		}

		if(ni >= mi) {
						
			half = (nl + nr) / 2;
			first_half = get_region(nl, ml, half, mr, preguntar_cache, treasure_coords);
			second_half = get_region(half + 1, ml, nr, mr, preguntar_cache, treasure_coords);

			/*
			cout << "n case\n";

			cout << "first_half " << first_half << '\n';
			cout << "coords: (" << nl << ", " << ml << ") (" << half << ", " << mr << ")\n";

			cout << "second_half " << second_half << '\n';
			cout << "coords: (" << half + 1 << ", " << ml << ") (" << nr << ", " << mr << ")\n";
			*/

			if(first_half >= second_half) {
				nr = half;
			} else {
				nl = half + 1;
			}

		} else {

			half = (ml + mr) / 2;
			first_half = get_region(nl, ml, nr, half, preguntar_cache, treasure_coords);
			second_half = get_region(nl, half + 1, nr, mr, preguntar_cache, treasure_coords);

			/*
			cout << "m case\n";

			cout << "first_half " << first_half << '\n';
			cout << "coords: (" << nl << ", " << ml << ") (" << nr << ", " << half << ")\n";

			cout << "second_half " << second_half << '\n';
			cout << "coords: (" << nl << ", " << half + 1 << ") (" << nr << ", " << mr << ")\n";
			*/

			if(first_half >= second_half) {
				mr = half;
			} else {
				ml = half + 1;
			}

		}
	}

	for(auto coord : treasure_coords) {
		Cavar(coord.first + 1, coord.second + 1);
	}

}