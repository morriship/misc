#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<stack>
#define INF (1<<29)
#define EPS (1e-7)
#define two(a) (1<<(a))
#define rep(a,b) for(a=0 ; a<b ; ++a)
#define xrep(a,b,c) for(a=b ; a<c ; ++a)
#define sca(t) scanf("%d",&t)
#define scal(t) scanf("%I64d",&t)
#define mod 1000000007
typedef long long ll;
using namespace std;

int main(){
	int n,m,k,i,j;
	while(cin >> n >> m >> k){
		if(k==1 || k>n){
			ll ans(m);
			rep(i,n-1){
				ans=(ans*m)%mod;
			}
			cout << ans << endl;
			continue;
		}
		if(k<n && k%2==1){
			cout << ((ll)(m)*m)%mod << endl;
			continue;
		}
		if(k<n){
			cout << m << endl;
			continue;
		}
		ll ans(m);
		n=(n+1)>>1;
		for(i=1 ; i<n ; i++){
			ans=(ans*m)%mod;
		}
		cout << ans << endl;
	}
}
