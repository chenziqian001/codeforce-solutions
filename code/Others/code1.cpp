#include<iostream>
#include<vector>
#include<set>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> row;
    vector<int> col;
    int maxi=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            if(x>maxi){
                maxi=x;
                row.clear();
                col.clear();
                row.push_back(i);
                col.push_back(j);
            }
            else if(x==maxi){
                row.push_back(i);
                col.push_back(j);
            }
            else continue;
        }
    }

    int len=row.size();
    
    if(len<=2){
        cout<<maxi-1<<'\n';
        return;
    }
    else{
        int h=0,l=0;
        vector<int> cnt(101);
        for(int i=0;i<len;i++){
            if(++cnt[row[i]]==2){
                h=row[i];
                break;
            }
        }
        vector<int> ads(101);
        for(int i=0;i<len;i++){
            if(++ads[col[i]]==2){
                l=col[i];
                break;
            }
        }
        for(int i=0;i<len;i++){
            if(row[i]!=h&&col[i]!=l){
                cout<<maxi<<'\n';
                return;
            }
            
        }
        cout<<maxi-1<<'\n';
        

            
    }
    


    

}


int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}