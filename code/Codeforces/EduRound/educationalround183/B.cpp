#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    int a=0,b=0,c=0;
    for(char ca:s){
        if(ca=='0') a++;
        else if(ca=='1') b++;
        else c++;
    }

    for(int i=1;i<=n;i++){
        if(i<=a || i>=n-b+1){
            cout<<'-';
            continue;
        }
        int l=a+c;
        int r=n-b-c+1;
        if(i>l && i<r){
            cout<<'+';
            continue;
        }
        if(c<n-a-b) cout<<'?';
        else{
            cout<<'-';
        }
    }
    cout<<'\n';    




    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}

/*
1 2 3 4 5 6 7
- -       - -
*/