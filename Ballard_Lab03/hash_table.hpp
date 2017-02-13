template <typename T>
hash_table<T>::hash_table(int prime_num)
{
  hash_map = new int[prime_num];
  has_been_used=new bool[prime_num];
  for(int i=0;i<prime_num; i++)
  {
    hash_map[i]= -1;
    has_been_used[i]=false;
  }
  size_of_map=prime_num;
  second_prime =0;
  version = quadtric;


}
template <typename T>
hash_table<T>::hash_table(int prime_num, int second_prime_num)
{
  hash_map = new int[prime_num];
  has_been_used=new bool[prime_num];
  for(int i=0;i<prime_num; i++)
  {
    hash_map[i]= -1;
    has_been_used[i]=false;
  }
  size_of_map=prime_num;
  version = double_hash;
  second_prime= second_prime_num;


}

template <typename T>
hash_table<T>::~hash_table()
{


}
template <typename T>
void hash_table<T>::insert(const T val)
{
  int key=hash(val);
  if (key== -1)
  {
    std::cout << "Error couldn't insert value" << '\n';
    return;
  }
  hash_map[key]= val;

  return;

}
template <typename T>
void hash_table<T>::delete_node(const T val)
{
  int key=search(val);
  if (key== -1)
  {
    std::cout << "Couldn't find value to delete" << '\n';
    return;
  }

  hash_map[key]= -1;
  has_been_used[key]=true;
  return;


}
template <typename T>
int hash_table<T>::search(const T val)
{
  int test_key;
  if(version== double_hash)
  {
    int second_hash = second_prime - val%second_prime;
  }else
  {
    int second_hash =0;

  }
  for(int i=0 ; i< size_of_map;i++)
  {
    if(version== double_hash)
    {
      test_key=(val+i*second_hash)%size_of_map;
    }else
    {
      test_key=(val+i*i)%size_of_map;
    }
    if(hash_map[test_key]==val)
      return test_key;
    else if(hash_map[test_key]==-1 &&  !(has_been_used[test_key]))
    {
      return -1;
    }

  }
  return -1;

}
template <typename T>
int hash_table<T>::hash(const T val)
{
  int location=-1;
    switch (version) {
      case quadtric:
      location = hash_quadtric(val);
      break;

      case double_hash:
      location = hash_double(val);
      break;
      default:
      break;

    }
    return location;

}
template <typename T>
int hash_table<T>::hash_quadtric(const T val)
{
int test_key;
for(int i=0 ; i< size_of_map;i++)
{
  test_key=(val+i*i)%size_of_map;

  if(hash_map[test_key]==-1)
    return test_key;

}
return -1;

}
template <typename T>
int hash_table<T>::hash_double(const T val)
{
int test_key;

int second_hash = second_prime - val%second_prime;
for(int i=0 ; i< size_of_map;i++)
{
  test_key=(val+i*second_hash)%size_of_map;

  if(hash_map[test_key]==-1)
    return test_key;

}
return -1;

}

template <typename T>
void hash_table<T>::print()
{

  for (int i=0; i<size_of_map; i++)
  {
    std::cout << i <<": "<< hash_map[i]<<" flag ="<< has_been_used[i] <<'\n';

  }
  return;



}
