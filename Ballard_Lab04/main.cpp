#include "hash_table.h"
#include "hash_table_open.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Timer.cpp"



 int main(int argc, char const *argv[]) {
   long* randnums;
   Timer time1;
   hash_table<long>* quadratic_table= new hash_table<long>(60011);
   hash_table_open<long>* open_table= new hash_table_open<long>(600011);
   hash_table<long>* double_table = new hash_table<long>( 600011, 5);
   srand(22);

   int loadfactor= 2;
   long size_loaded;
   long maxsize= 100;
   double timeran;

  while(loadfactor<10)
  {
    size_loaded=maxsize*loadfactor/10;
    randnums= new long[size_loaded];

    std::cout << "loadfactor -" <<loadfactor<<"\n"<< std::endl;
  for (int j = 0; j < 5; j++) {
    /* code */
    srand(j);
    std::cout << "srand- " <<j<< "\n"<<std::endl;
    for (long i = 0;i < size_loaded;i++) {
      randnums[j]=rand();
    }
    time1.start();
    for (long i = 0;i < size_loaded;i++)
    {

   quadratic_table->insert(randnums[i]);

    }

    timeran= time1.stop();
    std::cout <<"quadtric_hash: \n" <<timeran  << std::endl;
    delete(quadratic_table);
    quadratic_table = new hash_table<long>(7);
    time1.start();
     //std::cout << "TEST: " << size_loaded  << std::endl;
    for (long i = 0;i < size_loaded;i++)

    {
      open_table->insert(randnums[i]);
    }
    //open_table->print();
     timeran= time1.stop();
     std::cout <<"open_hash: \n" <<timeran  << std::endl;
     delete(open_table);
     open_table= new hash_table_open<long>(600011);

     time1.start();
    for (long i = 0;i < size_loaded;i++)
    {
      double_table->insert(randnums[i]);
    }
    timeran= time1.stop();
     std::cout <<"double_hash: \n" <<timeran  <<"\n" <<std::endl;
    delete(double_table);
    double_table= new hash_table<long>( 600011, 5);

  }





  loadfactor++;
  }


  return 0;
}
