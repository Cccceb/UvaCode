#include<iostream>
#include<string>
#include<map>
#include<queue>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("并行程序模拟in.txt", "r", stdin);
FILE *fout = freopen("并行程序模拟out.txt", "w", stdout);
#endif 
using namespace std;
#define maxn 500
int tim[5];//记录每个操作的时间
map<string, string> value;
deque<int> waiting;//等待队列，存队列的ID（数组中的下标）
int quota;//配额

bool lockKey = false;
int analysis(string s) {
	if (s.find('=') != -1) {
		int m = s.find('=');
		string l = s.substr(0, m - 1);
		string r = s.substr(m + 2);
		value[l] = r;
		return tim[0];
	}
	else if (s.substr(0, 5) == "print") {
		string a = s.substr(6);
		cout << waiting.front() + 1 << ": ";
		if(value.count(a)) cout<< value[a] << endl;
		else cout << "0" << endl;
		return tim[1];
	}
	else if (s == "lock") {
		if (!lockKey) {
			lockKey = true;
			return tim[2];
		}
		else return -1;

	}
	else if (s == "unlock") {
	
		lockKey = false;

		return -2;
	}
	else if (s == "end") {
		return tim[4];
	}
}
int main() {
	int T;
	cin >> T;
	bool first = true;
	while (T--) {
		if (first) first = false;
		else cout << endl;
		queue<string> pro[maxn];
	
		queue<int> block;//阻塞队列
		value.clear();
		waiting.clear();
		int n;
		cin >> n;
		for (int i = 0; i < 5; i++) cin >> tim[i];

		cin >> quota; getchar();
		for (int i = 0; i < n; i++) {
			string s;
			while (getline(cin, s)) {
				pro[i].push(s);
				if (s == "end") break;
			}
			waiting.push_back(i);
		}



		while (!waiting.empty()) {
			queue<string> running = pro[waiting.front()];
			int t = quota;
			bool flag = true;
			while (!running.empty() && t>0) {
				int w = analysis(running.front());
				if (w == -1) {//说明不是第一次执行到lock
					block.push(waiting.front());
					flag = false;
					break;
				}
				if (w == -2) {
					if (!block.empty()) {
						int now = waiting.front();
						waiting.pop_front();
						waiting.push_front(block.front());
						block.pop();
						waiting.push_front(now);
					}
					w = tim[3];
				}
				

				t -= w;
				running.pop();
				
			}
			if (flag && !running.empty()) {

				waiting.push_back(waiting.front());
			}
			pro[waiting.front()] = running;

			waiting.pop_front();
		}
	
	}

	
}