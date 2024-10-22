#include <cassert>
#include <vector>

namespace shizu {
namespace math {
template <typename T>
struct Matrix {
    int n, m;                         // n*m行列
    std::vector<std::vector<T>> vec;  // 受け取る行列
    std::vector<std::vector<T>> e;    // 単位行列(n*n)
    Matrix(std::vector<std::vector<T>> vec) : vec(vec) {
        n = this.vec.size();
        m = this.vec[0].size();
        // 掛け算にNM^2かかるので制限している
        assert(n * m * m <= 10010010);
        e.resize(n);
        for (int i = 0; i < n; ++i) {
            e[i].resize(n);
        }
        for (int i = 0; i < n; ++i) {
            assert((int)vec[i].size() == m);
        }
        for (int i = 0; i < n; ++i) {
            e[i][i] = 1;
        }
    }

    Matrix power(int x) {
        // Matrix power
        // O(N* M^2 * log x)
        assert(x != 0);
        assert(n == m);
        Matrix ret(e);
        Matrix a(vec);
        while (x > 0) {
            if (x & 1) ret = ret * a;
            a = a * a;
            x >>= 1;
        }
        return ret;
    }

    Matrix operator*(const Matrix &left, const Matrix &right) {
        // Matrix Multiply
        // O(N * M^2)
        const std::vector<std::vector<T>> &l = left.vec;
        const std::vector<std::vector<T>> &r = right.vec;
        int N = l.size();
        int M = r.size();
        for (int i = 0; i < N; ++i) {
            assert((int)l[i].size() == M);
        }
        for (int i = 0; i < M; ++i) {
            assert((int)r[i].size() == N);
        }
        std::vector<std::vector<T>> ret(N, std::vector<T>(M));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                T res = 0;
                for (int mi = 0; mi < M; ++mi) {
                    res += l[i][j] * r[i][j];
                }
                ret[i][j] = res;
            }
        }
        Matrix result(ret);
        return result;
    }

    int size() { return vec.size(); }
};
}  // namespace math
}  // namespace shizu