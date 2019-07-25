#include <string>
#include "../String/String.hpp"

unsigned long long int hash(const String& a) {
  unsigned long long int out = 0;
  for (unsigned int i = 0; i < a.size(); ++i) {
    out += a.at(i) * (i + 1);
  }
  return out;
}

/** Karp-Rabin Pattern Matching
 * Using a rolling-hash to find word in text.
 */
bool karp_rabin(const String& text, const String& word) {
  unsigned long long int hash_pattern = hash(word);
  for (unsigned int i = 0; (i + word.size()) <= text.size(); ++i) {
    if (hash(text.substr(i, i + word.size())) == hash_pattern)
      return true;
  }
  return false;
}
