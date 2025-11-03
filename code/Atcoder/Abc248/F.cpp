#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
struct node{
    int id,g,val;
    bool operator<(const node& other) const{
        return id<other.id;
    }
};
vector<node> b;

int get_left(int x){
    node n={x,0,0};
    auto [pos,tp,val]=*lower_bound(b.rbegin(),b.rend(),n);
    if(!tp) return val;
    else return val-a[x];
}
int get_right(int x){
    return get_left(x)+a[x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    b.push_back({n+1,0,0});

    int q;
    cin>>q;
    while(q--){
        int op,pos;
        cin>>op>>pos;
       
        op--;
        if(op!=2){
            pos--;
            while(b.back().id<pos) b.pop_back();
            b.push_back({pos,op,op?get_right(pos):get_left(pos)});
        }
        else{
            int l=0,r=n-1,res=n;
            while(l<=r){
                int mid=(l+r)/2;
                int ml=get_left(mid);
                int mr=get_right(mid);
                if(pos>=ml && pos<mr){
                    res=mid;
                    r=mid-1;
                }
                else l=mid+1;

            }
            cout<<n-res<<'\n';
        }
    }
    //system("pause");


}