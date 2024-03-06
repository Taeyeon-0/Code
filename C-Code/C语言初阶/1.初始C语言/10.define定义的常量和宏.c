//define定义标识符常量
#define MAX 1000
//define定义宏
#define ADD(x, y) ((x)+(y))
#define ADD1(x, y) x+y
#include <stdio.h>
int main()
{
    printf("%d\n", MAX);     //1000
    int sum = ADD(2, 3); 
    printf("sum = %d\n",sum);      //5

    sum = 10 * ADD(2, 3);       //50    10*(2+3)
    printf("sum = %d\n", sum);

    sum = 10 * ADD1(2, 3);     //23   10*2+3
    printf("sum = %d\n", sum);
    return 0;
}