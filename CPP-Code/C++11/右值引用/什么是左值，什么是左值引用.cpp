
void test() {
    int a = 0;
    int b = 1;
    int *p = &a;

    a + b;

    //左值引用给左值取别名
    int &ref = a;
}

int main() {
    // 以下的p、b、c、*p都是左值

    int *p = new int(0);
    int b = 1;
    const int c = 2;
    // 以下几个是对上面左值的左值引用
    int *&rp = p;
    int &rb = b;
    const int &rc = c;
    int &pvalue = *p;


    return 0;
}