// C program to print values of INT_MAX and INT_MIN
// we have to include limits.h for results in C
#include <stdio.h>
#include <limits.h>

int main() {
    printf("%d\n", divide(10,3));
    printf("%d\n", divide(7,-3));
    return 0;
}

/// O(log(dividend))
int divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == -1 || divisor == 0)
        return INT_MAX;
    unsigned int temp = dividend,sum = divisor,ret = 0,cnt = 1,sign = 1;
    if(temp & INT_MIN)
        temp = ~(temp -1);/// get absolute value
    if(sum & INT_MIN)
        sum = ~(sum -1);///get absolute value
    if(temp < sum)
        return 0;
    unsigned int  ts = sum;
    while(temp - sum >= sum) sum <<= 1,cnt <<=1;
    while(sum >= ts)
   {
        if(sum <= temp)
        {
            ret += cnt;
           temp -= sum;
        }
        sum >>= 1,cnt >>= 1;
    }
    if((dividend^divisor)&INT_MIN)/// check if the result should be negative.
        ret = (~ret) + 1;
    return ret;
}