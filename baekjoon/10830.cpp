// https://www.acmicpc.net/problem/10830
#include "_fileRead.hpp"
GNUES::FileRead f("10830.txt");

#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

Matrix Identity(5, std::vector<int>(5, 0));

Matrix mulMatrix(const Matrix& a, const Matrix& b, int divisor)
{
    auto size = std::min(a.size(), b.size());
    Matrix mul(size, std::vector<int>(size, 0));
    for (int i=0; i<size; ++i) for (int j=0; j<size; ++j)
    {
        for (int k=0; k<size; ++k)
            mul[i][j] += (a[i][k] * b[k][j]) % divisor;
        mul[i][j] %= divisor;
    }
    return mul;
}

// 빠른 제곱 O(log(exp))
Matrix pow(Matrix& a, long long exp, int divisor, int size)
{
    // 0 제곱 - 단위행렬
    if (exp == 0)
        return Identity;

    Matrix val = pow(a, exp/2, divisor, size);
    Matrix mul = mulMatrix(val, val, divisor);

    if (exp & 1)
        return mulMatrix(mul, a, divisor);
    else
        return mul;
}

int main()
{
    int n;
    long long b;
    std::cin >> n >> b;

    Matrix A(n, std::vector<int>(n, 0));

    int num;
    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j)
    {
        std::cin >> num;
        A[i][j] =  num;

        if (i==j)
            Identity[i][j] = 1;
    }

    Matrix ans = pow(A, b, 1000, n);

    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            std::cout << ans[i][j] << ' ';
        }
        std::cout << '\n';
    }
}