#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996);

#include "treeStructure.h"
#include "function.h"
#include "fileOperations.h"
#include "switchCase.h"

int number = 0; // 商品代码
int price = 0;  // 商品价格
int count = 0;  // 商品数量
char name[20];  // 商品名称

//所有的调用函数
void outputDate(Tree* curr);//输出商品和目录信息
void outputDate1(Tree* curr, int flag);
int outputCata(Tree* root, int n);//输出目录信息
void PrintAllNodes(Tree* curr);//打印所有节点信息，包括目录和商品
Tree* search(Tree* root, int level);//查找
Tree* searchPreNode(Tree* temp);//查找当前节点的前一个节点
Tree* modifyDate(Tree* curr, int target);//修改信息
Tree* deleteDate(Tree* root, int target);//删除信息
int insertGoods(Tree* curr);//插入商品信息
void readToTree(Tree* root, FILE* fp);//从文件中读取信息
void writeToFile(Tree* curr, FILE* fp);//将信息写入文件
int printfGoods(Tree* curr);//输出单条信息
Tree* upperCate(Tree* curr);//进入上一层目录
Tree* lowerCate(Tree* curr);//进入下一层目录
Tree* enterCata(Tree* root, int target);//进入选中目录
void countDate(Tree* curr, int* p, int* q);//统计商品库存和总商品价值

int main() {
	FILE* fp = NULL;
	fp = fopen("E:/code/date.txt", "r"); // 打开文件,读取信息
	Tree* root;
	InitiateTree(&root); // 初始化树
	readToTree(root, fp); //从文件中读取信息
	Tree* now = root->firstNode;//初始时位置为根节点的位置
	//菜单
	printf("*---------------------------------------------*\n");
	printf("|           欢迎使用超市管理系统              |\n");
	printf("|---------------------------------------------|\n");
	printf("|1.显示所有目录和商品信息                     |\n");
	printf("|2.切换当前分类目录到上一级分类目录           |\n");
	printf("|3.切换当前分类目录到下一级分类目录           |\n");
	printf("|4.添加新商品目录或商品信息                   |\n");
	printf("|5.在当前目录下删除商品目录或商品信息         |\n");
	printf("|6.在当前目录下修改商品目录或商品信息	      |\n");
	printf("|7.浏览当前商品分类目录的所有内容             |\n");
	printf("|8.查找商品或目录信息                         |\n");
	printf("|9.进入所选目录                               |\n");
	printf("|10.显示目录信息                              |\n");
	printf("|11.统计总商品数量和价值                      |\n");
	printf("|0.退出                                       |\n");
	printf("*---------------------------------------------*\n");
	switchCase(now, root, fp);//菜单选项
	return 0;
}