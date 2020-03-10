#include <iostream>
#include <stdlib.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648

class Solution {
public:
    //32 bit signed -> -2^31 to 2^31 - 1
    int reverse(int x) {
        int temp = 0;
        int rev = 0;
        int i = 0;

        while(x){
            // push
            temp = x % 10;
            x = x/10;

            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && temp > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && temp < -8)) return 0;
            rev = rev*10 + temp;
        }

        return rev;
    }
};

int main(){
    Solution solution;

    std::cout << solution.reverse(123) << '\n';

    return 0;
}