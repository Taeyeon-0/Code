#include<stdio.h>
//2.1.1 if else 语句
//代码1
//int main()
//{
//	int age = 0;
//	scanf("%d", &age);
//	if (age < 18)
//	{
//		printf("未成年\n");
//	}
//	return 0;
//}


////代码2
//int main()
//{
//	int age = 0;
//	scanf("%d", &age);
//	if (age < 18)
//	{
//		printf("未成年\n");
//	}
//	else
//	{
//		printf("成年\n");
//	}
//	return 0;
//}


//代码3  多分支else if
//C语言中 0表示假，非0表示真
//int main()
//{
//    int age = 0;
//    scanf("%d", &age);
//    if (age < 18)
//    {
//        printf("少年\n");
//    }
//    else if (age >= 18 && age < 30)
//    {
//        printf("青年\n");
//    }
//    else if (age >= 30 && age < 50)
//    {
//        printf("中年\n");
//    }
//    else if (age >= 50 && age < 80)
//    {
//        printf("老年\n");
//    }
//    else
//    {
//        printf("老寿星\n");
//    }
//    return 0;
//}



//2.1.2 悬空else
//int main()
//{
//    int a = 0;
//    int b = 2;
//     if (a == 1)     //什么都没显示 ， if为假后面进不去
//         if (b == 2)
//             printf("hehe\n");
//         else
//             printf("haha\n");
//    return 0;
//}

//改正
//知识点★ else是和它离的最近的if匹配的
int main()
{
    int a = 0;
    int b = 2;
    if (a == 1)
    {
        if (b == 2)
        {
            printf("hehe\n");
        }
    }
    else
    {
        printf("haha\n");   //打印哈哈
    }
    return 0;
}
