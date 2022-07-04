#include <iostream>
using namespace std;
const int MAX = 3;

int main(int argc, char* argv[])
{
  int  var[MAX] = {10, 100, 200};

  // 指针中最后一个元素的地址
  int* ptr = &var[MAX - 1];

  //int* ptr = var;

  for (int i = MAX; i > 0; i--)
  {
    //ptr--;

    cout << "Address of var[" << i << "] = ";
    cout << sizeof(int) << endl;

    cout << "Value of var[" << i << "] = ";
    cout << *ptr << endl;

    // 移动到下一个位置
    //ptr--;
    ptr --;

  }
  return 0;
}
