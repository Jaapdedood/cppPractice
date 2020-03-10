/* Runtime: 4 ms, faster than 95.69% of C++ online submissions for Longest Common Prefix.
Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Longest Common Prefix.
*/

#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::vector;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        } 

        string answer = "";    
        char c = strs[0][0];

        int j = 0;

        while(c != '\0'){
            for(int i = 0;i < strs.size(); i++){
                c = strs[0][j];
                if(c != strs[i][j]){
                    return answer;
                }
            }
            answer += c;
            j++;
        }

        return answer;
    }
};

int main(void){
    Solution solution;

    vector<string> inputs = {};

    std::cout <<  solution.longestCommonPrefix(inputs) << "\n";
    return 0;
}