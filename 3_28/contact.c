#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
#include <errno.h>

void CheckCapacity(Contact *pc)
{
	PeoInfo* ptr=(PeoInfo*)realloc(pc->data, (pc->capacity + 2) * sizeof(PeoInfo));
	{
		if (ptr == NULL)
		{
			printf("%s\n", strerror(errno));
			return;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += 2;
		}
	}
}

void InitContact(Contact* pc)
{
	pc->count = 0;
	pc->data = (PeoInfo*)calloc(3, sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		printf("%s\n", strerror(errno));
		return ;
	}
	pc->capacity = 3;
}
void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->count == pc->capacity)
	{
		CheckCapacity(pc);//增容
	}
	printf("请输入姓名:>");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->count].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->count].sex);		
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->count].addr);

	pc->count++;
	printf("增加成功\n");
}

void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	
	for (i = 0;i < pc->count;i++)
	{
		printf("%-20s\t%-3s\t%-5s\t%-12s\t%-30s\n","姓名","年龄", "性别","电话","地址");

		printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n", pc->data[i].name,
			                                   pc->data[i].age,
		                                   	   pc->data[i].sex,
			                                   pc->data[i].tele,
			                                   pc->data[i].addr);
	}

}
int FindByName(const Contact* pc, const char name[20])
{
	int i = 0;
	for (i = 0;i < pc->count;i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
		
	}
	return -1;
}
void DelContact(Contact* pc)
{
	int ret;
	int i = 0;
	char name[20];
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;
	}
	printf("请输入姓名:>");
	scanf("%s", name);
	ret=FindByName(pc,name);
    if (ret >= 0)
	{
		for (i = ret;i < pc->count - 1;i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		(pc->count)--;
		printf("删除成功\n");
	}
	else
	{
		printf("未找到此联系人\n");
	}
}

void SearchContact(const Contact* pc)
{
	char name[20];
	int ret;
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空，无法查询\n");
		return;
	}
	printf("请输入姓名:>");
	scanf("%s", name);
	ret = FindByName(pc, name);
    if (ret >= 0)
	{
		printf("%-20s\t%-3s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");

		printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n", pc->data[ret].name,
			pc->data[ret].age,
			pc->data[ret].sex,
			pc->data[ret].tele,
			pc->data[ret].addr);
		printf("查询成功\n");
	}
	else
	{
		printf("未找到此联系人\n");
	}
}
void ModifyContact(Contact* pc)
{
	char name[20];
	int ret;
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空，无法修改\n");
		return;
	}
	printf("请输入被修改人的姓名:>");
	scanf("%s", name);
	ret = FindByName(pc, name);
    if (ret >= 0)
	{
		printf("请输入新的姓名:>");
		scanf("%s", pc->data[ret].name);
		printf("请输入年龄:>");
		scanf("%d", &(pc->data[ret].age));
		printf("请输入性别:>");
		scanf("%s", pc->data[ret].sex);
		printf("请输入电话:>");
		scanf("%s", pc->data[ret].tele);
		printf("请输入地址:>");
		scanf("%s", pc->data[ret].addr);
		printf("修改成功\n");
	}
	else
	{
		printf("未找到此联系人\n");
	}
}
int cmp_peo_by_name(const void* e1, const void* e2)
{
    return(strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name));
}
void SortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
	printf("排序成功\n");
}

void DestroyContact(Contact* pc)
{
	if (pc == NULL)
		return;
	free(pc->data);
	pc->data = NULL;
	pc->count = 0;
	pc->capacity = 0;
}
