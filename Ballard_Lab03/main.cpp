#include "hash_table.h"
#include <string>
#include <iostream>
#include <fstream>

void printMenu() //prints the options available to the user
{
  std::cout << ".........................................................." << '\n';
  std::cout<<"\n"<<std::endl;
	std::cout<<"Select an action:"<<std::endl;
	std::cout<<"1) insert"<<std::endl;
	std::cout<<"2) Delete"<<std::endl;
	std::cout<<"3) Print"<<std::endl;
	std::cout<<"4) Exit"<<std::endl;


}

int main(int argc, char const *argv[]) {
 /* add data */

 if (argc != 2)
 {
   std::cout << "file didn't load use like this " << '\n';
   std::cout << "./hash_table data.txt" << '\n';
 }
 std::ifstream in(argv[1]);
 int value;
 int input;

 in>>value;
 std::cout<<"Select an action:"<<std::endl;
 std::cout<<"1- quadratic"<<std::endl;
 std::cout<<"2- double hashing"<<std::endl;
 std::cout<<"3- exit"<<std::endl;
hash_table<int>* table;
std::cin >> input;

if(input == 1)
{
   table = new hash_table<int>(value);
} else if(input ==2)
{
   table = new hash_table<int>(value, 5);
} else
{
  return 0;

}



 while(true)
 {
   if (!(in>>value)){ break;}
   table->insert(value);
 }
 do {
 printMenu();
 std::cin >> input;
   switch (input)
   {
     case 1:
       std::cout << "Choose a number to be added to the list:" << '\n';
       std::cin >> input;
       table->insert(input);
       input = 0;
       break;

     case 2:
       std::cout << "Choose a number to be deleted from the list:" << '\n';
       std::cin >> input;
       table->remove(input);
       input = 0;
       break;

     case 3:
       table->print();
       break;

     default:
       std::cout << "invalid input" << '\n';
       input = 0;
       break;

   }
   if(input == 4)
   {break;}
 } while(true);


 }
