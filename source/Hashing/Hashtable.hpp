#pragma once
#include <iostream>
#include "LinkedList.hpp"
#include "../String/String.hpp"
//#include <string>

class HashTable {
    private:
        unsigned int size;
        List* table;

        /** hash(String key)
         * Calculates the simple modular hash of a string being:
         * (sum of ascii values for each character) % (size data member)
         */
        int hash(const String& key);

    public:
        HashTable();
        ~HashTable();
        
        HashTable(int indices);
        
        /** Size()
         * Returns the value of the data member size, the number of indices in the table
         */
        unsigned int Size();


        /** insert(String key, int data)
         * Insert the value of data into the chain at index hash(key) 
         */
        void insert(const String& key, int data);


        /** remove(String key)
         * Removes the first instance of the given key from the chain located at hash(key) 
         */
        void remove(String& key);


        /** search(String key)
         * Returns true if it found an instance of the key at index hash(key) false otherwise
         */
        bool search(String& key);


        /** get(String key)
         * Returns the integer value associated with the given key from the key/value pair
         */
        int get(String& key);


        /** is_empty()
         * Returns true if all chains are of length 0 indicating them being empty, returns false otherwise
         */
        bool is_empty();


        /** print()
         * Calls the Linked List print() method on each of its chains
         */
        void print(std::ostream& oss = std::cout);
};