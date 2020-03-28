#ifndef _ints2_h
#define _ints2_h

int **ints2_new(int rows, int cols);
void ints2_get(int **a, int rows, int cols);
void ints2_get_by_row_column_some(int **a, int n);
void ints2_get_by_row_column(int **a);
void ints2_printf(char *fmt, int **a, int rows, int cols);

void ints2_exchange_rows(int **a, int r1, int r2);
void ints2_column(int **a, int rows, int cols, int x, int *b);
void ints2_multiply_by_array(int **a, int rows, int cols, const int *b, int *c);

void ints2_transpose(int **a, int rows, int columns, int **b);
void ints2_multiply(int **a, int rows_a, int cols_a,
  int **b, int rows_b, int cols_b,
  int **c);

void ints2_accumulate(int **a, int rows, int cols, int **z);

//---------------------------------

void test_ints2(void);

void test_ints2_printf(void);
void test_ints2_get_by_row_column_some(void);
void test_ints2_get_by_row_column(void);
void test_exchange_rows(void);

void test_ints2_add_rows(void);
void test_ints2_transpose(void);
void test_ints2_multiply(void);

void test_one(char x);

void test_ints_multiply(void);
void test_ints_add(void);
void test_ints_accumulate(void);


#endif
