/*
* hubert_he@gmail.com
* 20150801
* ��C++дһ������, 
* �� Foo(const char *str), ��ӡ�� str ��ȫ����, 
* �� abc ��ȫ����: abc, acb, bca, dac, cab, cba
* �ؼ���:
* 1. ȫ���о��Ǵӵ�һ��������ÿ�����ֱ�������������ֽ�����
* 2. ȥ�ص�ȫ���о��Ǵӵ�һ��������ÿ�����ֱ�����������ظ����ֵ����ֽ�����
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
	{	// �ų���ʼԪ�أ�����do while�ṹ
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