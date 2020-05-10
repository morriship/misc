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
#define mset(x) memset(x, 0, sizeof(x))
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


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    string s;
    cin >> n;
    vector<string> st;
    vector<string> ed;
    ll sum(0);
    vector<pair<int, string> > mi;
    int i;
    rep(i, n) {
        cin >> s;
        int rn(0), re(0);
        int j;
        int balance(0);
        int now(0);
        rep(j, sz(s)) {
            if (s[j] == '(') sum++;
            else sum--;
        }
        rep(j, sz(s)) {
            if (s[j] == '(') now++;
            else now--;
            rn = min(rn, now);
        }
        balance = now;
        now = 0;
        for (j = sz(s)-1; j >= 0; j--) {
            if (s[j] == ')') now++;
            else now--;
            re = min(re, now);
        }
        if (rn == 0) {
            st.push_back(s);
        } else if (re == 0) {
            ed.push_back(s);
        } else {
            // mi.push_back({{rn, re}, balance});
            mi.push_back({-balance, s});
        }
    }
    ll r(0), l(0);
    vector<string> w;
    rep(i, sz(st)) w.pb(st[i]);
    sort(mi.begin(), mi.end());
    rep(i, sz(mi)) w.pb(mi[i].second);
    rep(i, sz(ed)) w.pb(ed[i]);
    rep(i, sz(w)) {
        string s(w[i]);
        int j;
        rep(j, sz(s)) {
            if (s[j] == '(') r++;
            else r--;
            if (r < 0) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    if (r != 0) {
        cout << "No" << endl;
        return 0;
    }
    for (i = sz(w)-1; i>=0;i--) {
        string s(w[i]);
        int j;
        for (j = sz(s)-1; j >= 0; j--) {
            if (s[j] == ')') l++;
            else l--;
            if (l < 0) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
