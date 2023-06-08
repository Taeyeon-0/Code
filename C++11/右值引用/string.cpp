namespace bit {
    bit::string to_string(int value) {
        bool flag = true;
        if (value < 0) {
            flag = false;
            value = 0 - value;
        }
        bit::string str;
        while (value > 0) {
            int x = value % 10;
            value /= 10;
            str += ('0' + x);
        }
        if (flag == false) {
            str += '-';
        }

        std::reverse(str.begin(), str.end());
        return str;
    }
}// namespace bit
int main() {
    // 在bit::string to_string(int value)函数中可以看到，这里
    // 只能使用传值返回，传值返回会导致至少1次拷贝构造(如果是一些旧一点的编译器可能是两次拷
    bit::string ret1 = bit::to_string(1234);
    bit::string ret2 = bit::to_string(-1234);
    return 0;
}


int main() {
    string ret2 = to_string(-1234);
    return 0;
}

// 移动构造
string(string &&s)
    : _str(nullptr), _size(0), _capacity(0) {
    cout << "string(string&& s) -- 移动语义" << endl;
    swap(s);
}

int main() {
    string ret2 = to_string(-1234);
    return 0;
}
void test {
    string ret2 = to_string(-1234);
}

// 移动赋值
string &operator=(string &&s) {
    cout << "string& operator=(string&& s) -- 移动语义" << endl;
    swap(s);
    return *this;
}

int main() {
    string ret1;
    ret1 = to_string(1234);
    return 0;
}
// 运行结果：
// string(string&& s) -- 移动语义
// string& operator=(string&& s) -- 移动语义