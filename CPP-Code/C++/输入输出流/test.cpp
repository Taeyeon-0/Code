#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Date {
    friend ostream &operator<<(ostream &out, const Date &d);
    friend istream &operator>>(istream &in, Date &d);

public:
    Date(int year = 1, int month = 1, int day = 1)
        : _year(year), _month(month), _day(day) {}

    operator bool() {
        // 这里是随意写的，假设输入_year为0，则结束
        if (_year == 0)
            return false;
        else
            return true;
    }

private:
    int _year;
    int _month;
    int _day;
};

istream &operator>>(istream &in, Date &d) {
    in >> d._year >> d._month >> d._day;
    return in;
}

ostream &operator<<(ostream &out, const Date &d) {
    out << d._year << " " << d._month << " " << d._day;
    return out;
}

//printf/scanf
//fprintf/fscanf
//sprintf/sscanf

//ostream/istream 更好的支持自定义类型对象的流插入和流提取
//自定义类型，可以自己重载，控制流提取和流插入的方式
void test1() {
    int i = 1;
    double j = 2.2;
    cout << i << j << endl;//自动识别类型

    //2022 11 28
    int year, month, day;
    // cin >> year >> month >> day;
    //scanf("%d%d%d", &year, &month, &day);

    //20221128
    //scanf("%4d%2d%2d", &year, &month, &day);
    //C++方式
    string str;
    cin >> str;
    year = stoi(str.substr(0, 4));
    month = stoi(str.substr(4, 2));
    day = stoi(str.substr(6, 2));

    cout << year << " " << month << " " << day << endl;
}

void test2() {
    ifstream ifs("test.cpp");
    char ch = ifs.get();
    while (ifs) {
        cout << ch;
        ch = ifs.get();
    }
}

void test3() {
    ifstream ifs("test.txt");
    //C语言
    //fscanf("%d%s%f", );
    int i;
    string s;
    double d;
    ifs >> i >> s >> d;
    while (1)
        ;
}

//IP
struct ServerInfo {
    //char _address[32];
    string _address;
    int _port = 100;// 100
    Date _date;
};

// 二进制读写：在内存如何存储，就如何写到磁盘文件
// 优点：快 缺点：写出去内容看不见

// 文本读写：对象数据序列化字符串写出来，读回来也是字符串，反序列化转成对象数据
// 优点：可以看见写出去是什么 缺点：存在一个转换过程，要慢一些


struct ConfigManager {
public:
    ConfigManager(const char *filename = "server.txt")
        : _filename(filename) {}

    void WriteBinary(const ServerInfo &info) {
        ofstream ofs(_filename, ios_base::out | ios_base::binary);
        ofs.write((char *) &info, sizeof(info));
    }

    void ReadBinary(ServerInfo &info) {
        ifstream ifs(_filename, ios_base::in | ios_base::binary);
        ifs.read((char *) &info, sizeof(info));
    }

    //传统方式
    //void WriteText(ServerInfo& info)
    //{
    //	ofstream ofs(_filename, ios_base::out);
    //	ofs.write(info._address.c_str(), info._address.size());
    //	ofs.put('\n');
    //	const string str = to_string(info._port);
    //	ofs.write(str.c_str(), str.size());
    //}


    //void ReadText( ServerInfo& info) {
    //	ifstream ifs(_filename, ios_base::in);
    //	char buff[128];
    //	ifs.getline(buff, 128);
    //	info._address = buff;

    //	ifs.getline(buff, 128);
    //	info._port = stoi(buff);
    //}

    //新方法
    void WriteText(const ServerInfo &info) {
        ofstream ofs(_filename, ios_base::out);
        ofs << info._address << endl;
        ofs << info._port << endl;
        ofs << info._date << endl;//Date类中重载了<< 才支持
    }

    void ReadText(ServerInfo &info) {
        ifstream ifs(_filename, ios_base::in | ios_base::binary);
        ifs >> info._address >> info._port >> info._date;
    }

private:
    string _filename;//配置文件
};


void test4() {
    //二进制写出去
    ServerInfo winfo = {"127.0.0.1", 888};
    ConfigManager cm;
    cm.WriteBinary(winfo);
    //二进制读写， 不能用string,会引发深拷贝问题，因为string里面_ptr是在堆上
    ServerInfo rinfo;
    cm.ReadBinary(rinfo);
    cout << rinfo._address << endl;
    cout << rinfo._port << endl;
}

//文本读写 传统方式
void test5() {
    //ServerInfo winfo = { "127.0.0.1",888 };
    ServerInfo winfo = {"https://legacy.cplusplus.com/reference/istream/istream/read/", 888};
    ConfigManager cm;
    cm.WriteText(winfo);


    ServerInfo rinfo;
    cm.ReadText(rinfo);
    cout << rinfo._address << endl;
    cout << rinfo._port << endl;
}

//新方式
void test6() {
    ServerInfo winfo = {"https://legacy.cplusplus.com/reference/istream/istream/read/", 888, {2023, 6, 29}};
    ConfigManager cm;
    cm.WriteText(winfo);
    ServerInfo rinfo;
    cm.ReadText(rinfo);
    cout << rinfo._address << endl;
    cout << rinfo._port << endl;
    cout << rinfo._date << endl;
}


struct ChatInfo {
    string _name;// 名字
    int _id = 0; // id
    Date _date;  // 时间
    string _msg; // 聊天信息
};

void test7() {
    //序列化
    ChatInfo winfo = {"张三", 135246, {2022, 4, 10}, "晚上一起看电影吧"};
    //ostringstream oss;
    stringstream oss;
    oss << winfo._name << endl;
    oss << winfo._id << endl;
    oss << winfo._date << endl;
    oss << winfo._msg << endl;

    string str = oss.str();
    cout << str << endl;


    //网络传输str,另一端接受到了字符串信息数据
    //反序列化
    ChatInfo rInfo;
    //istringstream iss(str);
    stringstream iss(str);
    iss >> rInfo._name;
    iss >> rInfo._id;
    iss >> rInfo._date;
    iss >> rInfo._msg;
    cout << "----------------------------------" << endl;
    cout << rInfo._date << endl;
    cout << rInfo._name << "[" << rInfo._id << "]:>" << rInfo._msg << endl;
    cout << "----------------------------------" << endl;
}
int main() {
    //test1();
    test7();
    return 0;
}
