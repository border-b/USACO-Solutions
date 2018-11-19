/*
ID:
LANG: C++11
TASK: holstein
*/
#include <bits/stdc++.h>

using namespace std;

#define debug(s) cout<< #s <<" = "<< s <<endl
#define all(v) (v).begin(), (v).end()
#define mem(a,val) memset(a,val,sizeof a)

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define endl '\n'

ofstream fout ("holstein.out");
ifstream fin ("holstein.in");

int n,v;
int req[32],a[32][32];
vector<int> ans;
bool vis[32];
bool flag;

bool check()
{
  int tot[32];
  mem(tot,0);
  for(int j: ans){
    for(int i = 1; i <= v; ++i) tot[i] += a[j][i];
  }
  for(int i = 1; i <= v; ++i){;
    if(tot[i] < req[i]) return false;
  }
  return true;
}

void solve(int cur,int size)
{
  if((int)ans.size() == size){
    if(check()){
      flag = 1;
      fout << ans.size();
      for(int i: ans) fout << " " << i;
      fout << endl;
    }
    return;
  }
  for(int i = cur+1; i <= n; ++i){
    if(!vis[i]){
      vis[i] = 1;
      ans.pb(i);
      solve(i,size);
      if(flag) return;
      ans.pop_back();
      vis[i] = 0;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  /*#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out","w",stdout);
  #endif*/
  fin >> v;
  for(int i = 1; i <= v; ++i) fin >> req[i];
  fin >> n;
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= v; ++j) fin >> a[i][j];
  }
  for(int sz = 1; sz <= n; ++sz){
    ans.clear();
    solve(0,sz);
    if(flag) break;
  }
}

