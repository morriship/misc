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
typedef long long ll;
using namespace std;

int main(){
	int n,k,l,c,d,p,nl,np,ans,now;
	ans=0x7FFFFFFF;
	while(cin >> n >> k >> l >> c >> d >> p >> nl >> np){
		now=l*k/nl;
		now=min(now,c*d);
		now=min(now,p/np);
		cout << now/n << endl;
	}
}
