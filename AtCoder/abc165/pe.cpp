#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) ((a)<<(b))
#define Rshift(a,b) ((a)>>(b))
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define sz(a) int(a.size())
#define swap(a,b) ( (a^=b) , (b^=a) , (a^=b) )
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))
#define maxL (10000000>>5)+1
#define mod 1000000007
#define vi vector<int>
#define pii pair<int, int>
#define mii map<int, int>
#define si set<int>
#define pb push_back
typedef long long ll;
using namespace std;


int used[100100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    if (n % 2 == 1) {
        int i;
        rep(i, m) {
            cout << i + 1 << ' ' << n - i << endl;
        }
    } else {
        ll st = n / 2; 
        ll ed = st + 1;
        while (m--) {
            ll x = ed - st;
            x = min(x, n - x - 2);
            if (used[x]) {
                cout << st << ' ' << ed + 1 << endl;
            } else {
                cout << st << ' ' << ed << endl;
            }
            used[x] = 1;
            st--;
            ed++;
        }
    }
}
