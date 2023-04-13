#include"Header.h"
//用户界面
void UserFace()
{
	printf("\n");
	printf("====================================药店管理系统====================================");
	printf("\n\n\t\t\t\t      请你登录");
	printf("\n");
	char name[10] = { 0 }, passwd[10] = { 0 };
	//读取管理员账号权限码
	// 管理员账号密码表头
	Ua* list_head = ReadUa();
	printf("初始化完成\n");
	while (1)
	{
		scanf_s("%s", name, 10);
		int i = 0; //记录密码长度
		char c; //用于实现密码隐式输入
		while (1) {
			c = _getch(); //用 _getch() 函数输入，字符不会显示在屏幕上
			if (c == '\r')
			{
				//遇到回车，表明密码输入结束
				break; //while 循环的出口
			}
			else if (c == '\b')
			{
				//遇到退格，需要删除前一个星号
				printf("\b \b");  //退格，打一个空格，再退格，实质上是用空格覆盖掉星号
				--i;
			}
			else
			{
				passwd[i++] = c;//将字符放入数组
				printf("*");
			}
		}
		printf("\n正在登录.. ..");
		if (CheckAcount(name, passwd, list_head))
			break;
	}
	// 进入系统管理界面
	AdmFace();
}
//管理界面
void AdmFace()
{
	printf("====================================欢迎进入药店管理系统====================================");
	printf("\n\t\t\t1.进、退货\t\t\t\t2.售货");
	printf("\n\t\t\t3.查看最近热销\t\t\t\t4.药品信息查询");
	printf("\n\t\t\t5.添加管理员账号\t\t\t6.查看售出");
	printf("\n\t\t\t7.修改药品\t\t\t\t8.退出");
	printf("\n请按指定键进入相应子级系统\n");
	char option = '0';
	// 如果不在 1 - 6，不断读取输入
	while (!((1 <= option) & (option < 9)))
	{
		option = Getinput();
		// 消除回车键
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
		case 8:printf("成功退出系统"), exit(0);break;
		default: Sleep(1400);AdmFace();break;
		}
	}
	printf("跳出");
}
//管理员信息
void WtUserAcount() {
	Node* chu = NULL;
	char* path = "G:/Program_data/vs_c/chushi/Account.txt";
	FILE* fp = NULL;
	errno_t err;
	err = fopen_s(&fp, path, "a");
	//err不为零，则出现错误
	char hao[10] = { 0 }, passwd[10];
	printf("请输入账号，回车后输入密码\n按aa退出\n");
	scanf_s("%s %s", hao, 10, passwd, 10);
	if (err == 0)
	{
		if (fp)
		{
			while (strcmp(hao, "aa")==1)
			{
				fprintf(fp, "%s\t%s\n", hao, passwd);
				printf("新增成功");
				scanf_s("%s %s", hao, 10, passwd, 10);
			}
		}
	}
	if (fp)
		fclose(fp);
	printf("写入成功，正在跳转");
	Sleep(2400);
	system("cls");
}

int CheckAcount(char name[10], char passwd[10], Ua* chu) {
	for (Ua* a = chu;a->next->next;a = a->next)
	{
		if (strcmp(name, a->hao) == 0)
		{
			printf("正在进行验证\n");
			if (strcmp(passwd, a->passwd) == 0)
			{
				printf("正在进入系统");
				Sleep(1200);
				system("cls");
				return 1;
			}
			else
			{
				printf("密码输入错误\n请重新输入账号密码\n");
				return 0;
			}
		}
	}
	printf("账号密码输入错误\n请重新输入账号密码\n");
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
	//err不为零，则出现错误
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
//查询药品信息界面
void TackleMedInformation() {
	printf("1.查看库存\t\t2.查看过期药品\t\t3.查询过期(附数量)\n");
	int i = Getinput();
	switch (i)
	{
	case 1:ShowHeadMed(1);ShowMed(ReadListMed(0));break;
	case 2:OutDateMed(ReadListMed(0));break;
	case 3:printf("输入最大数量，低于该数量则不输出\n");int im = 0;scanf_s("%d", &im);ShowMed(FindOutDateMedWithQ(ReadListMed(0), im));break;
	default:break;
	}

}
