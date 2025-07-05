#include<iostream>
#include<vector>

using namespace std;


void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> pos;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a==1){
            pos.push_back(i);
        }
    }
    int s=pos.size();
    if((pos[s-1]-pos[0]+1)>x){
        cout<<"no"<<'\n';
    }
    else{
        cout<<"yes"<<'\n';
    }


    return;

}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;   
}