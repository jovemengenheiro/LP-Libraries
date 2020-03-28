#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <assert.h>

#include "our_ints.h"
#include "our_ints2.h"
#include "our_operators.h"

int **ints2_new(int rows, int cols)
{
  int **result = (int **) malloc(rows * sizeof(int *));
  int *p  = ints_new(rows * cols);
  for (int i = 0; i < rows; i++)
    result[i] = p + i * cols;
  return result;
}

void ints2_get(int **a, int rows, int cols)
{
  ints_get_some(*a, rows * cols);
}

void ints2_get_by_row_column_some(int **a, int n)
{
  int i, j;
  while (n--)
  {
    scanf("%d%d", &i, &j);
    scanf("%d", &a[i][j]);
  }
}

void ints2_get_by_row_column(int **a)
{
  int i, j, x;
  while (scanf("%d%d%d", &i, &j, &x) != EOF)
    a[i][j] = x;
}

void ints2_printf(char *fmt, int **a, int rows, int cols)
{
  for (int i = 0; i < rows; i++)
    ints_printfln(fmt, a[i], cols);
}

void ints2_exchange_rows(int **a, int x, int y)
{
  int *m = a[x];
  a[x] = a[y];
  a[y] = m;
}

void ints2_column(int **a, int rows, int cols, int x, int *b)
{
  for (int i = 0; i < rows; i++)
    b[i] = a[i][x];
}

void ints2_multiply_by_array(int **a, int rows, int cols, const int *b, int *c)
{
  for (int i = 0; i < rows; i++)
    c[i] = ints_inner_product(a[i], b, cols);
}

void ints2_accumulate(int **a, int rows, int cols, int **z)
{
  for (int i = 0; i < rows; i++)
    z[i][0] = 0;
  for (int j = 1; j < cols; j++)
    z[0][j] = 0;
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      z[i+1][j+1] = a[i][j] + z[i][j+1] + z[i+1][j] - z[i][j];
}

void test_ints2(void)
{
  int r, c;
  int **m;
  int **acc;
  scanf("%d%d", &r, &c);
  m = ints2_new(r, c);
  ints2_get(m, r, c);
  ints2_printf("%3d", m, r, c);
  acc = ints2_new(r+1, c+1);
  ints2_accumulate(m, r, c, acc);
  ints2_printf("%5d", acc, r+1, c+1);
}

void ints2_transpose(int **a, int rows, int columns, int **b)
{
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      b[j][i] = a[i][j];
}

void ints2_multiply(int **a, int rows_a, int cols_a,
  int **b, int rows_b, int cols_b,
  int **c)
{
  assert(cols_a == rows_b);
  int **z = ints2_new(cols_b, rows_b);
  ints2_transpose(b, rows_b, cols_b, z);
  for (int i = 0; i < rows_a; i++)
    for (int j = 0; j < cols_b; j++)
      c[i][j] = ints_inner_product(a[i], z[j], cols_a);
}

//---------------------------------

void test_ints2_printf(void)
{
  int r, c;
  int **m;
  scanf("%d%d", &r, &c);
  m = ints2_new(r, c);
  ints2_get(m, r, c);
  ints2_printf("%4d", m, r, c);
}

void test_ints2_get_by_row_column_some(void)
{
  int r, c;
  int **m;
  scanf("%d%d", &r, &c);
  m = ints2_new(r, c);
  int n = int_get();
  ints2_get_by_row_column_some(m, n);
  ints2_printf("%4d", m, r, c);
}

void test_ints2_get_by_row_column(void)
{
  int r, c;
  int **m;
  scanf("%d%d", &r, &c);
  m = ints2_new(r, c);
  ints2_get_by_row_column(m);
  ints2_printf("%4d", m, r, c);
}

void test_exchange_rows(void)
{
  int r, c;
  scanf("%d%d", &r, &c);
  int **a = ints2_new(r, c);
  ints2_get(a, r, c);
  ints2_printf("%4d", a, r, c);
  int x, y;
  while (scanf("%d%d", &x, &y) != EOF)
  {
    ints2_exchange_rows(a, x, y);
    ints2_printf("%4d", a, r, c);
  }
}

void test_ints_multiply(void)
{
  int x = int_get();
  int *a = ints_new(x);
  int n = ints_get_some(a, x);
  int *b = ints_new(x);
  int m = ints_get_some(b, x);
  assert (x == n);
  assert (n == m);
  int *c = ints_new(x);
  int k = ints_zip(a, b, n, product, c);
  assert(k == n);
  ints_println(c, n, " ");
}

void test_ints_add(void)
{
  int x;
  while (scanf("%d", &x) != EOF)
  {
    int *a = ints_new(x);
    int *b = ints_new(x);
    int n = ints_get_some(a, x);
    int m = ints_get_some(b, x);
    assert (x == n);
    assert (n == m);
    ints_zip(a, b, n, sum, a);
    ints_println(a, n, " ");
  }
}

void test_ints_accumulate(void)
{
  int a[1000];
  int n = ints_get(a);
  int b[1001];
  b[0] = 0;
  int m = 1;
  m += ints_zip(a, b, n, sum, b+1);
  ints_println(b, m, " ");
}

void test_ints2_transpose(void)
{
  int r, c;
  scanf("%d%d", &r, &c);
  int **a = ints2_new(r, c);
  ints2_get(a, r, c);
  ints2_printf("%4d", a, r, c);
  int **b = ints2_new(c, r);
  ints2_transpose(a, r, c, b);
  ints2_printf("%4d", b, c, r);
}

void test_ints2_multiply(void)
{
  int **a;
  int **b;
  int **c;
  int r_a, c_a;
  int r_b, c_b;
  scanf("%d%d", &r_a, &c_a);
  a = ints2_new(r_a, c_a);
  ints2_get(a, r_a, c_a);
  scanf("%d%d", &r_b, &c_b);
  b = ints2_new(r_b, c_b);
  ints2_get(b, r_b, c_b);
  assert(c_a == r_b);
  //ints2_putf("%3d", a, r_a, c_a);
  //ints2_putf("%3d", b, r_b, c_b);
  c = ints2_new(r_a, c_b);
  ints2_multiply(a, r_a, c_a, b, r_b, c_b, c);
  ints2_printf("%6d", c, r_a, c_b);
}



