#include "stdio.h"
#include "stdlib.h"
#include "Windows.h"
#include "String.h"
#include "time.h"
//����ʱ��ṹ��
struct time {
	int mday; /* һ�����е����� - ȡֵ����Ϊ[1,31] */
	int mon; /* �·ݣ���һ�¿�ʼ��0����һ�£� - ȡֵ����Ϊ[0,11] */
};
//��������Ա�ṹ��
struct Salesman {
	int num;
	int dSales;
	int produtionNum[5];
	struct time date;
};
//��������
int counts = 0;
char delnum[10];
//1:��ʼ�����ںͽ���
void initWindow(char *title);
//2:��ʼ���˵�
void initMenu();
//3.����ʱ�亯��
//3.1����day
int displayday();
//3.2����month
int displaymonth();
//4.��ӵ���������Ϣ
void addSales(struct Salesman sal[]);
//5.��ʾ������Ϣ
void display(struct Salesman sal[]);
//6.��������Ա��Ų�ѯ������Ϣ
void find(struct Salesman sal[]);
//7.���ݱ��ɾ��������Ϣ
void del(struct Salesman sal[]);
//8.���������۶�
void calculation1(struct Salesman sal[], int month);
//9.����ÿ�ֲ�Ʒ�������۶�
void calculation2(struct Salesman sal[]);
//10.��������
//10.1�����۶������Ա����
void sort1(struct Salesman sal[]);
//10.2����Ʒ�����۶�����
void sort2(struct Salesman sal[]);
//11.����������Ϣ
void save(struct Salesman stu[]);
//�������
void main() {
	//��ʽ�������ݼ�:ctrl+K+F
	//����ѧ������
	struct Salesman sal[2000] = { 0,0 };
	int result;
	char choice1 = ' ';
	int choice2, month;
	char title[] = "\t\t\t\t\t*********��ӭ����������Ϣ����ϵͳ��********\n\n\n";
	//1:��ʼ�����ںͽ���
	initWindow(title);
	memset(sal->produtionNum, 0, sizeof(sal->produtionNum));
	do {//ѭ��
		initMenu();
		printf("��ѡ��˵���1-9��:\n");
		//���������������
		fflush(stdin);
		scanf_s("%d", &result);
		//���������������
		fflush(stdin);
		if (result >= 1 && result <= 9) {
			switch (result) {
			case 1:
				while (1)
				{
					addSales(sal);//������ӵ���������Ϣ�ĺ���
					printf("�Ƿ����¼��������Ϣ(y/n)��");
					getchar();
					scanf_s("%c", &choice1, 1);
					if (choice1 == 'n') {
						break;
					}
				}
				break;
			case 2: display(sal);//������ʾ������Ϣ�ĺ���
				printf("\n");

				break;
			case 3:
				find(sal);//���ò�ѯ��Ϣ�ĺ���
				break;
			case 4:
				printf("��ȷ��Ҫɾ����?��y/n��");
				getchar();
				scanf_s("%c", &choice1, 1);
				if (choice1 == 'n') {
					break;
				}
				else del(sal);
				break;
			case 5:
				printf("�������·ݣ�\n");
				scanf_s("%d", &month);
				calculation1(sal, month);
				break;
			case 6:
				calculation2(sal);
				break;
			case 7:
				while (1)
				{
					printf("\t\t\t\t��ѡ��ģʽ\n");
					printf("\t\t\t\t 1.�����۶������Ա����\n");
					printf("\t\t\t\t 2.����Ʒ�����۶�����\n");
					printf("\t\t\t\t 3.�˳�ģʽ\n");
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
			default:printf("ллʹ�ã�");


			}
		}
		else printf("��������");
	} while (result != 9);
}
//1:��ʼ���ںͽ���
void initWindow(char *title) {
	//���ô��ڴ�С
	system("mode con:cols=110 lines=150");
	//���ô����������ɫ
	system("color F0");
	//ѭ��������⣨��������
	while (*title != 0)
	{
		//����ַ�ָ����ָ�������
		printf("%c", *title);
		//��ָ��ָ����һ���ַ�
		title++;
		//����
		Sleep(50);


	}
}
//2:��ʼ���˵�
void initMenu() {
	printf("\t\t\t\t\t    =========������Ϣ����ϵͳ=========\n");
	printf("\t\t\t\t 1.¼�뵱��������Ϣ\n");
	printf("\t\t\t\t 2.��ʾ������Ϣ\n");
	printf("\t\t\t\t 3.��������Ա��Ų�ѯ��Ϣ\n");
	printf("\t\t\t\t 4.ɾ��������Ϣ\n");
	printf("\t\t\t\t 5.������ÿ�����۶�\n");
	printf("\t\t\t\t 6.����ÿ�ֲ�Ʒ�����۶�\n");
	printf("\t\t\t\t 7.����\n");
	printf("\t\t\t\t 8.����������Ϣ(���ڱ���֮ǰ��C����ֱ�ӽ����ļ�xiaoshouxinxi.txt)\n");
	printf("\t\t\t\t 9.�˳�ϵͳ\n");
	printf("\t\t\t\t\t   ==================================\n");
}
//3.����ʱ�亯��
//3.1����day
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
//3.2����month
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
//4.��ӵ���������Ϣ
void addSales(struct Salesman sal[])
{
	int t = 0, num;
	while (1) {
		printf("\n������Ҫ���������Ա���(1-4��)��");
		scanf_s("%d", &sal[counts].num);
		if (!(sal[counts].num >= 1 && sal[counts].num <= 4))
			printf("��������");
		else break;
	}
	while (1) {
		printf("\n�����������(XX/XX)��");
		scanf_s("%d/%d", &sal[counts].date.mon, &sal[counts].date.mday);
		if (sal[counts].date.mday > 31 || sal[counts].date.mon > 12)
			printf("��������");
		else break;
	}
	while (t < 5) {
		while (1) {
			printf("\n������Ҫ��������۲�Ʒ���(1-5):");
			getchar();
			scanf("%d", &num);
			if (!(num >= 1 && num <= 5))
				printf("��������");
			else break;
		}
		while (1) {
			printf("\n�����������۲�Ʒ�");
			scanf_s("%d", &sal[counts].produtionNum[num - 1]);
			if (!(sal[counts].produtionNum[num - 1] > 0))
				printf("��������");
			else break;
		}
		t++;
	}
	printf("��Ϣ�Ѿ�¼��ϵͳ��\n");
	counts++;
	//���������������
	fflush(stdin);
}
//5.��ʾ������Ϣ
void display(struct Salesman sal[])
{
	int i, t, result;
	int day, month;
	if (counts == 0) {
		printf("û������!\n������������!\n");
	}
	else {
		printf("\t\t\t=========��ѡ����ʾʱ��=========\n");
		printf("\t\t\t\t 1.����\n");
		printf("\t\t\t\t 2.����\n");
		while (1) {
			scanf_s("%d", &result);
			if (result >= 1 && result <= 2)
			{
				if (result == 1) {
					day = displayday();
					month = displaymonth();
					printf("ʱ��\t������Ա���\t��Ʒ���\t��Ʒ���۶�\n");
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
					printf("ʱ��\t������Ա���\t��Ʒ���\t��Ʒ���۶�\n");
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
				printf("��������\n");
			}
		}
	}
}

//6.��������Ա��Ų�ѯ������Ϣ
void find(struct Salesman sal[])
{
	int i, t;
	int findnum;
	printf("������Ҫ��ѯ����Ա�ı��:");
	scanf_s("%d", &findnum);
	printf("����Ա���\t����ʱ��\t��Ʒ���\t���۶�\n");
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
			printf("�Բ���û�и�����Ա���\n");
	}
}
//7.���ݱ��ɾ��������Ϣ
void del(struct Salesman sal[]) {
	int i, j;
	int delnum;
	printf("����������Ա���\n");
	//����ѧ��
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
	printf("ɾ���ɹ���");//�ҵ�Ҫɾ��ѧ�ŵ�λ��
}
//8.������ÿ�����۶�
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
	printf("%d��ÿ�˵����۶", month);
	for (i = 0; i < 4; i++) {
		printf("����Ա��ţ�%d    %d\n", i + 1, each[i]);
	}
}
//9.����ÿ�ֲ�Ʒ�������۶�
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
		printf("��Ʒ%d��%d\n", t + 1, eachtotal[t]);
		t++;
	}
}
//10.��������
//10.1�����۶������Ա����
void sort1(struct Salesman sal[])
{
	int i = 0, j, k, t = 0, t1;
	struct sale {
		int num;
		int sales;
	}num[4] = { 0,0 };
	if (sal[i].dSales == 0) {
		printf("����ִ�в���5!\n");
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
	printf("�����۶������Ա�������򣨽��򣩽����\n");
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
//10.2����Ʒ�����۶�����
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
	printf("�������۶�Բ�Ʒ�������򣨽��򣩽����\n");
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
//11.����������Ϣ
void save(struct Salesman sal[]) {
	int i = 0, t;
	FILE *file;
	file = fopen("c:\\xiaoshouxinxi.txt", "ab");
	fprintf(file, "ʱ��\t����Ա���\t��Ʒ���\t���۶�\r\n");
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
	printf("����ɹ�\n");
}
