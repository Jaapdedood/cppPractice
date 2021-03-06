/* Return the index of the first occurrence of needle
 * in haystack, or -1 if needle is not part of haystack.
 */

#include <iostream>
#include <string>
using std::string;

class Solution {
public:
    int strStrBruteForce(string haystack, string needle){
        if(!needle.size()){
            return 0;
        }
        if(!haystack.size() || haystack.size() < needle.size()){
            return -1;
        }
        for(int i = 0; i <= haystack.size() - needle.size(); i++){
            int j = 0;
            for(; j < needle.size(); j++){
                if(haystack[i+j] != needle[j]){
                    break;
                }
            }
            if(j == needle.size()){
                return i;
            }
        }
    return -1;
    }

    int strStrKMP(string haystack, string needle){
        if(!needle.size()){
            return 0;
        }
        if(!haystack.size() || haystack.size() < needle.size()){
            return -1;
        }

        // Make prefix length array
        int prefixLen = 0;
        int needleLen = needle.size();

        int prefixLenArray[needleLen +1];
        prefixLenArray[0] = -1;

        for(int i = 1; i < needleLen; i++){
            if(needle[i] == needle[prefixLen]){
                prefixLen++;
            } 
            else{
                prefixLen = 0;
            }

            prefixLenArray[i+1] = prefixLen;
        }
        for(int i : prefixLenArray){
            std::cout << i << ' '; 
        }
        std::cout << '\n';
        // End making prefix length array

        int i = 0;
        for(; i <= haystack.size() - needle.size(); i++){
            int j = 0;
            for(; j < needle.size(); j++){
                if(haystack[i+j] != needle[j]){
                    i = j - prefixLenArray[j];
                    std::cout << i << ' ' << j << '\n';
                    break;
                }
            }
            if(j == needle.size()){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution solution;

    string haystack = "abcxxxabcy";
    string needle = "bba";
    

    std::cout << solution.strStrKMP(haystack, needle) << '\n';
    return 0;
}