#pragma once
//�˵�ѡ��
int switchCase(Tree* root, Tree* now, FILE* fp) {
	do {
		fflush(stdin);
		printf("������˵�ѡ��:");
		int menuItem;
		scanf("%d", &menuItem);
		if (menuItem > 13 || menuItem < 0) {
			printf("�˵�����������,");
		}
		printf("\n");
		switch (menuItem) {
		case 1: {
			printf("*��������������������������������������������������Ŀ¼����Ʒ��Ϣ������������������������������������������������������*\n\n");

			printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "һ��Ŀ¼<-", "����Ŀ¼<-", "����Ŀ¼<-", "��Ʒ���", "��Ʒ����", "��Ʒ�۸�", "��Ʒ����");
			printf("����������������������������������������������������������������������������������������������������������������������������������������\n");
			PrintAllNodes(root);
			printf("����������������������������������������������������������������������������������������������������������������������������������������\n");
			break;
		}
		case 2: {
			now = upperCate(now);
			break;
		}
		case 3: {
			now = lowerCate(now);
			break;
		}
		case 4: {
			insertGoods(now);
			break;
		}
		case 5: {
			int target = -1;
			printf("��������Ҫɾ����Ŀ¼��Ż���Ʒ���:");
			scanf("%d", &target);
			Tree* temp = deleteDate(now, target);
			if (temp) {
				printf("ɾ���ɹ���\n");
			}
			outputDate(now);
			break;
		}
		case 6: {
			int target = -1;
			printf("��������Ҫ�޸ĵ�Ŀ¼��Ż���Ʒ���:");
			scanf("%d", &target);
			Tree* temp = modifyDate(now, target);
			outputDate(temp);
			break;
		}
		case 7: {
			outputDate(now);
			break;
		}
		case 8: {
			int target = -1;
			printf("��������Ҫ���ҵ�Ŀ¼��Ż���Ʒ���:");
			scanf("%d", &target);
			Tree* temp = search(now, target);
			if (temp == NULL) {
				printf("�����ڸ���Ʒ��Ŀ¼!\n");
				break;
			}
			printf("���ҳɹ�!\n");
			printfGoods(temp);
			break;
		}
		case 9: {
			Tree* temp;
			int target = -1;
			printf("������Ŀ¼���:");
			scanf("%d", &target);
			temp = enterCata(root, target);
			if (temp == NULL) printf("����Ŀ¼ʧ��!\n");
			else now = temp;
			break;
		}
		case 10: {
			printf("*����������������������������������������������������������������������*\n");

			printf("|%-13s%-13s%-9s|\n", "һ��Ŀ¼", "����Ŀ¼", "����Ŀ¼");
			printf("��������������������������������������������������������������������������\n");

			outputCata(root, 0);
			printf("*����������������������������������������������������������������������*\n");

			break;
		}
		case 11: {
			int p = 0, q = 0;
			countDate(root, &p, &q);
			printf("-------------------------\n");
			printf("%-15s%-15s\n", "��Ʒ�ܼ�ֵ", "��Ʒ������");
			printf("-------------------------\n");
			printf("%-15d%-15d\n", p, q);
			printf("-------------------------\n");

			break;
		}
		case 0: {
			//д���ļ���
			FILE* fp1;
			fp1 = fopen("E:/code/date2.txt", "w");
			writeToFile(root->firstNode, fp1);
			printf("--���˳�ϵͳ--\n");
			fclose(fp);
			fclose(fp1);
			return 0;
		}
		}
		printf("\n");
	} while (1);
	return 1;
}