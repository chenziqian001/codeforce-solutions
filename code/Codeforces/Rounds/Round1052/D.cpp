#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a;

bool isSet(int x, int i) {
    return (x >> i) & 1;
}
void update(int l,int r,int ll){
    if(l>r) return;
    if(l==r){
        a[l-ll]=l;
        return;
    }
    int splitBit = -1;
    for (int i = 31; i >= 0; --i) {  
        if (isSet(r, i) != isSet(l, i)) { 
            splitBit = i;
            break;
        }
    }
    int mid = l;
    while (mid <= r && !isSet(mid, splitBit)) {
        ++mid;
    }
     int leftPtr = mid - 1;  
    int rightPtr = mid;
    while (leftPtr >= l && rightPtr <= r) {
        int leftIdx = leftPtr - ll;
        int rightIdx = rightPtr - ll;
        a[leftIdx] = rightPtr;  
        a[rightIdx] = leftPtr;
        --leftPtr;
        ++rightPtr;
    }


    update(l,leftPtr,ll);
    update(rightPtr,r,ll);

}

void solve(){
    int L, R;
    cin >> L >> R;
    int n=R-L+1;
    a.resize(n);
    update(L,R,L);
    long long res=0;
    for(int i=0;i<n;i++){
        res+=a[i]|(i+L);
    }
    cout<<res<<'\n';
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<'\n';
}
 
 
signed main(){
    int t;
    cin >> t;
    while(t--) solve();
    system("pause");
    return 0;
}
















