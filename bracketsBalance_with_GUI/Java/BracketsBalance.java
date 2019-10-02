import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

// This class check the user typed in string to see if the 
// bracket is balanced or not
public class BracketsBalance {
	
	// Function to process the user typed in string to see if the bracket are balanced or not 
	public String checkBalance(String userString) {
		
	 // create a map for the brackets
    Map<Character, Character> charMap = new HashMap<Character, Character>();     // create a map
    charMap.put('(', ')');                                      // populate the map
    charMap.put('[', ']');
    charMap.put('{', '}');

    boolean balanced = true;                                   // flag to indicate if brackets are balanced
    int numberOfBrackets = 0;                                  // number of brackets in the string
    Stack<Character> keyStack = new Stack<Character>();
    Collection<Character> values = charMap.values();      
  
    //Scanner input = new Scanner(System.in);                    // prompt user to type in a string
    //System.out.println("Enter a string with brackets:");

    //String userString = input.nextLine();

    char[] charArray = new char[userString.length()];
    userString.getChars(0, userString.length(), charArray, 0); // convert the string into a char array

    for (char ch : charArray)                                  // walk the string to find any bracket
    {
       if(values.contains(ch))                                 // got a close bracket
       {
          if(numberOfBrackets == 0)                            // first one is a close bracket, unbalanced
          {
              numberOfBrackets++;
              balanced = false;
              break;
          }
          else if(!keyStack.empty())
          {
              numberOfBrackets++;
              Character close = keyStack.peek(); 
              if ((charMap.get(close)).equals(ch))
              {
                // get a match
                keyStack.pop();
                continue;
              }
              else
              {
                balanced = false;
                break;
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
        //System.out.println("The brackets are NOT balanced.");
    	return "The brackets are NOT balanced."; 
    }
    else if(numberOfBrackets == 0)
    {
        //System.out.println("No brackets in the string!");
    	return "No brackets in the string!";
    }
    else
    {
        //System.out.println("The brackets are balanced.");
    	return "The brackets are balanced.";
    }
  }
}
