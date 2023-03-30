#pragma once
#pragma warning(disable:4996)

#include<stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define LEN sizeof(Node)

/**
  * @struct Book
  * @brief 记录图书信息
  */
typedef struct _Information

{	/*编号*/
	int book_id;
	/*分类*/
	char book_class[100];
	/*书名*/
	char book_name[100];
	/*作者*/
	char book_author[100];
	/*出版社*/
	char book_press[100];
	/*数量*/
	char book_number[100];
	/*单价*/
	char book_price[100];
} Information;

struct Node
{
	Information Info;
	//链表下一位
	struct Node* next;
};

/*记录总数*/
int n = 0;

/*头节点*/
struct Node* head = nullptr;
/*尾节点*/
struct Node* tail = nullptr;

/*保存信息*/
void saveInformation();
/*读取信息*/
void initInformation();

/*菜单*/
void menus();
/*退出菜单*/
int quitMenus(int num);

/*查找*/
void checkInformation();
/*插入*/
void insertInformation();
/*删除*/
void deleteInformation();
/*排序*/
void sortInformation();

/*更新*/
void motifyInformation();
/*浏览*/
void scanfInformation();

/*打印信息*/
void printInformation(Node* p);