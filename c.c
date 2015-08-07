#include <stdio.h>

//arr为原始数组
//start为遍历起始位置
//result保存结果，为一维数组
//count为result数组的索引值，起辅助作用
//NUM为要选取的元素个数
//arr_len为原始数组的长度，为定值
void combine_increase(int* arr, int start, int* result, int count, const int NUM, const int arr_len)
{
  int i = 0;
  printf("start %d count %d NUM %d arr_len %d\n", start, count, NUM, arr_len);
  for (i = start; i < arr_len + 1 - count; i++)
  {
    result[count - 1] = i;
    if (count - 1 == 0)
    {
      int j;
      for (j = NUM - 1; j >= 0; j--)
        printf("%d\t",arr[result[j]]);
      printf("\n");
    }
    else
      combine_increase(arr, i + 1, result, count - 1, NUM, arr_len);
  }
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6};
  int num = 4;
  int result[num];

  combine_increase(arr, 0, result, num, num, sizeof(arr)/sizeof(int));
  return 0;
}