#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFAULT 3    //通讯录的默认大小
#define INC_SZ 2  //通讯录每次开辟的空间为2个
//表示一个人的信息
struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	int age;
	char addr[MAX_ADDR];
};
//通讯录
//struct Contact
//{
//	//静态的版本
//	struct PeoInfo data[MAX];  
//	int sz;
//};
//希望通讯里最开始可以存放3个人的信息，如果放慢了就自动增加空间，每次增加2个人的信息

struct Contact
{
	struct PeoInfo* data;  //指向了存放数据的空间
	int sz;  //已经放进去的信息
	int capacity; //容量
};

//初始化通讯里
void InitContact(struct Contact* pc);
//销毁通讯录
void DestroyContact(struct Contact* pc);
//增加信息到通讯录中
void AddContact(struct Contact* pc);
//删除指定联系人通讯录
void DelContact(struct Contact* pc);
//查找指定联系人
void SearchContact(struct Contact* pc);
//修改指定联系人的信息
void ModifyContact(struct Contact* pc);
//排序通讯录中的信息
void SortContact(struct Contact* pc);
//显示通讯里中的信息
void ShowContact(const struct Contact* pc);
//保存通讯录
void SaveContact(struct Contact* pc);
//加载文件的信息到通讯录
void LoadContact(struct Contact* pc);