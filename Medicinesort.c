#include"Header.h"


//关于链表
/*
在写入时，前后各多一个空节点
返回时，将前面的界面后移一个，后面的指向null
在遍历时，自然遍历完（因为后面多了一个节点）
*/

//已对上述不足进行修改，
/*
具体实现变为：读取时返回头指针（具有信息）
遍历到末指针，判断条件为当前指针是否为空
*/


// 将药品信息存储到链表
Node* CreatMed() {
	Node* old_list = ReadListMed(0);
	system("cls");
	char authority_code = '8';
	printf("\n\t\t1.返回主菜单\t\t2.新增药物\t\t3.删除药物\n");
	// Sleep(120);
	authority_code = getchar();
	// 消除回车键
	char temporaryh = getchar();
	if (authority_code == '2')
	{
		printf("尾插按1，指定插入按2");
		int type_insert = 0;
		scanf_s("%d", &type_insert);
		ShowHeadMed(1);ShowMed(old_list);
		// old_list获得链表头，tempt_list是当前节点	
		// 录入信息
		char temporary[20] = { 0 };
		while (1)
		{
			printf("请依次输入药品名称、价格(可以含小数)、数量、有效期\n按aa结束\n");
			scanf_s("%s", temporary, 20);
			Node* temp_list = (Node*)malloc(sizeof(Node));
			if (strcmp(temporary, "aa") == 0)
				break;
			// 药品名称赋值
			if (temp_list)
				strcpy_s(temp_list->name, 20, temporary);
			// 对价格与数量进行合法性判定
			float t_jia = 0.0;
			int t_shu = 0;
			// 读取价格
			scanf_s("%f", &t_jia);
			char t81 = getchar();
			// 非正数返回
			while (t_jia <= 0)
			{
				printf("价格输入有误，请重新输入\n");
				scanf_s("%f", &t_jia);
				char t82 = getchar();
			}
			//char t8 = getchar();
			//读取数量
			scanf_s("%d", &t_shu);
			char t83 = getchar();
			// 非正数返回
			while ((t_shu <= 0) & (t_shu % 1 != 0))
			{
				printf("数量输入有误，请重新输入\n");
				scanf_s("%d", &t_shu);
				char t84 = getchar();
			}
			// 读取日期
			printf("正在输入日期，按年、月、日\n");
			int year = 1, month = 1, day = 1;
			scanf_s("%d %d %d", &year, &month, &day);
			char t85 = getchar();
			// 日期在今天之前或者输入格式不规范，则返回
			while ((!BoolDate(year, month, day)) || ((month - 12 > 0) || (day - 31 > 0))||(day*month<=0))
			{
				printf("当前药品有效期不符合规范\n");
				printf("正在输入日期，按年、月、日\n");
				scanf_s("%d %d %d", &year, &month, &day);
				char t88 = getchar();
				printf("%d %d %d\n", year, month, day);
			}
			// 添加到链表
			if (temp_list)
			{
				temp_list->year = year;
				temp_list->month = month;
				temp_list->day = day;
				temp_list->jia = t_jia;
				temp_list->shu = t_shu;
			}
			//if (int)
			//单个药品赋值完成
			//printf("%p", chu);
			// 链表转接
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
	// 输入错误也返回主菜单
	else if (authority_code == '3')
	{
		old_list = Delete(old_list);
	}
	else
		AdmFace();
	return old_list;
}
//修改思路
//一登陆，进行链表读取，保持不变，
//访问，修改使用二级链表
//最后结束时统一返回文件修改


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
		printf("未找到该药品");
		return NULL;
	}
	return NULL;
}

//  Node *chu  传递的是修改数据的链表
Node* AlterMed(Node* chu) {
	Node* t_list;
	//输出药品信息
	ShowMed(chu);
	printf("请输入要修改药品信息的名称\n按aa退出\n");
	t_list = FindMed(chu);
	// 没有找到则返回上一级
	if (!t_list)
	{
		Sleep(1200);
		return chu;
	}
	printf("请输入要修改的类型\n1.名称\t2.价格\t3.数量\t4.有效期year\t5.有效期month\t6.有效期day\n按9退出修改\n");
	int change_code = Getinput();
	//变量初始化：
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

//  Node *chu  传递的是写入数据的链表头
void WtMed(Node* chu, int authority_code)
{
	char* path = { "G:/Program_data/vs_c/chushi/Medicine.txt" };
	FILE* fp = NULL;
	errno_t err = 1;
	if (authority_code == 0)
		err = fopen_s(&fp, path, "a");
	else if (authority_code == 1)
		err = fopen_s(&fp, path, "w");
	//err不为零，则出现错误
	if (err == 0)
	{
		printf("Medicine打开成功\n");
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
		printf("Medicine打开失败");
	system("cls");
}

//type_authority 0 库存，1售出
Node* ReadListMed(int type_authority) {
	//分别读取数据
	Node* tou = (Node*)malloc(sizeof(Node));
	// 字符型指针数组
	char* paths[2] = {
		"G:/Program_data/vs_c/chushi/Medicine.txt" ,
		"G:/Program_data/vs_c/chushi/OutMed.txt"
	};
	FILE* fp = NULL;
	errno_t err;
	err = fopen_s(&fp, paths[type_authority], "r");
	//err不为零，则出现错误
	if (err == 0)
	{
		Node* chu = (Node*)malloc(sizeof(Node));
		// 头节点
		if (tou)
			tou->next = chu;
		while (!(feof(fp)))
		{
			if (chu)
			{
				// 药品读取
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
		// 读取完成，末尾加null，头部往下一个节点

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

// 0为当前时间之前，1为之后
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
	//err不为零，则出现错误
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
	printf("\n当前药品一共%.0f盒(瓶）\t\t\t当前药品总价%.3f元\n", a[0], a[1]);
	free(a);
}

//1库存，2售出的
void ShowHeadMed(int type_sort)
{
	if (type_sort == 1)
	{
		printf("==============================================================================\n");
		printf("序号\t药品名称\t\t价格\t\t数量（盒、瓶）\t\t有效期\n");
	}
	else if (type_sort == 2)
	{
		printf("==============================================================================\n");
		printf("序号\t药品名称\t\t价格\t\t数量（盒、瓶）\t\t出售日期\n");
	}
}

Node* MdOutMed(Node* chu, int o_shu)
{
	Node* t_list = (Node*)malloc(sizeof(Node));
	//记录出售时间
	time_t time_seconds = time(0);
	struct tm now_time;
	localtime_s(&now_time, &time_seconds);
	// 赋值链表节点
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
	// am是在old——list前面的一个指针，避免了
	//分插入的位置（插入位置是否为表头）而分开写的语法
	if (am)
		am->next = old_list;
	while (1 && code)
	{
		printf("请选择要删除的药品名称\naa退出\n");
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
				//仅剩一个元素
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
				printf("删除成功\n");
				//强制将old_list指针地址修改为am->next指向的地址
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
		printf("未找到\n");
		i = 0;
	}
	return old_list;
}
void OutDateMed(Node* chu)
{
	printf("以下药品过期了\n");
	for (Node* a = chu;a;a = a->next)
	{
		if (BoolDate(a->year, a->month, a->day))
			continue;
		else
		{
			printf("%s\n", a->name);
			if (!a->next)
			{
				printf("没有药品过期");
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