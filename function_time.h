//在需要测试的函数与主函数头部创建任意名字functime变量并传入函数名即可将此函数加入运行时间测试
//example: functime var_name(__func__);
//在需要测试的代码段前创建functime变量，在其后调用name.erase()即可将此代码段加入运行时间测试
// Add the function to the run-time test by creating an arbitrary functime variable in the header of the function to be tested and the main function and passing in the function name
//example: functime var_name (__ func__);
// Create the functime variable before the code snippet you want to test, and then call name.erase () to add the snippet to the run-time test
#ifndef function_time
#define function_time
#include <iostream>
#include <cstring>
#include <map>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
class functime
{
  public:
    functime(const char*);
    ~functime();
    void erase();
  private:
    struct f_time;
    static map<string,f_time> list;
    static int living;
    const string name;
    bool live;
    static void printime(int64_t);
};
#endif
