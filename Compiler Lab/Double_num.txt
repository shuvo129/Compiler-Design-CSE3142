#include<bits/stdc++.h>
using namespace std;

char str[100];

int isFloat(){
    int cn=0,i;
    for(i=0;str[i]!='.';i++){
        if(str[i]=='.')continue;
        if(str[i]<'0'||str[i]>'9') return 0;
    }
    for(i++;str[i];i++){
        if(str[i]<'0'||str[i]>'9') return 0;
        cn++;
    }
    return cn;
}


int main(){

    cin>>str;

    int ln = strlen(str);

    if(isFloat()>2&&(str[0]>='1'&&str[0]<='9'||str[0]=='.')){
        puts("Double Number");
    }
    else{
        puts("Undefined");
    }

    return 0;
}
