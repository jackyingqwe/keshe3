
//�ļ��Ĵ洢��path0�ǹ���Ա�˺���Ϣ��1��ҩƷ��Ϣ
#include"Header.h"


//1�۸�2������3����, 4����
Node* SortMed(int sort_type) {
	Node* chu, * pi, * pj, * pt, * t = (Node*)malloc(sizeof(Node));
	int pai = 5;
	//�ж�������Դ
	if (sort_type != 4)
	{
		chu = ReadListMed(0);
		printf("1.��������2.��������\n");
		pai = Getinput();
	}
	else
	{
		printf("��ʷ������0���������ڣ�����������1\n");
		int type_sort;
		scanf_s("%d", &type_sort);
		ShowHeadMed(2);
		chu = AltegetMed(ReadListMed(1), type_sort);
		sort_type = 2;
		pai = 2;
	}
	//ð������ 
	for (pi = chu; pi;pi = pi->next)
	{
		for (pj = pi->next; pj;pj = pj->next)
		{
			// �ж���������
			if (sort_type == 1)
			{
				int bi = pi->jia > pj->jia;
				if (pai == 2)
					bi = bi - 1;
				if (bi)
				{
					if (t)
						*t = *pi;
					*pi = *pj;
					if (t)
						*pj = *t;

					pt = pi->next;
					pi->next = pj->next;
					pj->next = pt;
				}
			}
			else if (sort_type == 2)
			{
				int bi = pi->shu > pj->shu;
				if (pai == 2)
					bi = bi - 1;
				if (bi)
				{
					if (t)
						*t = *pi;
					*pi = *pj;
					if (t)
						*pj = *t;

					pt = pi->next;
					pi->next = pj->next;
					pj->next = pt;
				}
			}
			else if (sort_type == 3) {
				int bi;
				// ���ڱȽϹ���
				if (pi->year > pj->year)
					bi = 1;
				else if (pi->year == pj->year)
				{
					if (pi->month > pj->month)
						bi = 1;
					else if (pi->month == pj->month)
					{
						if (pi->day > pj->day)
							bi = 1;
						else
							bi = 0;
					}
					else
						bi = 0;
				}
				else
					bi = 0;
				if (pai == 2)
					bi = bi - 1;
				if (bi)
				{
					if (t)
						*t = *pi;
					*pi = *pj;
					if (t)
						*pj = *t;

					pt = pi->next;
					pi->next = pj->next;
					pj->next = pt;
				}
			}
		}
	}
	return chu;
}

void SoldMed()
{
	printf("\t\t\t��ѡ����������\n\n\t\t1�۸�\t\t2����\t\t3����\n�������Ĭ��˳��\n");
	int sort_type = 0;
	sort_type = Getinput();
	char t81 = getchar();
	Node* chu = SortMed(sort_type);
	// �г�ҩƷ
	system("cls");
	printf("\tҩƷ����\t\t�۸�\t\t�������С�ƿ��\t\t��Ч��\n");
	ShowMed(chu);
	Node* out_med = (Node*)malloc(sizeof(Node));
	Node* t_list = (Node*)malloc(sizeof(Node));
	if (out_med)
		out_med->next = t_list;
	//�۳�ҩƷ
	while (1)
	{
		printf("������ҩƷ����\t\taa�˳�\n");
		// ����ҩƷ
		Node* med_now = FindMed(chu);
		// �˳�����,���
		//printf("%p", med_now);
		//���ؿ�ָ���ֵΪ0000000000000000
		if (med_now == 0000000000000000)
		{
			printf("��������\n");
			break;
		}
		//m_code -= 6;
		printf("������Ҫ���۵ĺ���");
		int o_shu = 0;
		scanf_s("%d", &o_shu);
		if (med_now)
		{
			while (o_shu > med_now->shu)
			{
				printf("û����ô��ҩƷŶ��");
				scanf_s("%d", &o_shu);
				char gt2 = getchar();
			}
			//�޸�����

			med_now->shu = med_now->shu - o_shu;
			// ������Ϊ���ɾ��
			//ǰ��һ��ָ�룬��ֹ�ֿ�����ͷָ��
			Node* q = (Node*)malloc(sizeof(Node));
			if (q)
				q->next = chu;
			if (med_now->shu == 0)
			{
				for (Node* a = q;a;a = a->next)
				{
					Node* p = a->next;
					if (strcmp(med_now->name, p->name) == 0)
					{
						a->next = p->next;
						break;
					}
				}
				if ((!chu->next) && (med_now == chu))
				{
					chu = NULL;
					char* path = { "G:/Program_data/vs_c/chushi/Medicine.txt" };
					FILE* fp = NULL;
					errno_t err = 1;
					err = fopen_s(&fp, path, "w");
					Sleep(500);
					if (fp)
						fclose(fp);
				}
				else
					chu = q->next;
			}
		}
		else
			break;
		// ��������ҩƷ����
		Node* t_list1 = MdOutMed(med_now, o_shu);
		if (t_list)
		{
			t_list->next = t_list1;
			t_list = t_list->next;
		}
	}
	// ��t_list����һ��ĩ�ڵ㣬����ĩ�ڵ�Null
	if (t_list)
	{
		Node* t_list1 = (Node*)malloc(sizeof(Node));
		t_list->next = t_list1;
		t_list = t_list->next;
		if (t_list)
			t_list->next = NULL;
	}
	if (out_med)
	{
		out_med = out_med->next;
		if (out_med)
		{
			out_med = out_med->next;
			if (out_med)
				OutMed(out_med);
		}
	}
	//�������,���ع���Ա���˵�
	printf("���۳ɹ�");
	//�����ܼ۸�
	float zong_jia = 0;
	if (out_med)
	{
		if (out_med)
		{
			for (Node* a = out_med;a->next;a = a->next)
				zong_jia += a->jia * a->shu;
		}
	}
	//�������ı�д���ļ�
	WtMed(chu, 1);
	printf("һ��%.3fԪ\n", zong_jia);
	Sleep(1200);
	printf("�����������");
	system("pause");
	system("cls");
	AdmFace();
}

int Getinput() {
	char du[20] = { 0 };
	scanf_s("%s", du, 20);
	int a = -2;
	a = (int)du[0] - 48;					//����ASCII�뽫�ַ�ת��Ϊ������ַ����� 
	if (strlen(du) > 1)
		a = 500;
	else if ((du[0] > '9') || (du[0] < '1'))
		a = 500;
	//���ش���ֵ����ʾ������� 
	return a;

}

// ����1����ʷ��0
Node* AltegetMed(Node* chu, int type_code)
{
	// ������������
	//���ظ���ȥ��
	Node* ai = chu;
	while (ai->next)
	{
		Node* aj = ai->next;
		Node* pt = ai;
		while (aj->next)
		{
			int qi_code = 5;
			if (ai)
			{
				qi_code = !((aj->year == ai->year) && (aj->month == ai->month) && (aj->day == ai->day));
				int code = !(qi_code * type_code);
				if ((strcmp(ai->name, aj->name) == 0) && code)
				{
					ai->shu = ai->shu + aj->shu;
					if (pt)
						pt->next = aj->next;
					//��ʷ�������еĻ��ܣ���������

				}
				else
				{
					if (pt)
						pt = pt->next;
				}
			}
			aj = aj->next;

		}
		ai = ai->next;
		//ShowMed(ai);
	}
	if (type_code == 0)
	{
		for (Node* am = chu;am;am = am->next)
		{
			am->year = 0;
			am->month = 0;
			am->day = 0;
		}
	}
	return chu;
}
//���صĵ�һ������
float* SumMed(Node* chu)
{
	//�ܼ�
	float sum_up = 0;
	//int sum_shu = (int*)malloc(sizeof(int));
	//������
	float sum_shu = 0;
	float** p;
	//����һ������ָ���ڴ�
	p = (float**)malloc(1 * sizeof(float**));
	//��������һ��ָ���ڴ�
	if (p)
		p[0] = (float*)malloc(2 * sizeof(float*));
	sum_shu = 0;
	for (Node* a = chu;a;a = a->next)
	{
		sum_up += a->jia * a->shu;
		sum_shu = sum_shu + a->shu;
	}
	if (p)
	{
		if (p[0])
		{
			p[0][0] = sum_shu;
			p[0][1] = sum_up;
		}
		return *p;
	}
	return NULL;

}
//�β�һ�Ǳ�ͷ�����ǲ����
Node* Insert(Node* old_list, Node* temp_list) {
	Node* am = (Node*)malloc(sizeof(Node));
	// am����old����listǰ���һ��ָ�룬������
	//�ֲ����λ�ã�����λ���Ƿ�Ϊ��ͷ�����ֿ�д���﷨
	if (am)
		am->next = old_list;
	int code = 1;
	int i = 0;
	while (1 && code)
	{
		printf("��ѡ��Ҫ��������\n");
		int order = -1;
		scanf_s("%d", &order);
		for (Node* a = am;a;a = a->next)
		{

			i += 1;
			if (i == order)
			{
				Node* temp_list1;
				temp_list1 = (Node*)malloc(sizeof(Node));
				if (temp_list)
				{
					temp_list1 = a->next;
					a->next = temp_list;
					temp_list->next = temp_list1;
				}
				code = 0;
				if (am)
					// ���������Ǳ�ͷ���򷵻�am
					return am->next;
				return old_list;
			}

		}
		printf("������Χ\n");
		i = 0;
	}
	return old_list;
}