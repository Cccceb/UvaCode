/*
如果x加上x的各个数字之和得到y，那么x就是y的生成元。给出n(1<=n<=100000)
求最小生成元。无解输出0.例如，n=216,121,2005时的解分别为198，0，1979
*/
#include<iostream>
#include<cstring>
#define maxn 100005
int main() {
	int ans[maxn]{  };
	for (int i = 1; i < maxn; i++) {
		//枚举求出所有的数的生成元，然后查表
		int x = i, y = i;
		while (x>0){//求各个位相加的方法
			y += x % 10;
			x /= 10;
		}
		if (ans[y] == 0 || ans[y] > i) {
			ans[y] = i;
		}
	}
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		std::cout << ans[n] << std::endl;
	}
	system("pause");
}