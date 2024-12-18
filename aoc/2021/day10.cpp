#include <bits/stdc++.h>
using namespace std;

int partOne(string &line){
    vector<char> openingChars; //stack of opening characters
    unordered_map<char,char> matchingChars = {{'}', '{'}, {']', '['}, {')', '('}, {'>', '<'}};
    unordered_map<char,int> errorVals = {{'}', 1197}, {']', 57}, {')', 3}, {'>', 25137}};

    for(char c : line){
        if(matchingChars.find(c) == end(matchingChars)){
            openingChars.push_back(c); 
        }
        else{
            if(openingChars.back() != matchingChars[c]) //find first error
                return errorVals[c];
            else
                openingChars.pop_back(); //discard complete chunks
        }
    }

    return 0; //if line isnt corrupted, it means it is incomplete
}

long long partTwo(string &line){
    long long completionScore = 0;
    vector<char> openingChars;
    unordered_map<char,char> matchingChars = {{'}', '{'}, {']', '['}, {')', '('}, {'>', '<'}};
    unordered_map<char,int> closingVals = {{'{', 3}, {'[', 2}, {'(', 1}, {'<', 4}};

    for(char c : line){ //discard complete chunks
        if(matchingChars.find(c) == end(matchingChars)){
            openingChars.push_back(c);
        }
        else{
            if(openingChars.back() == matchingChars[c])
                openingChars.pop_back();
        }
    }

    int n=openingChars.size();
    for(int i=n-1;i>=0;--i){
        completionScore *= 5;
        completionScore += closingVals[openingChars[i]];
    }

    return completionScore;
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);

    freopen("data.in","r",stdin);

    string line;
    int firstVal = 0, temp;
    vector<long long> completionVals;
    while(getline(cin,line)){
        temp = partOne(line);
        firstVal += temp;
        if(!temp) completionVals.push_back(partTwo(line));
    }

    sort(begin(completionVals),end(completionVals));
    cout << firstVal << "\n" << completionVals[completionVals.size()/2];
    return 0;
}