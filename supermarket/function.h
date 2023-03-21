void outputDate1(Tree* curr, int flag) {
	if (flag == 0) {
		printf("%-10d%-10s\n", curr->catalogue, curr->CName);
		if (curr->nextNode)
			outputDate1(curr->nextNode, 0);
	}
	else {
		printf(" %-10d%-12s%-10d%-10d\n", curr->CNumber, curr->CName, curr->CPrice, curr->CCount);
		if (curr->nextNode)
			outputDate1(curr->nextNode, 1);
	}
	return;
}
// ���ͬһĿ¼�µ���Ŀ¼����Ʒ
void outputDate(Tree* curr) {
	if (curr->father) curr = curr->father->firstNode;
	else curr = curr->firstNode;
	if (curr->catalogue <= 100 && curr->catalogue > 0) {  // ���Ŀ¼
		printf("\n*----%s----*\n\n", curr->father->CName);
		printf("%-10s%-10s\n", "Ŀ¼���", "Ŀ¼����");
		printf("������������������������������������\n");
		outputDate1(curr, 0);//���Ŀ¼��ʽ
	}
	else {
		printf("\n*--------------%s-------------*\n\n", curr->father->CName);
		printf("%-10s%-10s%-10s%-10s\n", "��Ʒ���", "��Ʒ����", "��Ʒ�۸�", "��Ʒ����");
		printf("����������������������������������������������������������������������������\n");
		outputDate1(curr, 1);
	}
	return;
}

// ����
Tree* search(Tree* root, int target) {
	Tree* curr;
	if (root == NULL)
		return NULL;
	if (root->catalogue == target || root->CNumber == target) {
		return root;
	}
	Tree* temp = search(root->firstNode, target);
	if (temp) {
		return temp;
	}
	return search(root->nextNode, target);
}

//�޸���Ʒ��Ϣ
Tree* modifyDate(Tree* curr, int target) {
	int flag = 0;
	Tree* temp = search(curr, target);//�ҵ���Ҫ�޸ĵĽڵ�
	if (temp->catalogue <= 100 && temp->catalogue > 0) {//�޸�Ŀ¼
		printf("ԭĿ¼��Ϣ:%d-%s\n", temp->catalogue, temp->CName);
		printf("�����µ�:Ŀ¼���-Ŀ¼����:");
		scanf("%d%s", &temp->catalogue, temp->CName);
		flag = 1;
	}
	else {
		printf("ԭ��Ʒ��Ϣ: %d-%s-%d-%d\n", temp->CNumber, temp->CName, temp->CPrice, temp->CCount);
		printf("�����µ�:��Ʒ���-��Ʒ����-��Ʒ�۸�-��Ʒ����:");
		scanf("%d%s%d%d", &temp->CNumber, temp->CName, &temp->CPrice, &temp->CCount);
		flag = 1;
	}
	if (flag == 1) printf("�޸���Ϣ�ɹ���");
	return temp;
}

//���ҵ�ǰ�ڵ��ǰһ���ڵ�
Tree* searchPreNode(Tree* temp) {
	Tree* pre = temp->father;
	//temp��pre�ĵ�һ������
	if (pre->firstNode == temp) {
		return pre;
	}
	else {
		pre = pre->firstNode;//temp����pre�ĵ�һ�����ӣ������ֵܽڵ�
		while (pre->nextNode->catalogue != temp->catalogue || pre->nextNode->CNumber != temp->CNumber) {
			pre = pre->nextNode;
		}
		return pre;
	}
	return NULL;
}
//ɾ��Ŀ¼������Ʒ��Ϣ
Tree* deleteDate(Tree* root, int target) {
	Tree* curr = search(root, target);//�ҵ���Ҫ�޸ĵĽڵ�
	Tree* pre = searchPreNode(curr);//�ҵ���ǰ�ڵ�ĸ��ڵ�
	//��temp�Ǻ��ӽڵ�
	if (pre->firstNode == curr) {
		pre->firstNode = curr->nextNode;
	}
	else {
		pre->nextNode = curr->nextNode;
	}
	free(curr);//�ͷŽڵ�
	return pre->firstNode;
}
// �ڵ�ǰĿ¼������Ʒ��Ϣ
int insertGoods(Tree* curr) {
	Tree* temp = (Tree*)malloc(sizeof(Tree));
	if (curr->catalogue == 1 || curr->upperCate <= 20) {//ͨ������жϲ���Ŀ¼��Ϣ����Ʒ��Ϣ
		temp->upperCate = curr->upperCate;
		printf("������:Ŀ¼���-Ŀ¼����:");
		scanf("%d%s", &temp->catalogue, temp->CName);
	}
	else {
		temp->catalogue = curr->catalogue;
		printf("������:��Ʒ���-��Ʒ����-��Ʒ�۸�-��Ʒ����:");
		scanf("%d%s%d%d", &temp->CNumber, temp->CName, &temp->CPrice, &temp->CCount);
		if (temp->CNumber == 0 || temp->CPrice == 0 || temp->CCount == 0) {//���ݼ��
			printf("��������ʧ�ܣ�����������");
		}
	}
	temp->father = curr->father;
	while (curr->nextNode != NULL) {
		curr = curr->nextNode;
	}
	temp->nextNode = curr->nextNode;
	curr->nextNode = temp;

	printf("�������ݳɹ���\n");
	outputDate(curr);
	return 0;
}

//��ʽ�����������Ϣ
int  printfGoods(Tree* curr) {
	if (curr->catalogue <= 20 && curr->catalogue > 0) {  // ���Ŀ¼
		printf("������������������������������������\n");
		printf("%-10s%-10s\n", "Ŀ¼���", "Ŀ¼����");
		printf("������������������������������������\n");
		printf("%-10d%-10s\n", curr->catalogue, curr->CName);
	}
	else {
		printf("����������������������������������������������������������������������������\n");
		printf("%-10s%-10s%-10s%-10s\n", "��Ʒ���", "��Ʒ����", "��Ʒ�۸�", "��Ʒ����");
		printf("����������������������������������������������������������������������������\n");
		printf("%-10d%-10s%-10d%-10d\n", curr->CNumber, curr->CName, curr->CPrice, curr->CCount);
	}
	return 1;
}

//�л�����һ��Ŀ¼���Ҵ�ӡ��Ϣ
Tree* upperCate(Tree* curr) {
	if (curr->father == NULL) {
		printf("��ǰ�ڵ���Ϊ���ϲ�Ŀ¼!\n");
		return curr;
	}
	Tree* temp;
	temp = curr->father;
	outputDate(temp);
	return temp;
}
//�л�����һ��Ŀ¼
Tree* lowerCate(Tree* curr) {
	Tree* temp;
	temp = curr->firstNode;
	if (temp == NULL) {
		printf("��ǰΪ���һ�㣡\n");
		return curr;
	}
	if (curr->firstNode == NULL) return NULL;
	outputDate(temp);
	return temp;
}

// ��ӡ���нڵ�
void PrintAllNodes(Tree* curr) {
	if (curr == NULL)
		return;                     // �����Ϊ�գ�ֱ�ӷ���
	if (curr->catalogue != 0) {
		if (curr->catalogue == 1) {
			printf("%s\n", curr->CName);     // �����ǰ����ֵ
		}
		else if (curr->father && curr->father->catalogue == 1) {//����һ�����ӽڵ�
			printf("%17s\n", curr->CName);     // �����ǰ����ֵ
		}
		else {
			printf("%28s\n", curr->CName);     // �����ǰ����ֵ
		}
	}
	else {
		printf("%36d     %-11s%-11d%-11d\n", curr->CNumber, curr->CName, curr->CPrice, curr->CCount);
	}

	PrintAllNodes(curr->firstNode); // �ݹ������һ�����ӵ����нڵ�
	PrintAllNodes(curr->nextNode);  // �ݹ���������ֵܵ����нڵ�
}

//����Ŀ¼
Tree* enterCata(Tree* root, int target) {
	Tree* curr = search(root, target);//�ҵ�Ŀ¼
	if (curr == NULL) return NULL;
	outputDate(curr->firstNode);
	return curr;
}
//�ṹ���������Ŀ¼
int outputCata(Tree* root, int n) {
	if (root == NULL || root->catalogue == 0) return 0;
	for (int i = 0; i < n; i++) {
		printf(" ");
	}
	printf("%d %s\n", root->catalogue, root->CName);

	outputCata(root->firstNode, n + 12);
	outputCata(root->nextNode, n);
	return 1;
}

//ͳ����Ϣ������Ʒ����p������Ʒ��ֵq
void countDate(Tree* curr, int* p, int* q) {
	if (curr == NULL)
		return;                     // �����Ϊ�գ�ֱ�ӷ���
	if (curr->CCount >= 0) *q += curr->CCount;
	if (curr->CPrice >= 0) *p += curr->CPrice;
	countDate(curr->firstNode, p, q); // �ݹ������һ�����ӵ����нڵ�
	countDate(curr->nextNode, p, q);  // �ݹ���������ֵܵ����нڵ�
}
