#include<iostream>
#include<vector>
#include<queue>
#include<set>
#pragma warning(disable:4996)
using namespace std;
typedef  long long   LL;
const int mulnum[3] = { 2,3,5 };
int main()
{

	priority_queue<LL, vector<LL>, greater<LL> > pq;
	set<LL> ugn;
	pq.push(1);
	ugn.insert(1);
	for (int i = 1;; i++) {
		LL x = pq.top();
		pq.pop();
		if (i == 1500) {
			cout << "The 1500'th ugly number is " << x << "."<<endl;
			break;
		}
		for (int j = 0; j < 3; j++) {

			LL x2 = x*mulnum[j];
			if (!ugn.count(x2)) {
				pq.push(x2);
				ugn.insert(x2);
			}


		}
	}
}