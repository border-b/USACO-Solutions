/*
ID:
LANG: C++11
TASK: sort3
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

ofstream fout ("sort3.out");
ifstream fin ("sort3.in");

int a[1011],b[1011],ret,n;
bool used[1011];

bool send(int now, int from)
{
  for(int i = 1; i <= n; ++i){
    if(a[i] != b[i] and !used[i] and a[i] == now){
      if(b[i] == from){
        used[i] = 1;
        return true;
      }
    }
  }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  /*#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out","w",stdout);
  #endif*/
  fin >> n;
  for(int i = 1; i <= n; ++i){
    fin >> a[i];
    b[i] = a[i];
  }
  sort(b+1,b+n+1);
  for(int i = 1; i <= n; ++i){
    if(a[i] == b[i]){
      used[i] = 1;
      continue;
    }
    if(a[i] != b[i] and !used[i]){
      if(send(b[i],a[i])){
        used[i] = 1;
        ret++;
      }
    }
  }
  //debug(ret);
  int cnt = 0;
  for(int i = 1; i <= n; ++i){
    if(!used[i]){
      ++cnt;
      //debug(i);
    }
  }
  //debug(cnt);
  ret += (cnt/3)*2;
  fout << ret << endl;
}

