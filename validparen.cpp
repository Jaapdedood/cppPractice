#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    bool isValid(string s) {
        while(!s.empty()){
            if(s.length() == 1){
                return false;
            }

            bool valid = false;

            for(int i = 0; i < s.length() - 1; i++){
                string nextTwo;
                nextTwo = s[i];
                nextTwo += s[i+1];

                if(nextTwo == "()" || nextTwo == "[]"  || nextTwo == "{}" ){
                    s.erase(i,2);
                    valid = true;
                    break;
                }
            }

            if(valid == false){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution solution;

    string input = "{{[][][]{}[][][]}}";
    std::cout << solution.isValid(input) << "\n";


    return 0;
}