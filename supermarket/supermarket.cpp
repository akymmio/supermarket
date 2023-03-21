#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996);

#include "treeStructure.h"
#include "function.h"
#include "fileOperations.h"
#include "switchCase.h"

int number = 0; // ��Ʒ����
int price = 0;  // ��Ʒ�۸�
int count = 0;  // ��Ʒ����
char name[20];  // ��Ʒ����

//���еĵ��ú���
void outputDate(Tree* curr);//�����Ʒ��Ŀ¼��Ϣ
void outputDate1(Tree* curr, int flag);
int outputCata(Tree* root, int n);//���Ŀ¼��Ϣ
void PrintAllNodes(Tree* curr);//��ӡ���нڵ���Ϣ������Ŀ¼����Ʒ
Tree* search(Tree* root, int level);//����
Tree* searchPreNode(Tree* temp);//���ҵ�ǰ�ڵ��ǰһ���ڵ�
Tree* modifyDate(Tree* curr, int target);//�޸���Ϣ
Tree* deleteDate(Tree* root, int target);//ɾ����Ϣ
int insertGoods(Tree* curr);//������Ʒ��Ϣ
void readToTree(Tree* root, FILE* fp);//���ļ��ж�ȡ��Ϣ
void writeToFile(Tree* curr, FILE* fp);//����Ϣд���ļ�
int printfGoods(Tree* curr);//���������Ϣ
Tree* upperCate(Tree* curr);//������һ��Ŀ¼
Tree* lowerCate(Tree* curr);//������һ��Ŀ¼
Tree* enterCata(Tree* root, int target);//����ѡ��Ŀ¼
void countDate(Tree* curr, int* p, int* q);//ͳ����Ʒ��������Ʒ��ֵ

int main() {
	FILE* fp = NULL;
	fp = fopen("E:/code/date.txt", "r"); // ���ļ�,��ȡ��Ϣ
	Tree* root;
	InitiateTree(&root); // ��ʼ����
	readToTree(root, fp); //���ļ��ж�ȡ��Ϣ
	Tree* now = root->firstNode;//��ʼʱλ��Ϊ���ڵ��λ��
	//�˵�
	printf("*---------------------------------------------*\n");
	printf("|           ��ӭʹ�ó��й���ϵͳ              |\n");
	printf("|---------------------------------------------|\n");
	printf("|1.��ʾ����Ŀ¼����Ʒ��Ϣ                     |\n");
	printf("|2.�л���ǰ����Ŀ¼����һ������Ŀ¼           |\n");
	printf("|3.�л���ǰ����Ŀ¼����һ������Ŀ¼           |\n");
	printf("|4.�������ƷĿ¼����Ʒ��Ϣ                   |\n");
	printf("|5.�ڵ�ǰĿ¼��ɾ����ƷĿ¼����Ʒ��Ϣ         |\n");
	printf("|6.�ڵ�ǰĿ¼���޸���ƷĿ¼����Ʒ��Ϣ	      |\n");
	printf("|7.�����ǰ��Ʒ����Ŀ¼����������             |\n");
	printf("|8.������Ʒ��Ŀ¼��Ϣ                         |\n");
	printf("|9.������ѡĿ¼                               |\n");
	printf("|10.��ʾĿ¼��Ϣ                              |\n");
	printf("|11.ͳ������Ʒ�����ͼ�ֵ                      |\n");
	printf("|0.�˳�                                       |\n");
	printf("*---------------------------------------------*\n");
	switchCase(now, root, fp);//�˵�ѡ��
	return 0;
}