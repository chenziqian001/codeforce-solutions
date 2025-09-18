#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    if(s[0]=='1' && s[n-1]<='1' && count(s.begin()+1,s.begin()+n-1,'0')==(n-2)){
        for(int i=0;i<n-2;i++){
            cout<<'9';
        }
        cout<<'\n';
        return;
    }
    vector<int> cnt(10);
    for(int i=n-1;i>=0;i--){
        if(s[i]>'0'){
            s[i]--;
            for(int j=i+1;j<n;j++) s[j]='9';
            break;
        }
    }
    for(char c:s){
        cnt[c-'0']^=1;
    }
    int odd=0;
    for(int i=0;i<10;i++){
        odd+=cnt[i];
    }

    if(odd>0){
        bool done=false;
        for(int i=n-1;i>=0 && !done;i--){
            cnt[s[i]-'0']^=1;
            odd+=cnt[s[i]-'0']*2-1;
            for(int j=s[i]-1;j>='0';j--){
                int v=j-'0';
                cnt[v]^=1;
                odd+=cnt[v]*2-1;
                if(odd<=n-1-i){
                    s[i]=j;
                    odd-=cnt[9];
                    for(int z=i+1;z<n-odd;z++) s[z]='9';
                    int k=n-odd;
                    for(int num=8;num>=0;num--){
                        if(cnt[num]>0){
                            s[k++]='0'+num;
                        }
                    }
                    done=true;
                    break;
                }
                cnt[v]^=1;
                odd+=cnt[v]*2-1;
            }
        }
    }
    cout<<s<<'\n';
}



int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}