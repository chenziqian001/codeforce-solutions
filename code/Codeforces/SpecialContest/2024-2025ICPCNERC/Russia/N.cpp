#include<bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int x=s[0]-'0';
        int y=s[2]-'0';
        if(s[1]=='<'){
            if(x<y){
                cout<<s<<'\n';
            }
            else if(x==y){
                cout<<s[0]<<'='<<s[2]<<'\n';
            }
            else{
                cout<<s[0]<<'>'<<s[2]<<'\n';
            }
        }
        else if(s[1]=='>'){
            if(x>y){
                cout<<s<<'\n';
            }
            else if(x==y){
                cout<<s[0]<<'='<<s[2]<<'\n';
            }
            else{
                cout<<s[0]<<'<'<<s[2]<<'\n';
            }
        }
        else{
            if(s[0]==s[2]){
                cout<<s<<'\n';
            }
            else{
                cout<<s[0]<<'='<<s[0]<<'\n';
            }
        }
    }

    
   

}
