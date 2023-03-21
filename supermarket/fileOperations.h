#pragma once
//文件读写操作
//从文件中读取信息插入
void readToTree(Tree* root, FILE* fp) {
	if (feof(fp)) {
		return;
	}
	Tree* curr = (Tree*)malloc(sizeof(Tree));
	fscanf(fp, "%d", &curr->upperCate);
	if (curr->upperCate < 20) { // 通过父亲目录来判断当前节点是否为目录
		fscanf(fp, "%d%s", &curr->catalogue, curr->CName);
		if (curr->catalogue < 0) { // 异常数据检查
			free(curr);
			return;
		}
	}
	else {
		fscanf(fp, "%d%s%d%d", &curr->CNumber, curr->CName, &curr->CPrice,
			&curr->CCount);
		curr->catalogue = 0;//商品信息不含目录编号，置为0；
		if (curr->CNumber < 0) { // 异常数据检查
			free(curr);
			return;
		}
	}

	Tree* temp = search(root, curr->upperCate); // 找到插入的目录
	curr->father = temp;//记录父亲节点
	if (temp == NULL)
		return;
	curr->firstNode = NULL;
	if (temp->firstNode == NULL) {
		curr->nextNode = temp->firstNode;
		temp->firstNode = curr;
	}
	else {
		temp = temp->firstNode; // 绕过第一个孩子找其兄弟
		while (temp->nextNode != NULL) {
			temp = temp->nextNode;
		}
		curr->nextNode = temp->nextNode;
		temp->nextNode = curr;
	}
	readToTree(root, fp);
	return;
}

//写入文件中
void writeToFile(Tree* curr, FILE* fp) {
	if (curr == NULL) return;
	else if (curr->catalogue != 0) {
		//写入目录
		fprintf(fp, "%-5d%-5d%-5s\n", curr->upperCate, curr->catalogue, curr->CName);
	}
	else {
		//写入商品选项
		fprintf(fp, "%-10d%-10d%-10s%-10d%-10d\n", curr->upperCate, curr->CNumber, curr->CName, curr->CPrice, curr->CNumber);
	}
	writeToFile(curr->firstNode, fp);
	writeToFile(curr->nextNode, fp);
	return;
}
