#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::vector;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string answer = "";    
        bool common = true;
        char c = strs[0][0];

        for(int j = 0; j < 10; j++){
            for(int i = 0;i < strs.size(); i++){
                c = strs[0][j];
                if(c != strs[i][j]){
                    return answer;
                }
            }
            answer += c;
        }

        return answer;
    }
};

int main(void){
    Solution solution;

    vector<string> inputs = {"hello", "helicopter", "hell", "helter"};

    std::cout <<  solution.longestCommonPrefix(inputs) << "\n";
    return 0;
}