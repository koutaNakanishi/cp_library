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

#define ll __int64
//#define ll long long
#define P pair<ll,ll>

ll q,h,s,d,n;

int main(){
	cin>>q>>h>>s>>d>>n;
	q*=4;//1l
	h*=2;//1l
	
	ll ans=0;
	ll one=1000000000000;
	ll two=one;

	one=min(one,q);
	one=min(one,h);
	one=min(one,s);
	two=min(one*2,d);
	
	ans=n*two/2;
	if(n%2)ans+=one;
	cout<<ans<<endl;
 
	return 0;
}