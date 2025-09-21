#include<iostream>
#define f(a,b) f[a*n+b]

using namespace std;

int n,m;
int x1,x2,Y1,y2;
int maxn,minn;
int f[300039];
void solve(){
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            Y1=i;y2=n-i;x1=j;x2=m-j;
            f(i,j)=(min(x1,y2)+min(x1,Y1)+min(x2,Y1)+min(x2,y2));
            maxn = max(x1,x2);minn=min(x1,x2);
            if(Y1-1>0)
                f(i,j)+=(Y1-1+((Y1-minn)>=0?(Y1-minn):0))*((Y1-minn-1)>=0?minn:Y1-1)/2;
            if(Y1-1>maxn)
                f(i,j)-=((Y1-1-maxn+(Y1-1-maxn)%2)*((Y1-1-maxn)%2==1?(Y1-1-maxn)/2+1:(Y1-1-maxn)/2)/2);
            if(y2-1>0)
                f(i,j)+=(y2-1+((y2-minn)>=0?(y2-minn):0))*((y2-1-minn)>=0?minn:y2-1)/2;
            if(y2-1>maxn)
                f(i,j)-=((y2-1-maxn+(y2-1-maxn)%2)*((y2-1-maxn)%2==1?(y2-1-maxn)/2+1:(y2-1-maxn)/2)/2);
            maxn = max(Y1,y2);minn=min(Y1,y2);
            if(x1-1>0)
                f(i,j)+=(x1-1+((x1-minn)>=0?(x1-minn):0))*((x1-minn-1)>=0?minn:x1-1)/2;
            if(x1-1>maxn)
                f(i,j)-=((x1-1-maxn+(x1-1-maxn)%2)*((x1-1-maxn)%2==1?(x1-1-maxn)/2+1:(x1-1-maxn)/2)/2);
            if(x2-1>0)
                f(i,j)+=(x2-1+((x2-minn)>=0?(x2-minn):0))*((x2-minn-1)>=0?minn:x2-1)/2;
            if(i==2&&j==0)
            printf("%d ",f(i,j));   
            if(x2-1>maxn)
                f(i,j)-=((x2-1-maxn+(x2-1-maxn)%2)*((x2-1-maxn)%2==1?(x2-1-maxn)/2+1:(x2-1-maxn)/2)/2);
            if(i==2&&j==0)
            printf("%d \n",f(i,j));    
               
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            printf("%d ",f(i,j));
        }
        printf("\n");
    }

}


int main(){

    solve();
    system("pause");
    return 0;
}