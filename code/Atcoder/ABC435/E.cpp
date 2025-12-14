#include<bits/stdc++.h>
using namespace std;





int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;


    map<int,int> mp;
    int black=0;


    while(q--){
        int l,r;
        cin>>l>>r;

        int nl=l,nr=r;
        auto it=mp.lower_bound(l);
        if(it!=mp.begin()){
            auto that=prev(it);
            if(that->second>=l-1){
                it=that;
            }
        }

        while(it!=mp.end() && it->first<=nr+1){
            nl=min(nl,it->first);
            nr=max(nr,it->second);
            black-=(it->second-it->first+1);
            it=mp.erase(it);
        }

        mp[nl]=nr;
        black+=nr-nl+1;

        cout<<n-black<<'\n';

    }

    //system("pause");


}

