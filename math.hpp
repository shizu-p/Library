#include <stdint.h>

#include <cassert>
#include <limits>
#include <vector>

#include "Matrix.hpp"
namespace shizu {
namespace math {

unsigned long long safe_multiply(unsigned long long a, unsigned long long b) {
    const unsigned long long MAX_64 =
        std::numeric_limits<unsigned long long>::max();
    const unsigned long long OVERFLOW_VALUE = 3e18;
    if (MAX_64 / b > a) {
        return OVERFLOW_VALUE;
    } else {
        return a * b;
    }
}

unsigned long long floor_sqrt(unsigned long long x) {
    assert(x != 0);
    unsigned long long left = 0;
    unsigned long long right = 3e18;
    while (left <= right) {
        unsigned long long mid = (right + left) / 2;
        if (mid * mid > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return right;
}

unsigned long long safe_pow(unsigned long long base,
                            unsigned long long exponent) {
    assert(base != 0);
    if (exponent == 0) {
        return 1;
    }

    const unsigned long long MAX_LL =
        std::numeric_limits<unsigned long long>::max();
    const unsigned long long OVERFLOW_VALUE = 3e18;
    long long result = 1;
    for (int i = 0; i < exponent; ++i) {
        if (result > MAX_LL / base) {
            return OVERFLOW_VALUE;
        }
        result *= base;
    }
    return result;
}

std::vector<long long> eratosthenes(long long x) {
    std::vector<long long> is_prime(x + 1, true);
    std::vector<long long> ret;
    for (long long p = 2; p <= x; ++p) {
        if (!is_prime[p]) continue;
        ret.emplace_back(p);
        for (long long q = p * 2; q <= x; q += p) {
            is_prime[q] = false;
        }
    }
    return ret;
}

unsigned long long modpow(unsigned long long a, unsigned long long n,
                          unsigned long long mod) {
    assert(mod >= 1);
    unsigned long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

template <typename T>
T positive_mod(T a, T b) {
    T res = a % b;
    if (res < 0) {
        res += b;
    }
    return res;
}

template <typename T>
T floor_div(T a, T b) {
    assert(b != 0);
    T res = a / b;
    if ((a % b != 0) && ((a < 0) != (b < 0))) {
        res--;
    }
    return res;
}

template <typename T>
T ceil_div(T a, T b) {
    assert(b != 0);

    T res = a / b;
    if ((a % b != 0) && ((a < 0) == (b < 0))) {
        res++;

        return res;
    }
}

// 正負関係なくx+yの床関数を求める 整数型以外許容しない
template <typename T>
T safe_floor_mid(const T x, const T y) {
    return (x & y) + ((x ^ y) >> 1);
}

}  // namespace math
}  // namespace shizu