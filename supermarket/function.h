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
// 输出同一目录下的子目录或商品
void outputDate(Tree* curr) {
	if (curr->father) curr = curr->father->firstNode;
	else curr = curr->firstNode;
	if (curr->catalogue <= 100 && curr->catalogue > 0) {  // 输出目录
		printf("\n*----%s----*\n\n", curr->father->CName);
		printf("%-10s%-10s\n", "目录编号", "目录名称");
		printf("——————————————————\n");
		outputDate1(curr, 0);//输出目录格式
	}
	else {
		printf("\n*--------------%s-------------*\n\n", curr->father->CName);
		printf("%-10s%-10s%-10s%-10s\n", "商品编号", "商品名称", "商品价格", "商品数量");
		printf("——————————————————————————————————————\n");
		outputDate1(curr, 1);
	}
	return;
}

// 查找
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

//修改商品信息
Tree* modifyDate(Tree* curr, int target) {
	int flag = 0;
	Tree* temp = search(curr, target);//找到需要修改的节点
	if (temp->catalogue <= 100 && temp->catalogue > 0) {//修改目录
		printf("原目录信息:%d-%s\n", temp->catalogue, temp->CName);
		printf("输入新的:目录编号-目录名称:");
		scanf("%d%s", &temp->catalogue, temp->CName);
		flag = 1;
	}
	else {
		printf("原商品信息: %d-%s-%d-%d\n", temp->CNumber, temp->CName, temp->CPrice, temp->CCount);
		printf("输入新的:商品编号-商品名称-商品价格-商品数量:");
		scanf("%d%s%d%d", &temp->CNumber, temp->CName, &temp->CPrice, &temp->CCount);
		flag = 1;
	}
	if (flag == 1) printf("修改信息成功！");
	return temp;
}

//查找当前节点的前一个节点
Tree* searchPreNode(Tree* temp) {
	Tree* pre = temp->father;
	//temp是pre的第一个孩子
	if (pre->firstNode == temp) {
		return pre;
	}
	else {
		pre = pre->firstNode;//temp不是pre的第一个孩子，遍历兄弟节点
		while (pre->nextNode->catalogue != temp->catalogue || pre->nextNode->CNumber != temp->CNumber) {
			pre = pre->nextNode;
		}
		return pre;
	}
	return NULL;
}
//删除目录或者商品信息
Tree* deleteDate(Tree* root, int target) {
	Tree* curr = search(root, target);//找到需要修改的节点
	Tree* pre = searchPreNode(curr);//找到当前节点的父节点
	//若temp是孩子节点
	if (pre->firstNode == curr) {
		pre->firstNode = curr->nextNode;
	}
	else {
		pre->nextNode = curr->nextNode;
	}
	free(curr);//释放节点
	return pre->firstNode;
}
// 在当前目录插入商品信息
int insertGoods(Tree* curr) {
	Tree* temp = (Tree*)malloc(sizeof(Tree));
	if (curr->catalogue == 1 || curr->upperCate <= 20) {//通过编号判断插入目录信息或商品信息
		temp->upperCate = curr->upperCate;
		printf("请输入:目录编号-目录名称:");
		scanf("%d%s", &temp->catalogue, temp->CName);
	}
	else {
		temp->catalogue = curr->catalogue;
		printf("请输入:商品编号-商品名称-商品价格-商品数量:");
		scanf("%d%s%d%d", &temp->CNumber, temp->CName, &temp->CPrice, &temp->CCount);
		if (temp->CNumber == 0 || temp->CPrice == 0 || temp->CCount == 0) {//数据检查
			printf("插入数据失败！，数据有误！");
		}
	}
	temp->father = curr->father;
	while (curr->nextNode != NULL) {
		curr = curr->nextNode;
	}
	temp->nextNode = curr->nextNode;
	curr->nextNode = temp;

	printf("插入数据成功！\n");
	outputDate(curr);
	return 0;
}

//格式化输出单条信息
int  printfGoods(Tree* curr) {
	if (curr->catalogue <= 20 && curr->catalogue > 0) {  // 输出目录
		printf("——————————————————\n");
		printf("%-10s%-10s\n", "目录编号", "目录名称");
		printf("——————————————————\n");
		printf("%-10d%-10s\n", curr->catalogue, curr->CName);
	}
	else {
		printf("——————————————————————————————————————\n");
		printf("%-10s%-10s%-10s%-10s\n", "商品编号", "商品名称", "商品价格", "商品数量");
		printf("——————————————————————————————————————\n");
		printf("%-10d%-10s%-10d%-10d\n", curr->CNumber, curr->CName, curr->CPrice, curr->CCount);
	}
	return 1;
}

//切换到上一层目录并且打印信息
Tree* upperCate(Tree* curr) {
	if (curr->father == NULL) {
		printf("当前节点已为最上层目录!\n");
		return curr;
	}
	Tree* temp;
	temp = curr->father;
	outputDate(temp);
	return temp;
}
//切换到下一层目录
Tree* lowerCate(Tree* curr) {
	Tree* temp;
	temp = curr->firstNode;
	if (temp == NULL) {
		printf("当前为最后一层！\n");
		return curr;
	}
	if (curr->firstNode == NULL) return NULL;
	outputDate(temp);
	return temp;
}

// 打印所有节点
void PrintAllNodes(Tree* curr) {
	if (curr == NULL)
		return;                     // 如果树为空，直接返回
	if (curr->catalogue != 0) {
		if (curr->catalogue == 1) {
			printf("%s\n", curr->CName);     // 输出当前结点的值
		}
		else if (curr->father && curr->father->catalogue == 1) {//不是一个孩子节点
			printf("%17s\n", curr->CName);     // 输出当前结点的值
		}
		else {
			printf("%28s\n", curr->CName);     // 输出当前结点的值
		}
	}
	else {
		printf("%36d     %-11s%-11d%-11d\n", curr->CNumber, curr->CName, curr->CPrice, curr->CCount);
	}

	PrintAllNodes(curr->firstNode); // 递归输出第一个孩子的所有节点
	PrintAllNodes(curr->nextNode);  // 递归输出相邻兄弟的所有节点
}

//进入目录
Tree* enterCata(Tree* root, int target) {
	Tree* curr = search(root, target);//找到目录
	if (curr == NULL) return NULL;
	outputDate(curr->firstNode);
	return curr;
}
//结构化输出所有目录
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

//统计信息，总商品数量p，总商品价值q
void countDate(Tree* curr, int* p, int* q) {
	if (curr == NULL)
		return;                     // 如果树为空，直接返回
	if (curr->CCount >= 0) *q += curr->CCount;
	if (curr->CPrice >= 0) *p += curr->CPrice;
	countDate(curr->firstNode, p, q); // 递归输出第一个孩子的所有节点
	countDate(curr->nextNode, p, q);  // 递归输出相邻兄弟的所有节点
}
