#include <iostream>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<map>
#include<deque>
#include<cstdio>
using namespace std;
#define rep(i,a) for(int i=0;i<a;i++)
#define mp make_pair
#define pb push_back
#define ll __int64
//#define ll long long

#define P pair<ll,ll>

struct unionFind{
	int n;
	vector<int>par;
	vector<int>rank;
	unionFind(int x){
		n=x;
		par.resize(x);
		rank.resize(x);
		rep(i,n){
			par[i]=i;
			rank[i]=0;
		}
	}
	
	int find(int x){
		if(par[x]==x)return x;
		else return par[x]=find(par[x]);
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	
	void unite(int x,int y){//x,y‚ğ•¹‡
		x=find(x);
		y=find(y);
		if(x==y)return;
		if(rank[x]<rank[y]){
			par[x]=par[y];
		}
		else{
			par[y]=x;
			if(rank[x]==rank[y])rank[x]++;
		}
	}
};

int main(){

	return 0;
}
