#include"Header.h"


//��������
/*
��д��ʱ��ǰ�����һ���սڵ�
����ʱ����ǰ��Ľ������һ���������ָ��null
�ڱ���ʱ����Ȼ�����꣨��Ϊ�������һ���ڵ㣩
*/

//�Ѷ�������������޸ģ�
/*
����ʵ�ֱ�Ϊ����ȡʱ����ͷָ�루������Ϣ��
������ĩָ�룬�ж�����Ϊ��ǰָ���Ƿ�Ϊ��
*/


// ��ҩƷ��Ϣ�洢������
Node* CreatMed() {
	Node* old_list = ReadListMed(0);
	system("cls");
	char authority_code = '8';
	printf("\n\t\t1.�������˵�\t\t2.����ҩ��\t\t3.ɾ��ҩ��\n");
	// Sleep(120);
	authority_code = getchar();
	// �����س���
	char temporaryh = getchar();
	if (authority_code == '2')
	{
		printf("β�尴1��ָ�����밴2");
		int type_insert = 0;
		scanf_s("%d", &type_insert);
		ShowHeadMed(1);ShowMed(old_list);
		// old_list�������ͷ��tempt_list�ǵ�ǰ�ڵ�	
		// ¼����Ϣ
		char temporary[20] = { 0 };
		while (1)
		{
			printf("����������ҩƷ���ơ��۸�(���Ժ�С��)����������Ч��\n��aa����\n");
			scanf_s("%s", temporary, 20);
			Node* temp_list = (Node*)malloc(sizeof(Node));
			if (strcmp(temporary, "aa") == 0)
				break;
			// ҩƷ���Ƹ�ֵ
			if (temp_list)
				strcpy_s(temp_list->name, 20, temporary);
			// �Լ۸����������кϷ����ж�
			float t_jia = 0.0;
			int t_shu = 0;
			// ��ȡ�۸�
			scanf_s("%f", &t_jia);
			char t81 = getchar();
			// ����������
			while (t_jia <= 0)
			{
				printf("�۸�������������������\n");
				scanf_s("%f", &t_jia);
				char t82 = getchar();
			}
			//char t8 = getchar();
			//��ȡ����
			scanf_s("%d", &t_shu);
			char t83 = getchar();
			// ����������
			while ((t_shu <= 0) & (t_shu % 1 != 0))
			{
				printf("����������������������\n");
				scanf_s("%d", &t_shu);
				char t84 = getchar();
			}
			// ��ȡ����
			printf("�����������ڣ����ꡢ�¡���\n");
			int year = 1, month = 1, day = 1;
			scanf_s("%d %d %d", &year, &month, &day);
			char t85 = getchar();
			// �����ڽ���֮ǰ���������ʽ���淶���򷵻�
			while ((!BoolDate(year, month, day)) || ((month - 12 > 0) || (day - 31 > 0))||(day*month<=0))
			{
				printf("��ǰҩƷ��Ч�ڲ����Ϲ淶\n");
				printf("�����������ڣ����ꡢ�¡���\n");
				scanf_s("%d %d %d", &year, &month, &day);
				char t88 = getchar();
				printf("%d %d %d\n", year, month, day);
			}
			// ��ӵ�����
			if (temp_list)
			{
				temp_list->year = year;
				temp_list->month = month;
				temp_list->day = day;
				temp_list->jia = t_jia;
				temp_list->shu = t_shu;
			}
			//if (int)
			//����ҩƷ��ֵ���
			//printf("%p", chu);
			// ����ת��
			if (type_insert == 2)
				old_list = Insert(old_list, temp_list);
			else if (type_insert == 1)
			{
				if (old_list)
				{
					Node* a = old_list;
					while (a->next)
						a = a->next;
					Node* t = a->next;
					a->next = temp_list;
					a = a->next;
					a->next = t;
				}
				else
				{
					old_list = temp_list;
					//*old_list = *temp_list;
					old_list->next = NULL;
				}
			}
			else
				AdmFace();

		}
	}
	// �������Ҳ�������˵�
	else if (authority_code == '3')
	{
		old_list = Delete(old_list);
	}
	else
		AdmFace();
	return old_list;
}
//�޸�˼·
//һ��½�����������ȡ�����ֲ��䣬
//���ʣ��޸�ʹ�ö�������
//������ʱͳһ�����ļ��޸�


Node* FindMed(Node* chu) {
	Node* a;
	int code = 1;
	while (code)
	{
		char medicine[20] = { 0 };
		scanf_s("%s", medicine, 20);
		if (strcmp(medicine, "aa") == 0)
		{
			return NULL;
		}
		for (a = chu;a;a = a->next)
		{
			if (strcmp(a->name, medicine) == 0)
			{
				code = 0;
				return a;
			}
		}
		printf("δ�ҵ���ҩƷ");
		return NULL;
	}
	return NULL;
}

//  Node *chu  ���ݵ����޸����ݵ�����
Node* AlterMed(Node* chu) {
	Node* t_list;
	//���ҩƷ��Ϣ
	ShowMed(chu);
	printf("������Ҫ�޸�ҩƷ��Ϣ������\n��aa�˳�\n");
	t_list = FindMed(chu);
	// û���ҵ��򷵻���һ��
	if (!t_list)
	{
		Sleep(1200);
		return chu;
	}
	printf("������Ҫ�޸ĵ�����\n1.����\t2.�۸�\t3.����\t4.��Ч��year\t5.��Ч��month\t6.��Ч��day\n��9�˳��޸�\n");
	int change_code = Getinput();
	//������ʼ����
	char name[20] = { 0 };
	float f = 0.0;
	int m = 0;
	if (change_code != 9)
	{
		switch (change_code)
		{
		case 1:strcpy_s(t_list->name, 20, name);scanf_s("%s", name, 20);strcpy_s(t_list->name, 20, name);break;
		case 2:scanf_s("%f", &f);t_list->jia = f;break;
		case 3:scanf_s("%d", &m);t_list->shu = m;break;
		case 4:scanf_s("%d", &m);t_list->year = m;break;
		case 5:scanf_s("%d", &m);t_list->month = m;break;
		case 6:scanf_s("%d", &m);t_list->day = m;break;
		default:break;
		}
	}
	return chu;
}

//  Node *chu  ���ݵ���д�����ݵ�����ͷ
void WtMed(Node* chu, int authority_code)
{
	char* path = { "G:/Program_data/vs_c/chushi/Medicine.txt" };
	FILE* fp = NULL;
	errno_t err = 1;
	if (authority_code == 0)
		err = fopen_s(&fp, path, "a");
	else if (authority_code == 1)
		err = fopen_s(&fp, path, "w");
	//err��Ϊ�㣬����ִ���
	if (err == 0)
	{
		printf("Medicine�򿪳ɹ�\n");
		while (chu)
		{
			if (fp)
			{
				fprintf(fp, "%s %f %d %d %d %d\n", chu->name, chu->jia, chu->shu, chu->year, chu->month, chu->day);
			}
			chu = chu->next;
		}
		if (fp != NULL)
			fclose(fp);
	}
	else
		printf("Medicine��ʧ��");
	system("cls");
}

//type_authority 0 ��棬1�۳�
Node* ReadListMed(int type_authority) {
	//�ֱ��ȡ����
	Node* tou = (Node*)malloc(sizeof(Node));
	// �ַ���ָ������
	char* paths[2] = {
		"G:/Program_data/vs_c/chushi/Medicine.txt" ,
		"G:/Program_data/vs_c/chushi/OutMed.txt"
	};
	FILE* fp = NULL;
	errno_t err;
	err = fopen_s(&fp, paths[type_authority], "r");
	//err��Ϊ�㣬����ִ���
	if (err == 0)
	{
		Node* chu = (Node*)malloc(sizeof(Node));
		// ͷ�ڵ�
		if (tou)
			tou->next = chu;
		while (!(feof(fp)))
		{
			if (chu)
			{
				// ҩƷ��ȡ
				if (fp)
				{
					char am[21] = { "xujiayao" };
					fscanf_s(fp, "%s,", am, 20);
					if (!strcmp(am, "xujiayao"))
					{
						chu->next = NULL;
						break;
					}
					Node* chu1 = (Node*)malloc(sizeof(Node));
					chu->next = chu1;
					chu = chu->next;

					//printf("\n%s", am);

					if (chu)
					{
						strcpy_s(chu->name, 20, am);
						fscanf_s(fp, "%f %d %d %d %d", &chu->jia, &chu->shu, &chu->year, &chu->month, &chu->day);
					}
				}
			}
		}
		// ��ȡ��ɣ�ĩβ��null��ͷ������һ���ڵ�

		if (tou)
		{
			tou = tou->next;
			if (tou)
				tou = tou->next;
		}
	}
	if (fp)
		fclose(fp);
	return tou;
}

// 0Ϊ��ǰʱ��֮ǰ��1Ϊ֮��
int BoolDate(int year, int month, int day)
{
	time_t time_seconds = time(0);
	struct tm now_time;
	localtime_s(&now_time, &time_seconds);
	//printf("%d-%d-%d %d:%d:%d\n", now_time.tm_year + 1900, now_time.tm_mon + 1,
		//now_time.tm_mday, now_time.tm_hour, now_time.tm_min, now_time.tm_sec);
	int m = -1;
	if (year < now_time.tm_year + 1900)
		m = 0;
	else if (year == now_time.tm_year + 1900)
	{
		if (month < now_time.tm_mon + 1)
			m = 0;
		else if (month == now_time.tm_mon + 1)
		{
			if (day <= now_time.tm_mday)
				m = 0;
			else
				m = 1;
		}
		else
			m = 1;;
	}
	else
		m = 1;
	return m;
}

void OutMed(Node* chu) {
	char* paths = { "G:/Program_data/vs_c/chushi/OutMed.txt" };
	FILE* fp = NULL;
	errno_t err;
	err = fopen_s(&fp, paths, "a");
	//err��Ϊ�㣬����ִ���
	if (err == 0)
	{
		while (chu->next)
		{
			if (fp)
			{
				fprintf(fp, "%s %f %d %d %d %d\n", chu->name, chu->jia, chu->shu, chu->year, chu->month, chu->day);
			}
			chu = chu->next;
		}
	}
	if (fp)
		fclose(fp);
}

void ShowMed(Node* chu) {
	int i = 1;
	for (Node* a = chu;a;a = a->next) {
		printf("%d\t", i);
		if (strlen(a->name) >= 8)
		{
			if (strlen(a->name) >= 16)
				printf("%s\t", a->name);
			else
				printf("%s\t\t", a->name);
		}
		else
			printf("%s\t\t\t", a->name);
		if(a->jia<1000)
			printf("%.3f\t\t", a->jia);
		else
			printf("%.3f\t", a->jia);
		printf("     %4d\t\t", a->shu);
		printf("%d-", a->year);
		printf("%02d-", a->month);
		printf("%02d\n", a->day);
		i += 1;
	}
	float* a = SumMed(chu);
	printf("\n��ǰҩƷһ��%.0f��(ƿ��\t\t\t��ǰҩƷ�ܼ�%.3fԪ\n", a[0], a[1]);
	free(a);
}

//1��棬2�۳���
void ShowHeadMed(int type_sort)
{
	if (type_sort == 1)
	{
		printf("==============================================================================\n");
		printf("���\tҩƷ����\t\t�۸�\t\t�������С�ƿ��\t\t��Ч��\n");
	}
	else if (type_sort == 2)
	{
		printf("==============================================================================\n");
		printf("���\tҩƷ����\t\t�۸�\t\t�������С�ƿ��\t\t��������\n");
	}
}

Node* MdOutMed(Node* chu, int o_shu)
{
	Node* t_list = (Node*)malloc(sizeof(Node));
	//��¼����ʱ��
	time_t time_seconds = time(0);
	struct tm now_time;
	localtime_s(&now_time, &time_seconds);
	// ��ֵ����ڵ�
	if (t_list)
	{
		strcpy_s(t_list->name, 20, chu->name);
		t_list->jia = chu->jia;
		t_list->shu = o_shu;
		t_list->year = now_time.tm_year + 1900;
		t_list->month = now_time.tm_mon + 1;
		t_list->day = now_time.tm_mday;
	}
	return t_list;
}

Node* Delete(Node* old_list)
{
	ShowHeadMed(1);ShowMed(old_list);
	int code = 1;
	int i = 0;
	Node* am= (Node*)malloc(sizeof(Node));
	// am����old����listǰ���һ��ָ�룬������
	//�ֲ����λ�ã�����λ���Ƿ�Ϊ��ͷ�����ֿ�д���﷨
	if (am)
		am->next = old_list;
	while (1 && code)
	{
		printf("��ѡ��Ҫɾ����ҩƷ����\naa�˳�\n");
		int order = 0;
		char name[20] = { 0 };
		scanf_s("%s", name, 20);
		if (strcmp(name, "aa")==0)
			return old_list;
		Node* ai = am;
		Node* a = am;
		while (a)
		{
			if (strcmp(a->name, name) == 0)
			{
				//��ʣһ��Ԫ��
				if ((a==am->next)&&(!a->next))
				{
					char* path = { "G:/Program_data/vs_c/chushi/Medicine.txt" };
					FILE* fp = NULL;
					errno_t err = 1;
					err = fopen_s(&fp, path, "w");
					Sleep(500);
					system("pause");					
					if(fp)
						fclose(fp);
					return NULL;
				}
				
				ai->next = a->next;
				printf("ɾ���ɹ�\n");
				//ǿ�ƽ�old_listָ���ַ�޸�Ϊam->nextָ��ĵ�ַ
				am = am->next;
				return am;
				//system("pause");
				if (order)
				{
					ai = ai->next;
				}
			}
			if (order)
			{
				ai = ai->next;
			}
			a = a->next;
			order++;
		}
		printf("δ�ҵ�\n");
		i = 0;
	}
	return old_list;
}
void OutDateMed(Node* chu)
{
	printf("����ҩƷ������\n");
	for (Node* a = chu;a;a = a->next)
	{
		if (BoolDate(a->year, a->month, a->day))
			continue;
		else
		{
			printf("%s\n", a->name);
			if (!a->next)
			{
				printf("û��ҩƷ����");
			}
		}
	}

}

Node* FindOutDateMedWithQ(Node* chu, int standerd)
{
	ShowHeadMed(1);
	Node* another = (Node*)malloc(sizeof(Node));
	Node* tempt_list = (Node*)malloc(sizeof(Node));
	if (another)
		another->next = tempt_list;
	for (Node* a = chu;a;a = a->next)
	{
		if (!BoolDate(a->year, a->month, a->day))
		{
			if (a->shu > standerd)
			{
				Node* tempt_list1 = (Node*)malloc(sizeof(Node));
				if (tempt_list1)
				{
					strcpy_s(tempt_list1->name, 20, a->name);
					tempt_list1->year = a->year;
					tempt_list1->month = a->month;
					tempt_list1->day = a->day;
					tempt_list1->jia = a->jia;
					tempt_list1->shu = a->shu;
				}
				if (tempt_list)
					tempt_list->next = tempt_list1;
				if (tempt_list)
					tempt_list = tempt_list->next;
			}
			else
				continue;
		}
	}
	if (tempt_list)
		tempt_list->next = NULL;
	if (another)
	{
		another = another->next;
		if (another)
			another = another->next;
	}
	return another;
}