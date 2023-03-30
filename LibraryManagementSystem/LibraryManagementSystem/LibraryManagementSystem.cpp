/**@file  LibraryManagementSystem.c
* @brief  项目主函数文件
* @details  主要包含协议应用栈程序框架，main函数入口
* @author  小邓子
* @date  2023-01-07
* @version     V1.0
* @copyright    
**********************************************************************************
* 
* @attention
* SDK版本：v2050.0.0
* @par 修改日志:
* <table>
* <tr><th>Date        <th>Version  <th>Author    <th>Description
* <tr><td>2010/02/17  <td>1.0      <td>wanghuan  <td>创建初始版本
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
		printf("打开文件失败！\n");
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
	printf("数据加载成功！\n");
}

void saveInformation()
{
	Node* p = head;
	FILE* fpoint = fopen("./books.txt", "w");
	if (fpoint == NULL)
	{
		printf("打开文件失败!\n");
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
************欢迎使用图书管理系统************\n\
--------------------------------------------\n\
---------------1.查找图书信息---------------\n\
---------------2.插入图书信息---------------\n\
---------------3.删除图书信息---------------\n\
---------------4.浏览图书信息---------------\n\
---------------5.对录入图书信息进行排序-----\n\
---------------6.更新图书信息---------------\n\
---------------7.退出-----------------------\n\
--------------------------------------------\n\
*****************谢谢使用!******************\n\
请选择 (1-7):\n");

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
			printf("你输入的格式有误,请重新输入！\n");
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
	printf("是否退至菜单?\n\
是/否请填(y/n)\n\
(已在菜单按\"n\"退出出入校系统)\n");

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
			printf("数据已保存。");
			return 1;
		default:
			printf("输入格式有误,请重新输入!\n");
			break;
		}
	default:
		printf("输入格式有误，请重新输入！\n");
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

	printf("编号:    分类:\t  书名:\t\t      作者:\t    出版社:\t\t  数量:\t  价格:\n");
	if (p == NULL) { printf("没有信息！\n"); return; }

	while (p != NULL)
	{
		printInformation(p);
		p = p->next;
	}
}

void checkInformation()
{
	int book_id;
	printf("请输入要查找的图书的编号: ");
	scanf("%d", &book_id);

	Node* curr = head;
	while (curr != NULL && curr->Info.book_id != book_id) 
	{
		curr = curr->next;
	}

	if (curr == NULL) 
	{
		printf("未找到编号为%s的图书!\n", book_id);
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
	printf("请输入新图书的信息:\n");
	Information info;
	printf("编号: \n");
	scanf("%d", &info.book_id);
	printf("分类: \n");
	scanf("%s", info.book_class);
	printf("书名: \n");
	scanf("%s", info.book_name);
	printf("作者: \n");
	scanf("%s", info.book_author);
	printf("出版社: \n");
	scanf("%s", info.book_press);
	printf("数量: \n");
	scanf("%s", info.book_number);
	printf("单价: \n");
	scanf("%s", info.book_price);

	int pos;
	printf("请输入新图书的插入位置(从1开始): ");
	scanf_s("%d", &pos);
	if (pos < 1 || pos > n + 1) {
		printf("你输入的位置有误,请重新输入!\n");
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
	printf("新图书插入成功!\n");
	system("pause");
	system("cls");
}

void deleteInformation()
{
	int book_id;
	scanfInformation();
	printf("请输入要删除的图书的编号: ");
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
		printf("未找到编号为%s的图书!\n", book_id);
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
	printf("图书删除成功!\n");
	system("pause");
	system("cls");
}

void sortInformation()
{
	Node* p = head;

	printf("A.对所有人员进行升序排序\n\
B.对所有人员进行降序排序\n\
请选择(A-B):\n");

	char ch;
	while (getchar() != '\n');
	(void)scanf("%c", &ch);
	switch (ch)
	{
	case 'a':
	case 'A':
	{	
		//冒泡
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
		printf("输入格式有误，请重新输入！\n");
		break;
	}

	printf("\n排序后:\n");
	scanfInformation();
	saveInformation();
	printf("排序已完成!\n");
	system("pause");
	system("cls");
}

void motifyInformation()
{
	Node* p = head;
	bool ok = FALSE;
	int book_id;

	printf("请输入编号\n");
	scanf("%d", &book_id);
	while (p != NULL)
	{
		if (book_id == p->Info.book_id)
		{
			ok = TRUE;
			printInformation(p);
			printf("是否修改数据？y/n:\n");
			char ch;
			while (getchar() != '\n');
			(void)scanf("%c", &ch);

			switch (ch)
			{
			case 'y':
			case 'Y':
				printf("修改哪项信息(0-6):\n");
				int choose;
				while (getchar() != '\n');
				(void)scanf("%d", &choose);
				printf("输入修改信息:\n");
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
					printf("输入格式有误，请重新输入！\n");
					break;
				} break;
			case 'n':
			case 'N':
				printf("将为你返回至菜单\n");
				Sleep(600);
				return;
			default:
				printf("输入格式有误，请重新输入！\n");
				return;
			}
			printInformation(p);
			saveInformation();
			printf("学生信息修改成功！\n");
			system("pause");
			system("cls");
		}
		p = p->next;
	}

	if (ok == FALSE) { printf("没有有关书籍信息！\n"); }
}

int main()
{
	initInformation();
	Sleep(600);
	menus();
	return 0;
}