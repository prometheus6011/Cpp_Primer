#include <iostream>
#include <vector>

using std::vector;
using std::cout; using std::endl;

void print_vector(const vector<int>& ivec, int idx)
{
  if (idx >= ivec.size()) {
    cout << endl;
    return ;
  }
  cout << ivec[idx] << " ";
  print_vector(ivec, idx + 1);
}

int main()
{
  vector<int> ivec = {5, 4, 3, 2, 1};
  print_vector(ivec, 0);
  return 0;
}