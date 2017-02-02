#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "linkedlist.h"

template <typename T>
class hash_table
{
  public:

    hash_table(int prime_num);

    ~hash_table();

    void insert(const T val);

    void delete_node(const T val);

    int hash(const T val);

    bool find(const T val);

    void print();

  private:

    linkedlist<T>** hash_map;
    int size_of_map;






};
#include "hash_table.hpp"
#endif
