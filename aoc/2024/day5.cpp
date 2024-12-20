#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int get_intersection_size(set<int> &a, set<int> &b) {
	set<int> c;
	set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
	return c.size();
}

int part_one(auto &prev, auto &updates) {

	int ans = 0;

	for(auto &update : updates) {

		set<int> l;
		set<int> r(update.begin(), update.end());
		bool valid = true;

		for(auto &x : update) {
			r.erase(x);
			if(get_intersection_size(r, prev[x])) {
				valid = false;
				break;
			}
			l.insert(x);
		}

		if(valid) {
			ans += update[update.size()/2];
		}

	}

	return ans;

}

int part_two(auto &prev, auto &updates) {

	//todo
}

int main(int argc, const char *argv[]) {

	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " <input_file>\n";
		return 1;
	}

	ifstream input(argv[1]);

	map<int, set<int>> prev;

	while(!input.eof()) {

		string line;
		getline(input, line);

		if(line == "") {
			break;
		}

		int a = stoi(line.substr(0, 2));
		int b = stoi(line.substr(3, 2));

		prev[a].insert(b);

	}

	vector<vector<int>> updates;

	while(!input.eof()) {

		string line;
		getline(input, line);

		stringstream ss(line);
		vector<int> update;

		while(getline(ss, line, ',')) {
			update.push_back(stoi(line));
		}

		updates.push_back(update);
		
	}

	cout << "Part one: " << part_one(prev, updates) << '\n';
	cout << "Part two: " << part_two(prev, updates) << '\n';

    return 0;
}