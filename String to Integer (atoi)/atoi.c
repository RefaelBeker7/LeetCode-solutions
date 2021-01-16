// C program to print values of INT_MAX and INT_MIN
// we have to include limits.h for results in C
#include <stdio.h>
#include <limits.h>

int main() {
    printf("%d\n", myAtoi("42"));
    printf("%d\n", myAtoi("-42"));
    printf("%d\n", myAtoi("-91283472332"));
    return 0;
}

int myAtoi(char * str){
    long long int ret = 0;
    int sign = 1;
    
    while(str[0] == ' ') str++;
    
    if (str[0] == '-') {
        sign = -1;
        str++;
    } else if (str[0] == '+') {
        str++;
    }

    while(str[0] >= 48 && str[0] <= 57) {
        ret *= 10;
        ret += str[0] - 48;

        // printf("%d\n", ret);
        if (ret * sign > INT_MAX) {
            return INT_MAX;
        }
        if (ret * sign < INT_MIN) {
            return INT_MIN;
        }
        str++;
    }
    return ret * sign;
}