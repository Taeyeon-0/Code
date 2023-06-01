// 声明一个类作为友元
template <typename T>
class OtherClass;

// 定义一个模板类
template <typename T>
class MyTemplateClass {
private:
    T privateVariable;  // 私有成员变量

    // 友元声明
    friend class OtherClass<T>;

public:
    // 公有成员函数和其他代码...
};

// 友元类的定义
template <typename T>
class OtherClass {
public:
    void accessPrivateVariable(MyTemplateClass<T>& obj) {
        T value = obj.privateVariable;  // 访问 MyTemplateClass 的私有成员变量
        // 使用 value 和其他操作...
    }
};

// 使用示例
int main() {
    MyTemplateClass<int> obj;
    OtherClass<int> otherObj;
    otherObj.accessPrivateVariable(obj);  // 调用友元函数来访问私有成员变量
    return 0;
}
