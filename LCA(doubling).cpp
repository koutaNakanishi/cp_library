#include <iostream>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<stack>
#include<map>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define rep(i,a) for(int i=0;i<a;i++)
#define mp make_pair
#define pb push_back
#define P pair<int,int>
#define ll __int64
//#define __int64 long long
const int MA=110000;
const int LOG_MA=30;
vector<int>G[MA];
int next2[LOG_MA+5][MA];//j”Ô–Ú‚Ì—v‘f‚Ì2^i‚Ìe
int h[MA];
int hh[MA];
bool used[MA];

void dfs(int p,int c){
	used[p]=1;
	h[p]=c;
	rep(i,G[p].size()){
		int ne=G[p][i];
		if(used[ne])continue;
		next2[0][ne]=p;
		dfs(ne,c+1);

	}
}

int chiled(int x,int k){//–Ø‚Ìx‚Ìk‚Âã‚ğ•Ô‚·
	for(int i=LOG_MA;i>=0;i--){
		if(x==-1)return -1;
		if((k>>i)&1)x=next2[i][x];
	}
	return x;
}

int lca(int a,int b){
	if(h[a]<h[b]){//b‚Ì‚Ù‚¤‚ª[‚¢‚Ì‚ÅAb‚ğˆø‚«ã‚°‚é
		int s=h[b]-h[a];
		b=chiled(b,s);
	}
	else if(h[a]>h[b]){
		int s=h[a]-h[b];
		a=chiled(a,s);
	}
	
	int l=0,r=h[b],mid;
	mid=(l+r)/2;

	rep(i,LOG_MA){
		if(chiled(a,mid)==chiled(b,mid))r=mid;
		else l=mid;
		mid=(l+r)/2;
	}
	if(chiled(a,mid)!=chiled(b,mid))mid++;
	//if(chiled(a,mid)==chiled(b,mid)&&chiled(a,mid+1)==chiled(b,mid+1)&&chiled(a,mid+1)!=-1)mid++;
	return chiled(a,mid);
}

int main(){
	int n;
	cin>>n;
	rep(i,n-1){
		int a,b;
		cin>>a>>b;
		a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(0,0);//0‚ğª‚Æ‚İ‚È‚µ‚Ädfs‚·‚é
	next2[0][0]=-1;
	
	rep(i,n)hh[i]=h[i];
	
	for(int i=0;i<LOG_MA;i++){
		for(int j=0;j<n;j++){
			if(next2[i][j]==-1)next2[i+1][j]=-1;
			else next2[i+1][j]=next2[i][next2[i][j]];
		}
	}

	int q;
	cin>>q;
	rep(i,q){
		int a,b;
		cin>>a>>b;	
		a--;b--;
		int ret=lca(a,b);
		//cout<<ret<<" :"<<a<<" "<<b<<h[a]<<" "<<h[b]<<" "<<h[ret]<<endl;
		cout<<hh[a]+hh[b]-hh[ret]*2+1<<endl;
	}
	return 0;
}

