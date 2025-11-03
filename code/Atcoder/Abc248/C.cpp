#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>q;
    vector<int> a{0};
    vector<int> b{0};
    while(q--){
        
        int op;
        cin>>op;
        if(op==1){
            char c;
            cin>>c;
            a.push_back(a.back()+(c=='('?1:-1));
            b.push_back(min(a.back(),b.back()));
        }
        else{
            a.pop_back();
            b.pop_back();
        }
        if(a.back()==0 && b.back()==0){
            cout<<"Yes"<<'\n';
        }
        else cout<<"No"<<'\n';
    } 
}