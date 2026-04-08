#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int scan(int r, int c) {
    cout << "SCAN " << r << " " << c <<endl;
    int ans;
    cin >> ans;
    return ans;
}
 
int dig(int r, int c) {
    if (r < 1 || r > n || c < 1 || c > m) {
        return 0;
    }
    cout << "DIG " << r << " " << c <<endl;
    int ans;
    cin >> ans;
    return ans;
}

void solve(){
    cin>>n>>m;

    //sx=x1+x2,sy=y1+y2;
    //sl=sx+sy-4
    int sl=scan(1,1);
    //sr=sx-sy+2m-2
    int sr=scan(1,m);

    int sx=(sl+sr)/2+3-m;
    int sy=(sl-sr)/2+1+m;

    int dx=scan(sx/2,1)-sy+2;
    int dy=scan(1,sy/2)-sx+2;

    int x1=(sx+dx)/2,x2=(sx-dx)/2;
    int y1=(sy+dy)/2,y2=(sy-dy)/2;

    if(dig(x1,y1)){
        dig(x2,y2);
    }
    else{
        dig(x1,y2);
        dig(x2,y1);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;

    while(t--) solve();
    //system("pause");
    return 0;
}