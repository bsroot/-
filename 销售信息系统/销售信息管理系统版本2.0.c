#include "stdio.h"
#include "stdlib.h"
#include "Windows.h"
#include "String.h"
#include "time.h"
//定义时间结构体
struct time {
	int mday; /* 一个月中的日期 - 取值区间为[1,31] */
	int mon; /* 月份（从一月开始，0代表一月） - 取值区间为[0,11] */
};
//定义销售员结构体
struct Salesman {
	int num;
	int dSales;
	int produtionNum[5];
	struct time date;
};
//定义数量
int counts = 0;
char delnum[10];
//1:初始化窗口和界面
void initWindow(char *title);
//2:初始化菜单
void initMenu();
//3.定义时间函数
//3.1定义day
int displayday();
//3.2定义month
int displaymonth();
//4.添加当日销售信息
void addSales(struct Salesman sal[]);
//5.显示销售信息
void display(struct Salesman sal[]);
//6.根据销售员编号查询销售信息
void find(struct Salesman sal[]);
//7.根据编号删除销售信息
void del(struct Salesman sal[]);
//8.计算月销售额
void calculation1(struct Salesman sal[], int month);
//9.计算每种产品的总销售额
void calculation2(struct Salesman sal[]);
//10.定义排序
//10.1按销售额对销售员排序
void sort1(struct Salesman sal[]);
//10.2按产品总销售额排序
void sort2(struct Salesman sal[]);
//11.保存销售信息
void save(struct Salesman stu[]);
//程序入口
void main() {
	//格式化代码快捷键:ctrl+K+F
	//定义学生数组
	struct Salesman sal[2000] = { 0,0 };
	int result;
	char choice1 = ' ';
	int choice2, month;
	char title[] = "\t\t\t\t\t*********欢迎进入销售信息管理系统！********\n\n\n";
	//1:初始化窗口和界面
	initWindow(title);
	memset(sal->produtionNum, 0, sizeof(sal->produtionNum));
	do {//循环
		initMenu();
		printf("请选择菜单（1-9）:\n");
		//清除缓冲区的内容
		fflush(stdin);
		scanf_s("%d", &result);
		//清除缓冲区的内容
		fflush(stdin);
		if (result >= 1 && result <= 9) {
			switch (result) {
			case 1:
				while (1)
				{
					addSales(sal);//调用添加当日销售信息的函数
					printf("是否继续录入销售信息(y/n)：");
					getchar();
					scanf_s("%c", &choice1, 1);
					if (choice1 == 'n') {
						break;
					}
				}
				break;
			case 2: display(sal);//调用显示销售信息的函数
				printf("\n");

				break;
			case 3:
				find(sal);//调用查询信息的函数
				break;
			case 4:
				printf("您确定要删除吗?（y/n）");
				getchar();
				scanf_s("%c", &choice1, 1);
				if (choice1 == 'n') {
					break;
				}
				else del(sal);
				break;
			case 5:
				printf("请输入月份：\n");
				scanf_s("%d", &month);
				calculation1(sal, month);
				break;
			case 6:
				calculation2(sal);
				break;
			case 7:
				while (1)
				{
					printf("\t\t\t\t请选择模式\n");
					printf("\t\t\t\t 1.按销售额对销售员排序\n");
					printf("\t\t\t\t 2.按产品总销售额排序\n");
					printf("\t\t\t\t 3.退出模式\n");
					scanf_s("%d", &choice2);
					if ((choice2 == 1) || (choice2 == 2))
						if (choice2 == 1)
							sort1(sal);
						else sort2(sal);
					else break;
				}
				break;
			case 8:
				save(sal);
				break;
			default:printf("谢谢使用！");


			}
		}
		else printf("输入有误！");
	} while (result != 9);
}
//1:初始窗口和界面
void initWindow(char *title) {
	//设置窗口大小
	system("mode con:cols=110 lines=150");
	//设置窗口字体的颜色
	system("color F0");
	//循环输出标题（条件：）
	while (*title != 0)
	{
		//输出字符指针所指向的内容
		printf("%c", *title);
		//将指针指向下一个字符
		title++;
		//休眠
		Sleep(50);


	}
}
//2:初始化菜单
void initMenu() {
	printf("\t\t\t\t\t    =========销售信息管理系统=========\n");
	printf("\t\t\t\t 1.录入当日销售信息\n");
	printf("\t\t\t\t 2.显示销售信息\n");
	printf("\t\t\t\t 3.根据销售员编号查询消息\n");
	printf("\t\t\t\t 4.删除销售信息\n");
	printf("\t\t\t\t 5.计算月每人销售额\n");
	printf("\t\t\t\t 6.计算每种产品总销售额\n");
	printf("\t\t\t\t 7.排序\n");
	printf("\t\t\t\t 8.保存销售信息(请在保存之前在C盘下直接建立文件xiaoshouxinxi.txt)\n");
	printf("\t\t\t\t 9.退出系统\n");
	printf("\t\t\t\t\t   ==================================\n");
}
//3.定义时间函数
//3.1定义day
int displayday()
{
	time_t timep;
	struct tm *p;
	time(&timep);
	p = gmtime(&timep);
	int date;
	date = p->tm_mday;
	return date;
}
//3.2定义month
int displaymonth()
{
	time_t timep;
	struct tm *p;
	time(&timep);
	p = gmtime(&timep);
	int date;
	date = 1 + p->tm_mon;
	return date;
}
//4.添加当日销售信息
void addSales(struct Salesman sal[])
{
	int t = 0, num;
	while (1) {
		printf("\n请输入要插入的销售员编号(1-4号)：");
		scanf_s("%d", &sal[counts].num);
		if (!(sal[counts].num >= 1 && sal[counts].num <= 4))
			printf("输入有误！");
		else break;
	}
	while (1) {
		printf("\n请输入的日期(XX/XX)：");
		scanf_s("%d/%d", &sal[counts].date.mon, &sal[counts].date.mday);
		if (sal[counts].date.mday > 31 || sal[counts].date.mon > 12)
			printf("输入有误！");
		else break;
	}
	while (t < 5) {
		while (1) {
			printf("\n请输入要插入的销售产品编号(1-5):");
			getchar();
			scanf("%d", &num);
			if (!(num >= 1 && num <= 5))
				printf("输入有误！");
			else break;
		}
		while (1) {
			printf("\n请输入日销售产品额：");
			scanf_s("%d", &sal[counts].produtionNum[num - 1]);
			if (!(sal[counts].produtionNum[num - 1] > 0))
				printf("输入有误！");
			else break;
		}
		t++;
	}
	printf("信息已经录入系统！\n");
	counts++;
	//清除缓冲区的内容
	fflush(stdin);
}
//5.显示销售信息
void display(struct Salesman sal[])
{
	int i, t, result;
	int day, month;
	if (counts == 0) {
		printf("没有数据!\n请先输入数据!\n");
	}
	else {
		printf("\t\t\t=========请选择显示时间=========\n");
		printf("\t\t\t\t 1.当日\n");
		printf("\t\t\t\t 2.上月\n");
		while (1) {
			scanf_s("%d", &result);
			if (result >= 1 && result <= 2)
			{
				if (result == 1) {
					day = displayday();
					month = displaymonth();
					printf("时间\t销售人员编号\t产品编号\t产品销售额\n");
					for (i = 0; i < counts; i++)
					{
						if (sal[i].date.mday == day && sal[i].date.mon == month)
						{
							printf("%d/%d\t   %d\t\t", sal[i].date.mon, sal[i].date.mday, sal[i].num);
							t = 0;
							while (t < 5) {
								printf("%d\t\t", t + 1);
								printf("%d\t\n", sal[i].produtionNum[t]);
								printf("\t\t\t");
								t++;
							}
							putchar('\n');
						}
					}
				}
				else
				{
					month = displaymonth() - 1;
					printf("时间\t销售人员编号\t产品编号\t产品销售额\n");
					for (i = 0; i < counts; i++)
					{
						if (sal[i].date.mon == month)
						{
							printf("%d//%d\t\t%d\t\t\t\t\t", sal[i].date.mon, sal[i].date.mday, sal[i].num);
							t = 0;
							while (t < 5) {
								printf("%d\t\t", t + 1);
								printf("%d\t\t\n", sal[i].produtionNum[t]);
								printf("\t\t\t\t\t\t\t\t");
								t++;
							}
							putchar('\n');
						}
					}
				}
				break;
			}
			else
			{
				printf("输入有误！\n");
			}
		}
	}
}

//6.根据销售员编号查询销售信息
void find(struct Salesman sal[])
{
	int i, t;
	int findnum;
	printf("请输入要查询销售员的编号:");
	scanf_s("%d", &findnum);
	printf("销售员编号\t销售时间\t产品编号\t销售额\n");
	for (i = 0; i < counts; i++) {
		if (findnum == sal[i].num) {
			printf("  %d\t", sal[i].num);
			printf("         %d/%d\t          ", sal[i].date.mon, sal[i].date.mday);
			t = 0;
			while (t < 5) {
				printf("%d\t\t", t + 1);
				printf("  %d\t\n", sal[i].produtionNum[t]);
				printf("\t\t\t\t  ");
				t++;
			}
			putchar('\n');
		}
		else if (findnum > 5 || findnum < 1)
			printf("对不起！没有该销售员编号\n");
	}
}
//7.根据编号删除销售信息
void del(struct Salesman sal[]) {
	int i, j;
	int delnum;
	printf("请输入销售员编号\n");
	//输入学号
	scanf_s("%d", &delnum);
	for (i = 0; i < counts; i++) {
		if (sal[i].num == delnum)
		{
			for (j = i; j < counts; j++)
				sal[j] = sal[j + 1];
			counts--;
		}
		break;
	}
	printf("删除成功！");//找到要删除学号的位置
}
//8.计算月每人销售额
void calculation1(struct Salesman sal[], int month)
{
	int i, j, t, total = 0;
	int each[4];
	for (j = 1; j <= 4; j++) {
		for (i = 0; i < counts; i++)
		{
			if ((month == sal[i].date.mon) && (j == sal[i].num)) {
				t = 0;
				while (t < 5)
				{
					sal[i].dSales += sal[i].produtionNum[t];
					t++;
				}
				total += sal[i].dSales;
			}
		}
		each[j - 1] = total;
	}
	printf("%d月每人的销售额：", month);
	for (i = 0; i < 4; i++) {
		printf("销售员编号：%d    %d\n", i + 1, each[i]);
	}
}
//9.计算每种产品的总销售额
void calculation2(struct Salesman sal[])
{
	int i, t = 0;
	int eachtotal[5];
	memset(eachtotal, 0, sizeof(eachtotal));
	while (t < 5)
	{
		for (i = 0; i < counts; i++)
		{
			eachtotal[t] += sal[i].produtionNum[t];
		}
		printf("产品%d：%d\n", t + 1, eachtotal[t]);
		t++;
	}
}
//10.定义排序
//10.1按销售额对销售员排序
void sort1(struct Salesman sal[])
{
	int i = 0, j, k, t = 0, t1;
	struct sale {
		int num;
		int sales;
	}num[4] = { 0,0 };
	if (sal[i].dSales == 0) {
		printf("请先执行操作5!\n");
	}
	else {
		while (t < 4) {
			num[t].num = t;
			for (i = 0; i < counts; i++)
			{
				if (sal[i].num == t)
					num[t].sales += sal[i].dSales;
			}
			t++;
		}
	}
	printf("按销售额对销售员进行排序（降序）结果：\n");
	for (i = 0; i < 3; i++)
	{
		k = i;
		for (j = i; j < 4; j++)
		{
			if (num[k].sales < num[j].sales) k = j;
		}
		t = num[i].sales;
		t1 = num[i].num;
		num[i].sales = num[k].sales;
		num[i].num = num[k].num;
		num[k].sales = t;
		num[k].num = t1;
	}
	for (i = 0; i < 4; i++)
	{
		printf("%d\n", num[i].num + 1);
	}
}
//10.2按产品总销售额排序
void sort2(struct Salesman sal[])
{
	int i, j, t = 0, t1, k;
	struct sale {
		int num;
		int sales;
	}total[5] = { 0,0 };
	while (t < 5) {
		total[t].num = t;
		for (i = 0; i < counts; i++)
		{
			total[t].sales += sal[i].produtionNum[t];
		}
		t++;
	}
	printf("按总销售额对产品进行排序（降序）结果：\n");
	for (i = 0; i < 4; i++)
	{
		k = i;
		for (j = i; j < 5; j++)
		{
			if (total[k].sales < total[j].sales) k = j;
		}
		t = total[i].sales;
		t1 = total[i].num;
		total[i].sales = total[k].sales;
		total[i].num = total[k].num;
		total[k].sales = t;
		total[k].num = t1;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d\t\t%d\n", total[i].num + 1, total[i].sales);
	}
}
//11.保存销售信息
void save(struct Salesman sal[]) {
	int i = 0, t;
	FILE *file;
	file = fopen("c:\\xiaoshouxinxi.txt", "ab");
	fprintf(file, "时间\t销售员编号\t产品编号\t销售额\r\n");
	printf("\r\n");
	while (i < counts) {
		fprintf(file, "%d/%d\t", sal[i].date.mon, sal[i].date.mday);
		fprintf(file, "                      %d\t", sal[i].num);
		t = 0;
		while (t < 5)
		{
			fprintf(file, "        %d\t", t);
			fprintf(file, "   %d\t\r\n", sal[i].produtionNum[t]);
			fprintf(file, "    \t\t\t");
			t++;
		}
		i++;
		fprintf(file, "\r\n");
	}
	fclose(file);
	printf("保存成功\n");
}
