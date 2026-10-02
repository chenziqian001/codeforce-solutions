#include<bits/stdc++.h>
using namespace std;
#define int long long


string merge(string x,string y){
    string s=y+'?'+x;
    int n=s.size();
    int m=y.size();
    vector<int> pi(n);
    for(int i=1,j=0;i<n;i++){
        while(j && s[j]!=s[i]) j=pi[j-1];
        if(s[j]==s[i]) j++;
        pi[i]=j;
        if(j==m) return x;
    }
    return x+y.substr(pi.back());
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<string> s(3);
    for(int i=0;i<3;i++) cin>>s[i];
    int res=1e9;
    vector<int> p={0,1,2};
    do{
        string t=merge(merge(s[p[0]],s[p[1]]),s[p[2]]);
        res=min(res,(int)t.size());
    }while(next_permutation(p.begin(),p.end()));
    cout<<res<<'\n';

    //system("pause");
    return 0;
}