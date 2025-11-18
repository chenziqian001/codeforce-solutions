#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;


    vector<int> diff(n+1);
    vector<int> st(n+1);
    vector<int> ed(n+1);
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        l--,r--;
        diff[l]++;
        st[l]++;
        ed[r]++;
        if(r+1<n) diff[r+1]--;
    }

    int sum=0;
    int pos0=-1,pos1=-1,pos2=-1;
    for(int i=0;i<n;i++){
        sum+=diff[i];
        if(sum==m){
            pos0=i;
        }
        if(i<n-1 && ed[i]==0){
            pos1=i,pos2=i+1;
        }
        if(i<n-1 && st[i+1]==0){
            pos1=i+1,pos2=i;
        }
    }
    if(pos0!=-1){
        int pin=1;
        for(int i=0;i<n;i++){
            if(i==pos0){
                cout<<0<<" ";
            }
            else cout<<pin++<<" ";
        }
        cout<<'\n';
        return;
    }

    if(pos1!=-1){
        int pin=2;
        for(int i=0;i<n;i++){
            if(i==pos1){
                cout<<0<<" ";
            }
            else if(i==pos2){
                cout<<1<<" ";
            }
            else{
                cout<<pin++<<" ";
            }
        }
        cout<<'\n';
        return;
    }

    
    cout<<0<<" "<<2<<" "<<1<<" ";
    for(int i=3;i<n;i++){
        cout<<i<<" ";
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


