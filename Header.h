#pragma once
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#define _CRT_SECURE_NO_WARNINGS			 /*不提示不安全警告*/
//创建药品的数据结构体
typedef struct medicine {
	char name[20];
	float jia;
	int shu, year, month, day;
	struct medicine* next;
}Node;

//管理员账号
typedef struct useraccount {
	char hao[10],passwd[10];
	struct useraccount* next;
}Ua;
//开始界面
void UserFace();
//管理员界面
void AdmFace();
//建立药品链表
Node *CreatMed();

//对药品链表分类
Node* SortMed(int sort_type);
//查找药品
Node* FindMed();
//改动药品
Node* AlterMed(Node* chu);
//写入管理员账号信息
void WtUserAcount();
//读取文件形成链表
//0 库存，1售出
Node* ReadListMed(int type_authority);
//检查登录资质
int CheckAcount(char name[10], char passwd[10],Ua *chu);
//判断药品有效期
int BoolDate(int year, int month, int day);
//将药品信息写入文件
void WtMed(Node* chu, int authority_code);
//售卖药品
void SoldMed();
//记录售出的药品
void OutMed(Node* chu);
//打印药品信息
void ShowMed(Node* chu);
/* 读取输入，防止多次循环 */
//用于自读一个数（0-9）
int Getinput();
//读取管理员账号
Ua* ReadUa();
// 打印药品信息头部
//1库存，2售出的
void ShowHeadMed(int type_sort);
//记录卖出的药品
Node* MdOutMed(Node* chu, int o_shu);
// 整合出售的药品
// 历史按0,近期1，
Node* AltegetMed(Node* chu,int type_code);
//统计数量与总价
float* SumMed(Node* chu);
//插入数据的子函数
//形参一是表头，二是插入的
Node *Insert(Node* old_list, Node* temp_list);

//删除节点，形参一是表头
Node* Delete(Node* old_list);
//查询过期药物
void OutDateMed(Node* chu);
//药品信息查询
void TackleMedInformation();
//查询过期且数量大于Standerd
Node* FindOutDateMedWithQ(Node* chu, int standerd);