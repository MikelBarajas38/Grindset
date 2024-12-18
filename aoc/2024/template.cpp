#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char *argv[]) {

	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " <input_file>\n";
		return 1;
	}

	ifstream input(argv[1]);

    return 0;
}