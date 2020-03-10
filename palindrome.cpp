#include <iostream>

class Solution {
public:
    bool isPalindrome(int x){
        int reversed = 0;

        if(x<0 || x % 10 == 0 && x != 0) return 0;

        // push
        while(x > reversed){
            reversed = reversed*10 + (x % 10);
            x = x/10;
        }

        if(x == reversed || x == reversed/10){
            return 1;
        }
        return 0;
    }
};

int main() {
    Solution solution;

    std::cout << solution.isPalindrome(12321) << '\n';
    std::cout << solution.isPalindrome(196) << '\n';
    std::cout << solution.isPalindrome(10) << '\n';
}