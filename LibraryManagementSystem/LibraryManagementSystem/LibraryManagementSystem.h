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
  * @brief ��¼ͼ����Ϣ
  */
typedef struct _Information

{	/*���*/
	int book_id;
	/*����*/
	char book_class[100];
	/*����*/
	char book_name[100];
	/*����*/
	char book_author[100];
	/*������*/
	char book_press[100];
	/*����*/
	char book_number[100];
	/*����*/
	char book_price[100];
} Information;

struct Node
{
	Information Info;
	//������һλ
	struct Node* next;
};

/*��¼����*/
int n = 0;

/*ͷ�ڵ�*/
struct Node* head = nullptr;
/*β�ڵ�*/
struct Node* tail = nullptr;

/*������Ϣ*/
void saveInformation();
/*��ȡ��Ϣ*/
void initInformation();

/*�˵�*/
void menus();
/*�˳��˵�*/
int quitMenus(int num);

/*����*/
void checkInformation();
/*����*/
void insertInformation();
/*ɾ��*/
void deleteInformation();
/*����*/
void sortInformation();

/*����*/
void motifyInformation();
/*���*/
void scanfInformation();

/*��ӡ��Ϣ*/
void printInformation(Node* p);