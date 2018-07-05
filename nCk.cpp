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
#define ll long long
const ll M=1000000007;
const int MAX_N=1000;
ll F[MAX_N];
ll IF[MAX_N];

ll invl(ll a,ll b,ll m){//ap-2乗るを返す
	ll tmp=1;
	
	while(b){
		if(b&1){
			tmp=(tmp*a)%m;
		}
		a=(a*a)%m;
		b/=2;
	}

	return tmp%m;
}

void init(ll m){
	F[0]=1;
	IF[0]=1;

	for(ll i=1;i<MAX_N;i++){
		F[i]=(F[i-1]*i)%m;
		IF[i]=invl(F[i],m-2,m)%m;//逆元を、フェルマーの小定理を利用して求める
	}
}

ll C(int n,int r,int m){

	if(n<0||r<0||r>n)return (ll)0;
	if(r>n/2)r=n-r;
	
	//cout<<F[n]<<" "<<IF[r]<<" "<<IF[n-r]<<endl;
	ll ret=F[n]*IF[r]%m*IF[n-r]%m;
	return ret;
}


int main(){

	return 0;
}
