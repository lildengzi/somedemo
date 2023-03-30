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
  * @brief ��¼����У԰��Ա��Ϣ
  * @note �ýṹ����һ������
  * 
  */
typedef struct _Information
{
	//��Ա���
	char XDU_job[100];

	//����
	char XDU_name[100];

	//���
	char XDU_num[100];

	//��ϵ��ʽ
	char XDU_tel[100];

	//���֤��
	char XDU_id[100];

	//��/��У��0/1��
	int XDU_io;
	//����ʱ��
	char time[100];
} Information;

struct Node
{
	Information Info;
	//������һλ
	struct Node* next;
};

//��¼����
int n = 0;

//ͷ�ڵ�
struct Node* head = nullptr;
//β�ڵ�
struct Node* tail = nullptr;

//��ӡ��Ա��Ϣ
void printInf(Node* p);
//���˵�
void menus();
//¼�����У԰��Ա��Ϣ
void enterInf();
//�������У԰��Ա��Ϣ
void saveInf();
void save();
//��ȡ����У԰��Ա��Ϣ
void initInf();
//�������У԰��Ա��Ϣ
void scanInf();
//��ѯ����У԰��Ա��Ϣ
void checkInf();
//����Ա��ݲ�ѯ
void checkJob();
//��������ѯ
void checkName();
//������У��ѯ
void checkIo();
//���ӳ���У԰��Ա��Ϣ
void addInf();
//ɾ������У԰��Ա��Ϣ
void delInf();
//�޸ĳ���У԰��Ա��Ϣ
void changeInf();
//ͳ�Ƴ���У԰��Ա��Ϣ
void sumInf();
//�����У��Ա����ͳ��
void sumTodayOut();
//������У��Ա����ͳ��
void sumTodayIn();
//��У��Ա����ͳ��
void sumAllTimeOut();
//��У��Ա����ͳ��
void sumAllTimeIn();
//�Գ���У԰��Ա��Ϣ��������
void sortInf();
//��������
void highSort();
//��������
void lowSort();
//�˳��˵�
int quitMenus(int num);