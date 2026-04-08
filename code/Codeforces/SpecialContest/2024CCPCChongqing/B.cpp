#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    string emp="";
    for(int i=0;i<n;i++){
        emp+='.';
    }


    vector<string> res(7,emp);
    res[0]=a;
    res[6]=b;

    int ca=0,cb=0;
    for(char c:a){
        if(c=='#') ca++;
    }
    for(char c:b){
        if(c=='#') cb++;
    }

    if(ca==n && cb==n){
        cout<<"Yes"<<'\n';
        for(int i=0;i<7;i++){
            cout<<a<<'\n';
        }
        return;
    }
    else if(((ca==n) && (cb!=0)) || ((cb==n) && (ca!=0))){
        cout<<"No"<<'\n';
        return;
    }
    else if(ca==0 || cb==0){
        if(ca==0){
            for(int j=0;j<n;j++){
                if(res[6][j]=='.'){
                    res[5][j]='#';
                }
            }
        }
        else{
            for(int j=0;j<n;j++){
                if(res[0][j]=='.'){
                    res[1][j]='#';
                }
            }
        }
        cout<<"Yes"<<'\n';
        for(string s:res){
            cout<<s<<'\n';
        }
        return;
    }
    for(int j=0;j<n;j++){
        if(res[6][j]=='.'){
            res[5][j]='#';
        }
    }
    for(int j=0;j<n;j++){
        if(res[0][j]=='.'){
            res[1][j]='#';
        }
    }
    int pos1=-1;
    int pos2=-1;
    for(int j=0;j<n;j++){
        if(res[1][j]=='.'){
            bool ok=false;
            if(j && res[1][j-1]=='#'){
                ok=true;
            }
            if(j+1<n && res[1][j+1]=='#'){
                ok=true;
            }
            if(!ok) continue;

            res[2][j]='#';
            pos1=j;
            break;
        }
    }
    for(int j=0;j<n;j++){
        if(res[5][j]=='.'){
            bool ok=false;
            if(j && res[5][j-1]=='#'){
                ok=true;
            }
            if(j+1<n && res[5][j+1]=='#'){
                ok=true;
            }
            if(!ok) continue;
            res[4][j]='#';
            pos2=j;
            break;
        }
    }

    if(pos1==pos2){
        res[3][pos1]='#';
    }
    else if(abs(pos1-pos2)==1){
        res[3][pos1]='#';
    }
    else{
        for(int i=min(pos1,pos2)+1;i<max(pos1,pos2);i++){
            res[3][i]='#';
        }
    }
    cout<<"Yes"<<'\n';
    for(string s:res){
        cout<<s<<'\n';
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    //system("pause");
    return 0;
}