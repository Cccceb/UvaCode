#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("ϰ��3-5in.txt", "r", stdin);
FILE *fout = freopen("ϰ��3-5out.txt", "w", stdout);
#endif 
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char puzzle[10][10];

void printPuzzle()
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 4; ++j)
			cout << puzzle[i][j] << ' ';
		cout << puzzle[i][4] << endl;
	}
}

int main()
{
	int kase = 0;
	while (fgets(puzzle[0], 7, stdin)) //����7-1=6���ַ�����ÿ�е�5���ַ��ӻ���
	{
		if (puzzle[0][0] == 'Z') break;
		for (int i = 1; i < 5; ++i)
			fgets(puzzle[i], 7, stdin);
		//cout << "Read Finished" << endl;
		//printPuzzle(); //���Զ������
		int ei = 0, ej = 0; //�ҳ��յ��Ǹ�����
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j)
				if (puzzle[i][j] == ' ')
				{
					ei = i, ej = j;
					break;
				}
		bool valid = true; //��־�Ƿ�ָ����ֹ�
		char moves[101];
		int cnt = 0;
		char c;
		while (cin >> c && c != '0') //���Ǹ��ж���
			moves[cnt++] = c;
		int ni = ei, nj = ej;
		for (int i = 0; i < cnt; ++i)
		{
			switch (moves[i])
			{
			case 'A': ni = ei - 1; nj = ej; break;
			case 'B': ni = ei + 1; nj = ej; break;
			case 'L': nj = ej - 1; ni = ei; break;
			case 'R': nj = ej + 1; ni = ei; break;
			default: break;
			}
			//�Ƿ����:
			if (ni < 0 || ni > 4 || nj < 0 || nj > 4)
			{
				valid = false;
				break;
			}
			else
			{
				swap(puzzle[ei][ej], puzzle[ni][nj]);
				ei = ni, ej = nj; //���¿ո�λ��
			}
		}
		getchar(); //�ǳ���Ҫ���̵�ָ�������0����Ļس���
		if (kase++) cout << endl; //���׸�����ǰ�������
		cout << "Puzzle #" << kase << ":\n";
		if (valid == false)
			cout << "This puzzle has no final configuration." << endl;
		else
			printPuzzle();
	}
	return 0;
}
