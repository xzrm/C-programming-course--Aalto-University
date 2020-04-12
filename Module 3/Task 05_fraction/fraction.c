// #include &lt;assert.h&gt;
#include "assert.h"
#include "fraction.h"
#include <stdlib.h>

struct fraction_st
{
    unsigned int num, denom;
};

/* Algorithm for determining greatest common divisor, needed in (d) */
/* The function returns gcd between the two parameters, u and v */

/* Taken from http://en.wikipedia.org/wiki/Binary_GCD_algorithm */
unsigned int gcd(unsigned int u, unsigned int v) {
    // simple cases (termination)
    if (u == v)
        return u;

    if (u == 0)
        return v;

    if (v == 0)
        return u;

    // look for factors of 2
    if (~u & 1) // u is even
    {
        if (v & 1) // v is odd
            return gcd(u >> 1, v);
        else // both u and v are even
            return gcd(u >> 1, v >> 1) << 1;
    }

    if (~v & 1) // u is odd, v is even
        return gcd(u, v >> 1);

    // reduce larger argument
    if (u > v)
        return gcd((u - v) >> 1, v);

    return gcd((v - u) >> 1, u);
}

Fraction *setFraction(unsigned int numerator, unsigned int denominator)
{
    Fraction *f = malloc(sizeof(struct fraction_st));
    f->num = numerator;
    f->denom = denominator;

    return f;
}

void freeFraction(Fraction *f)
{
    assert(f);
    free(f);
}

unsigned int getNum(const Fraction *f)
{
    return f->num;
}

unsigned int getDenom(const Fraction *f)
{
    return f->denom;
}

int compFraction(const Fraction *a, const Fraction *b)
{   
    float diff = a->num * b->denom - b->num * a->denom;


    if (diff < 0)
    {
        return -1;
    }
    else if (diff > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Fraction* addFraction(const Fraction *a, const Fraction *b){
    int numerator = a->num * b->denom + a->denom * b->num;
    int denominator = a->denom * b->denom;

    return setFraction(numerator, denominator);
}

void reduceFraction(Fraction *val){
    int res = gcd(val->num, val->denom);
    val->num = val->num / res;
    val->denom = val->denom / res;
}

void printFraction(const Fraction *val) {
    printf("%u/%u\n", val->num, val->denom);
}