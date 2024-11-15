#include "cave.h"
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int down[5000];
int door[5000];
int tries = 0;
int exitcode = 1;
const int maxTries = 70000;

int tryCombination(int _, int S[]) {
	if (_ != N) {
		cout << "WA - Size of array does not match N" << endl;
		exit(0);
	}
	if (tries++ == maxTries) {
		cout << "WA - Max tries exceeded" << endl;
		exit(0);
	}

	for (int i = 0; i < N; i++) {
		if (down[door[i]] != S[door[i]]) {
			return i;
		}
	}

	return -1;
}

void answer(int _, int S[], int D[]) {
	if (_ != N) {
		cout << "WA - Size of array does not match N" << endl;
		exit(0);
	}
	for (int i = 0; i < N; i++) {
		if (S[i] != down[i]) {
			cout << "WA - Wrong switch configuration. Switch " << (i + 1) << " was " << S[i] << " expecting " << down[i] << endl;
			exit(0);
		}
	}
	for (int i = 0; i < N; i++) {
		if (door[D[i]] != i) {
			cout << "WA - Wrong door configuration, Door " << (i + 1) << " was " << D[i] << " expecting " << door[i] << endl;
			exit(0);
		}
	}

	cout << "AC" << endl;

	exit(0);
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> down[i];
	}
	for (int i = 0; i < N; i++) {
		int idx;
		cin >> idx;
		door[idx] = i;
	}

	exploreCave(N);

	cout << "WA - Did not call answer()" << endl;
	return 0;
}
