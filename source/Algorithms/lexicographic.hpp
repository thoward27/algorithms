#include "../String/String.hpp"
#include "../Trees/Trie.hpp"

/** Lexicographic Sorting
 * Sorting Strings in Alphabetical Order
 *
 * Inputs:
 * @param arr: An array of String pointers.
 * @param n: The number of Strings provided.
 *
 * Outputs:
 * arr should be directly modified such that it's contents
 * are in lexicographically sorted order.
 *
 * O(n * L)
 */

void sort(String* arr[], int n) {
  Trie* t = new Trie();         // O(1)
  for (int i = 0; i < n; ++i)   // O(# Strings)
    t->put(arr[i]->cstr(), i);  // O(L)

  std::ostringstream oss;                             // O(1)
  t->print(oss);                                      // O(# Nodes in Trie)
  for (int i = 0, j = 0; i < n; ++i) {                // O(# Strings)
    arr[i]->clear();                                  // O(1)
    while (oss.str()[j] < 'a' || oss.str()[j] > 'z')  // O(1) because of print
      ++j;
    while (oss.str()[j] >= 'a' && oss.str()[j] <= 'z')  // O(L)
      arr[i]->append(oss.str()[j++]);
  }
  delete t;
}
