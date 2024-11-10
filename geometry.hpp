#include <math.h>
namespace shizu {
const long double PI = acosl(-1);

// 度数法から弧度法に変換
// 割り算を逆元の掛け算で行っている
template <typename T>
long double to_radian(T theta) {
    return theta * pow(180.0, -1) * PI;
}
// 弧度法から度数法に変換
template <typename T>
long double to_degree(T theta) {
    return theta * pow(PI, -1) * 180.0;
}

// 回転行列
template <typename T>
std::pair<T, T> rotation_matrix(T x, T y, T theta) {
    T retx = x * cos(theta) - y * sin(theta);
    T rety = x * sin(theta) + y * cos(theta);
    return std::pair<T, T>(retx, rety);
}

// 平行移動
template <typename T>
std::pair<T, T> parallel_movement(T x, T y, T dx, T dy) {
    T retx = x + dx;
    T rety = y + dy;
    return std::pair<T, T>(retx, rety);
}
}  // namespace shizu