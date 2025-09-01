#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> t(n);
    vector<int> parent(n);
    parent[0]=-1;
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
        x--;
        parent[i]=x;
        t[i].push_back(x);
        t[x].push_back(i);
    }
    



}