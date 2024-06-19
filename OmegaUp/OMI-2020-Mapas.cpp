#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void horizontal_flip(vector<vector<char>>& A) {
    int n = A.size();
    for(int i = 0; i < n; i++) {
        reverse(all(A[i]));
    }
}

void vertical_flip(vector<vector<char>>& A) {
    int n = A.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i < j) {
                swap(A[i][j], A[j][i]);
            }
        }
    }
}

void rotate_90(vector<vector<char>>& A) {
    int n = A.size();
    vector<vector<char>> B(n, vector<char>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            B[j][n - i - 1] = A[i][j];
        }
    }
    A = B;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n; 

    vector<vector<char>> A(n, vector<char>(n));
    vector<vector<char>> B(n, vector<char>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    bool found = false;
    for(int i = 0; i < 4; i++) {
        if(A == B) {
            found = true;
            break;
        }
        rotate_90(A);
    }

    if(!found) {
        horizontal_flip(A);
        for(int i = 0; i < 4; i++) {
            if(A == B) {
                found = true;
                break;
            }
            rotate_90(A);
        }
    }

    if(!found) {
        vertical_flip(A);
        for(int i = 0; i < 4; i++) {
            if(A == B) {
                found = true;
                break;
            }
            rotate_90(A);
        }
    }

    if(found) {
        cout << "IGUALES\n";
    } else {
        cout << "DIFERENTES\n";
    }

    return 0;
}