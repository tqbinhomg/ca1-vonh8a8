#include <stdio.h>
#include <time.h>

// Tách N thành (n-1) + n và gọi đệ quy 2 nhánh
long long sum_exponential(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    return sum_exponential(n - 1) + n;
}

// lặp lại lồng nhau
long long sum_quadratic(int n)
{
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            sum++; // Mỗi lần tăng 1 đơn vị
        }
    }
    return sum;
}

// thông thường hay viết
long long sum_linear(int n)
{
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

// Công thức toán học Gauss (O(1) - Độ phức tạp hằng số)
long long sum_constant(long long n)
{
    return n * (n + 1) / 2;
}

long long sum_tail(int n, long long acc) {
    if (n == 0) return acc;
    return sum_tail(n - 1, acc + n);
}

int main()
{
    // time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    int n = 43315;
    clock_t start, end;
    double time_taken;
    start = clock();
    printf("Tong sum_exponential: %lld\t\t", sum_exponential(n));
    end = clock();
    time_taken = ((double)(end - start));
    printf("Time sum_exponential: %.5f\t%.5f\n", time_taken, time_taken / CLOCKS_PER_SEC);

    start = clock();
    printf("Tong sum_quadratic  : %lld\t\t", sum_quadratic(n));
    end = clock();
    time_taken = ((double)(end - start));
    printf("Time sum_quadratic. : %.5f\t%.5f\n", time_taken, time_taken / CLOCKS_PER_SEC);

    start = clock();
    printf("Tong sum_linear     : %lld\t\t", sum_linear(n));
    end = clock();
    time_taken = ((double)(end - start));
    printf("Time sum_linear     : %.5f\t%.5f\n", time_taken, time_taken / CLOCKS_PER_SEC);

    start = clock();
    printf("Tong sum_constant   : %lld\t\t", sum_constant(n));
    end = clock();
    time_taken = ((double)(end - start));
    printf("Time sum_constant   : %.5f\t%.5f\n", time_taken, time_taken / CLOCKS_PER_SEC);
}
