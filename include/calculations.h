#ifndef CALCULATIONS_H
#define CALCULATIONS_H

typedef struct {
    double y1;
    double y2;
    double complex1;
    double complex2;
    double y3;
    char isComplex;
    char error;
} YResults;

typedef struct {
    double x1;
    double x2;
    double complex1;
    double complex2;
    double x3;
    char isComplex;
    char error;
} XResults;

double calcP (const double a, const double b);
double calcQ (const double a, const double b, const double c);
double calcDiscriminant(const double p, const double q);
YResults calcY(const double a, const double b, const double c);
XResults calcX(const double a, const double b, const double c);

#endif
