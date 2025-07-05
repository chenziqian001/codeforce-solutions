#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    } 
    int maxi=-1;
    for(int i=n-1;i>=0;i--){
        int j=i-2;
        int jn=i-3;
        if(a[i]==b[i]){
            maxi=max(maxi,i+1);
        }
        else if((i-1>=0)&&((a[i]==a[i-1])||(b[i]==b[i-1]))){
            maxi=max(maxi,i);
        }
        else if((j>=0)&&(a[i]==b[j]||a[j]==b[i])){
           maxi=max(maxi,j+1);
        }
        else if(j>=0&&(a[i]==a[j]||b[i]==b[j])){
            maxi=max(maxi,j+1);
        }
        else if((jn>=0)&&((a[i]==b[jn])||(a[jn]==b[i]))){
           maxi=max(maxi,jn+1);
        }
    }

    cout<<(maxi==-1?0:maxi)<<'\n';

    return;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    system("pause");
    return 0;
}