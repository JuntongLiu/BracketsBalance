
/*   
 *   C implementation:
 *
 *   When running, these program prompt user to type in a string with brackets 
 *   and the program will check to see if those brackets contained in the string 
 *   are balanced or not.
 * 
 *   {[()]}, {sdf[e()r]erq}             balanced
 *   {[]}}[  }abc()                     not balanced
 *  
 *   It is interesting to compare the C, C#, C++ and Java implementations.
 * 
 * 
 *                                           Juntong Liu    
 *                                                                 2019-07-17
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 256

/*
 * Functions prototype
 */
static int checkOpenBracket(char );
static int checkCloseBracket(char);
static int getOpenMatch(char);

int main()                               
{
  char token[128], buffer[BUFF_SIZE], c;                         // 128 chars should be enough for most cases
  int i, unbalance = 0, numberOfBrackets = 0, index = 0;
  
  printf("Type in a string with brackets:\n");                   // ask the user to type in a string with brackets

  fgets(buffer, BUFF_SIZE , stdin);
  
  for (i = 0; i<strlen(buffer); i++)                             // walk the user string
  { 
      c = buffer[i]; 
      
      // check first to filter out no-brackets letters in the string, to save some function calls. 
      // Or skip the following 2 lines, to check every letters with function calls.
      if(c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}')     
      { 
	  numberOfBrackets++;
          
	  if(checkOpenBracket(c) != -1)                           // An open bracket ?
	  {
	      printf("Open B : %c, \n", c);
	      token[index] = c;                                  // ...yes, save open bracket in array
	      index++;                                           // ...update index
	      continue;
	  }
	  else if(checkCloseBracket(c) != -1)                     // An close bracket ? 
          {
	      if(index == 0)                                      // ...yes, but first bracket can't be a close bracket, otherwise not balanced
	      {
		  unbalance = 1;
		  break;
	      }
	      else                                               // ... no, this close bracket is not the first bracket we find
              {
		if(token[index-1] == getOpenMatch(c))            // Is the latest open bracket match this closing bracket?
	        {	
		    printf("Close B : %c\n", c);                 // ...yes, get a matched pair
		    index --;                       
		    continue;
	        }
		else                                  
		{                                                // ...no, do not match, bracket-type is mismatching
		    printf("Unbalance = 1\n");
		    unbalance = 1;
		    break;	
	        }
	      }
	   }
       }
  }
  
  // now, the whole string is analyzed, time to make decision
  if(unbalance != 0 || index != 0)                               // if unbalance flag is on, or there are open bracket still in the array      
    printf("Brackets are NOT balanced\n\n");                     // ... not balanced
  else if (numberOfBrackets == 0 && unbalance == 0)              // if bracket counter is 0 and unbalance flag is not set
    printf("\nNo bracket found in the string\n\n");              // ...user forget to type in any bracket in the string
  else
    printf("Brackets are balanced\n\n");
  
  return 0;
  
}


/*
 * Take a closing bracket and find and return the corresponding open bracket.
 */
static int getOpenMatch(char c)
{
  if(c == ')')
    return '(';
  else if(c == ']')
    return '[';
  else if(c == '}')
    return '{';
  else 
    return -1;
}

/*
 * Check to see if the char is any of the open bracket, if so return it. if not, return -1
 */
static int checkOpenBracket(char c)
{
  if(c == '(')
    return '(';
  else if(c == '[')
    return '[';
  else if(c == '{')
    return '{';
  else 
    return -1;
}

/*
 * Check to see if the char is any of the close bracket, if so return it. If not, return -1
 */
static int checkCloseBracket(char c)
{
  if(c == ')')
    return ')';
  else if(c == ']')
    return ']';
  else if(c == '}')
    return '}';
  else 
    return -1;
}



