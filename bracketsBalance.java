/*
 *  Java implementation: 
 * 
 *   When running, this program prompt user to type in a string with brackets 
 *   and the program will check to see if those brackets contained in the string 
 *   are balanced or not.
 * 
 *   {[()]}, {sdf[e()r]erq}             balanced
 *   {[]}}[  }abc()                     not balanced
 *  
 *  
 *   It is interesting to compare the C, C++, C# and Java implementations. 
 * 
 * 
 *                                           Juntong Liu    
 *                                                                 2019-09-26
 *
 */

import java.util.*;
//import java.util.HashMap;
//import java.util.Scanner;
//import java.lang.Iterable;
//import java.util.Stack;
//import java.util.EmptyStackException;
//import java.util.Collection;
//import java.util.List;
//import java.util.Set;

public class bracketsBalance 
{
       // main method begins execution
        public static void main(String[] args)
        {
            // create a map for the brackets
            Map<Character, Character> charMap = new HashMap<Character, Character>();     // declare a map
            charMap.put('(', ')');                                      // populate the map
            charMap.put('[', ']');
            charMap.put('{', '}');

            boolean balanced = true;
            int numberOfBrackets = 0;
            Stack<Character> keyStack = new Stack<Character>();
            Collection<Character> values = charMap.values();      
          
            Scanner input = new Scanner(System.in);                   // for user type in a string
            System.out.println("Enter a string with brackets:");
 
            String userString = input.nextLine();

            char[] charArray = new char[userString.length()];
            userString.getChars(0, userString.length(), charArray, 0); // convert the string to a char array

            for (char ch : charArray)                                  // walk the string to find any bracket
            {
               if(values.contains(ch))                                 // got a close bracket
               {
                  if(keyStack.empty() || numberOfBrackets == 0)        // first one is a close bracket, unbalanced
                  {
                      numberOfBrackets++;
                      balanced = false;
                      break;
                  }
                  else 
                  {
                      Character close = keyStack.peek(); 
                      if ((charMap.get(close)).equals(ch))
                      {
                        numberOfBrackets++;                            // get a match
                        keyStack.pop();
                        continue;
                      }
                  }
                }
                else if(charMap.containsKey(ch))                       // got an open one
                {
                   numberOfBrackets++;
                   // we get a open one, and need to check the stack if we have a match key on stak
                   keyStack.push(ch);
                }
            }
            // Now, make decision
            if(!keyStack.empty() || balanced == false)
            {
                System.out.println("The brackets are NOT balanced.");
            }
            else if(numberOfBrackets == 0)
            {
                System.out.println("No brackets in the string!");
            }
            else
            {
                System.out.println("The brackets are balanced.");
            }
        }
}
