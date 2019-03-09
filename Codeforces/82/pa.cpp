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
#include<stdio.h>
#include<stdlib.h>
#define INF (1<<29)
#define EPS (1e-7)
#define two(a) (1<<(a))
#define rep(a,b) for(a=0 ; a<b ; ++a)
#define xrep(a,b,c) for(a=b ; a<c ; ++a)
#define sca(t) scanf("%d",&t)
#define scal(t) scanf("%lld",&t)
typedef long long ll;
using namespace std;

string out[5]={"Sheldon","Leonard","Penny","Rajesh","Howard"};

int main(){
	int t,i,n,in;
	in=5;
	cin >> n;
	for(; n>in ; in*=2){
		n-=in;
	}
	t=in/5;
	int w=0;
	while(n>t){
		w++;
		n-=t;
	}
	cout << out[w] << endl;
}
