#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k,p;
    cin>>n>>m>>k>>p;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>matrix[i][j];
    }  
    priority_queue<long long> row;
    priority_queue<long long> col;
    for(int i=0;i<n;i++){
        long long sum=0;
        for(int num:matrix[i]) sum+=num;
        row.push(sum);
    }
    for(int j=0;j<m;j++){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=matrix[i][j];
        }
        col.push(sum);
    }   
    vector<long long> a(k+1,0);
    vector<long long> b(k+1,0);
    for(int i=1;i<=k;i++){
        long long num=row.top();
        row.pop();
        a[i]=a[i-1]+num;
        row.push(num-p*m);
    }
    for(int i=1;i<=k;i++){    
        long long num=col.top();
        col.pop();
        b[i]=b[i-1]+num;
        col.push(num-p*n);
    }
    long long ans=a[0]+b[k];
    int i=0;
    while(i<=k){
        long long res=a[i]+b[k-i]-1LL*i*(k-i)*p;
        ans=max(ans,res);
        i++;
    }

    cout<<ans<<'\n';
    system("pause");
    return 0;
}