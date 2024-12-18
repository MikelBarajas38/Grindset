#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int part_one(vector<int> left_list, vector<int> right_list) {

	sort(left_list.begin(), left_list.end());
	sort(right_list.begin(), right_list.end());	

	int diff = 0;
	for(int i = 0; i < left_list.size(); i++) {
		diff += abs(left_list[i] - right_list[i]);
	}
	
	return diff;

}

int part_two(vector<int> left_list, vector<int> right_list) {

	unordered_map<int, int> left_frequency;

	for(int &x : left_list) {
		left_frequency[x] = 0;
	}

	for(int &x : right_list) {
		if(left_frequency.count(x)) {
			left_frequency[x]++;
		}
	}

	int score = 0;
	for(auto &[x, freq] : left_frequency) {
		score += x * freq;
	} 

	return score;

}

int main(int argc, const char *argv[]) {

	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " <input_file>\n";
		return 1;
	}

	ifstream input(argv[1]);

	vector<int> left_list;
	vector<int> right_list;

	while(!input.eof()) {
		int l, r;
		input >> l >> r;
		left_list.push_back(l);
		right_list.push_back(r);
	}

	cout << "Part one: " << part_one(left_list, right_list) << '\n';
	cout << "Part two: " << part_two(left_list, right_list) << '\n';

    return 0;
}