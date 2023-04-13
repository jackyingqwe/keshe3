
//文件的存储，path0是管理员账号信息，1是药品信息
#include"Header.h"


//1价格，2数量，3日期, 4热销
Node* SortMed(int sort_type) {
	Node* chu, * pi, * pj, * pt, * t = (Node*)malloc(sizeof(Node));
	int pai = 5;
	//判断数据来源
	if (sort_type != 4)
	{
		chu = ReadListMed(0);
		printf("1.正向排序，2.逆向排序\n");
		pai = Getinput();
	}
	else
	{
		printf("历史热销按0（忽略日期），近期热销1\n");
		int type_sort;
		scanf_s("%d", &type_sort);
		ShowHeadMed(2);
		chu = AltegetMed(ReadListMed(1), type_sort);
		sort_type = 2;
		pai = 2;
	}
	//冒泡排序 
	for (pi = chu; pi;pi = pi->next)
	{
		for (pj = pi->next; pj;pj = pj->next)
		{
			// 判断排序类型
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
				// 日期比较规则
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
	printf("\t\t\t请选择排序类型\n\n\t\t1价格\t\t2数量\t\t3日期\n任意键是默认顺序\n");
	int sort_type = 0;
	sort_type = Getinput();
	char t81 = getchar();
	Node* chu = SortMed(sort_type);
	// 列出药品
	system("cls");
	printf("\t药品名称\t\t价格\t\t数量（盒、瓶）\t\t有效期\n");
	ShowMed(chu);
	Node* out_med = (Node*)malloc(sizeof(Node));
	Node* t_list = (Node*)malloc(sizeof(Node));
	if (out_med)
		out_med->next = t_list;
	//售出药品
	while (1)
	{
		printf("请输入药品名称\t\taa退出\n");
		// 查找药品
		Node* med_now = FindMed(chu);
		// 退出售卖,完成
		//printf("%p", med_now);
		//返回空指针的值为0000000000000000
		if (med_now == 0000000000000000)
		{
			printf("售卖结束\n");
			break;
		}
		//m_code -= 6;
		printf("请输入要出售的盒数");
		int o_shu = 0;
		scanf_s("%d", &o_shu);
		if (med_now)
		{
			while (o_shu > med_now->shu)
			{
				printf("没有这么多药品哦！");
				scanf_s("%d", &o_shu);
				char gt2 = getchar();
			}
			//修改数量

			med_now->shu = med_now->shu - o_shu;
			// 数量变为零后，删掉
			//前置一个指针，防止分开处理头指针
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
		// 创建卖出药品链表
		Node* t_list1 = MdOutMed(med_now, o_shu);
		if (t_list)
		{
			t_list->next = t_list1;
			t_list = t_list->next;
		}
	}
	// 给t_list加上一个末节点，并将末节点Null
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
	//售卖完成,返回管理员主菜单
	printf("出售成功");
	//计算总价格
	float zong_jia = 0;
	if (out_med)
	{
		if (out_med)
		{
			for (Node* a = out_med;a->next;a = a->next)
				zong_jia += a->jia * a->shu;
		}
	}
	//将数量改变写入文件
	WtMed(chu, 1);
	printf("一共%.3f元\n", zong_jia);
	Sleep(1200);
	printf("按任意键返回");
	system("pause");
	system("cls");
	AdmFace();
}

int Getinput() {
	char du[20] = { 0 };
	scanf_s("%s", du, 20);
	int a = -2;
	a = (int)du[0] - 48;					//利用ASCII码将字符转换为读入的字符整型 
	if (strlen(du) > 1)
		a = 500;
	else if ((du[0] > '9') || (du[0] < '1'))
		a = 500;
	//返回错误值，提示输入错误 
	return a;

}

// 近期1，历史按0
Node* AltegetMed(Node* chu, int type_code)
{
	// 将数量加起来
	//将重复的去掉
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
					//历史，即所有的汇总，不含日期

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
//返回的第一个是数
float* SumMed(Node* chu)
{
	//总价
	float sum_up = 0;
	//int sum_shu = (int*)malloc(sizeof(int));
	//总数量
	float sum_shu = 0;
	float** p;
	//分配一个二级指针内存
	p = (float**)malloc(1 * sizeof(float**));
	//分配两个一级指针内存
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
//形参一是表头，二是插入的
Node* Insert(Node* old_list, Node* temp_list) {
	Node* am = (Node*)malloc(sizeof(Node));
	// am是在old——list前面的一个指针，避免了
	//分插入的位置（插入位置是否为表头）而分开写的语法
	if (am)
		am->next = old_list;
	int code = 1;
	int i = 0;
	while (1 && code)
	{
		printf("请选择要插入的序次\n");
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
					// 如果插入的是表头，则返回am
					return am->next;
				return old_list;
			}

		}
		printf("超出范围\n");
		i = 0;
	}
	return old_list;
}