#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<queue>
#include<stack>
#define INF (1<<29)
#define EPS (1e-7)
#define two(a) (1<<(a))
#define rep(a,b) for(a=0 ; a<b ; ++a)
#define xrep(a,b,c) for(a=b ; a<c ; ++a)
#define sca(t) scanf("%d",&t)
#define scal(t) scanf("%lld",&t)
typedef long long ll;
using namespace std;

int in[15];

int cmp(int a,int b){
	return a>b;
}

int main(){
	int i,j,k,t,now;
	while(cin >> t){
		rep(i,12) cin >> in[i];
		sort(in,in+12,cmp);
		now=0;
		if(t<=0){
			cout << 0 << endl;
			continue;
		}
		rep(i,12){
			now+=in[i];
			if(now>=t) break;
		}
		if(i<12){
			cout << i+1 << endl;
		}
		else cout << -1 << endl;
	}
}
