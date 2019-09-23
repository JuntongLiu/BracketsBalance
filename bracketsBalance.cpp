/*
 *   C++ implementation:
 *
 *   When running, these program prompt user to type in a string with brackets
 *   and the program will check to see if those brackets contained in the string
 *   are balanced or not.
 *
 *   {[()]}, {sdf[e()r]erq}             balanced
 *   {[]}}[  }abc()                     not balanced
 *
 * It is interesting to compare the C, C++ and C# implementations.
 *
 *
 *                                           Juntong Liu
 *                                                                 2019-09-22
 */

#include <iostream>
#include <string>
#include <map>
#include <stack>

std::map<char, char>charMap { {'(', ')'},
                              {'[', ']'},
                              {'{', '}'}
};

std::stack<char>charStack;

int main()
{
    std::string myString;
    std::cout << "Type in a string with brackets." << "\n";
    std::cin >> myString;

    bool balanced = true;
    int numberOfBrackets = 0;
    for (auto ch : myString)                                 //  Walk the string
    {
       for (const auto &[first, second] : charMap)
       {
           if(ch == first)                                   // Check to see if the char is an open bracket
           {
              charStack.push(ch);                            // ...yes, push it onto stack
              numberOfBrackets++;
              continue;
           }
           else if(ch == second)                             // Check to see if the ch is a close bracket
           {
               numberOfBrackets++;
                if(!charStack.empty())                       // ...yes, and make sure the stack is not empty
                {
                    if(charStack.top() != first)             // Check to see if the close bracket match the one on the stack
                    {
                        balanced = false;                    // ... no, mismatch
                        break;
                    }
                    else                                     // ... yes, got a match
                        charStack.pop();
                }
                else                                         // ... we have more close bracket
                {
                    balanced = false;
                    break;
                }
            }
        }
     }
     if(!charStack.empty() || balanced == false)              // Finally, make decision
     {
          std::cout << "The brackets are NOT balanced." << std::endl;
     }
     else if(numberOfBrackets == 0)
          std::cout << "No brackets in the string." << std::endl;
     else
          std::cout << "The brackets are Balanced!" << std::endl ;

    return 0;
}