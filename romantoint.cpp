#include <stdlib.h>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
using std::unordered_map;

// IV IX XL XC CD  CM
// 4  9  40 90 400 900

// I V X  L  C   D   M      
// 1 5 10 50 100 500 1000

// usually +
// I before V and X
// X before L and C
// C before D and M

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hash = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;
        
        for(int i = 0;i < s.length();i++){
            if(hash[s[i]] < hash[s[i+1]]){
                result = result + (hash[s[i+1]] - hash[s[i]]);
                i++;
            }
            else {
                result = result + hash[s[i]];
            }
        }
        return result;
    }
};

int main(){
    Solution solution;

    string input = "MMMDCCXXIV";
    int romanInt = solution.romanToInt(input);
    cout << romanInt << "\n";
}