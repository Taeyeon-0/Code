#include <stdio.h>
#define SQAP_BIT(n) n=(((n & 0xaaaaaaaa) >> 1) + ((n & 0x55555555) << 1))
int main()
{
    int a = 10;
    // 00000000000000000000000000001010
    SQAP_BIT(a);
    printf("%d\n", a);

    SQAP_BIT(a);
    printf("%d\n", a);
    return 0;
}