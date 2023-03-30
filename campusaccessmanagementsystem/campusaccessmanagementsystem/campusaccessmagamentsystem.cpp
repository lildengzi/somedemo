/**
* @file campus_access_management_system
* @brief 校园出入管理系统
* @author 待写入
* @date 2022/12/11
* @version v1.0.0测试版
* @see None
*/

#include"campusaccessmanagementsystem.h"

void initInf()
{
	FILE* fpoint = fopen("D:\\test\information.dat", "r");
	if (fpoint == NULL)
	{
		printf("打开文件失败！\n");
		return;
	}
	Information info;
	while (fread(&info, 1, sizeof(Information), fpoint))
	{
		Node* newNode = (Node*)malloc(LEN);
		newNode->next = NULL;

		memcpy(newNode, &info, sizeof(Information));

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

	fclose(fpoint);
	printf("文件加载成功！\n");
}

void printInf(Node* p)
{
	printf("%s \t%s \t%s \t%s \t%s \t%d \t%s\n"\
		, p->Info.XDU_job\
		, p->Info.XDU_name\
		, p->Info.XDU_num\
		, p->Info.XDU_tel\
		, p->Info.XDU_id\
		, p->Info.XDU_io\
		, p->Info.time);
}

void menus()
{
	system("cls");
	while (true)
	{
		printf("\
**********欢迎使用校园出入管理系统**********\n\
--------------------------------------------\n\
-----------1.录入出入校园人员信息-----------\n\
-----------2.保存出入校园人员信息-----------\n\
-----------3.浏览出入校园人员信息-----------\n\
-----------4.查询出入校园人员信息-----------\n\
-----------5.增加出入校园人员信息-----------\n\
-----------6.删除出入校园人员信息-----------\n\
-----------7.修改出入校园人员信息-----------\n\
-----------8.统计出入校园人员信息-----------\n\
-----------9.对出入校园人员信息进行排序-----\n\
-----------10.退出--------------------------\n\
--------------------------------------------\n\
*****************谢谢使用!******************\n\
请选择 (1-10):\n");

		int option;
		(void)scanf("%d", &option);
			switch (option)
			{
			case 1:enterInf(); break;
			case 2:saveInf(); break;
			case 3:scanInf(); break;
			case 4:checkInf(); break;
			case 5:addInf(); break;
			case 6:delInf(); break;
			case 7:changeInf(); break;
			case 8:sumInf(); break;
			case 9:sortInf(); break;
			case 10: if (quitMenus(4) == 1)return;
				break;
			default:
				printf("你输入的格式有误,请重新输入！\n");
				break;
			}

			while (getchar() != '\n');
	}
}

void enterInf()
{
	Node* newNode = (Node*)malloc(LEN);
	newNode->next = NULL;

	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
		tail->next = NULL;
	}
	else
	{
		tail->next = newNode;
		tail = tail->next;
	}

	printf("请输入人员身份:\n");
	(void)scanf("%s", newNode->Info.XDU_job);
	printf("请输入姓名:\n");
	(void)scanf("%s", newNode->Info.XDU_name);
	printf("请输入编号:\n");
	(void)scanf("%s", newNode->Info.XDU_num);
	printf("请输入联系方式:\n");
	(void)scanf("%s", newNode->Info.XDU_tel);
	printf("请输入身份证号:\n");
	(void)scanf("%s", newNode->Info.XDU_id);
	printf("请输入出/入校(0/1):\n");
	(void)scanf("%d", &newNode->Info.XDU_io);
	printf("请输入出入校时间:\n");
	(void)scanf("%s", newNode->Info.time);
	printf("输入\"#\"号结束\n");
	while (getchar() != '#');

	n++;
	printf("学生信息录入成功!\n");
	system("pause");
	system("cls");
}

void saveInf()
{
	save();
	system("pause");
	system("cls");
}

void save()
{
	Node* p = head;

	FILE* fpoint = fopen("D:\\test\information.dat", "w");
	if (fpoint == NULL)
	{
		printf("打开文件失败!\n");
		return;
	}
	while (p != NULL)
	{
		fwrite(&p->Info, 1, sizeof(Information), fpoint);
		p = p->next;
	}
	fclose(fpoint);
	printf("数据保存成功！\n");
}

void scanInf()
{
	Node* p = head;

	printf("人员身份：人员姓名：编号：\t联系方式：\t身份证号：\t出入校：出入校时间：\n");
	if (p == NULL) { printf("没有信息！\n"); }

		while (p != NULL)
		{
			printInf(p);
			p = p->next;
		}
		printf("学生信息打印完毕！\n");

	system("pause");
	system("cls");
}

void checkInf()
{
	printf("A.按人员身份查询\n\
B.按姓名查询\n\
C.按出/入校查询\n\
D.退出至菜单\n\
请选择(A-D):\n");

	char ch;
	while (getchar() != '\n');
	(void)scanf("%c", &ch);
	switch (ch)
	{
	case 'a':
	case 'A':checkJob(); break;
	case 'b':
	case 'B':checkName(); break;
	case 'c':
	case 'C':checkIo(); break;
	case 'd':
	case 'D':quitMenus(1); break;
	default:
		printf("\
输入格式有误，请重新输入！\n");
		break;
	}
	system("pause");
	system("cls");
}

void checkJob()
{
	Node* p = head;
	char job[100];

	printf("请输入你想查找的人员身份\n");
	(void)scanf("%s", &job);
	while (p != NULL)
	{
		if (0 == strcmp(job, p->Info.XDU_job)){printInf(p);}
		p = p->next;
	}
}

void checkName()
{
	Node* p = head;
	char name[100];

	printf("请输入你想查找的人员姓名\n");
	(void)scanf("%s", &name);
	while (p != NULL)
	{
		if (0 == strcmp(name, p->Info.XDU_name)){printInf(p);}
		p = p->next;
	}
}

void checkIo()
{
	Node* p = head;
	int io;

	printf("请输入0/1查找出校/入校人员\n");
	(void)scanf("%d", &io);
	while (p != NULL)
	{
		if (io == p->Info.XDU_io){printInf(p);}
		p = p->next;
	}
}

void addInf()
{
	Node* newNode = (Node*)malloc(LEN);
	newNode->next = NULL;

	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
		tail->next = NULL;
	}
	else
	{
		tail->next = newNode;
		tail = tail->next;
	}

	printf("请输入人员身份:\n");
	(void)scanf("%s", newNode->Info.XDU_job);
	printf("请输入姓名:\n");
	(void)scanf("%s", newNode->Info.XDU_name);
	printf("请输入编号:\n");
	(void)scanf("%s", newNode->Info.XDU_num);
	printf("请输入联系方式:\n");
	(void)scanf("%s", newNode->Info.XDU_tel);
	printf("请输入身份证号:\n");
	(void)scanf("%s", newNode->Info.XDU_id);
	printf("请输入出/入校(0/1):\n");
	(void)scanf("%d", &newNode->Info.XDU_io);
	printf("请输入出入校时间:\n");
	(void)scanf("%s", newNode->Info.time);
	
	n++;
	printf("学生信息添加成功!\n");
	save();
	system("pause");
	system("cls");
}

void delInf()
{
	bool ok = false;
	Node* p = head;
	Node* p2 = head;
	char name[100], id[100], time[100];
	int io;

	printf("请输入姓名，身份证号，出/入校,出/入校时间:\n");
	(void)scanf("%s %s %d %s", name, id, &io, time);
	while (true)
	{
		if ((0 == strcmp(name, p->Info.XDU_name)) && (0 == strcmp(id, p->Info.XDU_id)) && (io == p->Info.XDU_io) && (0 == strcmp(time, p->Info.time)))
		{
			ok = true;
			printInf(p);
			printf("是否删除数据？y/n:\n");
			char ch;
			while (getchar() != '\n');
			(void)scanf("%c", &ch);
		switch (ch)
			{
			case 'y':
			case 'Y':
				if (p == head)
				{
					if(p->next != NULL)
					{
						head = head->next;
						free(p);
						p = head;
					}
					else
					{
						free(p);
						p = head = NULL;
					}
				}
				else
				{
					while (true)
					{
						if (p2->next == p)
						{
							p2->next = p->next;
							free(p);
							p = p2;
							break;
						}
						p2 = p2->next;
					}
				}
				break;
				default:
					printf("输入格式有误，请重新输入！\n");
					return;
			case 'n':
			case 'N':
				printf("将为你返回至菜单\n");
				Sleep(1000);
				return;
			}
		}
		if (p == NULL) { break; }
		p = p->next;
	}

	if (ok == false){printf("没有有关人员信息！\n");}
	system("pause");
	system("cls");
}

void changeInf()
{
	Node* p = head;
	bool ok = false;
	char name[100], id[100], time[100];
	int io;

	printf("请输入姓名，身份证号，出/入校,出/入校时间:\n");
	(void)scanf("%s %s %d %s", name, id, &io, time);
	while (p != NULL)
	{
		if ((0 == strcmp(name, p->Info.XDU_name)) && (0 == strcmp(id, p->Info.XDU_id)) && (io == p->Info.XDU_io) && (0 == strcmp(time, p->Info.time)))
		{
			ok = true;
			printInf(p);
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
				case 0: (void)scanf("%s", p->Info.XDU_job); break;
				case 1: (void)scanf("%s", p->Info.XDU_name); break;
				case 2: (void)scanf("%s", p->Info.XDU_num); break;
				case 3: (void)scanf("%s", p->Info.XDU_tel); break;
				case 4: (void)scanf("%s", p->Info.XDU_id); break;
				case 5: (void)scanf("%d", &p->Info.XDU_io); break;
				case 6: (void)scanf("%s", p->Info.time); break;
				default:
					printf("输入格式有误，请重新输入！\n");
					break;
				}; break;
			case 'n':
			case 'N':
				printf("将为你返回至菜单\n");
				Sleep(1000);
				return;
			default:
				printf("输入格式有误，请重新输入！\n");
				return;
			}
			printf("学生信息修改成功！\n");
			save();
			system("pause");
			system("cls");
		}
		p = p->next;
	}
	if (ok == false) { printf("没有有关人员信息！\n"); }
	system("pause");
	system("cls");
}

void sumInf()
{
	printf("A.统计当天出校人员总数\n\
B.统计当天入校人员总数\n\
C.统计所有时间段出校人员总数\n\
D.统计所有时间段入校人员总数\n\
E.退出至菜单\n\
请选择(A-E):\n");

	char ch;
	while (getchar() != '\n');
	(void)scanf("%c", &ch);
	switch (ch)
	{
	case 'a':
	case 'A':sumTodayOut(); break;
	case 'b':
	case 'B':sumTodayIn(); break;
	case 'c':
	case 'C':sumAllTimeOut(); break;
	case 'd':
	case 'D':sumAllTimeIn(); break;
	case 'e':
	case 'E':quitMenus(2); break;
	default:
		printf("输入格式有误，请重新输入！\n");
		break;
	}
}

void sumTodayOut()
{
	int count = 0;
	Node* p = head;
	char time[100];

	printf("请输入今天的时间！\n");
	(void)scanf("%s", time);

	if (p == NULL) { printf("没有信息！\n"); }
		while (p != NULL)
		{
			if (p->Info.XDU_io == 0 && 0 == strcmp(time , p->Info.time))count++;
			p = p->next;
		}

	printf("统计今天出校人员总数一共有%d人\n", count);
	system("pause");
	system("cls");
}

void sumTodayIn()
{
	int count = 0;
	Node* p = head;
	char time[100];

	printf("请输入今天的时间！\n");
	(void)scanf("%s", time);
	
	if (p == NULL) { printf("没有信息！\n"); }
		while (p != NULL)
		{
			if (p->Info.XDU_io == 1 && 0 == strcmp(time, p->Info.time))count++;
			p = p->next;
		}

	printf("统计今天入校人员总数一共有%d人\n", count);
	system("pause");
	system("cls");
}

void sumAllTimeOut()
{
	int count = 0;
	Node* p = head;

	if (p == NULL) { printf("没有信息！\n"); }
		while (p != NULL)
		{
			if (p->Info.XDU_io == 0)count++;
			p = p->next;
		}

	printf("统计出校人员总数一共有%d人\n",count);
	system("pause");
	system("cls");
}

void sumAllTimeIn()
{
	int count = 0;
	Node* p = head;

	if (p == NULL) { printf("没有信息！\n"); }
		while (p != NULL)
		{
			if (p->Info.XDU_io == 1)count++;
			p = p->next;
		}

	printf("统计入校人员总数一共有%d人\n", count);
	system("pause");
	system("cls");
}

void sortInf()
{
	printf("A.对所有人员进行升序排序\n\
B.对所有人员进行降序排序\n\
请选择(A-B):\n");

	char ch;
	while (getchar() != '\n');
	(void)scanf("%c", &ch);
	switch (ch)
	{
	case 'a':
	case 'A':highSort(); break;
	case 'b':
	case 'B':lowSort(); break;
	case 'c':
	case 'C':quitMenus(3); break;
	default:
		printf("输入格式有误，请重新输入！\n");
		break;
	}
}

void highSort()
{
	Node* p = head;

	for (int i = n - 1; i > 0; i--)
	{
		for (int j = i; j > 0; j--) 
		{
			if (0 > strcmp(p->Info.time,p->next->Info.time))
			{
				Information temp = p->next->Info;
				p->next->Info = p->Info;
				p->Info = temp;
			}
			p = p->next;
		}
		p = head;
	}

	while (p != NULL)
	{
		printInf(p);
		p = p->next;
	}

	printf("排序已完成!\n");
	system("pause");
	system("cls");
}

void lowSort()
{
	Node* p = head;

	for (int i = n - 1; i > 0; i--)
	{
		for (int j = i; j > 0; j--)
		{
			if (0 < strcmp(p->Info.time, p->next->Info.time))
			{
				Information temp = p->next->Info;
				p->next->Info = p->Info;
				p->Info = temp;
			}
			p = p->next;
		}
		p = head;
	}

	while (p != NULL)
	{
		printInf(p);
		p = p->next;
	}

	printf("排序已完成!\n");
	system("pause");
	system("cls");
}

int quitMenus(int num)
{
	char over = NULL;
	char ch = NULL;
	while (getchar() != '\n');
	printf("是否退至菜单???\n\
是/否请填(y/n)\n(已在菜单按\"n\"退出出入校系统)\n");
	
	(void)scanf("%c", &ch);
	switch (ch)
	{
	case 'y':
	case 'Y':
		menus();
	case 'n':
	case 'N':
		switch (num)
		{
		case 1:checkInf(); break;
		case 2:sumInf(); break;
		case 3:sortInf(); break;
		case 4:
			printf("是否确认退出该系统？(y/n)\n");
			while (getchar() != '\n');
			(void)scanf("%c", &over);

			switch (over)
			{
			case 'y':
			case 'Y':return 1;
			case 'n':
			case 'N':return 0;
			default:
				printf("输入格式有误，请重新输入！");
				break;
		}
		default:
			break;
	}
	default:
		printf("输入格式有误，请重新输入！\n");
		break;
	}
}

int main()
{
	initInf();
	Sleep(1000);
	menus();
	printf("您已退出系统\n");
	system("pause");
	return 0;
}