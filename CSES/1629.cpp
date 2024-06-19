#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
 
  int n;
  cin >> n;
 
  vector<pair<int, int>> movies(n);
 
  for (int i = 0; i < n; i++) {
    cin >> movies[i].second >> movies[i].first;
  }
 
  sort(all(movies));
 
  int max_movies = 0;
  int current_end = 0;

  for (int i = 0; i < n; i++) {
    if (movies[i].second >= current_end) {
      max_movies++;
      current_end = movies[i].first;
    }
  }
 
  cout << max_movies << endl;
 
  return 0;
}