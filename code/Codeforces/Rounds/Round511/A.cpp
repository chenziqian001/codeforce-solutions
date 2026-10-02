#include<bits/stdc++.h>
using namespace std;

const int N=15000005;
int c[N];
bool v[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    int g=-1;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(g==-1) g=x;
        else{
            g=__gcd(x,g);
        }   
        a[i]=x;
    }
   for(int i=0;i<n;i++) c[a[i]/g]++;
    
    int mx=0;
    for(int i=2;i<N;i++){
        if(!v[i]){
            int s=0;
            for(int j=i;j<N;j+=i){
                v[j]=1;
                s+=c[j];
            }
            mx=max(mx,s);
        }
    }
    if(mx==0){
        cout<<-1<<'\n';
    }
    else cout<<n-mx<<'\n';
    

    //system("pause");
}

