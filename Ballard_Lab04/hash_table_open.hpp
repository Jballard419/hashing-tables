template <typename T>
hash_table_open<T>::hash_table_open(long prime_num)
{
  hash_map = new linkedlist<T>*[prime_num];
  for(long i=0;i<prime_num; i++)
  {
    hash_map[i]= new linkedlist<T>();
  }
  size_of_map=prime_num;


}
template <typename T>
hash_table_open<T>::~hash_table_open()
{
  for(long i =0; i<size_of_map; i++)
  {

    delete(hash_map[i]);
  }
  delete(hash_map);

}
template <typename T>
void hash_table_open<T>::insert(const T val)
{
  long key=hash(val);

  hash_map[key]->insert(val);

  return;

}
template <typename T>
void hash_table_open<T>::delete_node(const T val)
{
  long key=hash(val);

  hash_map[key]->delete_node(val);

  return;

}
template <typename T>
bool hash_table_open<T>::find(const T val)
{
  long key= hash(val);

  return hash_map[key]->find(val);

}
template <typename T>
long hash_table_open<T>::hash(const T val)
{

    return val%size_of_map;

}
template <typename T>
void hash_table_open<T>::print()
{
  std::cout << "Hash Table:" << std::endl;
  for(long i= 0; i< size_of_map; i++)
  {
    hash_map[i]->print();

  }


}
