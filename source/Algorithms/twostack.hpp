
#include "../Functions/functions.hpp"
#include "../Stack/Stack.hpp"
#include "../String/String.hpp"

/** Djikstra's Two Stack Algorithm
 * <Place your notes and analysis here>
 * O(?)
 */

bool isnum(char c) {
  return '0' <= c && c <= '9';
}

bool isop(char c) {
  char ops[] = {'+', '-', '*', '/', '^', '%'};
  for (unsigned int i = 0; i < sizeof(ops) / sizeof(char); ++i)
    if (c == ops[i])
      return true;
  return false;
}

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
      throw "Bad character in twostack string.";
    }
  }
  if (a.size() > 1)
    throw "Bad!";
  return a.pop();
}