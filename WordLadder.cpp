#include<bits/stdc++.h>
using namespace std;



int main() {
  
  string startWord,target;
  cin>>startWord>>target;
  int n;
  cin>>n;
  // given a list of words list
  vector<string> words(n);
  map<string,bool> mp;
  for (int i = 0; i < n; ++i)
  {
      mp[words[i]]=true;
  }
  queue<vector<string>> q;
  q.push({startWord});
  vector<string> usedOnLevel;
  int level=0;
  usedOnLevel.push_back(startWord);
  vector<vector<string>> ans;
  while(!q.empty()){

    vector<string> vec = q.front();
    q.pop();
    if(vec.size()>level){
        level++;
        for(auto it:usedOnLevel){
            mp[it]=false; // remove all the words and marked them as already visited;
        }
    }
    string cur = vec.back();

    if(cur==target){
        ans.push_back(vec);
    }
    
    for (int i = 0; i < cur.size(); ++i)
    {   
        char original = cur[i];
        for (char ch='a';ch<='z';ch++)
        {
            cur[i] = ch;

            if(mp[cur]){
               
               vec.push_back(cur);
               q.push(vec); // add for finding path to target word
               usedOnLevel.push_back(cur); // push the word cur for that level 
               vec.pop_back(); // retsore the original queue for multiple process
            }
        }
        cur[i]=original;
    }

  }

  // print ans
  
}
