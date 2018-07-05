#include <iostream>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<stack>
#include<map>
#include<cstdio>
using namespace std;
#define rep(i,a) for(int i=0;i<a;i++)
#define mp make_pair
#define pb push_back
#define P pair<int,int>
#define ll __int64
const int MAXN=1<<17;
const int INF=2147483647;
int seg[MAXN*2+1];

struct Seg{
	int n;//ƒm[ƒh‚ÌŒÂ”
	
	void init(int x){
		n=1;
		while(n<x)n*=2;//Å‰º’i‚ÌŒÂ”
		rep(i,n*2)seg[i]=INF;
	}
	void update(int i,int x){
		int now=i+n-1;
		seg[now]=x;
	
		while(now>0){
			now=(now-1)/2;
			seg[now]=min(seg[now*2+1],seg[now*2+2]);
		}
	}
	
	int find(int a,int b,int k,int l,int r){//(a,b,0,0,n)
		//cout<<"A"<<a<<" "<<b<<" "<<k<<" "<<l<<" "<<r<<endl;
		if(r<=a||b<=l)return INF;
		else if(a<=l&&r<=b)return seg[k];
		else{
			int v1,v2;
			v1=find(a,b,k*2+1,l,(l+r)/2);
			v2=find(a,b,k*2+2,(l+r)/2,r);
			return min(v1,v2);
		}
	}
	
	void debug(){
		for(int i=0;i<n*2-1;i++){
			cout<<seg[i]<<" ";
			bool ok=0;
			int t=0;
			for(int j=0;j<=17;j++){
				if(t==i)ok=1;
				t=t*2+2;
			}
			if(ok)cout<<endl;
		}	
	}
	
};
int main(){
Seg tree;
int m,q,c,x,y;
cin>>m>>q;
tree.init(m);

rep(i,q){
	cin>>c>>x>>y;
	if(c==0){
		tree.update(x,y);
	}
	else{
		int z=tree.find(x,y+1,0,0,tree.n);
		cout<<z<<endl;
	}
	
}

	return 0;
}
