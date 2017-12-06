#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define Max 65535
//���̵����㷨
//�����ȷ������Ѱ��ʱ�����ţ������㷨
//FCFS,SSTF,SCAN

void FCFS(int *diskline,int n,int scan) {
	int num=0;
	printf("---------------------FCFS---------------------------\n");
	for (int i = 0; i < n;i++) {
		printf("%d	",diskline[i]);
		num = num+abs(diskline[i] - scan);
		scan = diskline[i];
	}
	printf("\n");

	printf("�����ܴŵ�Ϊ��%d",num);
}
//���������

void SSTF(int *diskline, int n, int scan) {
	int *visited;
	int index = 0;
	int num = 0;
	int first = scan;
	visited = (int *)malloc(n * sizeof(int));//�Ѿ����ʹ��ķ�������
	
	for (int i = 0; i < n;i++) {
		int k = Max;
		for (int j = 0; j < n; j++) {
			if (diskline[j]<Max) {
				if (abs(diskline[j] - scan) < k) {
					k =abs(diskline[j] - scan);
					index = j;
				}
			}
		}
		visited[i] = diskline[index];
		diskline[index] =Max;
	}
	

	printf("-------------------SSTF--------------------------\n");
	for (int i = 0; i < n;i++) {
		printf("%d		",visited[i]);
		num += abs(visited[i]-first);
		first = visited[i];
	}
	printf("\n");
	printf("%d", num);
}

void SCAN(int *diskline,int n,int scan,int direcion) {
	int *visited1;//����
	int *visited2;//����
	int index=0;
	int pdex = 0;
	visited1 = (int *)malloc(n*sizeof(int));
	visited2 = (int *)malloc(n*sizeof(int));

	for (int i = 0; i < n;i++) {
		for (int j = i; j < n;j++) {
			if (diskline[j] <diskline[i]) {
				int temp = diskline[j];
				diskline[j] = diskline[i];
				diskline[i] = temp;
			}
		}
	}
	int least = diskline[0];
	int  more= diskline[n-1];
	//Ѱ�����Ҳ����
	for (int i = 0; i < n;i++) {
		if (diskline[i] < scan) {
			index++;
		}
	}
	pdex = index + 1;
//�����֣���������
	//visited1����
	for (int i = 0; i <n;i++) {
		for (int j =index; j >=0;j--) {
			visited1[i++] = diskline[j];
		
		}
		for (int k = pdex; k < n;k++) {
			visited1[i++] = diskline[k];
		
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = pdex; j < n; j++) {
			visited2[i] = diskline[j];
			
		}
		for (int k = index; k >= 0; k--) {
			visited2[i] = diskline[k];
	
		}
	}
		if (direcion==1) {
			for (int i = 0; i < n;i++) {
				printf("%d	",visited1[i]);
			}
			printf("\n");
			printf("%d",scan-least+more-least);
		}
		else{
			for (int i = 0; i < n;i++) {
				printf("%d	",visited2[i]);
			}
			printf("\n");
			printf("%d", more-scan+more-least);
		}
	

}

int main(void) {
	int scan;
	int n;//�����������и���
	int op;
	int direction;
	int *diskline = {};
		printf("�����뵱ǰ��ͷλ�ã�		\n");
		scanf_s("%d",&scan);
		printf("����������������и�����		\n");
		scanf_s("%d",&n);
		diskline = (int *)malloc(n * sizeof(int));
		for (int i = 0; i < n;i++) {
			printf("��������Ϊ��\n");
			scanf_s("%d",&diskline[i]);
		}
		printf("-------------------------------��������----------------------------------------\n");
		for (int i = 0; i < n;i++) {
			printf("%d		",diskline[i]);
		}
		printf("\n");
		printf("---------------------------------ѡ��--------------------------------------\n");
		printf("�ȵ��ȷ���	            1\n");
		printf("���Ѱ��ʱ�����ţ�	2\n");
		printf("�����㷨��			    3\n");
		scanf_s("%d",&op);
		if (op == 1)
			FCFS(diskline,n,scan);
		else if (op == 2) {
			printf("�ŵ���ʼ��%d\n",scan);
			SSTF(diskline,n,scan);
		}
		else {
			printf("1Ϊ����2Ϊ����\n");
			scanf_s("%d",&direction);
			SCAN(diskline,n,scan,direction);
		}

		system("pause");
	return 0;
}