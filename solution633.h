#include <math.h>

// Given a non-negative integer c decide whether 
// there're two integers a and b such that a*a + b*b = c.

class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c % 4 == 3)
            return false;   // due to modular arithmetic 

        long int left = 0, right = sqrt(c);
        // This process converges on c if it can be expressed as x*x+y*y
        while (left <= right) {
            long int temp = left * left + right * right;
            if (temp > c)    // if temp is too big decrement right
                --right;
            else if (temp < c)   // if temp is too small increment left
                ++left;
            else    // if temp is c return true
                return true;
        }   

        return false;
    }
};

