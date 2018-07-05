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
int h[100001],s[100001];

/////////query 区間加算,区間和
struct LazySeg{
	private:
	int n;
	vector<ll>node,lazy;
	public:
	LazySeg(vector<ll>v){//区間配列を渡す
		int sz=(int)v.size();
		n=1;
		while(n<sz)n*=2;
		node.resize(2*n-1);
		lazy.resize(2*n-1,0);

		for(int i=0;i<sz;i++)node[i+n-1]=v[i];
		for(int i=n-2;i>=0;i--)node[i]=node[i*2+1]+node[i*2+2];
	}

	void eval(int k,int l,int r){//自分のノード、自分の範囲[l,r)
		
		if(lazy[k]!=0){
			node[k]+=lazy[k];
		}
		if(r-l>1){
			lazy[2*k+1]+=lazy[k]/2;
			lazy[2*k+2]+=lazy[k]/2;
		}
		lazy[k]=0;
	}
	
	//区間和クエリ[a,b) (a,b,0,0,n)のように呼ぶ
	//lazyを、半分に分割しながら、区間を完全に内包するまで落としていくイメージ
	void add(int a,int b,ll x,int k,int l,int r){
		
		eval(k,l,r);
		if(b<=l || r<=a)return;
		
		else if(a<=l&&r<=b){
			lazy[k]+=(r-l)*x;
			eval(k,l,r);
		}
		
		else{
			add(a,b,x,2*k+1,l,(l+r)/2);
			add(a,b,x,2*k+2,(l+r)/2,r);		
			node[k]=node[2*k+1]+node[2*k+2];
		}
	}

	ll query(int a,int b,int k,int l,int r){
		
		eval(k,l,r);
		if(b<=l || r<=a)return 0;	
		else if(a<=l&&r<=b)return node[k];
		else{
				ll v1,v2;
				v1=query(a,b,2*k+1,l,(l+r)/2);
				v2=query(a,b,2*k+2,(l+r)/2,r);
				return v1+v2;
		}
	}

};

int main(){
	
	return 0;
} 

