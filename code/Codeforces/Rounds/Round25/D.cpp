#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int fa[N];


int find(int x){
    if(x!=fa[x]){
        fa[x]=find(fa[x]);
    }

    return fa[x];
}

bool merge(int x,int y){
    int fx=find(x);
    int fy=find(y);

    if(fx==fy) return false;

    fa[fx]=fy;
    return true;
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    
    int tt=n;

    vector<pair<int,int>> redu;
    for(int i=0;i<n;i++) fa[i]=i;
    
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        if(merge(u,v)){
            tt--;
        }
        else{
            redu.emplace_back(u,v);
        }
    }

   

    if(tt==1){
        cout<<0<<'\n';
        system("pause");
        return 0;
    }
    
    vector<pair<int,int>> need;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(merge(i,j)){
                need.emplace_back(i,j);
            }
        }
    }


    cout<<redu.size()<<'\n';
    for(int i=0;i<redu.size();i++){
        cout<<redu[i].first+1<<" "<<redu[i].second+1<<" ";
        cout<<need[i].first+1<<" "<<need[i].second+1<<'\n';
    }




    //system("pause");
    return 0;
}