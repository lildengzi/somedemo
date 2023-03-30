#pragma once

#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6054)

#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define LEN sizeof(Node)

/**
  * @struct Information
  * @brief 记录出入校园人员信息
  * @note 该结构体是一个链表
  * 
  */
typedef struct _Information
{
	//人员身份
	char XDU_job[100];

	//姓名
	char XDU_name[100];

	//编号
	char XDU_num[100];

	//联系方式
	char XDU_tel[100];

	//身份证号
	char XDU_id[100];

	//出/入校（0/1）
	int XDU_io;
	//出入时间
	char time[100];
} Information;

struct Node
{
	Information Info;
	//链表下一位
	struct Node* next;
};

//记录总数
int n = 0;

//头节点
struct Node* head = nullptr;
//尾节点
struct Node* tail = nullptr;

//打印人员信息
void printInf(Node* p);
//主菜单
void menus();
//录入出入校园人员信息
void enterInf();
//保存出入校园人员信息
void saveInf();
void save();
//读取出入校园人员信息
void initInf();
//浏览出入校园人员信息
void scanInf();
//查询出入校园人员信息
void checkInf();
//按人员身份查询
void checkJob();
//按姓名查询
void checkName();
//按出入校查询
void checkIo();
//增加出入校园人员信息
void addInf();
//删除出入校园人员信息
void delInf();
//修改出入校园人员信息
void changeInf();
//统计出入校园人员信息
void sumInf();
//当天出校人员总数统计
void sumTodayOut();
//当天入校人员总数统计
void sumTodayIn();
//出校人员总数统计
void sumAllTimeOut();
//入校人员总数统计
void sumAllTimeIn();
//对出入校园人员信息进行排序
void sortInf();
//升序排序
void highSort();
//降序排序
void lowSort();
//退出菜单
int quitMenus(int num);