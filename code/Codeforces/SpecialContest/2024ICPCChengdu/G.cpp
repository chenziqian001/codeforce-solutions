#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef __int128_t lll;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    set<int> st;
    //这题其实非常有意思,对于and or xor 三种操作你可以把集合A和集合B里面的‘1’分为三类
    //1.A独有的，2.B独有的，3.A 和 B 共享的
    //对于任何A和B进行这三种操作的结果一定是我们讨论的1,2,3这三种情况的线性组合
    //组合的方案数位2^3=8
    for(int i=1;i<n;i++){
        int x=a[i],y=a[i-1];
        st.insert(0); //1,2,3三组都不取
        st.insert(x&~y); // 仅仅拿1
        st.insert(y&~x); // 仅仅拿2
        st.insert(x&y);  // 仅仅拿3
        st.insert(x^y);  // 拿1和2
        st.insert(x);    //拿1和3
        st.insert(y);    //拿2和3
        st.insert(x|y);  // 全拿
    }

    cout<<st.size()<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t=1;
    while(t--)solve();
    //system("pause");
    return 0;
}