#pragma once
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#define _CRT_SECURE_NO_WARNINGS			 /*����ʾ����ȫ����*/
//����ҩƷ�����ݽṹ��
typedef struct medicine {
	char name[20];
	float jia;
	int shu, year, month, day;
	struct medicine* next;
}Node;

//����Ա�˺�
typedef struct useraccount {
	char hao[10],passwd[10];
	struct useraccount* next;
}Ua;
//��ʼ����
void UserFace();
//����Ա����
void AdmFace();
//����ҩƷ����
Node *CreatMed();

//��ҩƷ�������
Node* SortMed(int sort_type);
//����ҩƷ
Node* FindMed();
//�Ķ�ҩƷ
Node* AlterMed(Node* chu);
//д�����Ա�˺���Ϣ
void WtUserAcount();
//��ȡ�ļ��γ�����
//0 ��棬1�۳�
Node* ReadListMed(int type_authority);
//����¼����
int CheckAcount(char name[10], char passwd[10],Ua *chu);
//�ж�ҩƷ��Ч��
int BoolDate(int year, int month, int day);
//��ҩƷ��Ϣд���ļ�
void WtMed(Node* chu, int authority_code);
//����ҩƷ
void SoldMed();
//��¼�۳���ҩƷ
void OutMed(Node* chu);
//��ӡҩƷ��Ϣ
void ShowMed(Node* chu);
/* ��ȡ���룬��ֹ���ѭ�� */
//�����Զ�һ������0-9��
int Getinput();
//��ȡ����Ա�˺�
Ua* ReadUa();
// ��ӡҩƷ��Ϣͷ��
//1��棬2�۳���
void ShowHeadMed(int type_sort);
//��¼������ҩƷ
Node* MdOutMed(Node* chu, int o_shu);
// ���ϳ��۵�ҩƷ
// ��ʷ��0,����1��
Node* AltegetMed(Node* chu,int type_code);
//ͳ���������ܼ�
float* SumMed(Node* chu);
//�������ݵ��Ӻ���
//�β�һ�Ǳ�ͷ�����ǲ����
Node *Insert(Node* old_list, Node* temp_list);

//ɾ���ڵ㣬�β�һ�Ǳ�ͷ
Node* Delete(Node* old_list);
//��ѯ����ҩ��
void OutDateMed(Node* chu);
//ҩƷ��Ϣ��ѯ
void TackleMedInformation();
//��ѯ��������������Standerd
Node* FindOutDateMedWithQ(Node* chu, int standerd);