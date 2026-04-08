#include<bits/stdc++.h>
using namespace std;
#define int long long



signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x[3],y[3],sx[3],sy[3];
    for(int i=0;i<3;i++){
        cin>>x[i]>>y[i];
        sx[i]=x[i];
        sy[i]=y[i];
    }
    sort(sx,sx+3);
    sort(sy,sy+3);
    vector<array<int,4>> ans;
    
    if(sx[0]!=sx[2]) ans.push_back({sx[0],sy[1],sx[2],sy[1]});

    for(int i=0;i<3;i++){
        if(y[i]!=sy[1]) ans.push_back({x[i],y[i],x[i],sy[1]});
    }
    cout<<ans.size()<<'\n';
    for(auto p:ans) cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<" "<<p[3]<<'\n';
    
    
    //system("pause");
    return 0;
}