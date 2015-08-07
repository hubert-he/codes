/*******************************************************************
 * Copyright (C) Jerry Jiang
 *               
 * File Name   : swap.cpp
 * Author      : Jerry Jiang
 * Create Time : 2012-3-24 4:19:31
 * Mail        : jbiaojerry@gmail.com
 * Blog        : http://blog.csdn.net/jerryjbiao 
 *               
 * Description : �򵥵ĳ���ڹ��C++ STL�㷨ϵ��֮ʮ��                  
 *               �����㷨 : Ԫ�ؽ���swap   
 *               
 *  ԭ�ͣ�
	template <class T> void swap ( T& a, T& b )
	{
	  T c(a); a=b; b=c;
	}
 ******************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main () 
{
	
	int x = 10, y = 20;                         // x:10 y:20
	swap(x, y);                              // x:20 y:10
	cout << "x= " << x << "y=" << y << endl;
	vector<int> first (4, x), second (6, y);  // first:4x20 second:6x10
	swap(first, second);                     // first:6x10 second:4x20
	
	cout << "first contains:";
	//ʹ��һ���iterator��ʽ���first
	for (vector<int>::iterator it=first.begin();  it != first.end(); ++it)
	{
		cout << " " << *it;
	}
	cout << endl;

	cout << "second contains: ";
	//ʹ��copy()��ʵ��second�����
	copy(second.begin(), second.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	return 0;
}
