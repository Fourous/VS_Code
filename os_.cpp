//先来先服务算法
//最高响应比算法
//每当进程执行后
#include<stdio.h>
#include <stdlib.h>
#define MAX 50
typedef struct pcb
{
	int id;//进程号
	int ExecutionTime;//进程执行时间
	int ArrivalTime;//进程到达时间
	int level;//执行优先级
};

//排序用冒泡排序
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

//先来先服务算法
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
				printf("进程号:%d			执行时间:%d			到达时间:%d", &p[j].id, p[j].ExecutionTime, p[j].ArrivalTime);
				printf("\n");
			}
			else {
				j++;
			}
		}
	}

}


//最高响应比算法
void HRRF() {

}
int main(void) {
	int select;//选择的选项
	int n;
	struct pcb p[MAX];
	printf("请输入进程个数：	\n");
	scanf_s("%d", &n);
	printf("\n");
	for (int i = 1; i <= n;i++) {
		p[i].id = i;
	}
	for (int i = 1; i <= n; i++) {
		printf("请输入%d进程的执行时间：	\n",&p[i].id);
		scanf_s("%d", &p[i].ExecutionTime);
		printf("请输入%d进程到达时间：		\n", &p[i].id);
		scanf_s("%d", &p[i].ArrivalTime);
	}
	for (int i = 1; i <= n; i++) {
		printf("进程号:%d			执行时间:%d			到达时间:%d", &p[i].id, p[i].ExecutionTime, p[i].ArrivalTime);
		printf("\n");
	}
	printf("-----------------------------------选择调度算法：---------------------------------------------------\n");
	printf("	1：先来先服务算法					2：最高响应比算法\n");
	scanf_s("%d", &select);
	if (select == 1) {
		printf("---------------------先来先服务算法-----------------------");
		FCFS(p, n);

	}
	else if (select == 2) {
		printf("-------------------=最高响应比算法-----------------------");
		HRRF();
	}
	else {
		printf("你的输入数字有误，请重新运行！");
		exit(1);
	}
	return 0;
}
