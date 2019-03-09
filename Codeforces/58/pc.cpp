#include<iostream>
#include<sstream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<set>
#include<queue>
#define LINF 1ll<<60
#define INF 1<<29
#define EPS 1e-7
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
typedef long long ll;
using namespace std;

int main(){
	int i,j,k,n,w,ww,t;
	int can[100005];
	memset(can,0,sizeof(can));
	cin >> n;
	w=n/2;
	ww=n%2;
	for(i=0 ; i<w ; i++){
		cin >> t;
		if(t>=i) can[t-i]++;
	}
	if(ww){
		cin >> t;
		if(t>=w) can[t-w]++;
	}
	for(i=w-1 ; i>=0 ; i--){
		cin >> t;
		if(t>=i) can[t-i]++;
	}
	int ans=0;
	for(i=1 ; i<=100004 ; i++) if(can[i]>ans) ans=can[i];
	cout << n-ans << endl;
}
