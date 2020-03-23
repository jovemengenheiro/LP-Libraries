#include <stdio.h>
#include "our_operators.h"

// -------

int succ(int x) {return x+1;}
int pred(int x) {return x-1;}
int twice(int x) {return x*2;}
int half(int x) {return x/2;}
int is_zero(int x) {return x==0;}
int is_not_zero(int x) {return x!=0;}
int sign(int x){return (x >= 0) - (x <= 0);}
int square(int x){return x*x;}

int sum(int x, int y) {return x+y;}
int difference(int x, int y) {return x-y;}
int product(int x, int y) {return x*y;}
int quotient(int x, int y) {return x/y;}
int modulo(int x, int y) {return x%y;}
int difference_reverse(int x, int y) {return y-x;}
int quotient_inverse(int x, int y) {return y/x;}
int modulo_inverse(int x, int y) {return y%x;}

int less(int x, int y) {return x<y;}
int greater(int x, int y) {return x>y;}
int less_or_equal(int x, int y) {return x<=y;}
int greater_or_equal(int x, int y) {return x>=y;}
int equal(int x, int y) {return x==y;}
int not_equal(int x, int y) {return x!=y;}
int max(int x, int y) {return x <= y ? y : x;}
int min(int x, int y) {return x <= y ? x : y;}

double dbl_succ(double x) {return x+1;}
double dbl_pred(double x) {return x-1;}
double dbl_twice(double x) {return x*2;}
double dbl_half(double x) {return x/2;}
int dbl_is_zero(double x) {return x==0;}
int dbl_is_not_zero(double x) {return x!=0;}
int dbl_sign(double x){return (x >= 0) - (x <= 0);}
double dbl_inverse(double x){return 1/x;}
double dbl_square(double x){return x*x;}

double dbl_sum(double x, double y) {return x+y;}
double dbl_difference(double x, double y) {return x-y;}
double dbl_product(double x, double y) {return x*y;}
double dbl_quotient(double x, double y) {return x/y;}
double dbl_difference_reverse(double x, double y) {return y-x;}
double dbl_quotient_inverse(double x, double y) {return y-x;}

int dbl_less(double x, double y) {return x<y;}
int dbl_greater(double x, double y) {return x>y;}
int dbl_less_or_equal(double x, double y) {return x<=y;}
int dbl_greater_or_equal(double x, double y) {return x>=y;}
int dbl_equal(double x, double y) {return x==y;}
int dbl_not_equal(double x, double y) {return x!=y;}
double dbl_max(double x, double y) {return x <= y ? y : x;}
double dbl_min(double x, double y) {return x <= y ? x : y;}
