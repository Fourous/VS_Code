#include<iostream>

using namespace std;

struct work {

	int num;//��ҵ��
	int start;//�ύʱ��
	int time;//����ʱ��
	int starttime;//��ʼʱ��
	int endtime;//����ʱ��
	int alltime;
	int stu;//״̬
};

void FCFS(work data[10], int num) {
	int temp = data[0].start;//��¼��һ�εĽ���ʱ��
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

	int best = 0;//�����Ӧ�����
	float wt = 0;//��Ӧ��
	int w;//�ȴ�ʱ��
	int t;//ִ��ʱ��
	int temp = data[0].start;//��һ�����̽���ʱ��
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

	cout << "��ҵ��\t" << "�ύʱ��\t" << "����ʱ��\t" << "���п�ʼʱ��\t" << "���н���ʱ��\t" << "��תʱ��" << endl;
	for (int i = 0; i < num; i++) {
		data[i].alltime = data[i].endtime - data[i].start;
		cout << data[i].num << "\t" << data[i].start << "\t\t" << data[i].time << "\t\t" << data[i].starttime << "\t\t" << data[i].endtime << "\t\t" << data[i].alltime << endl;
	}
	float total = 0;
	for (int j = 0; j < num; j++) {
		total += data[j].alltime;
	}
	cout << "ƽ����תʱ�䣺" << total / num / 1.0 << endl;
	float avetotal = 0;
	for (int k = 0; k < num; k++) {
		float y = data[k].alltime / data[k].time / 1.0;
		avetotal += y;
	}
	cout << "ƽ����Ȩ��תʱ�䣺" << avetotal / num / 1.0 << endl;
}

int main() {


	work data[10];
	int num;
	cout << "��������Ե�������������Ϊ10����";
	cin >> num;
	cout << "��ʼ�������ݣ�" << endl;
	cout << "----------------------------" << endl;
	for (int i = 0; i< num; i++) {

		cout << "��ҵ�ţ�";
		cin >> data[i].num;
		cout << "�ύʱ�䣺";
		cin >> data[i].start;
		cout << "����ʱ�䣺";
		cin >> data[i].time;
		data[i].stu = 0;//�ý�����δִ��

		cout << "----------------------------" << endl;
	}

	while (true) {

		int j;
		cout << "��ѡ�����е��㷨" << endl;
		cout << "1.�Ƚ���ִ���㷨" << endl;
		cout << "2.�����Ӧ���㷨" << endl;
		cout << "3.�˳�" << endl;
		cout << "����ѡ���ǣ�";
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