#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
    string s3;
    cin>>s3;
    int len1,len2,len3;
    len1=s1.size(),len2=s2.size(),len3=s3.size();
    if(len1!=len2){
        cout<<"NO"<<'\n';
        return;
    }
    if(len1==len2 && len1!=len3){
        cout<<"YES"<<'\n';
        return;
    }
    vector<int> fa(26);
    vector<int> rank(26,1);
    for(int i=0;i<26;i++){
        fa[i]=i;
    }
    auto find=[&](auto&& find,int x)->int{
        if(x!=fa[x]){
            fa[x]=find(find,fa[x]);
        }
        return fa[x];
    };
    auto merge=[&](int a,int b)->void{
        int roota=find(find,a);
        int rootb=find(find,b);
        if(roota==rootb) return;
        if(rank[roota]<rank[rootb]){
            fa[roota]=rootb;
        }
        else{
            fa[rootb]=roota;
            if(rank[roota]==rank[rootb]) rank[roota]++;
        }
    };
    for(int i=0;i<len1;i++){
        int n1=s1[i]-'a';
        int n2=s2[i]-'a';
        merge(n1,n2);
    }
    bool ok=false;
    for(int i=0;i<len1;i++){
        int n1=s1[i]-'a';
        int n3=s3[i]-'a';
        int root1=find(find,n1);
        int root3=find(find,n3);
        if(root1!=root3){
            ok=true;
            break;
        }
    }
    if(ok) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
    
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}