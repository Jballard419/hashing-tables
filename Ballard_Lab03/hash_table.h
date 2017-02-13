#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
enum Type_of_hash { quadtric,  double_hash };

template <typename T>
class hash_table
{
  public:

    hash_table(int prime_num);

    hash_table(int prime_num, int second_prime_num);

    ~hash_table();

    void insert(const T val);

    void remove(const T val);


    int search(const T val);

    int hash_quadtric(const T val, bool insert);
    int hash_double(const T val, bool insert);


    void print();

  private:

    int* hash_map;
    bool* has_been_used;
    int size_of_map;
    Type_of_hash version;
    int second_prime;







};
#include "hash_table.hpp"
#endif
