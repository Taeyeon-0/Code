#include "SmartPtr.h"
#include<memory>
using namespace std;

class A {
public:
    ~A() {
        //cout << "Delete:" << endl;
        cout << "~A()" << endl;
    }

    int _a1 = 0;
    int _a2 = 0;
};


void test_auto_ptr() {
    phw::auto_ptr<A> ap1(new A);
    ap1->_a1++;
    ap1->_a2++;

    phw::auto_ptr<A> ap2(ap1);
    //ap1->_a1++;   //空指针解引用
    //ap1->_a2++;

    ap2->_a1++;
    ap2->_a2++;
    cout << ap2->_a1 << endl;//2
    cout << ap2->_a2 << endl;//2

    phw::auto_ptr<A> ap3(new A);
    ap2 = ap3;
    ap2->_a1++;
    ap2->_a2++;

    cout << ap2->_a1 << endl;//1
    cout << ap2->_a2 << endl;//1
}

//unique_ptr的思路是：简单粗暴，不让拷贝 只适用于不需要拷贝的一些场景
void test_unique_ptr() {
    phw::unique_ptr<A> up1(new A);
    up1->_a1++;
    up1->_a2++;

    phw::unique_ptr<A> up2(new A);
    //up1 = up2;    //err

    //phw::unique_ptr<A> up3(up2);   //err
}


//shared_ptr  需要拷贝的场景

void test_shared_ptr() {
    phw::shared_ptr<A> sp1(new A);
    phw::shared_ptr<A> sp2(sp1);
    phw::shared_ptr<A> sp3(sp1);
    sp1->_a1++;
    sp1->_a2++;

    cout << sp2->_a1 << ":" << sp2->_a2 << endl;

    sp2->_a1++;
    sp2->_a2++;
    cout << sp1->_a1 << ":" << sp1->_a2 << endl;
    phw::shared_ptr<int> sp4(new int);
    phw::shared_ptr<A> sp5(new A);
    phw::shared_ptr<A> sp6(sp5);
    sp1 = sp5;
    sp2 = sp5;
    sp3 = sp5;

    //自己给自己赋值
    sp4 = sp4;
    sp1 = sp5;//sp1和sp5 一起管理资源
}

struct Node {

    int _val = 0;
    //Node* _next;
    //Node* _prev;

    //需要将Node* 改完智能指针
    //phw::shared_ptr<Node> _next;
    //phw::shared_ptr<Node> _prev;

    //解决循环引用需要weak_ptr，而weak_ptr不需要引用计数
    phw::weak_ptr<Node> _next;
    phw::weak_ptr<Node> _prev;
    ~Node() {
        cout << "~Node()" << endl;
    }
};

//循环引用
void test_shared_ptr2() {
    phw::shared_ptr<Node> n1(new Node);
    phw::shared_ptr<Node> n2(new Node);

    n1->_next = n2;//自定义类型的指针，无法赋值给原生指针
    n2->_prev = n1;
}


//定制删除器
void test_shared_ptr3(){
    std::shared_ptr<Node> n1(new Node);
    //std::shared_ptr<Node> n2(new Node[5]);   //vs平台会崩溃
    std::shared_ptr<Node> n2(new Node[5],phw::DeleteArray<Node>());   //vs平台会崩溃
    std::shared_ptr<int> n3(new int[5],phw::DeleteArray<int>());
    std::shared_ptr<int> n4((int*)malloc(sizeof(int)),phw::Free<int>());

    //也可以用Lambda表达式代替仿函数对象
    std::shared_ptr<Node> n5(new Node[5],[](Node* ptr)->void{delete[] ptr;});
    std::shared_ptr<int> n6(new int[5], [](const int *ptr) -> void { delete[] ptr; });
    std::shared_ptr<int> n7((int*)malloc(sizeof(int)),[](int* ptr)->void{free(ptr);});
    std::shared_ptr<FILE> n8(fopen("test.txt", "w"), [](FILE* ptr)->void { fclose(ptr); });

    //unique_pttr  不支持仿函数，需要传模板参数
    std::unique_ptr<Node,phw::DeleteArray<Node>> up(new Node[5]);
}

int main() {
    //test_auto_ptr();
    //test_unique_ptr();
    //test_shared_ptr();
    test_shared_ptr3();
    return 0;
}