#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define readi(a) scanf("%d", &a)
#define swap(a,b) ( (a^=b) , (b^=a) , (a^=b) )
#define min(a,b) ( a < b ? a : b )
#define max(a,b) ( a > b ? a : b )
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))
#define maxL (10000000>>5)+1
#define mod 1000000007
typedef long long ll;
using namespace std;

double p;
double prob[3010][3010];
double sump[3010][3010];
double dp[3010];

void mkprob(int n) {
    int i, j;
    memset(prob, 0, sizeof(prob));
    prob[0][0] = 1;
    xrep(i, 1, n+1) {
        prob[i][0] = prob[i-1][0] * (1-p);
        xrep(j, 1, i+1) {
            prob[i][j] = prob[i-1][j] * (1-p) + prob[i-1][j-1] * p;
        }
    }
}

void mksump(int n, int k) {
    int i, j;
    memset(sump, 0, sizeof(sump));
    xrep(i, 1, n+1) {
        double sum(prob[i][i]);
        sump[i][i] = sum;
        for (j = i-1; j >= k; j--) {
            sum += prob[i][j];
            sump[i][j] = sum;
        }
    }
}

double calAns(int n, int k) {
    int i, j;
    memset(dp, 0, sizeof(dp)); 
    xrep(i, k, n+1) {
        dp[i] = 0;
        for (j = 0; j <= i-k; j++) {
            dp[i] = max(dp[i], dp[j] + sump[i-j][k]);
        }
    }
    return dp[n];
}

int main() {
    int tt, t, n, k;
    cin >> tt;
    xrep(t, 1, tt+1) {
        cin >> n >> k >> p;
        mkprob(n);
        mksump(n, k);
        double ans = calAns(n, k);
        cout << "Case #" << t << ": ";
        printf("%.9lf\n", ans);
    }
}
