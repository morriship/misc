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


int cnt[100100];

int main() {
    int n, s;
    cin >> n >> s;
    int i, j, x, y;
    rep(i, n - 1) {
        scanf("%d %d", &x, &y);
        cnt[x]++;
        cnt[y]++;
    }
    int tot = 0;
    xrep(i, 1, n + 1) {
        if (cnt[i] == 1) {
            tot++;
        }
    }
    double ans = s / double(tot) * 2.0;
    printf("%.12lf", ans);
}
