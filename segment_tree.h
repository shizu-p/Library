#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    // Range Minimum Query
   private:
    int n;
    vector<int> node;
    int inf = 1e9 + 7;

   public:
    SegmentTree(const vector<int>& vec) {
        int siz = (int)vec.size();
        n = 1;
        // 2^x 分の配列を確保
        while (n < siz) n *= 2;
        node.resize(2 * n - 1, inf);
        for (int i = 0; i < siz; ++i) node[i + n - 1] = vec[i];
        for (int i = n - 2; i >= 0; --i)
            node[i] = min(node[i * 2 + 1], node[i * 2 + 2]);
    }

    // indexed-0
    void update(int idx, int val) {
        idx = idx + n - 1;
        node[idx] = val;
        while (idx > 0) {
            // 親ノード
            idx = (idx - 1) / 2;
            node[idx] = min(node[idx * 2 + 1], node[idx * 2 + 2]);
        }
    }

    // indexed-0
    // 半開区間
    //[ql,qr) -> 知りたい区間
    //[l,r) -> 調査する区間
    int RetMin(int ql, int qr, int idx = 0, int l = 1, int r = -1) {
        if (r == -1) r = n;

        if (ql >= r || qr <= l) return -inf;

        if (ql <= l && qr >= r) return node[idx];

        int vl = RetMin(ql, qr, idx * 2 + 1, l, (l + r) / 2);
        int vr = RetMin(ql, qr, idx * 2 + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
};
