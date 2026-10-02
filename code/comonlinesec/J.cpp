#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,p;
    cin>>n>>p;
    int res=0;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int m=s.size();
        string sub=s;
        sub.pop_back();
        if(s=="UnreasonableProblemArrangement"){
            res+=10;
        }
        else if(sub=="WrongProblem" && s[m-1]<='L'){
            res+=100;
        }
        else if(sub=="SameProblem" && s[m-1]<='L'){
            res+=30;
        }
        else if(sub=="UnreasonableLimitForProblem" && s[m-1]<='L'){
            res+=5;
        }
        else if(sub=="WeakTestsForProblem" && s[m-1]<='L'){
            res+=3;
        }
        else if(sub=="BadProblem" && s[m-1]<='L'){
            res+=1;
        }
    }
    if(res>p){
        cout<<"Joker"<<'\n';
    }
    else cout<<"Judger"<<'\n';
}




signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;

}