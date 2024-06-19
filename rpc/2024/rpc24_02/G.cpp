#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pair<int, int>>;

typedef struct {
    long long x, y;
} point;

long long get_len(point &a, point &b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool are_perpendicular(point &a, point &b) {
    long long dot = a.x * b.x + a.y * b.y;
    return abs(dot) == 0;
}

bool are_parallel(point &a, point &b) {
    long long cross = a.x * b.y - b.x * a.y;
    return cross == 0;
}

point res(point &a, point &b) {
    point r = point({a.x - b.x, a.y - b.y});
    return r;
}

int main() {
    
    vector<point> p(4);
    for(point &pi : p) {
        cin >> pi.x >> pi.y;
    }

    vector<long long> len(4);
    len[0] = get_len(p[0], p[1]);
    len[1] = get_len(p[1], p[2]);
    len[2] = get_len(p[2], p[3]);
    len[3] = get_len(p[3], p[0]);

    bool are_sides_equal = (len[0] == len[1] &&
                            len[1] == len[2] &&
                            len[2] == len[3] &&
                            len[3] == len[0]);

    vector<point> v(4);
    v[0] = res(p[0], p[1]);
    v[1] = res(p[1], p[2]);
    v[2] = res(p[2], p[3]);
    v[3] = res(p[3], p[0]);

    bool are_all_right_angles = (are_perpendicular(v[0], v[1]) &&
                                 are_perpendicular(v[1], v[2]) &&
                                 are_perpendicular(v[2], v[3]) &&
                                 are_perpendicular(v[3], v[0]));

    if(are_sides_equal && are_all_right_angles) {
        cout << "square\n";
        return 0;
    } else if(are_all_right_angles) {
        cout << "rectangle\n";
        return 0;
    } else if(are_sides_equal) {
        cout << "rhombus\n";
        return 0;
    }

    bool is_parallel_1 = are_parallel(v[0], v[2]);
    bool is_parallel_2 = are_parallel(v[1], v[3]);

    if(is_parallel_1 && is_parallel_2) {
        cout << "parallelogram\n";
        return 0;
    } else if(is_parallel_1 || is_parallel_2) {
        cout << "trapezium\n";
        return 0;
    }

    point m_diag1 = res(p[0], p[2]);
    point m_diag2 = res(p[1], p[3]);

    if(are_perpendicular(m_diag1, m_diag2)) {
        cout << "kite\n";
        return 0;
    }

    cout << "none\n";

    return 0;
}