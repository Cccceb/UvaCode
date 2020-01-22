#include<iostream>
#include<string>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("Ï°Ìâ6-3in.txt", "r", stdin);
FILE *fout = freopen("Ï°Ìâ6-3out.txt", "w", stdout);
#endif 
using namespace std;
typedef struct node {
	struct node *lchild, *rchild;
	char data;
}node, *ptr;
ptr Create(char *pre, char *in, int n)
{
	ptr s;

	if (n == 1)
	{
		s = (ptr)malloc(sizeof(node));
		s->data = *pre;
		s->lchild = s->rchild = NULL;
		return s;
	}
	char *p;
	for (p = in; p < in + n; p++)
		if (*p == *pre) break;
	int k = p - in;
	s = (ptr)malloc(sizeof(node));
	s->data = *p;
	s->lchild = s->rchild = NULL;
	if (k) s->lchild = Create(pre + 1, in, k);
	if (n - k - 1) s->rchild = Create(pre + k + 1, p + 1, n - k - 1);
	return s;
}
int lastorder(ptr T)
{
	if (!T) return 0;
	lastorder(T->lchild);
	lastorder(T->rchild);
	printf("%c", T->data);
	return 1;
}
int main()
{

	string pre, in;
	while (cin >> pre >> in) {
		int n = pre.length();
		ptr T = Create(&pre[0], &in[0], n);
		lastorder(T);
		cout << endl;
	}

}