#include<bits/stdc++.h>
using namespace std;


bool isValid(char str[]){
    if(strlen(str)<4) return 0;
    for(int i=3;str[i];i++){
        if(str[i]=='_') return 0;
    }
    return 1;
}

int main(){
    char str[1000];
    cin>>str;

    if(str[0]=='b'&&str[1]=='n'&&str[2]=='_'&&isValid(str)){
        puts("Binary Variable");
    }

      else puts("Undefined");

    return 0;
}
