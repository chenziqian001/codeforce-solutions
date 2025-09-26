#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> s(m+1);
    vector<int> f(m-k+1);

    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            int x;
            cin>>x;
            s[j]=s[j-1]+x;
        }

        if(i==0){
            for(int j=0;j<=m-k;j++){
                f[j]=s[j+k]-s[j];
            }
            continue;
        }

        vector<int> nf(m-k+1);
        int mx=0;
        deque<int> q;
        for(int j=0;j<=m-k;j++){
            if(j>=k){
                mx=max(mx,f[j-k]+s[j]-s[j-k]);
            }
            while(!q.empty() && f[q.back()]-s[q.back()]<=f[j]-s[j]){
                q.pop_back();
            }
            q.push_back(j);
            if(q.front()<=j-k) q.pop_front();
            nf[j]=max(mx-s[j],f[q.front()]-s[q.front()])+s[j+k];
        }
        mx=0;
        q.clear();

        for(int j=m-k;j>=0;j--){
            if(j<=m-2*k){
                mx=max(mx,f[j+k]+s[j+2*k]-s[j+k]);
            }
            while(!q.empty() && f[q.back()]+s[q.back()+k]<=f[j]+s[j+k]){
                q.pop_back();
            }
            q.push_back(j);
            if(q.front()>=j+k) q.pop_front();
            nf[j]=max(nf[j],max(mx+s[j+k],f[q.front()]+s[q.front()+k])-s[j]);
        }
        f=move(nf);
    }


    cout<<*max_element(f.begin(),f.end())<<'\n';
    system("pause");
    return 0;
}