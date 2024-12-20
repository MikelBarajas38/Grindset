#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string XMAS = "XMAS";

bool is_valid(int i, int j, int n, int m) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

int get_xmas_matches(vector<string> &grid, int i, int j) {
	
	int n = grid.size();
	int m = grid[0].size();

	// matches: up, down, left, right, up-left, up-right, down-left, down-right
	vector<int> matches = {0, 0, 0, 0, 0, 0, 0, 0};

	for(int k = 0; k < 4; k++) {
		
		// up
		if(is_valid(i - k, j, n, m) && grid[i - k][j] == XMAS[k]) {
			matches[0]++;
		}

		// down
		if(is_valid(i + k, j, n, m) && grid[i + k][j] == XMAS[k]) {
			matches[1]++;
		}

		// left
		if(is_valid(i, j - k, n, m) && grid[i][j - k] == XMAS[k]) {
			matches[2]++;
		}

		// right
		if(is_valid(i, j + k, n, m) && grid[i][j + k] == XMAS[k]) {
			matches[3]++;
		}

		// up-left
		if(is_valid(i - k, j - k, n, m) && grid[i - k][j - k] == XMAS[k]) {
			matches[4]++;
		}

		// up-right
		if(is_valid(i - k, j + k, n, m) && grid[i - k][j + k] == XMAS[k]) {
			matches[5]++;
		}

		// down-left
		if(is_valid(i + k, j - k, n, m) && grid[i + k][j - k] == XMAS[k]) {
			matches[6]++;
		}

		// down-right
		if(is_valid(i + k, j + k, n, m) && grid[i + k][j + k] == XMAS[k]) {
			matches[7]++;
		}

	}

	return count(matches.begin(), matches.end(), 4);

}

int part_one(vector<string> &grid) {
	
	int n = grid.size();
	int m = grid[0].size();

	int matches = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(grid[i][j] == XMAS[0]) {
				matches += get_xmas_matches(grid, i, j);
			}
		}
	}

	return matches;

}

bool is_x_mas(char top_left, char top_right, char bottom_left, char bottom_right) {
	return top_left != bottom_right && top_right != bottom_left;
}

int get_x_mas_matches(vector<string> &grid, int i, int j) {
	
	int n = grid.size();
	int m = grid[0].size();

	if(!is_valid(i - 1, j - 1, n, m) || (grid[i - 1][j - 1] != 'M' && grid[i - 1][j - 1] != 'S')) {
		return 0;
	}
	char top_left = grid[i - 1][j - 1];

	if(!is_valid(i - 1, j + 1, n, m) || (grid[i - 1][j + 1] != 'M' && grid[i - 1][j + 1] != 'S')) {
		return 0;
	}
	char top_right = grid[i - 1][j + 1];


	if(!is_valid(i + 1, j - 1, n, m) || (grid[i + 1][j - 1] != 'M' && grid[i + 1][j - 1] != 'S')) {
		return 0;
	}
	char bottom_left = grid[i + 1][j - 1];

	if(!is_valid(i + 1, j + 1, n, m) || (grid[i + 1][j + 1] != 'M' && grid[i + 1][j + 1] != 'S')) {
		return 0;
	}
	char bottom_right = grid[i + 1][j + 1];

	return is_x_mas(top_left, top_right, bottom_left, bottom_right);

}

int part_two(vector<string> &grid) {

	int n = grid.size();
	int m = grid[0].size();

	int matches = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(grid[i][j] == 'A') {
				matches += get_x_mas_matches(grid, i, j);
			}
		}
	}

	return matches;
	
}

int main(int argc, const char *argv[]) {

	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " <input_file>\n";
		return 1;
	}

	ifstream input(argv[1]);

	vector<string> grid;

	while(!input.eof()) {
		string line;
		input >> line;
		grid.push_back(line);
	}

	cout << "Part one: " << part_one(grid) << '\n';
	cout << "Part two: " << part_two(grid) << '\n';

    return 0;
}