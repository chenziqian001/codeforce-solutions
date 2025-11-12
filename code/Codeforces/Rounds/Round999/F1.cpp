#include<bits/stdc++.h>
using namespace std;



void solve(){
    string s,t;
    cin>>s>>t;
    deque<int> a,b;
    auto get=[](string a,deque<int> &A){
        int len=0;
        for(int i=1;i<a.size();i++){
            if(a[i]==a[i-1]){
                len++;
            }
            else{
                A.push_back(len+1);
                len=0;
            }
        }
        len++;
        A.push_back(len);
    };
    get(s,a);
    get(t,b);
    for(int i=0;i<10;i++) a.push_back(0);
    int res=0;
    int ok=1;
    if(s[0]!=t[0]){
        a[2]+=a[0];
        a.pop_front();
        res++;
    }

    while(!b.empty()){
        int x=a.front();a.pop_front();
        int y=b.front();b.pop_front();
        while(x<y && a.size()>=3){
            x+=a[1];
            a[2]+=a[0];
            a.pop_front();
            a.pop_front();
            res++;
        }
        if(x!=y || a.empty()){
            ok=0;
            break;
        } 
    }

    if(ok) cout<<res<<'\n';
    else cout<<-1<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
}

