#include<bits/stdc++.h>
using namespace std;
const int N=2e5+19;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int stk[(int) 2e5+10];
    set<array<int,2>> st;
    int cnt=0;
    stk[0]=n;
    long long tmp=0;
    long long res=0;
    for(int i=n-1;i>=0;i--){
        int r=stk[cnt];
        while(cnt && a[stk[cnt]]<=a[i]){
            int pos=stk[cnt];
            if(b[pos]==a[pos]){
                tmp-=n-pos;
            }
            if(b[pos]<=a[i]){
                tmp+=n-pos;
            }
            else{
                st.insert({b[pos],pos});
            }
            cnt--;
            r=stk[cnt];
        }
        stk[++cnt]=i;
        while(((int)st.size()) && ((*st.begin())[0])<=a[i]){
            auto it=st.begin();
            int pos=(*it)[1];
            assert(pos<r);
            tmp+=(n-pos);
            st.erase(it);
        }
        if(a[i]==b[i]){
            tmp+=n-i;
        }
        res+=tmp;
    }
    cout<<res<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}




