#include<bits/stdc++.h>
using namespace std;
#define int long long
#define db double
const db eps=1e-9;
const db PI=acos(-1.0);
struct P{
    int x,y;
    P operator-(P b){return {x-b.x,y-b.y};}
    int operator*(P b){return x*b.y-y*b.x;}
    int dot(P b){return x*b.x+y*b.y;}
    int len2(){return x*x+y*y;}
};
int cross(P a,P b,P c){return (b-a)*(c-a);}
// 极角排序 atan2l 版
bool angCmp(P a,P b){
    long double ta=atan2l(a.y,a.x),tb=atan2l(b.y,b.x);
    if(abs(ta-tb)>1e-15)return ta<tb;
    return a.len2()<b.len2();
}
// 线段相交
bool intersect(P a,P b,P c,P d){
    if(max(a.x,b.x)<min(c.x,d.x)||max(c.x,d.x)<min(a.x,b.x)||
       max(a.y,b.y)<min(c.y,d.y)||max(c.y,d.y)<min(a.y,b.y))return 0;
    return cross(a,b,c)*cross(a,b,d)<=0&&cross(c,d,a)*cross(c,d,b)<=0;
}
// 点P到线段AB距离
db distToSeg(P p,P a,P b){
    if((p-a).dot(b-a)<=0)return sqrt((p-a).len2());
    if((p-b).dot(a-b)<=0)return sqrt((p-b).len2());
    return abs((p-a)*(b-a))/sqrt((b-a).len2());
}
// 多边形面积
db area(P p[],int n){
    db res=0;
    for(int i=1;i<=n;i++)res+=p[i]*p[i%n+1];
    return abs(res)/2.0;
}
// 多边形重心
void center(P p[],int n){
    db a=0,cx=0,cy=0;
    for(int i=1;i<=n;i++){
        db t=p[i]*p[i%n+1];
        a+=t;
        cx+=(p[i].x+p[i%n+1].x)*t;
        cy+=(p[i].y+p[i%n+1].y)*t;
    }
    printf("%.10f %.10f\n",cx/(3*a),cy/(3*a));
}
