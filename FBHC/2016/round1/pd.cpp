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

//#define DEBUG

int win[4][16][65536];
int iswin[4][16];
vector<int> winx[16];
int wins[16];
int tmp[17];
vector<int> tvec[16];
int n, before(-1);

vector<int> xn[4];

int get_best(int now) {
    if (wins[now] == 0) { return n/2 + 1; }
    int nn = Rshift(n, 1);
    for (int i = 0; i < 4; i++) {
        if (iswin[i][now]) { nn >>= 1; }
    }
    return nn + 1;
}

int get_worst(int now) {
    if (wins[now] == Lshift(1, n)-1-Lshift(1, now)) { return 1; }
    return n/2+1;
}

void get_vec(int vec_ind, int val, int now, int remain) {
    if (remain == 0) {
        xn[vec_ind].push_back(val);
        return;
    }
    for (int i = now; i <= n-remain; i++) {
        get_vec(vec_ind, (val|Lshift(1,i)), i+1, remain-1);
    }
}

void get_tmp(int num, vector<int> &vec, int val, int ind, int now) {
    if (num <= 0) {
        vec.push_back(now);
        return;
    }
    for (; ind <= n-num; ind++) {
        if (Lshift(1, ind) & val) {
            get_tmp(num-1, vec, val, ind+1, (now|(Lshift(1, ind))));
        }
    }
}

void build0() {
    if (n < 2) return;
    int i, j, k;
    rep(i, n) rep(k, winx[i].size()) {
        j = winx[i][k];
        win[0][i][Lshift(1, i) | Lshift(1, j)] = 1;
        iswin[0][i] = 1;
    }
}

void build1() {
    if (n < 4) return;
    int i, j, jj, k, kk, l, ll, now;
    rep(i, xn[2].size()) {
        now = xn[2][i];
        for (j = 0, jj = 1; j < n; j++, jj<<=1) {
            if (now & jj) {
                int flag(0);
                int valDiff(now^jj);
                for (k = 0, kk = 1; k < n; k++, kk<<=1) {
                    if ((valDiff & kk) && (wins[j] & kk)) {
                        int valDiff2(valDiff^kk);
                        for (l = 0, ll = 1; l < n; l++, ll<<=1) {
                            if ((valDiff2 & ll) && (wins[j] & ll) && win[0][l][valDiff2]) {
                                win[1][j][now] = 1;
                                iswin[1][j] = 1;
                                flag = 1;
                                break;
                            }
                        }
                        if (flag) break;
                    }
                }
            }
        }
    }
}

void build2() {
    if (n < 8) return;
    int a, b, i, ii, j, jj, k, kk, l, ll, s, now;
    rep(s, xn[3].size()) {
        now = xn[3][s];
        for (i = 0, ii = 1; i < n; i++, ii<<=1) {
            if (now & ii) {
                int flag(0);
                int now7(now^ii);
                for (j = 0, jj = 1; j < n; j++, jj<<=1) {
                    if ((now7 & jj) && (wins[i] & jj)) {
                        int x1(jj);
                        int now6(now7^jj);
                        tvec[0].clear();
                        get_tmp(4, tvec[0], now6, 0, 0);
                        auto &vec0 = tvec[0];
                        rep(a, vec0.size()) {
                            int x4 = vec0[a];
                            int x2(now6^x4);
                            for (k = 0, kk = 1; k < n; k++, kk<<=1) {
                                if ((x4 & kk) && (wins[i] & kk) && win[1][k][x4]) {
                                    for (l = 0, ll = 1; l < n; l++, ll<<=1) {
                                        if ((ll & x2) && (wins[i] & ll) && win[0][l][x2]) {
                                            win[2][i][now] = 1;
                                            iswin[2][i] = 1;
                                            flag = 1;
                                            break;
                                        }
                                    }
                                    if (flag) break;
                                }
                            }
                            if (flag) break;
                        }
                        if (flag) break;
                    }
                }
            }
        }
    }
}

void build3() {
    if (n < 16) return;
    int a, b, c, i, ii, j, jj, k, kk, l, ll, s, now;
    now = Lshift(1, 16) - 1;
    for (i = 0, ii = 1; i < n; i++, ii<<=1) {
        if (now & ii) {
            int flag(0);
            int now15(now^ii);
            auto &vec0 = tvec[0];
            vec0.clear();
            get_tmp(8, vec0, now, 0, 0);
            rep(a, vec0.size()) {
                int x8(vec0[a]);
                int now7(now15^x8);
                auto &vec1 = tvec[1];
                vec1.clear();
                get_tmp(4, vec1, now7, 0, 0);
                for (j = 0, jj = 1; j < n; j++, jj<<=1) {
                    if ((x8 & jj) && (wins[i] & jj) && win[2][j][x8]) {
                        rep(b, vec1.size()) {
                            int x4(vec1[b]);
                            int now3(now7^x4);
                            auto &vec2 = tvec[2];
                            vec2.clear();
                            get_tmp(2, vec2, now3, 0, 0);
                            for (k = 0, kk = 1; k < n; k++, kk<<=1) {
                                if ((x4 & kk) && (wins[i] & kk) && win[1][k][x4]) {
                                    rep(c, vec2.size()) {
                                        int x2(vec2[c]);
                                        int now1(now3^x2);
                                        if (wins[i] & now1) {
                                            for (l = 0, ll = 1; l < n; l++, ll<<=1) {
                                                if ((x2 & ll) && (wins[i] & ll) && win[0][l][x2]) {
                                                    iswin[3][i] = 1;
                                                    flag = 1;
                                                    break;
                                                }
                                                if (flag) break;
                                            }
                                            if (flag) break;
                                        }
                                    }
                                    if (flag) break;
                                }
                            }
                            if (flag) break;
                        }
                        if (flag) break;
                    }
                }
                if (flag) break;
            }
        }
    }
}

void init() {
    int i, j, k;
    if (n == before) return;
    rep(i, 5) xn[i].clear();
    rep(i, n) { xn[0].push_back(Lshift(1, i)); }
    if (n >= 2) { get_vec(1, 0, 0, 2); }
    if (n >= 4) { get_vec(2, 0, 0, 4); }
    if (n >= 8) { get_vec(3, 0, 0, 8); }
}

int main() {
    int t, tt, in, i, j;
    readi(tt);
    xrep(t, 1, tt+1) {
        readi(n);
        memset(win, 0, sizeof(win));
        memset(wins, 0, sizeof(wins));
        memset(iswin, 0, sizeof(iswin));
        rep(i, n) { winx[i].clear(); }
        init();
        rep(i, n) rep(j, n) {
            readi(in);
            if (in) { winx[i].push_back(j), wins[i] |= Lshift(1, j); }
        }
        build0();
        build1();
#ifdef DEBUG
        cout << "-----------------------" << endl << endl;
        rep(i, n) {
            cout << "iswin: " << iswin[1][i] << endl;
        }
#endif
        build2();
#ifdef DEBUG
        cout << endl;
        rep(i, n) {
            cout << "iswin: " << iswin[2][i] << endl;
        }
        cout << endl << endl;
#endif
        build3();
#ifdef DEBUG
        rep(i, n) {
            cout << "iswin: " << iswin[3][i] << endl;
        }
#endif
        cout << "Case #" << t << ": " << endl;
        rep(i, n) {
            cout << get_best(i) << ' ' << get_worst(i) << endl;
        }
    }
}
