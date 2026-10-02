#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    vector<int> a(6);
    for(int i=0;i<6;i++) cin>>a[i];
    int k;
    cin>>k;
    k-=6;
    if(k<0){
        cout<<"NO"<<'\n';
        return;
    }
    sort(a.begin(),a.end());
    vector<int> res(6,1);


    int s=0;
    bool ok=false;
    vector<int> x(6);
    for(int x1=6;x1>=0;x1--){
        if(ok) break;
        s+=a[0]*x1; 
        for(int x2=x1;x2>=0;x2--){
            if(ok) break;
            s+=(a[1]-a[0])*x2;
            for(int x3=x2;x3>=0;x3--){
                if(ok) break;
                s+=(a[2]-a[1])*x3;
                for(int x4=x3;x4>=0;x4--){
                    if(ok) break;
                    s+=(a[3]-a[2])*x4;
                    for(int x5=x4;x5>=0;x5--){
                        if(ok) break;
                        s+=(a[4]-a[3])*x5;
                        for(int x6=x5;x6>=0;x6--){
                            if(ok) break;
                            s+=(a[5]-a[4])*x6;
                            if(s<=k && ((x1+x2+x3+x4+x5+x6)>=19)){
                                ok=true;
                                x[0]=x1;
                                x[1]=x2;
                                x[2]=x3;
                                x[3]=x4;
                                x[4]=x5;
                                x[5]=x6;
                                break;
                            }    
                            s-=(a[5]-a[4])*x6;                        
                        }
                        s-=(a[4]-a[3])*x5;
                    }
                    s-=(a[3]-a[2])*x4;
                }
                s-=(a[2]-a[1])*x3;
            }
            s-=(a[1]-a[0])*x2;
        }
        s=0;
    }    

    if(!ok){
        cout<<"NO"<<'\n';
        return;
    }
    
    int pos=5;
    int pre=-1;
    for(int i=5;i>=0;i--){
        if(x[i]==0) continue;
        int v=a[i];
        int t;
        if(pre==-1){
            t=x[i];
        }
        else{
            t=x[i]-pre;
        }
        pre=t;

        while(t>0 && pos>=0){
            t--;
            res[pos]+=v;
            pos--;
        }
    }
    int exa=k-s;
    if(exa<0){
        cout<<"NO"<<'\n';
        return;
    }
    res[5]+=exa;
    cout<<"YES"<<'\n';
    for(int i=0;i<6;i++){
        cout<<res[i]<<" ";
    }
    cout<<'\n';


}



signed main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    system("pause");
}