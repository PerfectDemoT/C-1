#include<stdio.h>
main()
{
    /* 字符串数组 */
    char *arr[] = {"How are you?", "I'am fine! and you?", "I'am fine too."};
    int i;
    int len = 3;

    /* 逐个输出数组中的字符串 */
    for(i=0; i<len; i++)
    {
  printf("%s\n", arr[i]);
    }
}
