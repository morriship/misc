template<class T, int SZ> class SegmenetTree {
private:
    T val[SZ*4];
    pair<int, int> range[SZ*4];
    void clear() { memset(val, 0, sizeof(val)); }
    void build(int idx, int l, int r) {
        range[idx] = {l, r};
        if (l != r) {
            int mi = (l + r) >> 1;
            build(idx + idx, l, mi);
            build(idx + idx + 1, mi + 1, r);
        }
    }
    int getIdx(int pos) {
        int l(1), r(SZ), idx(1);
        while (l < r) {
            int mi((l + r) >> 1);
            idx <<= 1;
            if (mi >= pos) { r = mi; }
            else { ++idx, l = mi + 1; }
        }
        return idx;
    }

public:
    SegmenetTree() { build(1, 1, SZ), clear(); }
};
