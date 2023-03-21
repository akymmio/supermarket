#pragma once
//菜单选项
int switchCase(Tree* root, Tree* now, FILE* fp) {
	do {
		fflush(stdin);
		printf("请输入菜单选项:");
		int menuItem;
		scanf("%d", &menuItem);
		if (menuItem > 13 || menuItem < 0) {
			printf("菜单编号输入错误,");
		}
		printf("\n");
		switch (menuItem) {
		case 1: {
			printf("*—————————————————————————目录和商品信息———————————————————————————*\n\n");

			printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "一级目录<-", "二级目录<-", "三级目录<-", "商品编号", "商品名称", "商品价格", "商品数量");
			printf("————————————————————————————————————————————————————————————————————\n");
			PrintAllNodes(root);
			printf("————————————————————————————————————————————————————————————————————\n");
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
			printf("请输入需要删除的目录编号或商品编号:");
			scanf("%d", &target);
			Tree* temp = deleteDate(now, target);
			if (temp) {
				printf("删除成功！\n");
			}
			outputDate(now);
			break;
		}
		case 6: {
			int target = -1;
			printf("请输入需要修改的目录编号或商品编号:");
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
			printf("请输入需要查找的目录编号或商品编号:");
			scanf("%d", &target);
			Tree* temp = search(now, target);
			if (temp == NULL) {
				printf("不存在该商品或目录!\n");
				break;
			}
			printf("查找成功!\n");
			printfGoods(temp);
			break;
		}
		case 9: {
			Tree* temp;
			int target = -1;
			printf("请输入目录编号:");
			scanf("%d", &target);
			temp = enterCata(root, target);
			if (temp == NULL) printf("进入目录失败!\n");
			else now = temp;
			break;
		}
		case 10: {
			printf("*———————————————————————————————————*\n");

			printf("|%-13s%-13s%-9s|\n", "一级目录", "二级目录", "三级目录");
			printf("—————————————————————————————————————\n");

			outputCata(root, 0);
			printf("*———————————————————————————————————*\n");

			break;
		}
		case 11: {
			int p = 0, q = 0;
			countDate(root, &p, &q);
			printf("-------------------------\n");
			printf("%-15s%-15s\n", "商品总价值", "商品总数量");
			printf("-------------------------\n");
			printf("%-15d%-15d\n", p, q);
			printf("-------------------------\n");

			break;
		}
		case 0: {
			//写入文件中
			FILE* fp1;
			fp1 = fopen("E:/code/date2.txt", "w");
			writeToFile(root->firstNode, fp1);
			printf("--已退出系统--\n");
			fclose(fp);
			fclose(fp1);
			return 0;
		}
		}
		printf("\n");
	} while (1);
	return 1;
}