#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    long long fast_pow(int a,int n){
        long long res=1;
        while(n){
            if(n&1){
                res=(res*a)%M;
            }
            a=(a*a)%M;
            n>>=1;
        }
        return res;
    }

public:
    const int M=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int threshold=(target+2-1)/2;
        auto it1=lower_bound(nums.begin(),nums.end(),threshold);
        int rg=-1;
        if(it1!=nums.end()) rg=it1-nums.begin();
        int rgg=-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]+nums[0]<=target){
                rgg=i;
                break;
            }
        }
        long long res=fast_pow(2,rgg+1)-1;
        cout<<"res:"<<res<<'\n';
        cout<<"rg"<<rg<<'\n';
        cout<<"rgg"<<rgg<<'\n';
        cout<<"fast_pow(2,rgg-rg):"<<fast_pow(2,rgg-rg)<<'\n';
        if(rgg>=rg){
            res-=fast_pow(2,rgg-rg);
        }
        return res;
        
    }
};
int main(){
    Solution sol;
    vector<int> nums={2,3,3,4,6,7};
    int target=9;
    sol.numSubseq(nums,target);
    system("pause");
    return 0;
}