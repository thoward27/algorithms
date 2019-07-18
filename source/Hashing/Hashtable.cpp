#include "Hashtable.hpp"
#include "SLL.cpp"

int HashTable::hash(const String& key){
    int hash = 0;
    for(int i = 0; i < key.size(); ++i){
        hash = key.at(i) + hash;
    }
    return hash % size;
}

HashTable::HashTable(){
    size = 5;
    table = new List[5];
}

HashTable::~HashTable(){
    delete [] table;
    size = 0;
}

HashTable::HashTable(int indices){
    size = indices;
    table = new List[indices];
    for(int i = 0; i < indices; ++i){
        table[i] = List();
    }
}

unsigned int HashTable::Size(){
    return size;
}

void HashTable::insert(const String& key, int data){
    int h = hash(key);
    table[h].push_back(key, data);
    // for(int i = 0; i < size; ++i){
    //     if(table[i].length() / size >= 8){
    //         double the size
    //     }else if(table[i].length() / size <= 2){
    //         halve the size
    //     }
    // }
}

void HashTable::remove(String& key){
    int to_remove = hash(key);
    table[to_remove].remove(key);
}

bool HashTable::search(String& key){
    int h = hash(key);
    if(table[h].index(key) != -1){
        return true;
    }else{
        return false;
    }
}

int HashTable::get(String& key){
    int h = hash(key);
    int idx = table[h].index(key);
    return table[h].at(idx);
}

bool HashTable::is_empty(){
    for(int i = 0; i < size; ++i){
        if(table[i].length() != 0){
            return false;
        }
    }
    return true;
}

void HashTable::print(){
    for(int i = 0; i < size; ++i){
        table[i].print();
    }
}