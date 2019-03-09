#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define swap(a,b) ( (a^=b) , (b^=a) , (a^=b) )
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))
#define maxL (10000000>>5)+1
#define mod 1000000007
typedef long long ll;
using namespace std;

ll in[5100];
int dp[5100][5001];
int pre[5100];

int main() {
    int n, k, i, j;
    cin >> n >> k;
    rep(i, n) {
        cin >> in[i];
    }
    in[n] = -10000;
    sort(in, in + n + 1);
    int st = 1, ed;
    pre[0] = -1;
    xrep(ed, 1, n + 1) {
        while(in[ed] > in[st] + 5) { st++; }
        pre[ed] = st - 1;
    }

    xrep(i, 1, k + 1) {
        dp[i][0] = 0;
        xrep(j, 1, n + 1) {
            dp[i][j] = max(dp[i-1][j-1] + 1, dp[i-1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
            if (pre[j] == -1) {
                dp[i][j] = j;
            } else {
                dp[i][j] = max(dp[i][j], dp[i-1][pre[j]] + (j - pre[j]));
            }
        }
    }
    cout << dp[k][n] << endl;
}
