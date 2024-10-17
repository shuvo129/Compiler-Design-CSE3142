#include<bits/stdc++.h>
using namespace std;

bool isBinary(char str[]){
    //if(strlen(str)<2) return 0;
    if(str[0]!='0') return 0;
    for(int i=1;str[i];i++){
        if(str[i]!='1'&&str[i]!='0') return 0;
    }
    return 1;
}

int main(){
    char str[1000];
    cin>>str;

    if(isBinary(str)){
        puts("Binary Number");
    }
    else puts("Undefined");

    return 0;
}
