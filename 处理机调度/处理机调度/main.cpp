//�����ȷ����㷨
//�����Ӧ���㷨
//������תʱ�䣬ÿһ�����̰�������ʱ��ͷ���ʱ��
//����ʱ��Ҫ������תʱ������ʱ�䣬�������Ȩ��תʱ��
#include<stdio.h>
#include <stdlib.h>
#define MAX 50
struct pcb
{
	int id;//���̺�
	int ExecutionTime;//����ִ��ʱ��
	int ArrivalTime;//���̵���ʱ��
};

//�����ȷ����㷨
void FCFS(pcb *p, int n) {
	int *start = {};//���̿�ʼʱ��
	int *end = {};//���̽���ʱ��
	pcb temp;
	int *ztime = {};//��תʱ��
	int *pztime = {};//��Ȩ��תʱ��
						//���Ҵ�ŵ���Сֵ
	start = (int *)malloc(n*sizeof(int));
	end = (int *)malloc(n * sizeof(int));
	ztime = (int *)malloc(n * sizeof(int));
	pztime = (int *)malloc(n * sizeof(int));
	for (int i = 1; i < n; i++) {
		if (p[i].ArrivalTime > p[i + 1].ArrivalTime) {
			temp = p[i];
			p[i] = p[i + 1];
			p[i + 1] = temp;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			start[i] = p[i].ArrivalTime;
			end[i] = start[i] + p[i].ExecutionTime;
		}
		else {
			start[i] = end[i - 1];
			end[i] = start[i] + p[i].ExecutionTime;
		}
		ztime[i] = end[i] - p[i].ArrivalTime;
		pztime[i] = ztime[i] / p[i].ExecutionTime;
		printf("���̺�:%d	ִ��ʱ��:%d	����ʱ��:%d	��ʼʱ��:%d	���ʱ��:%d	��תʱ��:%d	��Ȩ��תʱ��:%d", p[i].id, p[i].ExecutionTime, p[i].ArrivalTime, start[i], end[i], ztime[i], pztime[i]);
		printf("\n");
	}
}


//�����Ӧ���㷨
void HRRF(pcb *p, int n) {
	//����Ӧʱ��+��ҵ����ʱ�䣩/��ҵ����ʱ��=1+��Ӧʱ��/��ҵ����ʱ��
	int *start = {};
	int *end = {};
	int *ztime = {};
	int small=255;
	int *pztime = {};
	int x=255;//�Ƚϵ�����
	pcb temp;
	start = (int *)malloc(n * sizeof(int));
	end = (int *)malloc(n * sizeof(int));
	ztime = (int *)malloc(n * sizeof(int));
	pztime = (int *)malloc(n * sizeof(int));
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
				//�������Ƚ���Ľ���
			for (int j = 1; j <=n;j++) {
				if (small> p[j].ArrivalTime)		small = p[j].ArrivalTime;
			}
					start[i] = small;
					end[i] = start[i] + p[i].ExecutionTime;
					ztime[i] = end[i] - p[i].ArrivalTime;
				//	printf("���̺�:%d	ִ��ʱ��:%d	����ʱ��:%d	��ʼʱ��:%d	���ʱ��:%d	��תʱ��:%d	��Ȩ��תʱ��:%d", p[i].id, p[i].ExecutionTime, p[i].ArrivalTime, start[i], end[i], ztime[i], pztime[i]);
					//printf("\n");
		}
		else {
			//�жϵȴ��Ľ��̣�ɨ�����Ҫ��Ľ���,���̵ȴ�ִ��
			if (p[i].ArrivalTime < end[i-1]) {
				for (int j = i; j < n;j++) {
					if ((end[i - 1] - p[j].ArrivalTime) / p[j].ExecutionTime >(end[i - 1] - p[j+1].ArrivalTime) / p[j+1].ExecutionTime) {
						temp = p[j];
						p[j] = p[j+1];
						p[j + 1] = temp;
						//x = (end[i - 1] - p[j].ArrivalTime) / p[j].ExecutionTime;
					}
				}
			}
			start[i] = end[i - 1];
			end[i] = start[i] + p[i].ExecutionTime;
			ztime[i] = end[i] - p[i].ArrivalTime;
			pztime[i] = ztime[i] / p[i].ExecutionTime;
		}
		printf("���̺�:%d	ִ��ʱ��:%d	����ʱ��:%d	��ʼʱ��:%d	���ʱ��:%d	��תʱ��:%d	��Ȩ��תʱ��:%d", p[i].id, p[i].ExecutionTime, p[i].ArrivalTime, start[i], end[i], ztime[i], pztime[i]);
		printf("\n");
	}

}
int main(void) {
	int select;//ѡ���ѡ��
	int n;//���̸���
	struct pcb p[MAX];
	printf("��������̸�����	\n");
	scanf_s("%d", &n);
	printf("\n");
	for (int i = 1; i <= n; i++) {
		p[i].id = i;
	}
	for (int i = 1; i <= n; i++) {
		printf("������%d���̵�ִ��ʱ�䣺	\n", p[i].id);
		scanf_s("%d", &p[i].ExecutionTime);
		printf("������%d���̵���ʱ�䣺		\n", p[i].id);
		scanf_s("%d", &p[i].ArrivalTime);
	}
	for (int i = 1; i <= n; i++) {
		printf("���̺�:%d			ִ��ʱ��:%d			����ʱ��:%d", p[i].id, p[i].ExecutionTime, p[i].ArrivalTime);
		printf("\n");
	}
	printf("-----------------------------------ѡ������㷨��---------------------------------------------------\n");
	printf("	1�������ȷ����㷨					2�������Ӧ���㷨\n");
	scanf_s("%d", &select);
	if (select == 1) {
		printf("---------------------�����ȷ����㷨-----------------------\n");
		FCFS(p, n);

	}
	else if (select == 2) {
		printf("-------------------=�����Ӧ���㷨-----------------------\n");
		HRRF(p, n);
	}
	else {
		printf("������������������������У�");
		exit(1);
	}
	system("pause");
	return 0;
}
