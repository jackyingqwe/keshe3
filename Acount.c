#include"Header.h"
//�û�����
void UserFace()
{
	printf("\n");
	printf("====================================ҩ�����ϵͳ====================================");
	printf("\n\n\t\t\t\t      �����¼");
	printf("\n");
	char name[10] = { 0 }, passwd[10] = { 0 };
	//��ȡ����Ա�˺�Ȩ����
	// ����Ա�˺������ͷ
	Ua* list_head = ReadUa();
	printf("��ʼ�����\n");
	while (1)
	{
		scanf_s("%s", name, 10);
		int i = 0; //��¼���볤��
		char c; //����ʵ��������ʽ����
		while (1) {
			c = _getch(); //�� _getch() �������룬�ַ�������ʾ����Ļ��
			if (c == '\r')
			{
				//�����س������������������
				break; //while ѭ���ĳ���
			}
			else if (c == '\b')
			{
				//�����˸���Ҫɾ��ǰһ���Ǻ�
				printf("\b \b");  //�˸񣬴�һ���ո����˸�ʵ�������ÿո񸲸ǵ��Ǻ�
				--i;
			}
			else
			{
				passwd[i++] = c;//���ַ���������
				printf("*");
			}
		}
		printf("\n���ڵ�¼.. ..");
		if (CheckAcount(name, passwd, list_head))
			break;
	}
	// ����ϵͳ�������
	AdmFace();
}
//�������
void AdmFace()
{
	printf("====================================��ӭ����ҩ�����ϵͳ====================================");
	printf("\n\t\t\t1.�����˻�\t\t\t\t2.�ۻ�");
	printf("\n\t\t\t3.�鿴�������\t\t\t\t4.ҩƷ��Ϣ��ѯ");
	printf("\n\t\t\t5.��ӹ���Ա�˺�\t\t\t6.�鿴�۳�");
	printf("\n\t\t\t7.�޸�ҩƷ\t\t\t\t8.�˳�");
	printf("\n�밴ָ����������Ӧ�Ӽ�ϵͳ\n");
	char option = '0';
	// ������� 1 - 6�����϶�ȡ����
	while (!((1 <= option) & (option < 9)))
	{
		option = Getinput();
		// �����س���
		char temporary = getchar();
		switch (option)
		{
		case 1:WtMed(CreatMed(), 1);AdmFace();break;
		case 2:system("cls");SoldMed();break;
		case 3:system("cls");ShowMed(SortMed(4));AdmFace();break;
		case 4:system("cls");TackleMedInformation();AdmFace();break;
		case 5:WtUserAcount();AdmFace();break;
		case 6:system("cls");ShowHeadMed(2);ShowMed(ReadListMed(1));AdmFace();break;
		case 7:system("cls");ShowHeadMed(1);WtMed(AlterMed(ReadListMed(0)), 1);AdmFace();break;
		case 8:printf("�ɹ��˳�ϵͳ"), exit(0);break;
		default: Sleep(1400);AdmFace();break;
		}
	}
	printf("����");
}
//����Ա��Ϣ
void WtUserAcount() {
	Node* chu = NULL;
	char* path = "G:/Program_data/vs_c/chushi/Account.txt";
	FILE* fp = NULL;
	errno_t err;
	err = fopen_s(&fp, path, "a");
	//err��Ϊ�㣬����ִ���
	char hao[10] = { 0 }, passwd[10];
	printf("�������˺ţ��س�����������\n��aa�˳�\n");
	scanf_s("%s %s", hao, 10, passwd, 10);
	if (err == 0)
	{
		if (fp)
		{
			while (strcmp(hao, "aa")==1)
			{
				fprintf(fp, "%s\t%s\n", hao, passwd);
				printf("�����ɹ�");
				scanf_s("%s %s", hao, 10, passwd, 10);
			}
		}
	}
	if (fp)
		fclose(fp);
	printf("д��ɹ���������ת");
	Sleep(2400);
	system("cls");
}

int CheckAcount(char name[10], char passwd[10], Ua* chu) {
	for (Ua* a = chu;a->next->next;a = a->next)
	{
		if (strcmp(name, a->hao) == 0)
		{
			printf("���ڽ�����֤\n");
			if (strcmp(passwd, a->passwd) == 0)
			{
				printf("���ڽ���ϵͳ");
				Sleep(1200);
				system("cls");
				return 1;
			}
			else
			{
				printf("�����������\n�����������˺�����\n");
				return 0;
			}
		}
	}
	printf("�˺������������\n�����������˺�����\n");
	return 0;
}

Ua* ReadUa() {
	Ua* chu;
	char hao[10] = { 0 }, passwd[10] = { 0 };
	char* path = "G:/Program_data/vs_c/chushi/Account.txt";
	chu = (Ua*)malloc(sizeof(Ua));
	FILE* fp = NULL;
	errno_t err;
	err = fopen_s(&fp, path, "r");
	//err��Ϊ�㣬����ִ���
	Ua* t_list = (Ua*)malloc(sizeof(Ua));
	if (chu)
		chu->next = t_list;
	if (err == 0)
	{
		if (fp)
		{
			while (!feof(fp))
			{
				fscanf_s(fp, "%s\t%s", hao, 10, passwd, 10);
				if (t_list)
				{
					strcpy_s(t_list->hao, 10, hao);
					strcpy_s(t_list->passwd, 10, passwd);
					Ua* t_list1 = (Ua*)malloc(sizeof(Ua));
					t_list->next = t_list1;
					t_list = t_list->next;
				}
			}
			if (t_list)
				t_list->next = NULL;
		}
		if (chu)
			chu = chu->next;
		if (fp)
			fclose(fp);
	}
	else
		chu = NULL;

	return chu;
}
//��ѯҩƷ��Ϣ����
void TackleMedInformation() {
	printf("1.�鿴���\t\t2.�鿴����ҩƷ\t\t3.��ѯ����(������)\n");
	int i = Getinput();
	switch (i)
	{
	case 1:ShowHeadMed(1);ShowMed(ReadListMed(0));break;
	case 2:OutDateMed(ReadListMed(0));break;
	case 3:printf("����������������ڸ����������\n");int im = 0;scanf_s("%d", &im);ShowMed(FindOutDateMedWithQ(ReadListMed(0), im));break;
	default:break;
	}

}
