#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

using std::unordered_map;
using std::string;
using std::stack;

class Solution {
private:
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
                    char topElement = myStack.pop();
                    if(topElement != hashMap[c]{
                        return false
                    }
                }
            }
            else{ // current char is an open bracket
                myStack.push(c);
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