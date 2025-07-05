#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int get_len(string a,string b){
        int pos=0;
        int res=0;
        while(pos<a.size()&&pos<b.size()&&a[pos]==b[pos]){
            res++;
            pos++;
        }
        return res;
    }

    
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n=words.size();
        vector<int> res(n);
        vector<array<int,3>> p;
        for(int i=1;i<n;i++){
            if(words[i][0]!=words[i-1][0]) continue;
            int length=get_len(words[i],words[i-1]);
            p.push_back({length,i,i-1});
        }
       
        sort(p.begin(),p.end(),[](array<int,3> a,array<int,3> b){
            return a[0]>b[0]; 
        });
         for(int i=0;i<p.size();i++){
            cout<<p[i][0]<<" "<<p[i][1]<<" "<<p[i][2]<<'\n';
        }
        int m=p.size();
        for(int i=0;i<n;i++){
            int val=0;
            for(int j=0;j<m;j--){
                if((i!=p[j][1])&&(i!=p[j][2])){
                    val=p[j][0];
                    break;
                }
            }
           
            res[i]=val;
            
        }
        return res;
        
        
        
        
    }
};




int main()
{
    Solution sol;
    vector<string> words={"fec","fef","acaa","adfa","afc","fdbda"};
    sol.longestCommonPrefix(words);

    system("pause");
    return 0;
}