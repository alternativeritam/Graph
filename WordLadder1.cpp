#include<bits/stdc++.h>
using namespace std;



int main() {
  
  string word,target;
  cin>>word>>target;
  int n;
  cin>>n;
  // given a list of words list
  vector<string> words(n);
  map<string,bool> mp;
  for (int i = 0; i < n; ++i)
  {
      mp[words[i]]=true;
  }
  queue<pair<string,int>> q;
  q.push({word,0});
  int ans = INT_MAX;

  while(!q.empty()){

    string cur = q.top().first;
    int dist = q.top().second;
    q.pop();
    if(cur==target){
        cout<<dist;
        break;
    }
    for (int i = 0; i < cur.size(); ++i)
    {   
        char original = cur[i];
        for (char ch='a';ch<='z';ch++)
        {
            cur[i] = ch;

            if(mp[cur]){
                mp[cur]=false;
                q.push({cur,dist+1});
            }
        }
        cur[i]=original;
    }

  }

  cout<<ans<<endl;

}
