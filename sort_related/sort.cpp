#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <cstdio>

using namespace std;

#define print(arr,n) copy(arr,arr+n,ostream_iterator<int>(cout," "));\
    cout<<endl;
using namespace std;
const char *const red = "\033[0;40;31m";
const char *const green= "\033[0;40;32m";
const char *const normal = "\033[0m";

#define TESTCASE 1

void sort_test(void (*_sort)(int*,int))
{
    const int N=10;
    int orig[N] = {52,92,98, 78, 63, 7, 24, 33, 55, 73};
    int standard[N];
    int arr[N];
    srand(time(0));
    for(int j=0;j < TESTCASE; j++)
    {
#if TESTCASE > 1
        for(int i=0;i<N;i++)
            orig[i]=rand()%100;//随机生成序列
#endif			
        cout << "bef:";
        print(orig,N);

        copy(orig,orig+N,standard);
        sort(standard,standard+N);//利用sort函数进行排序
        cout << "std:";
        print(standard,N);

        copy(orig,orig+N,arr);
        _sort(arr,N);//采用我们的方法进行排序
        cout<<"aft:";
        print(arr,N);
        if(equal(standard,standard+N,arr))//测试我们的方法是否正确
            printf("%sOK%s\n",green,normal);
        else
            printf("%sNO%s\n",red,normal);
    }
}

int findPos(int *arr, int low, int high, int key)
{
    int i;
    for(i = low; i < high; i++)
    {
        if(arr[i] > key) break;
    }
    return i;

}

void insertSort(int *a, int total)
{
    int locating, rightPos = 0;
    for(int i = 1; i < total; i++)
    {
        locating = a[i];
        rightPos = findPos(a, 0, i, a[i]);
        //cout << rightPos << "\n";
        for(int j = i - 1; j >= rightPos; j--)
            a[j+1] = a[j];
        a[rightPos] = locating;
        //print(a, 10);
    }
}

void selectSort(int *a, int total)
{
	int leastIndex = 0;
	for(int i = 0; i < total; i++)
	{
		leastIndex = i;
		for(int j = i; j < total; j++)
		{
			if(a[leastIndex] > a[j])
				leastIndex = j;
		}
		if(leastIndex != i )
		{
			swap(a[i], a[leastIndex]);
		}
	}
}

void BubbleSort(int *a, int total)
{
	for(int i = total - 1; i >= 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			if(a[j] > a[j+1])
				swap(a[j], a[j+1]);
		}
	}
}
// [low, high)
void _quickSort(int *a, int low, int high)
{
	int midElem = a[low];
	int i = low, j = high-1;
	if(i >= j) return; // 问题1: 忽视了递归退出条件
	while(i < j)
	{
		while(midElem < a[j] && i < j) // 问题2: 忽视连续查找
			j--;
		if(i < j)
		{
			a[i] = a[j];
			i++;
		}
		while(midElem > a[i] && i < j)
			i++;
		if( i < j)
		{
			a[j] = a[i];
			j--;
		}
	}
	a[i] = midElem;// 问题3: 忽视拷贝回去的动作
	_quickSort(a, low, i);
	_quickSort(a, i+1, high); // 问题4： 界限落实
}

// c=true => 从小到大
void _quickSort(int *a, int left, int right, bool c)
{
	if(left >= right) return;
	int p = a[left];
	int i = left, j = right - 1;
	while(i < j)
	{	// 问题5： 注意运算符优先级
		// (i < j && c?(p < a[j]):(p > a[j]))
		// <=> ((i <j) && c) ? () : ()
		while((i < j) && (c?(p < a[j]):(p > a[j])))
			j--;
		if(i < j)
		{
			a[i] = a[j];
			i++;
		}
		while((i < j) && (c?(p > a[i]):(p < a[i])))
			i++;
		if(i < j)
		{
			a[j] = a[i];
			j--;
		}
	}
	a[i] = p;
	_quickSort(a, left, i, c);
	_quickSort(a, i + 1, right, c);
}

void quickSort(int *a, int total)
{
	_quickSort(a, 0, total,true);
}

void heapAdjust(int *a, int root, int total)
{
	int min = 0;
	if(root*2+1 > total)
	{
		if(root*2 > total) return;
		else
		{
			min = a[root]>a[root*2]?root*2:root;
		}
	}
	else
	{
		min = a[root*2] > a[root*2+1]?(root*2+1):(root*2);
		min = min > a[root]? root:min;
	}
	if(root != min)
	{
		swap(a[root], a[min]);
		heapAdjust(a, min, total);
	}
}

void heapBuilt(int *a, int total)
{
	for(int i = total/2; i >= 0; i--)
	{
		heapAdjust(a, i, total);
	}
}

void heapSort(int *a, int total)
{
	heapBuilt(a, total);
	print(a, 10);
}

void mergeSort(int *a, int total)
{
}

int main()
{
#if 0
    sort_test(insertSort);
	sort_test(selectSort);
	sort_test(BubbleSort);
#else
	sort_test(heapSort);
#endif
    return 0;
}


























