#include<bits/stdc++.h>
using namespace std;
const int N=105;


struct pre{
    int pi,pj,pk;
    char take;
};
pre p[N][N][N];

int pi[N];
int nx[N][26];

string a,b,c;
int la,lb,lc;

void init(){
    pi[0]=0;
    for(int i=1;i<lc;i++){
        int j=pi[i-1];
        while(j && c[i]!=c[j]) j=pi[j-1];
        if(c[i]==c[j]) j++;
        pi[i]=j;
    }

    for(int len=0;len<lc;len++){
        for(int k=0;k<26;k++){
            if((k+'A')==c[len]) nx[len][k]=len+1;
            else{
                int j=(len==0?0:pi[len-1]);
                while(j && (k+'A')!=c[j]) j=pi[j-1];
                if((k+'A')==c[j]) j++;
                nx[len][k]=j;
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>b>>c;
    la=a.size(),lb=b.size(),lc=c.size();
    init();

    vector<vector<vector<int>>> dp(la+1,vector<vector<int>>(lb+1,vector<int>(lc,-1)));
    dp[0][0][0]=0;


    for(int i=0;i<=la;i++){
        for(int j=0;j<=lb;j++){
            for(int k=0;k<lc;k++){
                if(dp[i][j][k]==-1) continue;
                int curlen=dp[i][j][k];
                if(i<la){
                    if(curlen>dp[i+1][j][k]){
                        dp[i+1][j][k]=curlen;
                        p[i+1][j][k]={i,j,k,'!'};
                    }
                }
                if(j<lb){
                    if(curlen>dp[i][j+1][k]){
                        dp[i][j+1][k]=curlen;
                        p[i][j+1][k]={i,j,k,'!'};
                    }
                }
               
                if((i<la && j<lb) && (a[i]==b[j])){
                    
                    int nxk=nx[k][a[i]-'A'];
                    if(nxk<lc){
                        int newl=curlen+1;
                        if(newl>dp[i+1][j+1][nxk]){
                            dp[i+1][j+1][nxk]=newl;
                            p[i+1][j+1][nxk]={i,j,k,a[i]};    
                        } 
                    }
                }
            }
        }
    }

    int kk=-1;
    int mxlen=0;
    for(int i=0;i<lc;i++){
        if(dp[la][lb][i]>mxlen){
            mxlen=max(mxlen,dp[la][lb][i]);
            kk=i;
        }
    }

    if(mxlen==0){
        cout<<0<<'\n';
        //system("pause");
        return 0;
    }

    string res;
    int i=la,j=lb,k=kk;
    while(i>0 || j>0){

        pre pp=p[i][j][k];
        if(pp.take!='!'){
            res+=pp.take;
        }
        i=pp.pi;
        j=pp.pj;
        k=pp.pk;
    }


    reverse(res.begin(),res.end());
    cout<<res<<'\n';


    //system("pause");
    return 0;
}
