#include <bits/stdc++.h>
using namespace std;

bool hasWon(vector<vector<bool>> &boardCheck){
    bool winner = true;

    //check rows
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j)
            winner = winner && boardCheck[i][j];

        if(winner) return true;
        winner = true;
    }

    //check columns
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j)
            winner = winner && boardCheck[j][i];

        if(winner) return true;
        winner = true;
    }

    return false;
}

int validateBoard(vector<vector<int>> &board, vector<vector<bool>> &boardCheck, vector<int> &nums){
    int turns=1;

    for(int &n: nums){

        for(int i=0;i<5;++i)
            for(int j=0;j<5;++j)
                if(board[i][j]==n)
                    boardCheck[i][j]=1;

        if(hasWon(boardCheck)) return turns;
        else ++turns;
    }

    return -1;
}

int sumUnmarked(vector<vector<int>> &board, vector<vector<bool>> &boardCheck){
    int unmarkedSum = 0;

    for(int i=0;i<5;++i)
        for(int j=0;j<5;++j)
            if(!boardCheck[i][j])
                unmarkedSum += board[i][j];
    
    return unmarkedSum;
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    vector<vector<int>> board (5,vector<int>(5));
    vector<vector<bool>> boardChecked (5,vector<bool>(5));
    vector<int> numSubSys;
    string empty;

    freopen("data.in","r",stdin);

    string num;
    while(getline(cin,num,',')){
        numSubSys.push_back(stoi(num));
    }

    getline(cin,empty);
    
    //compare boards
    string line;
    int i=0, min=INT32_MAX, max=0, boardTurns, lastScore, firstScore;

    while(getline(cin,line)){
        if(line==""){
            
            boardTurns = validateBoard(board,boardChecked,numSubSys);

            //get the best board score
            if(boardTurns<min){
                firstScore = sumUnmarked(board,boardChecked) * numSubSys[boardTurns-1];
                min = boardTurns;
            }

            //get the worst board score
            if(boardTurns>max){
                lastScore = sumUnmarked(board,boardChecked) * numSubSys[boardTurns-1];
                max = boardTurns;
            }

            i = 0; //restart board
        }
        else{
            //Store board values
            stringstream ss(line);
            string data;

            for(int j=0; j<5; ++j){
                ss>>data;
                board[i][j] = stoi(data);
                boardChecked[i][j] = 0;
            }

            ++i;
        }
    }

    cout << firstScore << "\n" << lastScore;
    
    return 0;
}