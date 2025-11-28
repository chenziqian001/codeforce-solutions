#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s=" ";
    vector<string> p;

    while(cin>>s && s!="."){
        p.push_back(s);
    }
    s=" ";
    string tmp;
    cin>>tmp;
    s+=tmp;

    vector<bool> f(s.size()+1,false);
    f[0]=true;


    auto check=[&](int pos){
        for(string pt:p){
            int len=pt.size();
            if(pos>=len){
                if(f[pos-len] && s.substr(pos-len,len)==pt){
                    f[pos]=true;
                    break;
                }
            }
        }
    };

    for(int i=1;i<=s.size();i++){
        check(i);
    }

    for(int i=1;i<=s.size();i++){
        if(!f[i]){
            cout<<i-1<<'\n';
            return 0;
        }
    }
    cout<<s.size()-1<<'\n';
    //system("pause");
    return 0;
}