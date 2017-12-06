//先来先服务算法
//最高响应比算法
//计算周转时间，每一个进程包括到达时间和服务时间
//计算时候要计算周转时间和完成时间，并计算带权周转时间
#include<stdio.h>
#include <stdlib.h>
#define MAX 50
struct pcb
{
	int id;//进程号
	int ExecutionTime;//进程执行时间
	int ArrivalTime;//进程到达时间
};

//先来先服务算法
void FCFS(pcb *p, int n) {
	int *start = {};//进程开始时间
	int *end = {};//进程结束时间
	pcb temp;
	int *ztime = {};//周转时间
	int *pztime = {};//带权周转时间
						//查找存放的最小值
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
		printf("进程号:%d	执行时间:%d	到达时间:%d	开始时间:%d	完成时间:%d	周转时间:%d	带权周转时间:%d", p[i].id, p[i].ExecutionTime, p[i].ArrivalTime, start[i], end[i], ztime[i], pztime[i]);
		printf("\n");
	}
}


//最高响应比算法
void HRRF(pcb *p, int n) {
	//（响应时间+作业运行时间）/作业运行时间=1+响应时间/作业运行时间
	int *start = {};
	int *end = {};
	int *ztime = {};
	int small=255;
	int *pztime = {};
	int x=255;//比较的依据
	pcb temp;
	start = (int *)malloc(n * sizeof(int));
	end = (int *)malloc(n * sizeof(int));
	ztime = (int *)malloc(n * sizeof(int));
	pztime = (int *)malloc(n * sizeof(int));
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
				//查找最先进入的进程
			for (int j = 1; j <=n;j++) {
				if (small> p[j].ArrivalTime)		small = p[j].ArrivalTime;
			}
					start[i] = small;
					end[i] = start[i] + p[i].ExecutionTime;
					ztime[i] = end[i] - p[i].ArrivalTime;
				//	printf("进程号:%d	执行时间:%d	到达时间:%d	开始时间:%d	完成时间:%d	周转时间:%d	带权周转时间:%d", p[i].id, p[i].ExecutionTime, p[i].ArrivalTime, start[i], end[i], ztime[i], pztime[i]);
					//printf("\n");
		}
		else {
			//判断等待的进程，扫描符合要求的进程,进程等待执行
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
		printf("进程号:%d	执行时间:%d	到达时间:%d	开始时间:%d	完成时间:%d	周转时间:%d	带权周转时间:%d", p[i].id, p[i].ExecutionTime, p[i].ArrivalTime, start[i], end[i], ztime[i], pztime[i]);
		printf("\n");
	}

}
int main(void) {
	int select;//选择的选项
	int n;//进程个数
	struct pcb p[MAX];
	printf("请输入进程个数：	\n");
	scanf_s("%d", &n);
	printf("\n");
	for (int i = 1; i <= n; i++) {
		p[i].id = i;
	}
	for (int i = 1; i <= n; i++) {
		printf("请输入%d进程的执行时间：	\n", p[i].id);
		scanf_s("%d", &p[i].ExecutionTime);
		printf("请输入%d进程到达时间：		\n", p[i].id);
		scanf_s("%d", &p[i].ArrivalTime);
	}
	for (int i = 1; i <= n; i++) {
		printf("进程号:%d			执行时间:%d			到达时间:%d", p[i].id, p[i].ExecutionTime, p[i].ArrivalTime);
		printf("\n");
	}
	printf("-----------------------------------选择调度算法：---------------------------------------------------\n");
	printf("	1：先来先服务算法					2：最高响应比算法\n");
	scanf_s("%d", &select);
	if (select == 1) {
		printf("---------------------先来先服务算法-----------------------\n");
		FCFS(p, n);

	}
	else if (select == 2) {
		printf("-------------------=最高响应比算法-----------------------\n");
		HRRF(p, n);
	}
	else {
		printf("你的输入数字有误，请重新运行！");
		exit(1);
	}
	system("pause");
	return 0;
}
