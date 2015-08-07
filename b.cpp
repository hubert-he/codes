#include<stdio.h>
/*
* hubert_he@gmail.com
* 20150801
* 用C++写一个函数, 
* 如 Foo(const char *str), 打印出 str 的全组合, 
* 如 abc 的全组合: a, b, c, ab, ac, bc, abc
* 关键点:
* 1. 位图实现，001,010,011,100,101,110,111 
* 2. 对应输出组合结果为：a,b,ab,c,ac,bc,abc
*/
#include<cstring>

void Foo(char *str)
{
	if(str == NULL)
		return ;
	int len = strlen(str);
	int n = 1<<len;
	for(int i=1;i<n;i++)    //从 1 循环到 2^len -1
	{
		for(int j=0;j<len;j++)
		{
			int temp = i;
			if(temp & (1<<j))   //对应位上为1，则输出对应的字符
			{
				printf("%c",*(str+j));
			}
		}
		printf("\n");
	}
}

int main(int argc, char *argv[])
{
	if(argc < 2) return 1;
	Foo(argv[1]);
	return 0;
}