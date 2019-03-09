#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
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

long long n,len,xlen,ylen;
char x[1111],y[1111];

ll gcd(ll a,ll b){
	return a%b==0?b:gcd(b,a%b);
}

int main(){
	long long a,b,c,w,ax,bx,i,j,k;
	while(cin >> n){
		a=b=0;
		cin >> x >> y;
		xlen=strlen(x);
		ylen=strlen(y);
		len=xlen*ylen/gcd(xlen,ylen);
		c=n%len;
		w=n/len;
		int ox=1;
		ax=bx=0;
		for(i=1 ; i<=len ; i++){
			if(i>c) ox=0;
			if(x[ax]=='R'){
				if(y[bx]=='P'){
					b+=w+ox;
				}
				else if(y[bx]=='S'){
					a+=w+ox;
				}
			}
			if(x[ax]=='P'){
				if(y[bx]=='R') a+=w+ox;
				if(y[bx]=='S') b+=w+ox;
			}
			if(x[ax]=='S'){
				if(y[bx]=='P') a+=w+ox;
				if(y[bx]=='R') b+=w+ox;
			}
			ax++;
			bx++;
			if(ax==xlen) ax=0;
			if(bx==ylen) bx=0;
		}
		cout << b << ' '<< a << endl;
	}
}
