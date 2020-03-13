/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
 * Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Valid Parentheses.
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

using std::unordered_map;
using std::string;
using std::stack;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> hashMap = {
            {'}', '{'},
            {')', '('},
            {']', '['}
        };
    
        stack<char> myStack;
        
        for(char &c : s){   /*range-based for loop. Great article:
                             * https://www.cprogramming.com/c++11/c++11-ranged-for-loop.html
                             * "if you want to avoid copying large objects,
                             * and the underlying iterator supports it,
                             * you can make the loop variable a reference."
                             */
            if (hashMap.count(c)){ // current char is a closing bracket
                if(myStack.empty()){
                    return false;
                }
                else{
                    char topElement = myStack.top(); // can't just ... = ..pop I guess
                    myStack.pop();

                    if(topElement != hashMap[c]){ // unexpected closing bracket
                        return false;
                    }
                }
            }
            else{ // current char is an open bracket
                myStack.push(c);
            }
        }
        if(myStack.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    Solution solution;

    string input = "{{))[][][]{}[][][]}}";
    std::cout << solution.isValid(input) << "\n";


    return 0;
}