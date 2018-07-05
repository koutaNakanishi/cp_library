#include <iostream>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<map>
#include<cstdio>
using namespace std;
#define rep(i,a) for(int i=0;i<a;i++)
#define mp make_pair
#define pb push_back
#define P pair<int,int>
#define ll __int64
int n,m;
int G[2000][2000];
bool used[300000];
int heiro;
int topo[300000];//トポロジカルソートされた要素番号が入る




void visit(int now){
	if(heiro)return ;
	if(used[now]){
		heiro=1;
		return ;
	}

	else if(!u[now]){
		used[now]=1;
		rep(i,G[now].size()){
			//cout<<now+1<<" "<<G[now][i]+1<<endl;
			visit(G[now][i]);
			used[G[now][i]]=0;
		}
		used[now]=0;
		u[now]=1;
		topo[pos++]=now;
	}
}

int main(){
cin>>n>>m>>s;
rep(i,n)G[i].resize(0);
int a,b;
rep(i,m){
	cin>>a>>b;
	//if(a==b)continue
	//if(t.find(mp(a,b))!=t.end())continue;
	a--;b--;
	G[a].push_back(b);
	//t.insert(mp(a,b));
}



rep(i,n){
	if(!u[i]){
	visit(i);

	}
}

if(heiro){
	cout<<-1<<endl;
	return 0;
}

	return 0;
}