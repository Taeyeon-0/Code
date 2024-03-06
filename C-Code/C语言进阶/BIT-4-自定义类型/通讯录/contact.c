#include"contact.h"
//初始化通讯录
//静态的版本初始化
/*
void InitContact(struct Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	memset(pc->data, 0, 100 * sizeof(struct PeoInfo)); //将pc指向的data  100个struct PeoInfo数据初始化为0
}
*/
int check_capacity(struct Contact* pc);
void LoadContact(struct Contact* pc)
{
	//打开文件
	FILE* pf = fopen("data.txt", "rb");
	if (pf == NULL)
	{
		perror("LoadContact::fopen");
		return;
	}
	//读文件 - 通讯录最开始设置的为3个数据，超过3个怎么办？
	struct PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(struct PeoInfo), 1, pf))
	{
		//读完考虑增加容量的问题
		check_capacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
}
//动态的版本初始化
void InitContact(struct Contact* pc)
{
	assert(pc);
	pc->data = (struct PeoInfo*)malloc(3 * sizeof(struct PeoInfo));
	if (pc == NULL)
	{
		perror("InitContact()");
		return;
	}

	pc->sz = 0;
	pc->capacity = DEFAULT;
	//加载文件中的信息，到通讯录中
	LoadContact(pc);
}

//销毁通讯录
void DestroyContact(struct Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}

//增加信息到通讯录中(静态)
/*
void AddContact(struct Contact* pc)
{
	assert(pc);
	if (pc->sz == MAX)
	{
		printf("通讯录已满，无法添加数据\n");
		return;
	}
	//增加人的信息
	printf("请输入名字:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入年龄:>");
	scanf("%d", &pc->data[pc->sz].age);
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("成功增加联系人\n");
}
*/

static int check_capacity(struct Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		//增加容量
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(pc->data, (pc->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("增加容量成功\n");
			return 1;
		}
		else
		{
			perror("AddContact()");
			return 0;
		}
	}
	else return 1;   //有空间
}

//增加信息到通讯录中(动态)
void AddContact(struct Contact* pc)
{
	assert(pc);
	if (0 == check_capacity(pc))
		return;

	//增加人的信息
	printf("请输入名字:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入年龄:>");
	scanf("%d", &pc->data[pc->sz].age);
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("成功的增加联系人\n");
}


static int FindByName(const struct Contact* pc, char* name)  //static 只能再本源程序中使用该函数
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
			return i;
	}
	return -1;
}

//删除指定联系人通讯录
void DelContact(struct Contact* pc)
{
	char name[MAX_NAME];
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	//查找一下指定的人是否存在
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		//删除
		int j = 0;
		for (j = ret; j < pc->sz - 1; j++)
		{
			pc->data[j] = pc->data[j + 1];
		}
		pc->sz--;
		printf("成功删除联系人\n");
	}
}

//查找指定联系人
void SearchContact(const struct Contact* pc)
{
	char name[MAX_NAME];
	printf("请输入要查找的名字:>");
	scanf("%s", name);
	//查找一下指定的人是否存在
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "住址");
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-30s\n",
			pc->data[ret].name,
			pc->data[ret].sex,
			pc->data[ret].age,
			pc->data[ret].tele,
			pc->data[ret].addr);
	}
}


//修改指定联系人的信息
void ModifyContact(struct Contact* pc)
{
	char name[MAX_NAME];
	printf("请输入要修改的名字:>");
	scanf("%s", name);
	//查找一下指定的人是否存在
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("要修改的人不存在\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", pc->data[ret].name);
		printf("请输入性别:>");
		scanf("%s", pc->data[ret].sex);
		printf("请输入年龄:>");
		scanf("%d", &pc->data[ret].age);
		printf("请输入电话:>");
		scanf("%s", pc->data[ret].tele);
		printf("请输入地址:>");
		scanf("%s", pc->data[ret].addr);
		printf("成功修改联系人\n");
	}
}

int CmpByAge(const void* e1, const void* e2)
{
	return ((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age;
}

int CmpByName(const void* e1, const void* e2)
{
	return strcmp(((struct PeoInfo*)e1)->name, ((struct PeoInfo*)e2)->name);
}
//排序通讯录中的信息-按照年龄来排序
void SortContact(struct Contact* pc)
{
	//按照年龄排
	qsort(pc->data, pc->sz, sizeof(struct PeoInfo), CmpByAge);
	//按照姓名排
	//qsort(pc->data, pc->sz, sizeof(struct PeoInfo), CmpByName);
}

//显示通讯里中的信息
void ShowContact(const struct Contact* pc)  //不改变 只打印  加上const更好
{
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "住址");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-30s\n",
			pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}

//保存通讯录
void SaveContact(struct Contact* pc)
{
	//打开文件
	FILE* pfw = fopen("data.txt", "wb");  
	if (pfw == NULL)
	{
		perror("SaveContact::fopen");
		return;
	}
	else
	{
		//写文件
		int i = 0;
		for (i = 0; i < pc->sz; i++)
		{
			fwrite(pc->data + i, sizeof(struct PeoInfo), 1, pfw);
		}
		printf("保存文件成功\n");
	}
	//关闭文件
	fclose(pfw);
	pfw = NULL;
}