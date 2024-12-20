#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int part_one(string memory) {

	regex re(R"(mul\((\d+),(\d+)\))");
	smatch match;

	int ans = 0;
	while(regex_search(memory, match, re)) {
		ans += stoi(match[1]) * stoi(match[2]);
		memory = match.suffix().str();
	}

	return ans;

}

int part_two(string memory) {

	regex re(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))");
	smatch match;

	int ans = 0;
	bool enabled = true;
	while(regex_search(memory, match, re)) {
		if(match.str() == "do()") {
			enabled = true;
		} else if(match[0] == "don't()") {
			enabled = false;
		} else if(enabled) {
			ans += stoi(match[1]) * stoi(match[2]);
		}
		memory = match.suffix().str();
	}

	return ans;
	
}

int main(int argc, const char *argv[]) {

	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " <input_file>\n";
		return 1;
	}

	ifstream input(argv[1]);

	string memory;

	while(!input.eof()) {
		string line;
		getline(input, line);
		memory += line;
	}

	cout << "Part one: " << part_one(memory) << '\n';
	cout << "Part two: " << part_two(memory) << '\n';

    return 0;
}