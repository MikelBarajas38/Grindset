#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    string command;
    int mov, hor=0, depth=0, aim=0;

    freopen("data.in","r",stdin);
    while(cin>>command){
        cin>>mov;

        if(command=="forward"){
            hor+=mov;
            depth+=aim*mov; //part 2
        }
        else if (command=="down")
            aim+=mov;
            //depth+=mov //part 1
        else if(command=="up")
            aim-=mov;
            //depth-=mov //part 1
    }

    cout<<depth*hor;
    return 0;
}