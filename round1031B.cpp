#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


void solve(){
    int w,h,a,b;
    int x1,y1,x2,y2;
    
    cin>>w>>h>>a>>b;
    cin>>x1>>y1>>x2>>y2;
    int narrow_w;

    if(x2>=x1){
        narrow_w=x2-(x1+a);
    }   
    else{
        narrow_w=x1-(x2+a);
    }
    int narrow_h;
    if(y2>=y1){
        narrow_h=y2-(y1+b);
    }
    else{
        narrow_h=y1-(y2+b);
    }
    if(narrow_w==0||narrow_h==0){
        cout<<"YES"<<'\n';
    }
    else if(narrow_w<a&&narrow_h<b){
        cout<<"NO"<<'\n';
    }
    else if(narrow_h<b&&(narrow_w%a!=0)){
        cout<<"NO"<<'\n';
    }
    else if(narrow_w<a&&(narrow_h%b!=0)){
        cout<<"NO"<<'\n';
    }
    else{
        cout<<"YES"<<'\n';
    }
    

}


int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}