//�����ȷ����㷨
//�����Ӧ���㷨
//ÿ������ִ�к�
#include<stdio.h>
#include <stdlib.h>
#define MAX 50
typedef struct pcb
{
	int id;//���̺�
	int ExecutionTime;//����ִ��ʱ��
	int ArrivalTime;//���̵���ʱ��
	int level;//ִ�����ȼ�
};

//������ð������
void BubbleSort(int *a, int n) {
	int bound = 0;
	int exchange = n - 1;
	while (exchange != 0) {
		exchange = bound;
		for (int i = 0; i<n; i++) {
			if (a[i]>a[i + 1]) {
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = a[i];
				exchange = i;
			}
		}
	}
}

//�����ȷ����㷨
void FCFS(pcb *p, int n) {
	 int *time;
	 time = (int *)malloc(n*sizeof(int));
	for (int i = 1; i <= n; i++) {
		time[i] = p[i].ArrivalTime;
	}
	BubbleSort(time, n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (time[i] == p[j].ArrivalTime) {
				printf("���̺�:%d			ִ��ʱ��:%d			����ʱ��:%d", &p[j].id, p[j].ExecutionTime, p[j].ArrivalTime);
				printf("\n");
			}
			else {
				j++;
			}
		}
	}

}


//�����Ӧ���㷨
void HRRF() {

}
int main(void) {
	int select;//ѡ���ѡ��
	int n;
	struct pcb p[MAX];
	printf("��������̸�����	\n");
	scanf_s("%d", &n);
	printf("\n");
	for (int i = 1; i <= n;i++) {
		p[i].id = i;
	}
	for (int i = 1; i <= n; i++) {
		printf("������%d���̵�ִ��ʱ�䣺	\n",&p[i].id);
		scanf_s("%d", &p[i].ExecutionTime);
		printf("������%d���̵���ʱ�䣺		\n", &p[i].id);
		scanf_s("%d", &p[i].ArrivalTime);
	}
	for (int i = 1; i <= n; i++) {
		printf("���̺�:%d			ִ��ʱ��:%d			����ʱ��:%d", &p[i].id, p[i].ExecutionTime, p[i].ArrivalTime);
		printf("\n");
	}
	printf("-----------------------------------ѡ������㷨��---------------------------------------------------\n");
	printf("	1�������ȷ����㷨					2�������Ӧ���㷨\n");
	scanf_s("%d", &select);
	if (select == 1) {
		printf("---------------------�����ȷ����㷨-----------------------");
		FCFS(p, n);

	}
	else if (select == 2) {
		printf("-------------------=�����Ӧ���㷨-----------------------");
		HRRF();
	}
	else {
		printf("������������������������У�");
		exit(1);
	}
	return 0;
}
