#include<bits/stdc++.h>
using namespace std;




int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    double a[8],b[8],ans=0;
    for(int i=0;i<8;i++)cin>>a[i]>>b[i];
    int p[8]={0,1,2,3,4,5,6,7};
    do{
        double d[4][8]={};
        for(int i=0;i<8;i++)d[0][i]=1;
        for(int r=1;r<=3;r++){
            int l=1<<r,h=l/2;
            for(int i=0;i<8;i+=l)
                for(int x=i;x<i+h;x++)
                    for(int y=i+h;y<i+l;y++){
                        double w=a[p[x]]/(a[p[x]]+b[p[y]]);
                        d[r][x]+=d[r-1][x]*d[r-1][y]*w;
                        d[r][y]+=d[r-1][y]*d[r-1][x]*(1-w);
                    }
        }
        for(int i=0;i<8;i++)if(!p[i])ans=max(ans,d[3][i]);
    }while(next_permutation(p,p+8));
    printf("%.9f\n",ans);
}