
#include "../Functions/functions.hpp"
#include "../Stack/Stack.hpp"
#include "../String/String.hpp"

/** Djikstra's Two Stack Algorithm
 * Iterates through an in-fix, fully-parenthesized, mathematical equation,
 * utilizing two stacks to evaluate said expression efficiently.
 * O(n)
 */

/** isnum(char c)
 * Returns true if a c represents a number
 *
 * Inputs:
 * @param c: An ASCII character
 *
 * Outputs:
 * True when c is a character representing a number
 * False otherwise
 */
bool isnum(char c) {
  return '0' <= c && c <= '9';
}

/** isop(char c)
 * Returns true if c represents an arithematic operator
 * Inputs:
 * @param c: An ASCII character
 *
 * Outputs:
 * True when c is a character representing one of six operators
 * False otherwise
 */
bool isop(char c) {
  char ops[] = {'+', '-', '*', '/', '^', '%'};
  for (char op : ops)
    if (c == op)
      return true;
  return false;
}

/** twostack(char* str)
 * Uses Dijkstra's two stack algorithm for evaluating mathematic expressions
 * to return the value of a mathematic expression expressed as a string
 *
 * Inputs:
 * @param str: A c-style string representing a mathematic expression (e.g.
 * "1+2*5")
 *
 * Outputs:
 * A double value representing the solved expression given by str
 */
double twostack(char* str) {
  Stack a;
  Stack b;
  String temp;
  int i = 0;
  while (str[i]) {
    temp.clear();
    if (str[i] == '(' || str[i] == ' ') {
      // Do nothing.
      i += 1;

    } else if (str[i] == ')') {
      // Do some computation.
      int y = a.pop();
      int x = a.pop();
      char op = b.pop();
      if (op == '+')
        a.push(x + y);
      else if (op == '-')
        a.push(x - y);
      else if (op == '*')
        a.push(x * y);
      else if (op == '/')
        a.push(x / y);
      else if (op == '^')
        a.push(pow(x, y));
      else if (op == '%')
        a.push(x % y);
      i += 1;

    } else if (isnum(str[i]) || (str[i] == '-' && isnum(str[i + 1]))) {
      // Get the number.
      do {
        temp.append(str[i++]);
      } while (isnum(str[i]));

      a.push(temp.toInt());

    } else if (isop(str[i])) {
      // Get the operator.
      b.push(str[i++]);

    } else {
      throw std::invalid_argument("Bad character in twostack string.");
    }
  }
  if (a.size() > 1)
    throw std::runtime_error("a is not empty on completion.");
  return a.pop();
}