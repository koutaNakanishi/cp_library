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
#define P pair<int,int>
int n;
int h[110000];
int w[110000];
int dp[100000];

struct Bit{
	vector<int>bit;
	public:
	Bit(int x){
		bit.resize(x);
	}

	int sum(int i){
		int s=0;
		while(i>0){
			s+=bit[i];
			i=i-(i&-i);
		}
		return s;
	}
	
	void change(int i,int x){
		while(i<=n){
			bit[i]=max(x,bit[i]);
			i=i+(i&-i);//Å‘å‚ðŽæ‚è‚È‚ª‚ç“o‚Á‚Ä‚¢‚­
		}
	}

};

const int INF=-1;
int ans=0;
int main(){
	cin>>n;
	rep(i,n)cin>>h[i]>>w[i];

	Bit b(111111);
	
	rep(i,n){
		b.query(i);
	}
	cout<<ans<<endl;
	return 0;
}

