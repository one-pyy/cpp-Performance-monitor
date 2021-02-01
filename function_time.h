//在需要测试的函数与主函数头部创建任意名字functime变量并传入函数名即可将此函数加入运行时间测试
//example: fct var_name(__func__);
//在需要测试的代码段前后加入functime::insert("any name")与functime::erase("same name")即可将此代码段加入运行时间测试
#ifndef function_time
#define function_time
#include <iostream>
#include <cstring>
#include <map>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
struct name_time
{
  string name;
  int64_t time;
  name_time(string a,int64_t b):name(a),time(b){}
};
struct f_time
{
  int64_t time;
  chrono::high_resolution_clock::time_point begin;
  int living;
  f_time():time(0),living(0){}
};
class functime
{
  private:
    static map<string,f_time> list;
    static int living;
    const string name;
    static void printime(int64_t);
  public:
    functime(const char*);
    ~functime();
    static void insert(const char*);
    static void erase(const char*);
};

#endif
