#include <stdio.h>
#include <math.h>

// 方程式 f(x) = cos(x) - x^2
double f(double x) {
    return cos(x) - pow(x, 2);
}

// 導関数 f'(x) = -sin(x) - 2x
double df(double x) {
    return -sin(x) - 2 * x;
}

// ニュートン法による根の計算
double newton(double x0, double tol, int max_iter) {
    double x = x0;
    double h = f(x) / df(x);
    int iter = 0;

    while (fabs(h) >= tol && iter < max_iter) {
        h = f(x) / df(x);
        x = x - h;  // 次の近似値を計算
        iter++;
	printf("iter: %d, error: %le\n",iter,h);
    }

    if (iter >= max_iter) {
        printf("Error: Maximum iterations reached.\n");
        return -1;  // 収束しない場合はエラーを返す
    }
    printf("iter:%d\n",iter);
    return x;
}

int main() {
    double x0 = 0.5;  // 初期値
    double tol = 0.00001;  // 許容誤差
    int max_iter = 1000;  // 最大反復回数

    double root = newton(x0, tol, max_iter);
    if (root != -1) {
        printf("An approximate root is: %f\n", root);
    }

    return 0;
}
