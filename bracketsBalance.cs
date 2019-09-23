//
//         C# implementation:
//
// When running, this program prompt user to type in a string with brackets 
// and the program will check to see if those brackets contained in the string 
// are balanced or not.
//  
//    {[()]}, {sdf[e()r]erq}             balanced
//    {[]}}[  }abc()                     not balanced
//
//
//
// It is interesting to compare the C, C++ and C# implementations.
//
//
//                                                       Juntong Liu
//                                                                        2019.04.15

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SkalProj_Datastrukturer_Minne
{
    class Program
    {
        static void Main()
        {
            CheckParanthesis();
            
        }
        
        
        static void CheckParanthesis()
        {
            /*
             * Use this method to check if the paranthesis in a string is balanced or in or in balanced.
             * Example of correct: (()), {}, [({})]
             * Example of incorrect: (()]), [), {[()}]
             */
            
            Dictionary<char, char> ParanthesisPairs = new Dictionary<char, char>()
                    {
                        {'(', ')'},
                        {'[', ']'},
                        {'{', '}'}
                    };

            // declare a stack
            Stack<char> charStack = new Stack<char>();
            Console.WriteLine("Please type in the brackets pattern:");
            string userInput = Console.ReadLine();
            bool isGood = true;
            if (!string.IsNullOrEmpty(userInput))
            {
                foreach (char c in userInput)                                // walk through the chars on the string
                {
                    if (ParanthesisPairs.Keys.Contains(c))                  // if it is a key(a open paranthesis) in the dictionary
                    {
                        charStack.Push(c);                                  // push it onto the stack
                    }
                    else if (ParanthesisPairs.Values.Contains(c))           // If it is a value(a closing bracket) in the dictionary
                    {
                        if (charStack.Count > 0)                            // Make sure that there is a key on the stack, so we do not operate with empty stack
                        {
                            if (c == ParanthesisPairs[charStack.First()])   // ...further check to see if the first(last pushed opening bracket) on the stack match the key
                            {
                                charStack.Pop();                            // if so, we get a march, and pop the open bracket(key) off the stack (this pair is done)
                            }
                            else
                            {
                                break;                                      // a mismatch, there still a key(open bracket) on stack, that means pattern is bad
                            }
                        }
                        else
                        {
                            isGood = false;                                 // mismatch, there are more values than keys.
                            break;
                        }
                    }
                    else
                    {
                        continue;
                    }
                }

                if (charStack.Count == 0 && isGood)
                {
                    Console.WriteLine("\nThe brackets pattern " + userInput + " is good!\n");
                }
                else
                {
                    Console.WriteLine("\nThe brackets pattern " + userInput + " is NOT good!\n");
                }
            }
            else
            {
                Console.WriteLine("Wrong input! try again!");
            }
         }
    }
}
