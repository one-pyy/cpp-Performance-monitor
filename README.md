# run_time
测试c++程序中函数与代码块所用的时间
在需要测试的函数与主函数头部创建任意名字functime变量并传入函数名即可将此函数加入运行时间测试
example: fct var_name(__func__);
在需要测试的代码段前后加入functime::insert("any name")与functime::erase("same name")即可将此代码段加入运行时间测试（他们应当成对出现）
Time spent testing functions and code blocks in C++ programs
Create a variable named functime in the function to be tested and the head of the main function and pass in the function name to add this function to the runtime test
example: fct var_name(__func__);
Add functime::insert("any name") and functime::erase("same name") before and after the code segment to be tested to add this code segment to the runtime test (they should appear in pairs)
