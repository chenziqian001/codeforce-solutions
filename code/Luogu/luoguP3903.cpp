#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    /*
    int ans=0;
    for(int st=0;st<n;st++){
        int res=1;
        int pev=a[st];
        int ok=1;
        for(int i=st+1;i<n;i++){
            if(ok){
                if(a[i]<pev){
                    res++;
                    pev=a[i];
                    ok=0;
                }
                else if(a[i]>pev){
                    pev=a[i];
                }
            }
            else{
                if(a[i]>pev){
                    res++;
                    pev=a[i];
                    ok=1;
                }
                else if(a[i]<pev){
                    pev=a[i];
                }

            }
        }
        ans=max(ans,res);
    }
    */
    int res=1;
    int pre=a[0];
    int ok=1;
    for(int i=1;i<n;i++){
        if(ok){
            if(a[i]<pre){
                res++;
                pre=a[i];
                ok=0;
            }
            else if(a[i]>pre){
                pre=a[i];
            }
        }
        else{
            if(a[i]>pre){
                res++;
                pre=a[i];
                ok=1;
            }
            else if(a[i]<pre){
                pre=a[i];
            }
        }

    }

    cout<<res<<'\n';
    //system("pause");
    return 0;
}