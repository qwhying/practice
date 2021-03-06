// 算法竞赛入门经典第三章练习题3-5.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<iostream>
using namespace std;
#define SPACE ' '
char table[4][4];

int main()
{
	int kongx, kongy;
	char ch;
	for(int i=0;i<5;i++)
		for (int j = 0; j < 6; j++) 
		{
			ch = getchar();
			if (ch == SPACE) 
			{
				kongy = i; kongx = j;
				table[i][j] = ch;
			}
			else if ((ch == '\n')||(j==5))continue;
			else table[i][j] = ch;
		}
	char instruct;
	while ((instruct = getchar()) != '0'); {
		char temp;
		switch (instruct) {
		case 'A':
			if (kongy == 0) {
				cout << "This puzzle has no final configuration" << endl;
				break;
			}
			else {
				temp = table[kongy][kongx];
				table[kongy][kongx] = table[kongy-1][kongx];
				table[kongy-1][kongx] = temp;
				kongy--;
				break;
			}
		case'R':
			if (kongx == 4) {
				cout << "This puzzle has no final configuration" << endl;
				break;
			}
			else {
				temp = table[kongy][kongx];
				table[kongy][kongx] = table[kongy][kongx+1];
				table[kongy][kongx+1] = temp;
				kongx++;
				break;
			}
		case'B':
			if (kongy == 4) {
				cout << "This puzzle has no final configuration" << endl;
				break;
			}
			else {
				temp = table[kongy][kongx];
				table[kongy][kongx] = table[kongy+1][kongx];
				table[kongy+1][kongx] = temp;
				kongy++;
				break;
			}
		case'L':
			if (kongx== 0) {
					cout << "This puzzle has no final configuration" << endl;
					break;
				}
			else {
				temp = table[kongy][kongx];
				table[kongy][kongx] = table[kongy][kongx - 1];
				table[kongy][kongx-1] = temp;
				kongx--;
				break;
			}
		default:
			cout << "This puzzle has no final configuration" << endl;
			break;
		}
	}
	for (int y = 0; y < 5; y++) {
		for (int x= 0;x < 5; x++) {
			cout << table[y][x] << " ";
		}
		cout << "\n";
	}
    return 0;
}

