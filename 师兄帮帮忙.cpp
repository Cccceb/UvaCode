/*
p89例题4-6
*/
#include<iostream>
#include<cstring>
#include<string>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("师兄帮帮忙in.txt", "r", stdin);
FILE *fout = freopen("师兄帮帮忙out.txt", "w", stdout);
#endif 
using namespace std;
#define eps  1e-6
#define maxn 10000
typedef struct {
	int no;
	char SID[10];
	int CID;
	char name[10];
	int sorce[4];
	int total;
	int	ranking;
	double ave;
}Student;
Student stu[maxn];
int isScore(char s[]);
void add();
void remove();
void query();
void showRanking();
void showStatisting();
int cmp2(const void *a, const void *b) {
	if (((Student *)a)->no && ((Student *)b)->no)
		return   ((Student *)a)->no - ((Student *)b)->no;
	else	return ((Student *)a)->no ? 0 : 1;
}
int node(const void *a, const void *b) {
	if (((Student *)b)->total && ((Student *)a)->total)

		return  ((Student *)b)->total - ((Student *)a)->total;

	else return ((Student *)a)->total ? 0 : 1;
}

int sum = 0;
int account = 0;

void show() {
	cout << "show" << endl;
	for (int i = 0; i < sum; i++) {

		if (stu[i].SID) cout << "SID  " << stu[i].SID << "  CID  " << stu[i].CID << "  NAME  " << stu[i].name
			<< "Chinses  " << stu[i].sorce[0] << "  math  " << stu[i].sorce[1] <<
			"  English  " << stu[i].sorce[2] << "  Pro  " << stu[i].sorce[3] << endl;

	}
}
int main() {

	int choice;
	for (;;) {
		cout << "Welcome to Student Performance Management System (SPMS)." << endl << endl << "1 - Add" << endl << "2 - Remove" << endl << "3 - Query" << endl << "4 - Show ranking"
			<< endl << "5 - Show Statistics" << endl << "0 - Exit" << endl << endl;
		scanf("%d", &choice);
		//cout << "choice" << choice<<endl;
		switch (choice) {
			//case 1:add(); show(); break;
		case 1:add(); break;
		case 2:remove(); break;
			//case 2:remove(); show(); break;
		case 3:query(); break;
		case 4:showRanking(); break;
		case 5:showStatisting(); break;
		case 0:return 0; break;
		default:return 0;
		}
	}
	system("pause");
}
void add() {

	for (;; ) {
		int i = sum;
		cout << "Please enter the SID, CID, name and four scores. Enter 0 to finish." << endl;
		int flag = 1;
		scanf("%s", stu[i].SID);
		for (int j = 0; j < sum; j++)
		{
			if (!strcmp(stu[i].SID, stu[j].SID)) {
				cout << "Duplicated SID." << endl;
				flag = 0;
			}
		}
		if (strlen(stu[i].SID) == 1) return;
		scanf("%d %s", &stu[i].CID, stu[i].name);
		//cout << "SID  " << stu[i].SID << "  CID  " << stu[i].CID << "  NAME  " << stu[i].name;
		stu[i].total = 0;
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &stu[i].sorce[j]);
			stu[i].total += stu[i].sorce[j];

			//	cout << stu[i].sorce[j] << " ";
		}
		stu[i].ave = stu[i].total / 4.0;
		if (flag) {
			sum++;
			account++;
			stu[i].no = sum;
		}
		else {
			stu[i].total = 0;
			stu[i].CID = 0;
			stu[i].SID[0] = '\0';
			stu[i].name[0] = '\0';
			for (int j = 0; j < 4; j++) stu[i].sorce[j] = 0;
		}
	}
}
void remove() {


	for (;;) {
		int num = 0;
		cout << "Please enter SID or name. Enter 0 to finish." << endl;
		char s[20];
		scanf("%s", s);
		if (strlen(s) == 1 && s[0] == '0') return;
		for (int i = 0; i < sum; i++) {
			if (!strcmp(stu[i].name, s) || !strcmp(stu[i].SID, s)) {
				stu[i].no = 0;
				stu[i].total = 0;
				stu[i].CID = 0;
				stu[i].SID[0] = '\0';
				stu[i].name[0] = '\0';
				num++;
				account--;




			}
		}
		cout << num << " student(s) removed." << endl;
	}
}
void query() {
	//按总成绩排名
	for (int i = 0; i < sum; i++) qsort(stu, sum - i, sizeof(Student), node);
	//cout << "ranking!!" << endl; for (int i = 0; i < sum; i++) cout << stu[i].total<<endl;
	for (int i = 0; i < sum; i++) {
		if (stu[i].total == stu[i - 1].total) stu[i].ranking = stu[i - 1].ranking;
		else stu[i].ranking = i + 1;
	}
	for (int i = 0; i < sum; i++)qsort(stu, sum - i, sizeof(Student), cmp2);




	for (;;) {
		cout << "Please enter SID or name. Enter 0 to finish." << endl;
		char s[20];
		scanf("%s", s);
		if (strlen(s) == 1 && s[0] == '0') return;
		//输入的是姓名
		for (int i = 0; i < sum; i++) {
			Student p = stu[i];
			if (!strcmp(stu[i].name, s) || !strcmp(stu[i].SID, s)) {
				//	cout << "No. " << stu[i].no << endl;
				printf("%d %s %d %s ", p.ranking, p.SID, p.CID, p.name);
				for (int i = 0; i < 4; i++) printf("%d ", p.sorce[i]);
				printf("%d %.2f\n", p.total, p.ave);
			}
		}
	}
};
void showRanking() {
	cout << "Showing the ranklist hurts students' self-esteem. Don't do that." << endl;
	return;
};
void showStatisting() {
	cout << "Please enter class ID, 0 for the whole statistics." << endl;
	int cls;
	int num = 0;
	double ac = 0.0, am = 0.0, ap = 0.0, ae = 0.0;//平均分
	int pc = 0, pm = 0, pp = 0, pe = 0, pa = 0;//通过人数
	int m = 0, n = 0, p = 0, q = 0;
	int pass[5]{};
	memset(pass, 0, 5 * sizeof(int));
	cin >> cls;
	//cout << "Class: " << cls << endl;
	if (cls == 0) {
		for (int i = 0; i < sum; i++) {
			if (stu[i].CID) {
				int hh = 0;
				ac += stu[i].sorce[0]; if (stu[i].sorce[0] >= 60) { hh++; pc++; }
				am += stu[i].sorce[1]; if (stu[i].sorce[1] >= 60) { hh++; pm++; }
				ae += stu[i].sorce[2]; if (stu[i].sorce[2] >= 60) { hh++; pe++; }
				ap += stu[i].sorce[3]; if (stu[i].sorce[3] >= 60) { hh++; pp++; }
				for (int j = 1; j <= hh; j++)pass[j]++;
			}
		}
		num = account;
	}
	else {
		for (int i = 0; i < sum; i++) {
			if (stu[i].CID == cls) {
				num++;
				int hh = 0;
				ac += stu[i].sorce[0]; if (stu[i].sorce[0] >= 60) { hh++; pc++; }
				am += stu[i].sorce[1]; if (stu[i].sorce[1] >= 60) { hh++; pm++; }
				ae += stu[i].sorce[2]; if (stu[i].sorce[2] >= 60) { hh++; pe++; }
				ap += stu[i].sorce[3]; if (stu[i].sorce[3] >= 60) { hh++; pp++; }
				for (int j = 1; j <= hh; j++)pass[j]++;
			}

		}
	}
	if (num) {
		ac = ac / num + eps;
		am = am / num + eps;
		ae = ae / num + eps;
		ap = ap / num + eps;
	}
	else {
		ac = ap = am = ae = 0.00;
	}

	printf("Chinese\nAverage Score: %.2f\nNumber of passed students: %d\nNumber of failed students: %d\n\n",
		ac, pc, num - pc);
	printf("Mathematics\nAverage Score: %.2f\nNumber of passed students: %d\nNumber of failed students: %d\n\n",
		am, pm, num - pm);
	printf("English\nAverage Score: %.2f\nNumber of passed students: %d\nNumber of failed students: %d\n\n",
		ae, pe, num - pe);
	printf("Programming\nAverage Score: %.2f\nNumber of passed students: %d\nNumber of failed students: %d\n\n",
		ap, pp, num - pp);
	printf("Overall:\nNumber of students who passed all subjects: %d\nNumber of students who passed 3 or more subjects: %d\n", pass[4], pass[3]);
	printf("Number of students who passed 2 or more subjects: %d\nNumber of students who passed 1 or more subjects: %d\n", pass[2], pass[1]);
	printf("Number of students who failed all subjects: %d\n\n", num - pass[1]);


}