#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int main() {
  double n,m;
  cin >> n >> m;
  double aT = 100-n;
  double aP = 100 - m;
  double yT = (aT * m)/aP;
  double r = n / yT;
  cout << fixed << setprecision(7) << r << endl;
}