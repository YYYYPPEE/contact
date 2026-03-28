#pragma once
#include<string.h>
#include<assert.h>
#include <stdio.h>
#include<stdlib.h>
//类型声明
typedef struct PeoInfo
{
	char name[20];
	int age;
	char sex[10];
	char tele[12];
	char addr[30];
}PeoInfo;


//通讯录
typedef struct Contact
{
	PeoInfo data[100];
	int count;
}Contact;

void InitContact(Contact *pc);//初始化
//增加成员
void AddContact(Contact* pc);
//删除成员
void DelContact(Contact* pc);

//展示通讯录
void ShowContact(const Contact* pc);

//查询通讯录
void SearchContact(const Contact* pc);

//修改通讯录
void ModifyhContact(const Contact* pc);
//给通讯录排序
void SortContact(const Contact* pc);
