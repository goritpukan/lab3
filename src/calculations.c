#include <math.h>
#include "../include/calculations.h"

double calcP(const double a, const double b) {
    return b - (pow(a, 2) / 3.0);
}

double calcQ(const double a, const double b, const double c) {
    return ((2.0 * pow(a, 2)) / 27.0) - ((a * b) / 3.0) + c;
}

double calcDiscriminant(const double p, const double q) {
    return (pow(p, 3) / 27.0) + (pow(q, 2) / 4.0);
}

YResults calcY(const double a, const double b, const double c) {
    const double q = calcQ(a, b, c);
    const double p = calcP(a, b);
    const double discriminant = calcDiscriminant(p, q);

    YResults yResults = {};
    yResults.error = 0;

    if (discriminant > 0.0) {

        yResults.isComplex = 1;
        const double u = cbrt((-(q / 2.0)) + sqrt(discriminant));
        const double v = -(p / (3.0 * u));

        yResults.y1 = u + v;
        yResults.y2 = -((u + v) / 2.0) + ((sqrt(3.0) * (u - v)) / 2.0);
        yResults.y3 = -((u + v) / 2.0) - ((sqrt(3.0) * (u - v)) / 2.0);
    }else if(discriminant == 0.0) {
        yResults.isComplex = 0;
        yResults.y1 = (3.0 * q) / p;
        yResults.y2 = -((3.0 * q) / (2.0 * p));
        yResults.y3 = yResults.y2;
    }else if(discriminant < 0.0){
        const double rWithoutSqrt = -(pow(p, 3) / 27.0);
        if(rWithoutSqrt >= 0.0) {
            const double r = sqrt(rWithoutSqrt);
            const double phi = acos((-q / (2.0 * r)));
            if(isnan(phi)) {
                yResults.error = 1;
                return yResults;
            }
            yResults.isComplex = 0;
            yResults.y1 = 2.0 * fabs(cbrt(r) * cos(phi / 3.0));
            yResults.y2 = 2.0 * fabs(cbrt(r)) * cos((phi + ( 2.0 * M_PI)) / 3.0);
            yResults.y3 = 2.0 * fabs(cbrt(r)) * cos((phi + ( 4.0 * M_PI)) / 3.0);
        }else {
            yResults.error = 1;
        }
    }
    return yResults;
}
XResults calcX(const double a, const double b, const double c) {
    XResults xResults = {};

    const YResults yResults = calcY(a, b, c);
    if(isnan(yResults.y1) || isnan(yResults.y2) || isnan(yResults.y3)) {
        xResults.error = 1;
        return xResults;
    }
    if(yResults.error) {
        xResults.error = yResults.error;
        return xResults;
    }
    xResults.x1 = yResults.y1 - a / 3.0;
    xResults.x2 = yResults.y2 - a / 3.0;
    xResults.x3 = yResults.y3 - a / 3.0;

    return xResults;
}