nclude<iostream>
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

string name[101],str;
char in[15];
int pi[101],ta[101],gi[101];

int main(){
	int i,j,k,n,w;
	while(cin >> n){
		memset(pi,0,sizeof(pi));
		memset(ta,0,sizeof(ta));
		memset(gi,0,sizeof(gi));
		rep(i,n){
			cin >> w >> name[i];
			rep(j,w){
				scanf("%s",in);
				if(in[0]==in[1] && in[1]==in[3] && in[3]==in[4] && in[4]==in[6] && in[6]==in[7]){
					ta[i]++;
				}
				else if(in[0]>in[1] && in[1]>in[3] && in[3]>in[4] && in[4]>in[6] && in[6]>in[7]){
					pi[i]++;
				}
				else{
					gi[i]++;
				}
			}
		}
		int first(1);
		cout << "If you want to call a taxi, you should call:";
		int w(0);
		rep(i,n){
			if(ta[i]>w) w=ta[i];
		}
		rep(i,n){
			if(ta[i]==w){
				if(!first) cout << ',';
				first=0;
				cout << ' ' << name[i];
			}
		}
		cout << '.' << endl;
		cout << "If you want to order a pizza, you should call:";
		w=0,first=1;
		rep(i,n) w=max(w,pi[i]);
		rep(i,n){
			if(pi[i]==w){
				if(!first) cout << ',';
				first=0;
				cout << ' ' << name[i];
			}
		}
		cout << '.' << endl;
		cout << "If you want to go to a cafe with a wonderful girl, you should call:";
		w=0,first=1;
		rep(i,n) w=max(w,gi[i]);
		rep(i,n){
			if(gi[i]==w){
				if(!first) cout << ',';
				first=0;
				cout << ' ' << name[i];
			}
		}
		cout << '.' << endl;
	}
}
