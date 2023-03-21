//树的结构，初始化树
typedef struct Node {
	int upperCate = 0;//当前目录的父亲目录
	int catalogue = 0;//当前目录编号
	int CNumber = 0; // 商品代码
	int CPrice = 0;  // 商品价格
	int CCount = 0;  // 商品数量
	char CName[20];  // 商品名称
	struct Node* firstNode;
	struct Node* nextNode;
	struct Node* father;
} Tree;

// 初始化
void InitiateTree(Tree** root) {
	*root = (Tree*)malloc(sizeof(Tree));
	(*root)->firstNode = NULL;
	(*root)->nextNode = NULL;
	(*root)->father = NULL;
	(*root)->upperCate = 1;
	(*root)->catalogue = 1;             // 根节点目录编号为1
	strcpy((*root)->CName, "超市商品"); // 根节点名称
}
