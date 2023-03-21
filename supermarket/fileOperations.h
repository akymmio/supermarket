#pragma once
//�ļ���д����
//���ļ��ж�ȡ��Ϣ����
void readToTree(Tree* root, FILE* fp) {
	if (feof(fp)) {
		return;
	}
	Tree* curr = (Tree*)malloc(sizeof(Tree));
	fscanf(fp, "%d", &curr->upperCate);
	if (curr->upperCate < 20) { // ͨ������Ŀ¼���жϵ�ǰ�ڵ��Ƿ�ΪĿ¼
		fscanf(fp, "%d%s", &curr->catalogue, curr->CName);
		if (curr->catalogue < 0) { // �쳣���ݼ��
			free(curr);
			return;
		}
	}
	else {
		fscanf(fp, "%d%s%d%d", &curr->CNumber, curr->CName, &curr->CPrice,
			&curr->CCount);
		curr->catalogue = 0;//��Ʒ��Ϣ����Ŀ¼��ţ���Ϊ0��
		if (curr->CNumber < 0) { // �쳣���ݼ��
			free(curr);
			return;
		}
	}

	Tree* temp = search(root, curr->upperCate); // �ҵ������Ŀ¼
	curr->father = temp;//��¼���׽ڵ�
	if (temp == NULL)
		return;
	curr->firstNode = NULL;
	if (temp->firstNode == NULL) {
		curr->nextNode = temp->firstNode;
		temp->firstNode = curr;
	}
	else {
		temp = temp->firstNode; // �ƹ���һ�����������ֵ�
		while (temp->nextNode != NULL) {
			temp = temp->nextNode;
		}
		curr->nextNode = temp->nextNode;
		temp->nextNode = curr;
	}
	readToTree(root, fp);
	return;
}

//д���ļ���
void writeToFile(Tree* curr, FILE* fp) {
	if (curr == NULL) return;
	else if (curr->catalogue != 0) {
		//д��Ŀ¼
		fprintf(fp, "%-5d%-5d%-5s\n", curr->upperCate, curr->catalogue, curr->CName);
	}
	else {
		//д����Ʒѡ��
		fprintf(fp, "%-10d%-10d%-10s%-10d%-10d\n", curr->upperCate, curr->CNumber, curr->CName, curr->CPrice, curr->CNumber);
	}
	writeToFile(curr->firstNode, fp);
	writeToFile(curr->nextNode, fp);
	return;
}
