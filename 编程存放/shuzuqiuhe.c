#include<stdio.h>
main()
{
    /* �ַ������� */
    char *arr[] = {"How are you?", "I'am fine! and you?", "I'am fine too."};
    int i;
    int len = 3;

    /* �����������е��ַ��� */
    for(i=0; i<len; i++)
    {
  printf("%s\n", arr[i]);
    }
}
