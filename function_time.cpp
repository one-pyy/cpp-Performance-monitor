#include "function_time.h"
int functime::living=0;
map<string,functime::f_time> functime::list;
struct name_time
{
  string name;
  int64_t time;
  name_time(string a,int64_t& b):name(a),time(b){}
};
struct functime::f_time
{
  int64_t time;
  chrono::high_resolution_clock::time_point begin;
  int living;
  f_time():time(0),living(0){}
};
functime::functime(const char* s):name(s)
{
  ++living;
  live=1;
  f_time& a=list[name];
  if(++a.living==1)
    a.begin=chrono::high_resolution_clock::now();
}
functime::~functime()
{
  if(live)
  {
    f_time& a=list[name];
    if(!(--a.living))
      a.time+=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now()-a.begin).count();
    if(!(--living))printime(a.time);
  }
}
void functime::erase()
{
  f_time& a=list[string(name)];
  if(!(--a.living))
    a.time+=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now()-a.begin).count();
  live=0;
  if(!(--living))printime(a.time);
}
void functime::printime(int64_t all)
{
  puts("\n");
  vector<name_time> z;
  for(auto i=list.begin();i!=list.end();++i)
  {
    z.push_back(name_time(i->first,i->second.time));
  }
  sort(z.begin(),z.end(),[&](name_time& a,name_time& b)->bool {return a.time>b.time;});
  for(register int i=0;i<z.size();++i)
    printf("%s: %.4fms  %3.2f%c\n",z[i].name.c_str(),z[i].time/1000000.0,all==0?100.0:z[i].time*100.0/all,'%');
}
