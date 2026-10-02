#include<bits/stdc++.h>
using namespace std;
#define int long long

int ask(int a,int b,int c){
    cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
    int res;
    cin>>res;
    return res;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a;
    for(int i=1;i<=n;i+=3){
        int x=ask(i,i+1,i+2);
        a.push_back(x);
    }
    int cr=-1,im=-1,id1=-1,id2=-1;
    for(int i=1;i<a.size();i++){
        if(a[i]!=a[i-1]){
            id1=i-1;
            id2=i;
            int st=(i-1)*3+1;
            int pv=a[i-1];
            for(int j=st+1;j<=st+2;j++){
                int x=ask(j,j+1,j+2);
                if(pv==0&&x==1){
                    im=j-1;
                    cr=j+2;
                    break;
                }
                if(pv==1&&x==0){
                    cr=j-1;
                    im=j+2;
                    break;
                }
                pv=x;
            }
            if(im==-1){
                if(pv==0&&a[i]==1){
                    im=st+2;
                    cr=st+5;
                }
                if(pv==1&&a[i]==0){
                    cr=st+2;
                    im=st+5;
                }
            }
            break;
        }
    }
    vector<int> res;
    res.push_back(im);
    for(int i=0;i<a.size();i++){
        int u=i*3+1,v=u+1,w=v+1;
        if(i==id1||i==id2){
            for(int x:{u,v,w}){
                if(x!=cr&&x!=im){
                    int y=ask(x,cr,im);
                    if(y==0) res.push_back(x);
                }
            }
            continue;
        }
        if(a[i]==0){
            int x=ask(u,v,cr);
            if(x==0){
                res.push_back(u);
                res.push_back(v);
                int y=ask(w,cr,im);
                if(y==0) res.push_back(w);
            }
            else{
                res.push_back(w);
                int y=ask(u,cr,im);
                if(y==0) res.push_back(u);
                else res.push_back(v);
            }
        }
        else{
            int x=ask(u,v,im);
            if(x==1){
                int y=ask(w,cr,im);
                if(y==0) res.push_back(w);
            }
            else{
                int y=ask(u,im,cr);
                if(y==0) res.push_back(u);
                else res.push_back(v);
            }
        }
    }
    sort(res.begin(),res.end());
    cout<<"! "<<res.size()<<" ";
    for(int x:res) cout<<x<<" ";
    cout<<endl;
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