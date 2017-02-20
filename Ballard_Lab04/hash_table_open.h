#ifndef HASH_TABLE_OPEN_H
#define HASH_TABLE_OPEN_H

#include "linkedlist.h"

template <typename T>
class hash_table_open
{
  public:

    hash_table_open(long prime_num);

    ~hash_table_open();

    void insert(const T val);

    void delete_node(const T val);

    long hash(const T val);

    bool find(const T val);

    void print();

  private:

    linkedlist<T>** hash_map;
    long size_of_map;






};
#include "hash_table_open.hpp"
#endif
