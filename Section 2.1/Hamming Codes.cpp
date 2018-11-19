/*
ID:
LANG: C++11
TASK: hamming
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

ofstream fout ("hamming.out");
ifstream fin ("hamming.in");

vector<int>ans;
int n,b,d;
bool flag;

bool check(int num)
{
  for(int i: ans){
    int x = i^num;
    if(__builtin_popcount(x) < d) return false;
  }
  return true;
}

void solve(int cur, int size)
{
  if((int)ans.size() == size){
    flag = 1;
    for(int i = 0; i < (int)ans.size(); ++i){
      if(i % 10 == 0 and i) fout << endl;
      fout << ans[i];
      if(i != (int)ans.size()-1 and (i+1) % 10 ) fout << " "; 
    }
    fout << endl;
    return;
  }
  for(int i = cur+1; i <= (1 << b); ++i){
    if(check(i)){
      ans.pb(i);
      solve(i,size);
      if(flag) return;
      ans.pop_back();
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
  fin >> n >> b >> d;
  for(int i = 0; i <= (1 << b); ++i){
    ans.pb(i);
    solve(i,n);
    ans.pop_back();
    if(flag) break;
  }
}

