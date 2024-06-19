// AC

#include<bits/stdc++.h>

using namespace std;

struct Sock
{
    int any;
    int left;
    int right;
};

bool is_possible(Sock sock) {
    if (sock.any >= 2)
        return true;

    if (sock.any >= 1 && min(sock.left, sock.right) >= 1)
        return true;

    if (sock.any == 0 && (sock.left >= 1 && sock.right >= 1))
        return true;

    return false;
}

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(0);

    map<string, Sock> socks;

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string name, type;
        int total;

        cin >> name >> type >> total;

        if (type == "any") {
            socks[name].any = total;
        } else if (type == "left") {
            socks[name].left = total;
        } else {
            socks[name].right = total;
        }
    }
    
    bool possible = false;
    int total = 1;
    for (pair<string, Sock> p : socks) {
        Sock sock = p.second;

        int ct = max(sock.left, sock.right);

        if (ct == 0 && sock.any > 0) {
            ct = 1;
        } 

        if (is_possible(sock))
            possible = true;

        total += ct;
    }

    if (possible) {
        cout << total << '\n';
    } else {
        cout << "impossible\n";
    }

    return 0;
}
