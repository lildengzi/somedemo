/**
* @file campus_access_management_system
* @brief У԰�������ϵͳ
* @author ��д��
* @date 2022/12/11
* @version v1.0.0���԰�
* @see None
*/

#include"campusaccessmanagementsystem.h"

void initInf()
{
	FILE* fpoint = fopen("D:\\test\information.dat", "r");
	if (fpoint == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
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
	printf("�ļ����سɹ���\n");
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
**********��ӭʹ��У԰�������ϵͳ**********\n\
--------------------------------------------\n\
-----------1.¼�����У԰��Ա��Ϣ-----------\n\
-----------2.�������У԰��Ա��Ϣ-----------\n\
-----------3.�������У԰��Ա��Ϣ-----------\n\
-----------4.��ѯ����У԰��Ա��Ϣ-----------\n\
-----------5.���ӳ���У԰��Ա��Ϣ-----------\n\
-----------6.ɾ������У԰��Ա��Ϣ-----------\n\
-----------7.�޸ĳ���У԰��Ա��Ϣ-----------\n\
-----------8.ͳ�Ƴ���У԰��Ա��Ϣ-----------\n\
-----------9.�Գ���У԰��Ա��Ϣ��������-----\n\
-----------10.�˳�--------------------------\n\
--------------------------------------------\n\
*****************ллʹ��!******************\n\
��ѡ�� (1-10):\n");

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
				printf("������ĸ�ʽ����,���������룡\n");
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

	printf("��������Ա���:\n");
	(void)scanf("%s", newNode->Info.XDU_job);
	printf("����������:\n");
	(void)scanf("%s", newNode->Info.XDU_name);
	printf("��������:\n");
	(void)scanf("%s", newNode->Info.XDU_num);
	printf("��������ϵ��ʽ:\n");
	(void)scanf("%s", newNode->Info.XDU_tel);
	printf("���������֤��:\n");
	(void)scanf("%s", newNode->Info.XDU_id);
	printf("�������/��У(0/1):\n");
	(void)scanf("%d", &newNode->Info.XDU_io);
	printf("���������Уʱ��:\n");
	(void)scanf("%s", newNode->Info.time);
	printf("����\"#\"�Ž���\n");
	while (getchar() != '#');

	n++;
	printf("ѧ����Ϣ¼��ɹ�!\n");
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
		printf("���ļ�ʧ��!\n");
		return;
	}
	while (p != NULL)
	{
		fwrite(&p->Info, 1, sizeof(Information), fpoint);
		p = p->next;
	}
	fclose(fpoint);
	printf("���ݱ���ɹ���\n");
}

void scanInf()
{
	Node* p = head;

	printf("��Ա��ݣ���Ա��������ţ�\t��ϵ��ʽ��\t���֤�ţ�\t����У������Уʱ�䣺\n");
	if (p == NULL) { printf("û����Ϣ��\n"); }

		while (p != NULL)
		{
			printInf(p);
			p = p->next;
		}
		printf("ѧ����Ϣ��ӡ��ϣ�\n");

	system("pause");
	system("cls");
}

void checkInf()
{
	printf("A.����Ա��ݲ�ѯ\n\
B.��������ѯ\n\
C.����/��У��ѯ\n\
D.�˳����˵�\n\
��ѡ��(A-D):\n");

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
�����ʽ�������������룡\n");
		break;
	}
	system("pause");
	system("cls");
}

void checkJob()
{
	Node* p = head;
	char job[100];

	printf("������������ҵ���Ա���\n");
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

	printf("������������ҵ���Ա����\n");
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

	printf("������0/1���ҳ�У/��У��Ա\n");
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

	printf("��������Ա���:\n");
	(void)scanf("%s", newNode->Info.XDU_job);
	printf("����������:\n");
	(void)scanf("%s", newNode->Info.XDU_name);
	printf("��������:\n");
	(void)scanf("%s", newNode->Info.XDU_num);
	printf("��������ϵ��ʽ:\n");
	(void)scanf("%s", newNode->Info.XDU_tel);
	printf("���������֤��:\n");
	(void)scanf("%s", newNode->Info.XDU_id);
	printf("�������/��У(0/1):\n");
	(void)scanf("%d", &newNode->Info.XDU_io);
	printf("���������Уʱ��:\n");
	(void)scanf("%s", newNode->Info.time);
	
	n++;
	printf("ѧ����Ϣ��ӳɹ�!\n");
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

	printf("���������������֤�ţ���/��У,��/��Уʱ��:\n");
	(void)scanf("%s %s %d %s", name, id, &io, time);
	while (true)
	{
		if ((0 == strcmp(name, p->Info.XDU_name)) && (0 == strcmp(id, p->Info.XDU_id)) && (io == p->Info.XDU_io) && (0 == strcmp(time, p->Info.time)))
		{
			ok = true;
			printInf(p);
			printf("�Ƿ�ɾ�����ݣ�y/n:\n");
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
					printf("�����ʽ�������������룡\n");
					return;
			case 'n':
			case 'N':
				printf("��Ϊ�㷵�����˵�\n");
				Sleep(1000);
				return;
			}
		}
		if (p == NULL) { break; }
		p = p->next;
	}

	if (ok == false){printf("û���й���Ա��Ϣ��\n");}
	system("pause");
	system("cls");
}

void changeInf()
{
	Node* p = head;
	bool ok = false;
	char name[100], id[100], time[100];
	int io;

	printf("���������������֤�ţ���/��У,��/��Уʱ��:\n");
	(void)scanf("%s %s %d %s", name, id, &io, time);
	while (p != NULL)
	{
		if ((0 == strcmp(name, p->Info.XDU_name)) && (0 == strcmp(id, p->Info.XDU_id)) && (io == p->Info.XDU_io) && (0 == strcmp(time, p->Info.time)))
		{
			ok = true;
			printInf(p);
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
				case 0: (void)scanf("%s", p->Info.XDU_job); break;
				case 1: (void)scanf("%s", p->Info.XDU_name); break;
				case 2: (void)scanf("%s", p->Info.XDU_num); break;
				case 3: (void)scanf("%s", p->Info.XDU_tel); break;
				case 4: (void)scanf("%s", p->Info.XDU_id); break;
				case 5: (void)scanf("%d", &p->Info.XDU_io); break;
				case 6: (void)scanf("%s", p->Info.time); break;
				default:
					printf("�����ʽ�������������룡\n");
					break;
				}; break;
			case 'n':
			case 'N':
				printf("��Ϊ�㷵�����˵�\n");
				Sleep(1000);
				return;
			default:
				printf("�����ʽ�������������룡\n");
				return;
			}
			printf("ѧ����Ϣ�޸ĳɹ���\n");
			save();
			system("pause");
			system("cls");
		}
		p = p->next;
	}
	if (ok == false) { printf("û���й���Ա��Ϣ��\n"); }
	system("pause");
	system("cls");
}

void sumInf()
{
	printf("A.ͳ�Ƶ����У��Ա����\n\
B.ͳ�Ƶ�����У��Ա����\n\
C.ͳ������ʱ��γ�У��Ա����\n\
D.ͳ������ʱ�����У��Ա����\n\
E.�˳����˵�\n\
��ѡ��(A-E):\n");

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
		printf("�����ʽ�������������룡\n");
		break;
	}
}

void sumTodayOut()
{
	int count = 0;
	Node* p = head;
	char time[100];

	printf("����������ʱ�䣡\n");
	(void)scanf("%s", time);

	if (p == NULL) { printf("û����Ϣ��\n"); }
		while (p != NULL)
		{
			if (p->Info.XDU_io == 0 && 0 == strcmp(time , p->Info.time))count++;
			p = p->next;
		}

	printf("ͳ�ƽ����У��Ա����һ����%d��\n", count);
	system("pause");
	system("cls");
}

void sumTodayIn()
{
	int count = 0;
	Node* p = head;
	char time[100];

	printf("����������ʱ�䣡\n");
	(void)scanf("%s", time);
	
	if (p == NULL) { printf("û����Ϣ��\n"); }
		while (p != NULL)
		{
			if (p->Info.XDU_io == 1 && 0 == strcmp(time, p->Info.time))count++;
			p = p->next;
		}

	printf("ͳ�ƽ�����У��Ա����һ����%d��\n", count);
	system("pause");
	system("cls");
}

void sumAllTimeOut()
{
	int count = 0;
	Node* p = head;

	if (p == NULL) { printf("û����Ϣ��\n"); }
		while (p != NULL)
		{
			if (p->Info.XDU_io == 0)count++;
			p = p->next;
		}

	printf("ͳ�Ƴ�У��Ա����һ����%d��\n",count);
	system("pause");
	system("cls");
}

void sumAllTimeIn()
{
	int count = 0;
	Node* p = head;

	if (p == NULL) { printf("û����Ϣ��\n"); }
		while (p != NULL)
		{
			if (p->Info.XDU_io == 1)count++;
			p = p->next;
		}

	printf("ͳ����У��Ա����һ����%d��\n", count);
	system("pause");
	system("cls");
}

void sortInf()
{
	printf("A.��������Ա������������\n\
B.��������Ա���н�������\n\
��ѡ��(A-B):\n");

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
		printf("�����ʽ�������������룡\n");
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

	printf("���������!\n");
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

	printf("���������!\n");
	system("pause");
	system("cls");
}

int quitMenus(int num)
{
	char over = NULL;
	char ch = NULL;
	while (getchar() != '\n');
	printf("�Ƿ������˵�???\n\
��/������(y/n)\n(���ڲ˵���\"n\"�˳�����Уϵͳ)\n");
	
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
			printf("�Ƿ�ȷ���˳���ϵͳ��(y/n)\n");
			while (getchar() != '\n');
			(void)scanf("%c", &over);

			switch (over)
			{
			case 'y':
			case 'Y':return 1;
			case 'n':
			case 'N':return 0;
			default:
				printf("�����ʽ�������������룡");
				break;
		}
		default:
			break;
	}
	default:
		printf("�����ʽ�������������룡\n");
		break;
	}
}

int main()
{
	initInf();
	Sleep(1000);
	menus();
	printf("�����˳�ϵͳ\n");
	system("pause");
	return 0;
}