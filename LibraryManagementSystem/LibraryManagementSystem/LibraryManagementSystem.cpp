/**@file  LibraryManagementSystem.c
* @brief  ��Ŀ�������ļ�
* @details  ��Ҫ����Э��Ӧ��ջ�����ܣ�main�������
* @author  С����
* @date  2023-01-07
* @version     V1.0
* @copyright    
**********************************************************************************
* 
* @attention
* SDK�汾��v2050.0.0
* @par �޸���־:
* <table>
* <tr><th>Date        <th>Version  <th>Author    <th>Description
* <tr><td>2010/02/17  <td>1.0      <td>wanghuan  <td>������ʼ�汾
* </table>
*
**********************************************************************************
*/

#include "LibraryManagementSystem.h"


void initInformation()
{
	FILE* fp = fopen("./books.txt", "r");
	if (fp == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		return;
	}
	Information info;
	while (fread(&info, sizeof(Information), 1, fp))
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->next = NULL;
		newNode->Info = info;

		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
		n++;
	}

	fclose(fp);
	printf("���ݼ��سɹ���\n");
}

void saveInformation()
{
	Node* p = head;
	FILE* fpoint = fopen("./books.txt", "w");
	if (fpoint == NULL)
	{
		printf("���ļ�ʧ��!\n");
		return;
	}
	while (p != NULL)
	{
		fwrite(&p->Info,  sizeof(Information), 1, fpoint);
		p = p->next;
	}

	fclose(fpoint);
}

void menus()
{
	system("cls");
	while (TRUE)
	{
		printf("\
************��ӭʹ��ͼ�����ϵͳ************\n\
--------------------------------------------\n\
---------------1.����ͼ����Ϣ---------------\n\
---------------2.����ͼ����Ϣ---------------\n\
---------------3.ɾ��ͼ����Ϣ---------------\n\
---------------4.���ͼ����Ϣ---------------\n\
---------------5.��¼��ͼ����Ϣ��������-----\n\
---------------6.����ͼ����Ϣ---------------\n\
---------------7.�˳�-----------------------\n\
--------------------------------------------\n\
*****************ллʹ��!******************\n\
��ѡ�� (1-7):\n");

		int option;
		scanf_s("%d", &option);
		switch (option)
		{
		case 1:checkInformation(); break;
		case 2:insertInformation(); break;
		case 3:deleteInformation(); break;
		case 4:scanfInformation(); break;
		case 5:sortInformation(); break;
		case 6:motifyInformation(); break;
		case 7:if (quitMenus(0) == 1)return;
			break;
		default:
			printf("������ĸ�ʽ����,���������룡\n");
			break;
		}

		while (getchar() != '\n');
	}
}

int quitMenus(int num)
{
	char over = NULL;
	char ch = NULL;
	while (getchar() != '\n');
	printf("�Ƿ������˵�?\n\
��/������(y/n)\n\
(���ڲ˵���\"n\"�˳�����Уϵͳ)\n");

	scanf_s("%c", &ch, 1);
	switch (ch)
	{
	case 'y':
	case 'Y':
		menus();
	case 'n':
	case 'N':
		switch (num)
		{
		case 1:checkInformation(); break;
		case 2:sortInformation(); break;
		case 0:saveInformation();
			printf("�����ѱ��档");
			return 1;
		default:
			printf("�����ʽ����,����������!\n");
			break;
		}
	default:
		printf("�����ʽ�������������룡\n");
		break;
	}
	return 0;
}

void printInformation(Node* p)
{
	printf("%-8d %-10s %-20s %-15s %-20s %-5s %-10s\n" \
	,p->Info.book_id\
	,p->Info.book_class\
	,p->Info.book_name\
	,p->Info.book_author\
	,p->Info.book_press\
	,p->Info.book_number\
	,p->Info.book_price);
}

void scanfInformation()
{
	Node* p = head;

	printf("���:    ����:\t  ����:\t\t      ����:\t    ������:\t\t  ����:\t  �۸�:\n");
	if (p == NULL) { printf("û����Ϣ��\n"); return; }

	while (p != NULL)
	{
		printInformation(p);
		p = p->next;
	}
}

void checkInformation()
{
	int book_id;
	printf("������Ҫ���ҵ�ͼ��ı��: ");
	scanf("%d", &book_id);

	Node* curr = head;
	while (curr != NULL && curr->Info.book_id != book_id) 
	{
		curr = curr->next;
	}

	if (curr == NULL) 
	{
		printf("δ�ҵ����Ϊ%s��ͼ��!\n", book_id);
		return;
	}
	else
	{
		printInformation(curr);
	}
	
	system("pause");
	system("cls");
}

void insertInformation()
{
	printf("��������ͼ�����Ϣ:\n");
	Information info;
	printf("���: \n");
	scanf("%d", &info.book_id);
	printf("����: \n");
	scanf("%s", info.book_class);
	printf("����: \n");
	scanf("%s", info.book_name);
	printf("����: \n");
	scanf("%s", info.book_author);
	printf("������: \n");
	scanf("%s", info.book_press);
	printf("����: \n");
	scanf("%s", info.book_number);
	printf("����: \n");
	scanf("%s", info.book_price);

	int pos;
	printf("��������ͼ��Ĳ���λ��(��1��ʼ): ");
	scanf_s("%d", &pos);
	if (pos < 1 || pos > n + 1) {
		printf("�������λ������,����������!\n");
		return;
	}

	Node* newNode = (Node*)malloc(LEN);
	newNode->next = NULL;
	memcpy(newNode, &info, sizeof(Information));

	if (pos == 1) 
	{
		newNode->next = head;
		head = newNode;
	}
	else 
	{
		Node* prev = head;
		for (int i = 1; i < pos - 1; i++) {
			prev = prev->next;
		}
		newNode->next = prev->next;
		prev->next = newNode;
	}

	if (pos == n + 1) {
		tail = newNode;
	}

	n++;
	scanfInformation();
	saveInformation();
	printf("��ͼ�����ɹ�!\n");
	system("pause");
	system("cls");
}

void deleteInformation()
{
	int book_id;
	scanfInformation();
	printf("������Ҫɾ����ͼ��ı��: ");
	scanf("%d", &book_id);

	Node* prev = NULL;
	Node* curr = head;
	while (curr != NULL && curr->Info.book_id != book_id) 
	{
		prev = curr;
		curr = curr->next;
	}

	if (curr == NULL) 
	{
		printf("δ�ҵ����Ϊ%s��ͼ��!\n", book_id);
		return;
	}

	if (prev == NULL) 
	{
		head = curr->next;
	}
	else 
	{
		prev->next = curr->next;
	}

	if (curr == tail) {
		tail = prev;
	}
	free(curr);
	n--;
	scanfInformation();
	saveInformation();
	printf("ͼ��ɾ���ɹ�!\n");
	system("pause");
	system("cls");
}

void sortInformation()
{
	Node* p = head;

	printf("A.��������Ա������������\n\
B.��������Ա���н�������\n\
��ѡ��(A-B):\n");

	char ch;
	while (getchar() != '\n');
	(void)scanf("%c", &ch);
	switch (ch)
	{
	case 'a':
	case 'A':
	{	
		//ð��
		for (int i = n - 1; i > 0; i--)
		{
			for (int j = i; j > 0; j--)
			{
				if (p->Info.book_id > p->next->Info.book_id)
				{
					Information temp = p->next->Info;
					p->next->Info = p->Info;
					p->Info = temp;
				}
				p = p->next;
			}
			p = head;
		}
	}break;
	case 'b':
	case 'B':
	{	
		for (int i = n - 1; i > 0; i--)
		{
			int max = i;
			for (int j = i; j > 0; j--)
			{
				if (p->Info.book_id <  p->next->Info.book_id)
				{
					max = j;
				}
				p = p->next;
			}
			if (max != i) {
				Information temp = p->Info;
				p->Info = p->Info;
				p->Info = temp;
			}
			p = head;
		}
	}break;
	case 'c':
	case 'C':quitMenus(3); break;
	default:
		printf("�����ʽ�������������룡\n");
		break;
	}

	printf("\n�����:\n");
	scanfInformation();
	saveInformation();
	printf("���������!\n");
	system("pause");
	system("cls");
}

void motifyInformation()
{
	Node* p = head;
	bool ok = FALSE;
	int book_id;

	printf("��������\n");
	scanf("%d", &book_id);
	while (p != NULL)
	{
		if (book_id == p->Info.book_id)
		{
			ok = TRUE;
			printInformation(p);
			printf("�Ƿ��޸����ݣ�y/n:\n");
			char ch;
			while (getchar() != '\n');
			(void)scanf("%c", &ch);

			switch (ch)
			{
			case 'y':
			case 'Y':
				printf("�޸�������Ϣ(0-6):\n");
				int choose;
				while (getchar() != '\n');
				(void)scanf("%d", &choose);
				printf("�����޸���Ϣ:\n");
				switch (choose)
				{
				case 0: (void)scanf("%lld", &p->Info.book_id); break;
				case 1: (void)scanf("%s", p->Info.book_class); break;
				case 2: (void)scanf("%s", p->Info.book_name); break;
				case 3: (void)scanf("%s", p->Info.book_author); break;
				case 4: (void)scanf("%s", p->Info.book_press); break;
				case 5: (void)scanf("%s", p->Info.book_number); break;
				case 6: (void)scanf("%s", p->Info.book_price); break;
				default:
					printf("�����ʽ�������������룡\n");
					break;
				} break;
			case 'n':
			case 'N':
				printf("��Ϊ�㷵�����˵�\n");
				Sleep(600);
				return;
			default:
				printf("�����ʽ�������������룡\n");
				return;
			}
			printInformation(p);
			saveInformation();
			printf("ѧ����Ϣ�޸ĳɹ���\n");
			system("pause");
			system("cls");
		}
		p = p->next;
	}

	if (ok == FALSE) { printf("û���й��鼮��Ϣ��\n"); }
}

int main()
{
	initInformation();
	Sleep(600);
	menus();
	return 0;
}