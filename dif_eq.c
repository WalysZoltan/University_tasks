#include <stdio.h>
#include <stdlib.h>

#define H 0.01



int main(void)
{
    int     i;
    double     *t;
    double     *s;
    double     *x;
    double     *y;
    double     a;
    double     b;
    double      t1;
    double      t2;
    int     n;
    
    printf("y'' + (1 / x) * y' = 1 / x,                0.5 < x < 1\ny'(0.5) = 3, y(1) = 1\n");
    a = 0.5;
    b = 1;
    n = (b -a) / H;
    t = (double*)malloc(sizeof(double) * (n + 1));
    s = (double*)malloc(sizeof(double) * (n + 1));
    x = (double*)malloc(sizeof(double) * (n + 1));
    y = (double*)malloc(sizeof(double) * (n + 1));
    x[0] = a;
    i = 1;
    while (i < n + 1)
    {
        x[i] = x[i - 1] + H;
        i++;
    }
    s[0] = 1;
    t[0] = -3 * H;
    i = 1;
    while (i < n + 1)
    {
        t1 = -1 / (H * H) - 1 / (x[i] * 2 * H);
        t2 = -2 / (H * H) - (-1 / (H * H) + 1 / (x[i] * 2 * H)) * s[i - 1];
        s[i] = t1 / t2;
        t[i] = ((-1 / (H * H) + 1 / (x[i] * 2 * H)) * t[i - 1] + 1 / x[i]) / (-2 / (H * H) - (-1 / (H * H) + 1 / (x[i] * 2 * H)) * s[i - 1]);
        i++;
    }
    i = n;
    y[i] = 1;
    i--;
    while (i >= 0)
    {
        y[i] = s[i] * y[i + 1] + t[i];
        i--;
    }
    i = 0;
    while (i < n + 1)
    {
        printf("%f %f\n", x[i], y[i]);
        i++;
    }
    free(t);
    free(s);
    free(x);
    free(y);
    return 0;
}
