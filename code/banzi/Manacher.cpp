#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
char s[N],t[N];
int d[N],n;
void manacher(){
    int l=0,r=-1;
    for(int i=1;i<=n;i++){
        int k=(i>r)?1:min(d[l+r-i],r-i+1);
        while(i-k>0&&i+k<=n&&t[i-k]==t[i+k])k++;
        d[i]=k--;
        if(i+k>r)l=i-k,r=i+k;
    }
}
int main(){
    scanf("%s",s+1);
    int len=strlen(s+1);
    t[++n]='~';
    for(int i=1;i<=len;i++)t[++n]='#',t[++n]=s[i];
    t[++n]='#',t[++n]='!';
    manacher();
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,d[i]);
    printf("%d\n",ans);
    return 0;
}