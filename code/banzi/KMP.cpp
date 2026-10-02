#include<bits/stdc++.h>
using namespace std;

// s: 模式串(短); p: 文本串(长)
vector<int> get_nxt(string s){
  int n=s.size();
  vector<int> nxt(n); // nxt[i]表示[0...i]最长公共前后缀
  for(int i=1,j=0;i<n;i++){
    while(j&&s[i]!=s[j])j=nxt[j-1]; // 字符不匹配，j跳回到上一个可能匹配的位置
    if(s[i]==s[j])j++; // 匹配成功，j后移
    nxt[i]=j;
  }
  return nxt;
}

void kmp(string p,string s){
  vector<int> nxt=get_nxt(s);
  for(int i=0,j=0;i<p.size();i++){
    while(j&&p[i]!=s[j])j=nxt[j-1]; // 在文本串p中匹配模式串s
    if(p[i]==s[j])j++;
    if(j==s.size()){
      // 此时匹配成功！起始位置是 i-s.size()+1
      j=nxt[j-1]; // 继续找下一个可能的匹配(可能有重叠)
    }
  }
}