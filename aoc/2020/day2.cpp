#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    char hyphen,colon;
    int low,high,cont,validPasswords=0;
    char letter;
    string password;

    freopen("data.in","r",stdin);
    
    /*part 1
    while(cin>>low>>hyphen>>high>>letter>>colon>>password){
        //cout<<low<<" "<<hyphen<<" "<<high<<" "<<c<<" "<<colon<<" "<<password<<"\n";
        cont=0;
        for(char c: password)
            if(c==letter)
                ++cont;
        
        if(low<=cont && cont<=high)
            ++validPasswords;
    }
    */
 
    //part 2
    while(cin>>low>>hyphen>>high>>letter>>colon>>password){
        cont=0;
        
        if(password[low-1]==letter)
            ++cont;
        
        if(password[high-1]==letter)
            ++cont;
        
        if(cont==1)
            ++validPasswords;
    }


    cout<<validPasswords;
    return 0;
}