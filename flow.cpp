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
//#define __int64 long long
#define P pair<ll,ll>
int n,g,e;
int a[102];

const int MAX_V=102;
const int INF=1000000000;
struct edge{
	public:
int to;
int cap;
int rev;
	edge(int a,int b,int c){
		to=a;
		cap=b;
		rev=c;
	}
};//行先、要領、逆辺
vector<edge>G[MAX_V];
bool used[MAX_V];

void add_edge(int from,int to,int cap){//fromからtoへ向かう容量capの辺を追加する
	G[from].push_back(edge(to,cap,G[to].size()));
	G[to].push_back(edge(from,0,G[from].size()-1));
}

int dfs(int v,int t,int f){//v今の頂点
	if(v==t)return f;
	used[v]=1;
	for(int i=0;i<G[v].size();i++){
		edge &e=G[v][i];
		if(!used[e.to]&&e.cap>0){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s,int t){
	int flow=0;
	for(;;){
		rep(j,MAX_V)used[j]=0;
		int f=dfs(s,t,INF);
		if(f==0)return flow;
		flow+=f;
	}
	return flow;
}	

int main(){
	cin>>n>>g>>e;
	rep(i,g)cin>>a[i];
	rep(i,e){
		int x,y;
		cin>>x>>y;
		add_edge(x,y,1);
		add_edge(y,x,1);
		
	}
	rep(i,g){
		add_edge(a[i],n,1);
		add_edge(n,a[i],1);
	}
	cout<<max_flow(0,n)<<endl;
	return 0;
} 

