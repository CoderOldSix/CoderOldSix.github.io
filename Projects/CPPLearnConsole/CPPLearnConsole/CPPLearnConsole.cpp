#include <iostream>
using namespace std;
const int MAX = 3;

int main(int argc, char* argv[])
{

  /*
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

  }*/

  /*
   * 指针数组互换
   */
  int  var[MAX] = {10, 100, 200};

  // for (int i = 0; i < MAX; i++)
  // {
  //   *var = i;    // 这是正确的语法
  //   var++;       // 这是不正确的
  // }
  *(var+2)=500;
  cout << "Value of var[" << 2 << "] = ";
  cout << var[2] << endl;

  return 0;
}
