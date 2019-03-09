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
#define scal(t) scanf("%lld",&t)
typedef long long ll;
using namespace std;

struct In{
	int rank,v;
}in[100011];

int cmp(In a,In b){
	return a.v>b.v;
}

int main(){
	int n,i,j,a,b,an,bn;
	while(cin >> n){
		queue<int> aq,bq;
		a=b=an=bn=0;
		rep(i,n){
			sca(in[i].v);
			in[i].rank=i+1;
		}
		sort(in,in+n,cmp);
		a=b=an=bn=0;
		int ox(0);
		aq.push(in[0].rank);
		an++;
		for(i=1 ; i<n ; i+=2){
			ox^=1;
			if(ox){
				bq.push(in[i].rank);
				bn++;
				if(i<n-1){
					bq.push(in[i+1].rank);
					bn++;
				}
			}
			else{
				aq.push(in[i].rank);
				an++;
				if(i<n-1){
					aq.push(in[i+1].rank);
					an++;
				}
			}
		}
		cout << an << endl;
		cout << aq.front();
		aq.pop();
		while(!aq.empty()){
			printf(" %d",aq.front());
			aq.pop();
		}
		puts("");
		cout << bn << endl;
		cout << bq.front();
		bq.pop();
		while(!bq.empty()){
			printf(" %d",bq.front());
			bq.pop();
		}
		puts("");
	}
}
