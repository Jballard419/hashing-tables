template <typename T>
hash_table<T>::hash_table(int prime_num)
{
  hash_map = new linkedlist<T>*[prime_num];
  for(int i=0;i<prime_num; i++)
  {
    hash_map[i]= new linkedlist<int>();
  }
  int size_of_map=prime_num;


}
template <typename T>
hash_table<T>::~hash_table()
{

}
template <typename T>
void hash_table<T>::insert(const T val)
{
  int key=hash(val);

  hash_map[key]->insert(val);

  return;

}
template <typename T>
void hash_table<T>::delete_node(const T val)
{
  int key=hash(val);

  hash_map[key]->delete_node(val);

  return;

}
template <typename T>
bool hash_table<T>::find(const T val)
{
  int key= hash(val);

  return hash_map[key]->find(val);

}
template <typename T>
int hash_table<T>::hash(const T val)
{

    return val%size_of_map;

}
template <typename T>
void hash_table<T>::print()
{
  std::cout << "Hash Table:" << std::endl;
  for(int i= 0; i< size_of_map; i++)
  {
    hash_map[i]->print();

  }


}
