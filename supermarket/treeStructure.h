//���Ľṹ����ʼ����
typedef struct Node {
	int upperCate = 0;//��ǰĿ¼�ĸ���Ŀ¼
	int catalogue = 0;//��ǰĿ¼���
	int CNumber = 0; // ��Ʒ����
	int CPrice = 0;  // ��Ʒ�۸�
	int CCount = 0;  // ��Ʒ����
	char CName[20];  // ��Ʒ����
	struct Node* firstNode;
	struct Node* nextNode;
	struct Node* father;
} Tree;

// ��ʼ��
void InitiateTree(Tree** root) {
	*root = (Tree*)malloc(sizeof(Tree));
	(*root)->firstNode = NULL;
	(*root)->nextNode = NULL;
	(*root)->father = NULL;
	(*root)->upperCate = 1;
	(*root)->catalogue = 1;             // ���ڵ�Ŀ¼���Ϊ1
	strcpy((*root)->CName, "������Ʒ"); // ���ڵ�����
}
