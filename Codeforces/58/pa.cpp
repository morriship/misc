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
	int i,j,k;
	string str;
	string s("hello");
	cin >> str;
	for(i=j=0 ; str[j] && s[i] ; i++,j++){
		for(; str[j] && str[j]!=s[i] ; j++);
		if(!str[j]) break;
	}
	if(s[i]) cout << "NO" << endl;
	else cout << "YES" << endl;
}
