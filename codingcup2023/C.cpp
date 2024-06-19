#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool found = false;


struct miner {
    int state; // 0 piso 1 cayendo
    int uptime;
    int downtime;
    bool jumping;
    bool pickaxe;
    bool trampoline;
};

void handle_state(miner &m, int i, int j, vector<string> &cave){
    if(cave[i+1][j] == '#' or cave[i+1][j] == '@'){
        m.state = 0;
        return;
    }

    m.state = 1;
}

void dfs(miner m, int i, int j, string past, vector<string> &cave, vector<string> map) {
    handle_state(m, i, j, cave);

    if(!found && cave[i][j] == 'S') {
        cout << past;
        found = true;
        return;
    }

    if(map[i][j] == '*') {
        return;
        //exit
    }

    if(found) {
        return;
    }

    map[i][j] = '*';

    if(m.state == 0 && m.jumping == false) {

        if(m.downtime >= 4) {
            return;
        }

        m.downtime = 0;
        m.jumping = false;

        //left
        if(cave[i][j-1] == '@' && m.pickaxe){
            past += 'L';
            m.pickaxe = false;
            dfs(m, i, j-1, past + "l", cave, map);
        } else if (cave[i][j-1] == ' ' || cave[i][j-1] == 'S'){
            dfs(m, i, j-1, past + "l", cave, map);
        }

        if(found) {
            return;
        }

        //right
        if(cave[i][j+1] == '@' && m.pickaxe){
            past += 'R';
            m.pickaxe = false;
            dfs(m, i, j+1, past + "r", cave, map);
        } else  if (cave[i][j+1] == ' ' || cave[i][j+1] == 'S'){
            dfs(m, i, j+1, past + "r", cave, map);
        }

        if(found) {
            return;
        }

        //up
        if(m.trampoline && cave[i-1][j] == '@' && m.pickaxe){
            past += 'U';
            m.pickaxe = false;
            m.jumping = true;
            m.uptime = 1;
            dfs(m, i-1, j, past + "T", cave, map);
        } else if(m.trampoline) {
            m.jumping = true;
            m.uptime = 1;
            dfs(m, i-1, j, past + "T", cave, map);
        }

        if(found) {
            return;
        }

        //down
        if(cave[i+1][j] == '@' && m.pickaxe){
            past += 'D';
            m.pickaxe = false;
            dfs(m, i, j, past, cave, map);
        } else {
            dfs(m, i, j, past, cave, map);
        }

        if(found) {
            return;
        }

    } else {
        if(m.jumping) {
            if(m.uptime >= 4 || cave[i-1][j] != ' ') {
                m.jumping = false;
                m.downtime = 0;
            } else {
                m.uptime ++;
                dfs(m, i-1, j, past, cave, map);
            }

        } 

        if(!m.jumping){

            if(m.downtime >= 4) {
                return;
            }
            
            m.downtime++;

            if(cave[i+1][j] == ' ' || cave[i+1][j] == 'S')  {
                dfs(m, i+1, j, past + "d", cave, map);
            }

            if(found) {
                return;
            }
            
            if(cave[i+1][j-1] == ' ' || cave[i+1][j-1] == 'S')  {
                dfs(m, i+1, j-1, past + "l", cave, map);
            }

            if(found) {
                return;
            }

            if(cave[i+1][j+1] == ' ' || cave[i+1][j+1] == 'S')  {
                dfs(m, i+1, j+1, past + "r", cave, map);
            }  

            if(found) {
                return;
            }           

        }
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

    vector<string> cave;
    vector<string> map;

    string line;
    while(getline(cin, line)){
        cave.push_back(line);
        map.push_back(line);
    }

    int x0, y0;
    for(int i = 0; i < cave.size(); i++){
        for(int j = 0; j < cave[i].length(); j++){
            if(cave[i][j] == 'E'){
                y0 = i;
                x0 = j;
                break;
            }
        }
    }

    miner m;
    m.downtime = 0;
    m.pickaxe = true;
    m.jumping = false;
    m.trampoline = true;
    m.uptime = 0;

    dfs(m, y0, x0, "", cave, map);

    return 0;
}