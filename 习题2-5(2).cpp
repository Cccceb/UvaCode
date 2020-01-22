#include<iostream>
#include <sstream>
#pragma  warning (disable:4996) 
#define LOCAL
int main() {
	using namespace std;
	FILE *fin, *fout;
	int kase = 0;
	long long int a,b;
	int c;
	string s;
#ifdef LOCAL
	fin = freopen("习题2-5in.txt", "r", stdin);
	fout = freopen("习题2-5out.txt", "w", stdout);
#endif
	while (cin >> a >> b >> c && a && c && c) {
		double cn = 5;
		long long int mu = 1, flo = 0;
		stringstream ss;
		double con = (double)a / (double)b;
		switch (c) {
		case 0: printf("%.0f\n", con); break;
		case 1: printf("%.1f\n", con); break;
		case 2: printf("%.2f\n", con); break;
		case 3: printf("%.3f\n", con); break;
		case 4: printf("%.4f\n", con); break;
		case 5: printf("%.5f\n", con); break;
		case 6: printf("%.6f\n", con); break;
		case 7: printf("%.7f\n", con); break;
		case 8: printf("%.8f\n", con); break;
		case 9: printf("%.9f\n", con); break;
		case 10: printf("%.10f\n", con); break;
		case 11: printf("%.11f\n", con); break;
		case 12: printf("%.12f\n", con); break;
		case 13: printf("%.13f\n", con); break;
		case 14: printf("%.14f\n", con); break;
		case 15: printf("%.15f\n", con); break;
		case 16: printf("%.16f\n", con); break;
		case 17: printf("%.17f\n", con); break;
		case 18: printf("%.18f\n", con); break;
		case 19: printf("%.19f\n", con); break;
		case 20: printf("%.20f\n", con); break;
		case 21: printf("%.21f\n", con); break;
		case 22: printf("%.22f\n", con); break;
		case 23: printf("%.23f\n", con); break;
		case 24: printf("%.24f\n", con); break;
		case 25: printf("%.25f\n", con); break;
		case 26: printf("%.26f\n", con); break;
		case 27: printf("%.27f\n", con); break;
		case 28: printf("%.28f\n", con); break;
		case 29: printf("%.29f\n", con); break;
		case 30: printf("%.30f\n", con); break;
		case 31: printf("%.31f\n", con); break;
		case 32: printf("%.32f\n", con); break;
		case 33: printf("%.33f\n", con); break;
		case 34: printf("%.34f\n", con); break;
		case 35: printf("%.35f\n", con); break;
		case 36: printf("%.36f\n", con); break;
		case 37: printf("%.37f\n", con); break;
		case 38: printf("%.38f\n", con); break;
		case 39: printf("%.39f\n", con); break;
		case 40: printf("%.40f\n", con); break;
		case 41: printf("%.41f\n", con); break;
		case 42: printf("%.42f\n", con); break;
		case 43: printf("%.43f\n", con); break;
		case 44: printf("%.44f\n", con); break;
		case 45: printf("%.45f\n", con); break;
		case 46: printf("%.46f\n", con); break;
		case 47: printf("%.47f\n", con); break;
		case 48: printf("%.48f\n", con); break;
		case 49: printf("%.49f\n", con); break;
		case 50: printf("%.50f\n", con); break;
		case 51: printf("%.51f\n", con); break;
		case 52: printf("%.52f\n", con); break;
		case 53: printf("%.53f\n", con); break;
		case 54: printf("%.54f\n", con); break;
		case 55: printf("%.55f\n", con); break;
		case 56: printf("%.56f\n", con); break;
		case 57: printf("%.57f\n", con); break;
		case 58: printf("%.58f\n", con); break;
		case 59: printf("%.59f\n", con); break;
		case 60: printf("%.60f\n", con); break;
		case 61: printf("%.61f\n", con); break;
		case 62: printf("%.62f\n", con); break;
		case 63: printf("%.63f\n", con); break;
		case 64: printf("%.64f\n", con); break;
		case 65: printf("%.65f\n", con); break;
		case 66: printf("%.66f\n", con); break;
		case 67: printf("%.67f\n", con); break;
		case 68: printf("%.68f\n", con); break;
		case 69: printf("%.69f\n", con); break;
		case 70: printf("%.70f\n", con); break;
		case 71: printf("%.71f\n", con); break;
		case 72: printf("%.72f\n", con); break;
		case 73: printf("%.73f\n", con); break;
		case 74: printf("%.74f\n", con); break;
		case 75: printf("%.75f\n", con); break;
		case 76: printf("%.76f\n", con); break;
		case 77: printf("%.77f\n", con); break;
		case 78: printf("%.78f\n", con); break;
		case 79: printf("%.79f\n", con); break;
		case 80: printf("%.80f\n", con); break;
		case 81: printf("%.81f\n", con); break;
		case 82: printf("%.82f\n", con); break;
		case 83: printf("%.83f\n", con); break;
		case 84: printf("%.84f\n", con); break;
		case 85: printf("%.85f\n", con); break;
		case 86: printf("%.86f\n", con); break;
		case 87: printf("%.87f\n", con); break;
		case 88: printf("%.88f\n", con); break;
		case 89: printf("%.89f\n", con); break;
		case 90: printf("%.90f\n", con); break;
		case 91: printf("%.91f\n", con); break;
		case 92: printf("%.92f\n", con); break;
		case 93: printf("%.93f\n", con); break;
		case 94: printf("%.94f\n", con); break;
		case 95: printf("%.95f\n", con); break;
		case 96: printf("%.96f\n", con); break;
		case 97: printf("%.97f\n", con); break;
		case 98: printf("%.98f\n", con); break;
		case 99: printf("%.99f\n", con); break;
		case 100: printf("%.100f\n", con); break;

		}
		/*for (int i = 0; i <= c; i++) {
			cn /= 10;
		}
		con += cn;//四舍五入
		for (int i = 0; i < c; i++) {
			con *= 10;
			mu *= 10;
		}
		flo = con + cn / 10;
		ss << flo;
		s = ss.str();
		s.insert(s.length() - c, ".");
		if ((s.length() - c) == 1) s.insert(0, "0");
		cout << s << endl;

	//	cout << "Case" << ++kase << ": " << flo / mu << "." << flo % mu << endl;;*/
	}
}