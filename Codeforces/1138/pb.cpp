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

char sa[5100], sb[5100];
int d[5100];

int main() {
    int n, i, j;
    int na(0), nb(0), both(0);
    cin >> n;
    scanf("%s", sa);
    scanf("%s", sb);
    rep(i, n) {
        sa[i] -= '0';
        sb[i] -= '0';
        if (sa[i] && sb[i]) { both++; }
        if (sa[i]) { na++; }
        if (sb[i]) { nb++; }
    }
    int xa = max(nb, na);
    int xb = min(nb, na);
    // if (xa - xb - both > n / 2) {
    //     cout << -1 << endl;
    //     return 0;
    // }
    int x = xa - both;
    int y = xb - both;
    na -= both;
    nb -= both;
    int aa(n / 2), ab(n / 2);
    int ca(0), cb(0);
    if (na - both - nb > 0) {
        na = both + nb;
    }
    if (nb - both - na > 0) {
        nb = both + na;
    }
    int req = (na + nb + both) / 2;
    rep(i, n) {
        if (sa[i] && sb[i]) {
            if (na + ca < req) {
                d[i] = 1;
                ca++;
                aa--;
            } else if (nb + cb < req) {
                d[i] = 2;
                cb++;
                ab--;
            }
        }
    }
    rep(i, n) {
        if (sa[i] && sb[i] && d[i] == 0) {
            if (na >= nb) {
                d[i] = 1;
                na--;
                aa--;
            } else {
                d[i] = 2;
                nb--;
                ab--;
            }
        }
    }
    rep(i, n) {
        if (d[i] == 0) {
            if (sa[i]) {
                if (!na) {
                    d[i] = 2;
                    ab--;
                } else {
                    d[i] = 1;
                    na--;
                    aa--;
                }
            }
            if (sb[i]) {
                if (!nb) {
                    d[i] = 1;
                    aa--;
                } else {
                    d[i] = 2;
                    nb--;
                    ab--;
                }
            }
        }
    }
    rep(i, n) {
        if (d[i] == 0) {
            if (aa) {
                d[i] = 1;
                aa--;
            } else if (ab) {
                d[i] = 2;
                ab--;
            }
        }
    }
    int ccc = 0;
    rep(i, n) {
        if (d[i] == 0) {
            cout << -1 << endl;
            return 0;
        }
        if (d[i] == 1) {
            ccc ++;
        }
        if (d[i] == 2) {
            ccc --;
        }
    }
    if (ccc != 0 || na || nb){
        cout << -1 << endl;
        return 0;
    }
    rep(i, n) {
        if (d[i] == 1) {
            cout << i + 1 << ' ';
        }
    }
    cout << endl;
}
