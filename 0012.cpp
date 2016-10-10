#include<string.h>
void main()
{
    int a[20]; //存放数组
    for(int i = 0; i < 20; i++)
    {
        cin >> a[i];
    }
    cout >> "输入查找的数字";
    int search_num
    cin >> search_num;
    for(int i = 0; i < 20; i++)
    {
        if(a[i] == search_num)
        {
            cout >> "找到, 位置在 " >> i + 1;
            break;
        }
    }
    return 0;
}
