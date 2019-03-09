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

ll n,fac[100000];
int flen;
map<ll,int> xmap;
ll win[100000],lose[100000];

int cmp(ll a,ll b){
	return a>b;
}

void go_win(ll);
void go_lose(ll a){
	ll &ret=win[a];
	if(ret!=-1){
		return;
	}
	ll aa=fac[a],ox(0);
	ret=0;
	int i;
	for(i=flen-2 ; i>a ; i--){
		if(aa%fac[i]==0){
			ox=1;
			go_win(i);
			if(win[i]==0){
				lose[i]=0;
				return;
			}
		}
	}
	if(!ox) lose[i]=0;
	else lose[i]=1;
}

void go_win(ll a){
	ll &ret=win[a];
	if(ret!=-1){
		return;
	}
	int i;
	ll aa=fac[a],ox(0);
	ret=0;
	for(i=flen-2 ; i>a ; i--){
		if(aa%fac[i]==0){
			ox=1;
			go_lose(i);
			if(lose[i]){
				ret=fac[i];
				return;
			}
		}
	}
	if(!ox) ret=1;
	else ret=0;
}


int main(){
	ll i,j,k;
	while(cin >> n){
		xmap.clear();
		memset(win,-1,sizeof(win));
		memset(lose,-1,sizeof(lose));
		flen=0;
		for(i=1 ; i*i<n ; i++){
			if(n%i==0){
				fac[flen++]=i;
				fac[flen++]=n/i;
			}
		}
		if(i*i==n){
			fac[flen++]=i;
		}
		sort(fac,fac+flen,cmp);
		rep(i,flen){
			xmap[fac[i]]=i;
		}
		win[flen-1]=1;
		lose[flen-1]=0;
		go_win(0);
		if(win[0]){
			if(win[0]!=1) cout << 1 << '\n' << win[0] << endl;
			else cout << 1 << '\n' << 0 << endl;
		}
		else cout << 2 << endl;
	}
}
