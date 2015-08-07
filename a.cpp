/*
* hubert_he@gmail.com
* 20150801
* 用C++写一个函数, 
* 如 Foo(const char *str), 打印出 str 的全排列, 
* 如 abc 的全排列: abc, acb, bca, dac, cab, cba
* 关键点:
* 1. 全排列就是从第一个数字起每个数分别与它后面的数字交换。
* 2. 去重的全排列就是从第一个数字起每个数分别与它后面非重复出现的数字交换。
*/
#include <iostream>
#include <cstring>

void Foo( char *str, int start)
{
	char *p = str + start;
	int len = strlen(str);
	if(strlen(p) <= 0) 
	{
		std::cout << str << std::endl;
		return;
	}
	char tmp;
	for(int i = start; i < len; i++)
	{	// 排除起始元素，或用do while结构
		if(start == i || str[i] != str[start])
		{
			tmp = str[i];
			str[i] = str[start];
			str[start] = tmp;
			Foo(str, start+1);
			tmp = str[i];
			str[i] = str[start];
			str[start] = tmp;
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc < 2) return 1;
	Foo(argv[1], 0);
	return 0;
}