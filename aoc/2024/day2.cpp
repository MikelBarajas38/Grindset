#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#define IGNORE -1

bool is_safe_transition(int level_a, int level_b, bool increasing) {
	int diff = abs(level_a - level_b);
	return diff >= 1 && diff <= 3 && (increasing == (level_a < level_b)) && level_a != level_b;
}

bool is_safe_report(vector<int> &report, bool try_again) {

	int n = report.size();

	int first = report[0], second = report[1];

	if(report[0] == IGNORE) {
		first = report[1];
		second = report[2];
	} else if(report[1] == IGNORE) {
		second = report[2];
	}

	bool increasing = first < second;

	for(int i = 0; i < n - 1; i++) {

		int current = report[i], next = report[i + 1];

		if(current == IGNORE) {
			continue;
		}

		if(next == IGNORE) {
			if(i + 2 < n) {
				next = report[i + 2];
			} else {
				continue;
			}
		}

		if(!is_safe_transition(current, next, increasing)) {

			if(try_again) {

				report[i] = IGNORE;
				bool try_one = is_safe_report(report, false);
				report[i] = current;

				report[i + 1] = IGNORE;
				bool try_two = is_safe_report(report, false);
				report[i + 1] = next;

				if(i - 1 >= 0) {
					int prev = report[i - 1];
					report[i - 1] = IGNORE;
					try_one = try_one || is_safe_report(report, false);
					report[i - 1] = prev;
				}

				return try_one || try_two;

			}

			return false;
			
		}
	}

	return true;

}

int part_one(vector<vector<int>> &reports) {

	int safe_reports = 0;

	for(auto &report : reports) {
		if(is_safe_report(report, false)) {
			safe_reports++;
		}
	}

	return safe_reports;

}

int part_two(vector<vector<int>> &reports) {

	int safe_reports = 0;

	for(auto &report : reports) {
		if(is_safe_report(report, true)) {
			safe_reports++;
			continue;
		}
	}
	
	return safe_reports;
}

int main(int argc, const char *argv[]) {

	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " <input_file>\n";
		return 1;
	}

	ifstream input(argv[1]);

	vector<vector<int>> reports;

	while(!input.eof()) {

		string line;
		getline(input, line);
		stringstream ss(line);

		vector<int> report;
		while(!ss.eof()) {
			int x;
			ss >> x;
			report.push_back(x);
		}
		reports.push_back(report);

	}

	cout << "Part one: " << part_one(reports) << '\n';
	cout << "Part two: " << part_two(reports) << '\n';

    return 0;
}