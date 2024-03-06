//异或： 相同为0,相异为1
// a^a=0  0^a=a    1^1^3 ==3   1^3^1==3

//分组两个单身狗
// 1.计算5和6的哪一位为1 - n
// 2.以第n位为标准，第n位为1的放一组，第一位为0方一组

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 6};
    int sz = sizeof(arr) / sizeof(arr[0]);
    //所有数字异或
    int i = 0;
    int ret = 0;
    for (i = 0; i < sz; i++)
    {
        ret ^= arr[i];
    }
    // ret就是5^6的结果，二进制中一定有1
    //计算ret的第几位为1
    int pos = 0;
    for (i = 0; i < 32; i++)
    {
        if ((ret >> i) & 1 == 1)
        {
            pos = i;
            break;
        }
    }
    // ret的第pos位为1
    //把arr数组中的每个元素的第pos位为1的数字异或在一起
    int num1 = 0;
    int num2 = 0;
    for (i = 0; i < sz; i++)
    {
        if ((arr[i] >> pos) & 1 == 1)
        {
            num1 ^= arr[i];
        }
        else
        {
            num2 ^= arr[i];
        }
    }
    printf("%d %d", num1, num2);
    return 0;
}