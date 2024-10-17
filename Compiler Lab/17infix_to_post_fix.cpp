#include<bits/stdc++.h>
#define P(X) cout<<X<<endl;
#define P2(X,Y) cout<<X<<" "<<Y<<endl;
using namespace std;

stack<char>st;
string str,ans;

int main(){
    int i,j,k,l,m,n;
    char ch;
    //cin>>str;
    str = //"A+(B*C-(D/E^F)*G)*H";
    "(A-B)*(D/E)";//"A*(B+C*D)+E";
    str = "(" + str + ")";
    ans = "";
    for(i=0;i<str.size();i++){
        if(isalpha(str[i])) ans += str[i];
        else if(str[i]=='+'||str[i]=='-'){
            while(st.top()!='('){
                ans += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
        else if(str[i]=='*'||str[i]=='/'){
                //P("sssss")
            while(st.top()!='('&&st.top()!='+'&&st.top()!='-'){
                ans += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
        else if(str[i]==')'){
            while(st.top()!='('){
                //P(st.top())
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else st.push(str[i]);
        //P(str[i]);
    }
    cout<<ans<<endl;

    return 0;
}
