#include<stdio.h>
/*
* hubert_he@gmail.com
* 20150801
* ��C++дһ������, 
* �� Foo(const char *str), ��ӡ�� str ��ȫ���, 
* �� abc ��ȫ���: a, b, c, ab, ac, bc, abc
* �ؼ���:
* 1. λͼʵ�֣�001,010,011,100,101,110,111 
* 2. ��Ӧ�����Ͻ��Ϊ��a,b,ab,c,ac,bc,abc
*/
#include<cstring>

void Foo(char *str)
{
	if(str == NULL)
		return ;
	int len = strlen(str);
	int n = 1<<len;
	for(int i=1;i<n;i++)    //�� 1 ѭ���� 2^len -1
	{
		for(int j=0;j<len;j++)
		{
			int temp = i;
			if(temp & (1<<j))   //��Ӧλ��Ϊ1���������Ӧ���ַ�
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