/*
ID: babune91
LANG: C++11
TASK: frac1
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

ofstream fout ("frac1.out");
ifstream fin ("frac1.in");

bool cmp(pair<pair<int,int>,double> A, pair<pair<int,int>,double> B){
  return A.ss < B.ss;
}

int main()
{
  int n;
  fin >> n;
  int cnt = 0;
  pair<pair<int,int>,double> a[30011];
  for(int i = 1; i <= n; ++i){
    for(int j = 0; j <= n; ++j){
      if(j > i) continue;
      if(j == 0 and i == 1){
        a[cnt++] = {{j,i},0};
      }
      else{
        if(__gcd(i,j) == 1){
          if(i == j and i != j) continue;
          double x = (double)j/i;
          a[cnt++] = {{j,i},x};
        }
      }
    }
  }
  sort(a,a+cnt,cmp);
  for(int i = 0; i < cnt; ++i){
    fout << a[i].ff.ff << "/" << a[i].ff.ss << endl;
  }
}
