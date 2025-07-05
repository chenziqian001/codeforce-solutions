#include<iostream>
#include<vector>
#include<set>
using namespace std;

void solve(){
    int n;
    cin>>n;
    
    set<int> st;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        st.insert(x);
    }
    int cnt=1;
    vector<int> a(st.begin(),st.end());
    int m=a.size();
    for(int i=1;i<m;){
        if(a[i]-a[i-1]>1){
            cnt++;
            i++;
            continue;
        }
        if(i+1<m){
            if((a[i]-a[i-1]==1)&&(a[i+1]-a[i]==1)){
                cnt++;
                i+=2;
                continue;
            }
        }
        i++;
    }
    cout<<cnt<<'\n';
    return;
}


int main(){
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}