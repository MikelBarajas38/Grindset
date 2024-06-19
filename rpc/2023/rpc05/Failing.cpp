#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<string,double> known = {{"N", 0}, {"E", 90}, {"S", 180}, {"W", 270},
                         {"NE", 45}, {"SE", 135}, {"SW", 225}, {"NW", 315}};

void get_starting_values(string base, double &dir, char &high, char &low) {
    dir = known[base];
    if(base == "NE") {
        low = 'N';
        high = 'E';
    } else if (base == "SE") {
        low = 'E';
        high = 'S';
    } else if (base == "SW") {
        low = 'S';
        high = 'W';
    } else if (base == "NW") {
        low = 'S';
        high = 'N';
    }
}

double convert(string dir) {

    if(dir.size() < 3) {
        return known[dir];
    }

    int starting_index = dir.size() - 2;
    string base = dir.substr(starting_index);
    
    double angle;
    char high, low;

    get_starting_values(base, angle, high, low);

    double mid = 22.5;
    starting_index--;
    while(starting_index >= 0) {
        char next = dir[starting_index];

        if(next == high) {
            angle += mid;
        } else if (next == low) {
            angle -= mid;
        }
        
        starting_index--;
        mid /= 2;
    }

    return angle;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    string X, Y ;
    cin >> X >> Y;

    double xang = convert(X);
    double yang = convert(Y);

    cout << fixed << setprecision(7) << min(abs(xang - yang), 360 - abs(xang - yang));

    return 0;
}