#include<iostream>

using namespace std;

struct work {

	int num;//作业号
	int start;//提交时间
	int time;//运行时间
	int starttime;//开始时间
	int endtime;//结束时间
	int alltime;
	int stu;//状态
};

void FCFS(work data[10], int num) {
	int temp = data[0].start;//记录上一次的结束时间
	for (int i = 0; i<num; i++) {
		if (data[i].start <= temp) {
			data[i].starttime = temp;
			data[i].endtime = temp + data[i].time;
			temp = data[i].endtime;
		}
		else {
			data[i].starttime = data[i].start;
			data[i].endtime = data[i].start + data[i].time;
			temp = data[i].endtime;
		}

	}
}

void HRN(work data[10], int num) {

	int best = 0;//最高响应比序号
	float wt = 0;//响应比
	int w;//等待时间
	int t;//执行时间
	int temp = data[0].start;//上一个进程结束时间
	for (int i = 0; i < num; i++) {
		data[best].starttime = temp;
		data[best].endtime = temp + data[best].time;
		data[best].alltime = data[best].endtime - data[best].start;
		temp = data[best].endtime;
		data[best].stu = 1;
		wt = 0;
		for (int j = 0; j < num; j++) {
			if (data[j].stu == 1)
				continue;
			if (data[j].start < temp) {
				w = temp - data[j].start;
				t = data[j].time;
				float k = 1 + w / t / 1.0;
				if (k >= wt) {
					best = j;
					wt = k;
				}
			}
		}
	}
}

void printW(work data[10], int num) {

	cout << "作业号\t" << "提交时间\t" << "运行时间\t" << "运行开始时间\t" << "运行结束时间\t" << "周转时间" << endl;
	for (int i = 0; i < num; i++) {
		data[i].alltime = data[i].endtime - data[i].start;
		cout << data[i].num << "\t" << data[i].start << "\t\t" << data[i].time << "\t\t" << data[i].starttime << "\t\t" << data[i].endtime << "\t\t" << data[i].alltime << endl;
	}
	float total = 0;
	for (int j = 0; j < num; j++) {
		total += data[j].alltime;
	}
	cout << "平均周转时间：" << total / num / 1.0 << endl;
	float avetotal = 0;
	for (int k = 0; k < num; k++) {
		float y = data[k].alltime / data[k].time / 1.0;
		avetotal += y;
	}
	cout << "平均带权周转时间：" << avetotal / num / 1.0 << endl;
}

int main() {


	work data[10];
	int num;
	cout << "请输入测试的数据量（上限为10）：";
	cin >> num;
	cout << "开始输入数据：" << endl;
	cout << "----------------------------" << endl;
	for (int i = 0; i< num; i++) {

		cout << "作业号：";
		cin >> data[i].num;
		cout << "提交时间：";
		cin >> data[i].start;
		cout << "运行时间：";
		cin >> data[i].time;
		data[i].stu = 0;//该进程尚未执行

		cout << "----------------------------" << endl;
	}

	while (true) {

		int j;
		cout << "请选择运行的算法" << endl;
		cout << "1.先进先执行算法" << endl;
		cout << "2.最高响应比算法" << endl;
		cout << "3.退出" << endl;
		cout << "您的选择是：";
		cin >> j;

		switch (j) {

		case 1:FCFS(data, num); printW(data, num); break;
		case 2:HRN(data, num); printW(data, num); break;
		case 3:break;
		}
		if (j == 3)
			break;
	}

	return 0;
}