#include<bits/stdc++.h>
using namespace std;

bool isOther(char str[]){
    for(int i=0;str[i];i++){
        //cout<<str[i]<<endl;
        if(str[i]=='_'&&i==2) continue;
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')||(str[i]>='0'&&str[i]<='9')){
            continue;
        }
        else return 1;
    }
    return 0;
}

int main(){
    char str[1000];
    cin>>str;

     if(str[0]=='c'&&str[1]=='h'&&str[2]=='_'&&isValid(str)){
        puts("Character Variable");
    }

       else puts("Undefined");

    return 0;
}
