#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<sstream>
#include<vector>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<queue>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define swap(a,b) ( (a^=b) , (b^=a) , (a^=b) )
typedef long long ll;
using namespace std;

int gcd(int a, int b){ return a%b ? gcd(b,a%b) : b; }

int ans[2001];
char in[2011];

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    int i,j;
    memset(ans,0,sizeof(ans));
    rep(i,n) {
        scanf("%s",in);
        rep(j,m) {
            char now = in[j];
            if (now == 'U'){
                if (i % 2 == 0) ans[j]++;
            }
            else if (now == 'L') {
                if (j >= i) {
                    ans[j-i]++;
                }
            }
            else if (now == 'R') {
                if (m - j - 1 >= i) {
                    ans[j+i]++;
                }
            }
        }
    }
    rep(i,m) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
}
