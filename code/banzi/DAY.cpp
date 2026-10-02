#include<bits/stdc++.h>
using namespace std;
#define int long long

// 1. 每月天数表（下标从1开始，2月默认为28天）
int mday[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

// 2. 闰年判断：四年一闰，百年不闰，四百年再闰
bool isL(int y){
    return (y%4==0&&y%100!=0)||(y%400==0);
}

// 3. 获取指定年月的天数：特判闰年2月
int getD(int y,int m){
    if(m==2)return 28+isL(y);
    return mday[m];
}

/* 
   4. 基姆拉尔森公式：推算星期
   输入：y(年), m(月), d(日)
   返回值：1-7 (1=周一, 2=周二, ..., 6=周六, 7=周日)
   核心逻辑：1月2月看作上一年的13月14月
*/
int getW(int y,int m,int d){
    if(m==1||m==2)m+=12,y--;
    // (d + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400) % 7 
    // 得到 0=周一, 1=周二, ..., 6=周日
    int res=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    return res+1;
}

// 5. 辅助：校验日期合法性（常用于日期区间遍历）
bool check(int y,int m,int d){
    if(m<1||m>12)return 0;
    if(d<1||d>getD(y,m))return 0;
    return 1;
}

// 6. 模拟：计算 X 天后的日期（暴力跳法，稳如老狗）
void nextDay(int &y,int &m,int &d){
    d++;
    if(d>getD(y,m)){
        d=1;m++;
        if(m>12){m=1;y++;}
    }
}

