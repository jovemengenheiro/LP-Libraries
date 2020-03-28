#ifndef our_operators_h
#define our_operators_h

int succ(int x);
int pred(int x);
int twice(int x);
int half(int x);
int is_zero(int x);
int is_not_zero(int x);
int sign(int x);
int square(int x);

int sum(int x, int y);
int difference(int x, int y);
int product(int x, int y);
int quotient(int x, int y);
int modulo(int x, int y);
int difference_reverse(int x, int y);
int quotient_inverse(int x, int y);
int modulo_inverse(int x, int y);

int less(int x, int y);
int greater(int x, int y);
int less_or_equal(int x, int y);
int greater_or_equal(int x, int y);
int equal(int x, int y);
int not_equal(int x, int y);
int max(int x, int y);
int min(int x, int y);

double dbl_succ(double x);
double dbl_pred(double x);
double dbl_twice(double x);
double dbl_half(double x);
int dbl_is_zero(double x);
int dbl_is_not_zero(double x);
int dbl_sign(double x);
double dbl_inverse(double x);
double dbl_square(double x);

double dbl_sum(double x, double y);
double dbl_difference(double x, double y);
double dbl_product(double x, double y);
double dbl_quotient(double x, double y);
double dbl_difference_reverse(double x, double y);
double dbl_quotient_inverse(double x, double y);

int dbl_less(double x, double y);
int dbl_greater(double x, double y);
int dbl_less_or_equal(double x, double y);
int dbl_greater_or_equal(double x, double y);
int dbl_equal(double x, double y);
int dbl_not_equal(double x, double y);
double dbl_max(double x, double y);
double dbl_min(double x, double y);

#endif
