#include<bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin>>s;
    int n=s.size();
    
    string res;
    vector<vector<bool>> dp(6000,vector<bool>(1<<12)); //dp[i][j]表示为处理前i个字符，已经使用了操作为mask的状态，dp值为1则表示可达
    dp[0][0]=1;

    vector<pair<int,int>> cur;//存放目前的可能成为最优构造方法的dp状态候选
    cur.push_back({0,0});
    

    int final_size=n;
    int cur_len=1;
    int cnt=0;

    while((1<<cnt)<n){
        cnt++;
    }
    cnt--;

    vector<vector<int>> bits(1<<12);
    for(int i=0;i<(1<<cnt);i++){
        for(int j=0;j<cnt;j++){
            if(!((i>>j)&1)) bits[i].push_back(j);
        }
    }//为了方便取用，先存下每种使用状态的补集，到时候直接枚举补集


    while(final_size>cur_len){
        final_size-=cur_len;
        cur_len*=2;
    }


    while(res.size()<final_size){
        char min_c='z';

        for(int i=0;i<cur.size();i++){//开始遍历状态进行枚举，需要注意的是，这些状态都是符合前缀字典序最小的
            auto x=cur[i];

            for(auto y:bits[x.second]){
                if(!dp[x.first+(1<<y)][x.second^(1<<y)]){
                    cur.emplace_back(x.first+(1<<y),x.second^(1<<y));
                    dp[x.first+(1<<y)][x.second^(1<<y)]=1;
                }

            }
            min_c=min(min_c,s[x.first]);

        }

        res.push_back(min_c);

        vector<pair<int,int>> new_cur; 
        for(auto x:cur){
            if(s[x.first]==min_c){
                dp[x.first+1][x.second]=1;
                new_cur.emplace_back(x.first+1,x.second);
            }
        }//无情的淘汰掉那些比min_char大的状态，贪心思想的体现

        cur=new_cur;

    }


    cout<<res<<'\n';
    //system("pause");

}