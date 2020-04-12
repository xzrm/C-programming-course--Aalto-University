#include <stdio.h>
#include "anydata.h"

AnyData setDouble(double value)
{
    AnyData data;
    data.type = DOUBLE;
    data.value.dval = value;
    return data;
}

AnyData setInt(int value)
{
    AnyData data;
    data.type = INT;
    data.value.ival = value;
    return data;
}

AnyData setByte(char value)
{
    AnyData data;
    data.type = BYTE;
    data.value.bval = value;
    return data;
}

void printDouble(double val) {
    printf("D:%lf", val);
}

void printInt(int val) {
    printf("I:%d", val);
}

void printByte(char val) {
    printf("B:%d", val);
}

void printValue(AnyData val)
{
    switch (val.type)
    {
    case BYTE:
        printByte(val.value.bval);
        break;
    case INT:
        printInt(val.value.ival);
        break;
    case DOUBLE:
        printDouble(val.value.dval);
        break;
    case UNDEF:
        printf("--\n");
        break;
    }
}