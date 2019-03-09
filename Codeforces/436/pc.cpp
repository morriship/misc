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

int n,m,k,w;

char in[1001][11][11];
int t[1001];
int dist[1001][1001];
int use[1001];
int d[1001];
int out[1001];

int main() {
    cin >> n >> m >> k >> w;
    int nm = n*m;
    int i,j,a,b;
    memset(t,0,sizeof(t));

    rep(i,k) {
        rep(j,n) {
            scanf("%s",in[i][j]);
        }
    }
    rep(i,k) xrep(j,i+1,k) {
        int cnt(0);
        rep(a,n) rep(b,m) {
            if (in[i][a][b] != in[j][a][b]) {
                cnt++;
            }
        }
        dist[i][j] = dist[j][i] = min(cnt*w, nm);
    }
    memset(use,0,sizeof(use));
    use[0] = 1;
    out[0] = 0;
    xrep(i,1,k) {
        d[i] = dist[0][i];
        if (d[i] != nm) t[i] = 1;
    }
    xrep(i,1,k) {
        int ind(-1),minx(INF);
        rep(j,k) {
            if (!use[j] && d[j] < minx) {
                minx = d[j];
                ind = j;
            }
        }
        if (ind == -1) break;
        use[ind] = 1;
        out[i] = ind;
        rep(j,k) {
            if (!use[j] && d[j] > dist[ind][j]) {
                d[j] = dist[ind][j];
                t[j] = ind + 1;
            }
        }
    }
    int ans(nm);
    rep(i,k) ans += d[i]; 
    cout << ans << endl;
    rep(i,k) {
        cout << out[i]+1 << ' ' << t[out[i]] << endl;
    }
}
