#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(n));
    int r=(n-1)/2,c=(n-1)/2,d=0,len=1,cnt=0,i=0;
    int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
    
    while(i<n*n){
        for(int k=0;k<len;k++){
            if(r>=0&&r<n&&c>=0&&c<n)a[r][c]=i++;
            r+=dx[d];c+=dy[d];
        }
        d=(d+1)%4;
        cnt++;
        if(cnt%2==0)len++;
    }
    
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            cout<<a[x][y]<<" \n"[y==n-1];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    if(cin>>t){
        while(t--)solve();
    }
    //system("pause");
    return 0;
}