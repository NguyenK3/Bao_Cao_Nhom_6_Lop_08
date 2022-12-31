#include <iostream>
#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
struct Record
{
    int key;
	int mau;
};
struct Data
{
	int l, r;
	Data* next;
};
void swap(Record& a, Record& b)
{
	Record temp = a;
	a = b;
	b = temp;
}
struct STACK {
	Data* top;

	void init() { top = nullptr; }
	bool isEmpty() { return top == nullptr; }
	bool insertNode(int l, int r) {
		Data* x = new Data();
		x->l = l;
		x->r = r;
		x->next = nullptr;
		if (top == nullptr) {
			top = x;
			return true;
		}
		x->next = top;
		top = x;
		return true;
	}
	Data* deleteNode() {
		if (top == nullptr) return nullptr;

		Data* result = new Data();
		result->l = top->l;
		result->r = top->r;
		result->next = nullptr;

		Data* temp = top->next;
		delete top;
		top = temp;

		return result;
	}
};

// Comparison Counting
void ComparisionCounting(Record M[], int N)
{
	//Nhap
	cout << "Nhap n: "; cin >> N;
	cout << "Nhap Key[]: ";
	for (int i = 0; i < N; i++)
	{
		cin >> M[i].key;
	}
	system("cls");

	//Mo phong
	Sleep(500);
	gotoxy(0, 1); printf("KEY: ");
	Sleep(500);
	for (int i = 0; i < N; i++)
	{
		box((i + 1) * 15, 0, 2, 11, M[i].key, 0, 0);
		Sleep(200);
		/*printf("%d ", M[i].key);*/
	}

	int* COUNT = (int*)malloc(sizeof(int));
	for (int i = 0; i < N; i++)
	{
		COUNT[i] = 0;
	}
	gotoxy(0, 8); printf("COUNT: ");
	Sleep(500);

	for (int k = 0; k < N; k++)
	{
		box((k + 1) * 15, 7, 2, k + 4, COUNT[k], 0, 0);
		Sleep(200);
		/*printf("%d ", COUNT[k]);*/
	}
	for (int i = N - 1; i >= 1; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			box((i + 1) * 15, 0, 2, 11, M[i].key, 1, 1);
			Sleep(200);
			box((j + 1) * 15, 0, 2, 11, M[j].key, 1, 0);
			Sleep(200);
			if (M[i].key <= M[j].key)
			{
				Sleep(500);
				gotoxy(15, 12);
				printf("%d <= %d", M[i].key, M[j].key);
				Sleep(800);
				gotoxy(15, 13);
				printf("COUNT[j] = COUNT[j] + 1");
				Sleep(500);
				COUNT[j]++;
				box((j + 1) * 15, 7, 2, j + 4, COUNT[j], 1, 0);
				Sleep(200);
			}
			else
			{
				Sleep(500);
				gotoxy(15, 12);
				printf("%d >  %d", M[i].key, M[j].key);
				Sleep(500);
				gotoxy(15, 13);
				printf("=> COUNT[i] = COUNT[i] + 1");
				Sleep(700);
				COUNT[i]++;
				box((i + 1) * 15, 7, 2, i + 4, COUNT[i], 1, 1);
				Sleep(500);
			}
			box((i + 1) * 15, 0, 2, 11, M[i].key, 0, 1);
			box((j + 1) * 15, 0, 2, 11, M[j].key, 0, 0);
			box((j + 1) * 15, 7, 2, j + 4, COUNT[j], 0, 0);
			box((i + 1) * 15, 7, 2, i + 4, COUNT[i], 0, 0);
			gotoxy(15, 12);
			printf("                                       ");
			gotoxy(15, 13);
			printf("                                       ");
			Sleep(200);
		}
	}
	Sleep(1000);
	for (int k = 0; k < N; k++)
	{
		box((k + 1) * 15, 7, 2, 4, COUNT[k], 0, 0);
		Sleep(200);
		/*printf("%d ", COUNT[k]);*/
	}

	// di chuyen box
	gotoxy(0, 8); printf("       ");
	Sleep(500);
	for (int k = 0; k < N; k++)
	{
		int i, j;
		for (i = 0; i < 4; i++)
		{
			box((k + 1) * 15, 7 - i, 2, 4, COUNT[k], 0, 0);
			Sleep(100);
			/*printf("%d ", COUNT[k]);*/
		}
		for (j = 0; j < 3; j++)
		{
			box((k + 1) * 15 - j, 7 - i, 2, 4, COUNT[k], 0, 0);
			Sleep(100);
			xoabox((k + 1) * 15 - j, 7 - i, 2, COUNT[k]);
			/*printf("%d ", COUNT[k]);*/
		}
		for (i = 0; i < 4; i++)
		{
			box((k + 1) * 15 - j, 3 - i, 2, 4, COUNT[k], 0, 0);
			Sleep(100);
			/*printf("%d ", COUNT[k]);*/
		}
	}

	int A[100];
	for (int i = 0; i < N; i++)
	{
		A[COUNT[i]] = M[i].key;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (COUNT[j] == i)
			{
				for (int k = 0; k < 3; k++)
				{
					gotoxy(0, 10); printf("KQ: ");
					xoabox((j + 1) * 15, 0, 2, M[j].key);
					xoabox((i + 1) * 15, 9, 2, A[i]);
					Sleep(200);
					box((j + 1) * 15, 0, 2, 8, M[j].key, 0, 0);
					box((i + 1) * 15, 9, 2, 8, A[i], 0, 0);
					Sleep(200);
				}
			}
		}
	}

	Sleep(200);
	gotoxy(0, 10); textcolor(7); printf("KQ: ");
	Sleep(500);
	for (int i = 0; i < N; i++)
	{
		box((i + 1) * 15, 9, 2, 5, A[i], 0, 0);
		Sleep(100);
	}
	Sleep(1000);
	system("cls");
	Sleep(500);
	for (int i = 0; i < N; i++)
	{
		boxCot((i + 3) * 7, 25, 5, A[i], 15, (i + 1) * 25);
		Sleep(100);
		xoaboxCot((i + 3) * 7, 25, 5, A[i]);
		Sleep(100);
	}
	for (int i = 0; i < N; i++)
	{
		boxCot((i + 3) * 7, 25, 5, A[i], 15, (i + 1) * 25);
		Sleep(100);
		xoaboxCot((i + 3) * 7, 25, 5, A[i]);
		Sleep(100);
	}
	for (int i = 0; i < N; i++)
	{
		boxCot((i + 3) * 7, 25, 5, A[i], 15, (i + 1) * 25);
	}
}

// ShellSort
void ShellSort(Record A[], int N)
{
	//Nhap
	cout << "Nhap n: "; cin >> N;
	cout << "Nhap Key[]: ";
	for (int i = 0; i < N; i++)
	{
		cin >> A[i].key;
	}
	for (int i = 0; i < N; i++)
	{
		A[i].mau = (i + 1) * 25;
	}
	system("cls");
	Sleep(500);
	//in ra day ban dau
	for (int i = 0; i < N; i++)
	{
		boxCot((i + 3) * 7, 25, 5, A[i].key, 15, A[i].mau);
	}
	Sleep(500);
	int i, s, j, h, K, t = N - 1;
	int arrH[100];
	Record R;

	for (i = t - 1; i >= 0; i--)
	{
		arrH[i] = i;
	}
	//int dem = 0;i = 1;
	//while (i <= t)
	//{
	//	arrH[dem] = i;
	//	dem++;
	//	i = i * 2;
	//}

	for (s = t -1; s >= 1; s--)
	{
		h = arrH[s];
		gotoxy(100, 27); cout << "h = " << h;
		for (j = h; j < N; j++)
		{
			i = j - h;
			K = A[j].key;
			R = A[j];
			bool flag = false;
			//chon 2 cot can so sanh
			for (int k = 0; k < 2; k++)
			{
				xoaboxCot((i + 3) * 7, 25, 5, A[i].key);
				xoaboxCot((j + 3) * 7, 25, 5, A[j].key);
				Sleep(200);
				boxCot((i + 3) * 7, 25, 5, A[i].key, 15, A[i].mau);
				boxCot((j + 3) * 7, 25, 5, A[j].key, 15, A[j].mau);
				Sleep(200);
			}
			while (K < A[i].key && i >= 0)
			{
				gotoxy(100, 28); cout << "              ";
				flag = true;
				A[i + h] = A[i];
				//thay doi gia tri cot A[i+h]=A[i]
				for (int k = 0; k < 2; k++)
				{
					xoaboxCot((i + h + 3) * 7, 25, 5, A[i+h+h].key);
					Sleep(200);
					boxCot((i + h + 3) * 7, 25, 5, A[i].key, 15, A[i].mau);
					Sleep(200);
				}
				i = i - h;
				gotoxy(100, 28); cout << "i = " << i;
				Sleep(1000);
			}
			A[i + h] = R;
			//gia tri A[i+h] = R (R = A[j] ban dau)
			if (flag) {
				for (int k = 0; k < 2; k++)
				{
					xoaboxCot((i + h + 3) * 7, 25, 5, A[i + h + h].key);
					Sleep(200);
					boxCot((i + h + 3) * 7, 25, 5, R.key, 15, R.mau);
					Sleep(200);
				}
			}
			gotoxy(100, 28); cout << "              ";
		}
		//in ra tat ca cac cot sau khi thay doi
		for (int i = 0; i < N; i++)
		{
			boxCot((i + 3) * 7, 25, 5, A[i].key, 15, A[i].mau);
		}
	}
	for (int i = 0; i < N; i++)
	{
		boxCot((i + 3) * 7, 25, 5, A[i].key, 15, A[i].mau);
	}
}

// SelectionSort
void SelectionSort(Record A[], int N)
{
	// Nhap
	cout << "Nhap n: "; cin >> N;
	cout << "Nhap Key[]: ";
	for (int i = 0; i < N; i++)
	{
		cin >> A[i].key;
	}
	for (int i = 0; i < N; i++)
	{
		A[i].mau = (i + 1) * 25;
	}
	system("cls");
	Sleep(500);
	int i, j;
	Record temp;
	// in ra mang
	for (int i = 0; i < N; i++)
	{
		boxCot((i + 3) * 7, 25, 5, A[i].key, 15, A[i].mau);
		Sleep(100);
	}

	Sleep(500);
	for (j = N - 1; j >= 1; j--)
	{
		int max = A[j].key;
		int vt = j;
		for (i = j-1; i >= 0; i--)
		{
			if (max < A[i].key)
			{
				max = A[i].key;
				vt = i;
			}
		}
		// nhap nhay cot cai gia tri max
		for (int h = 0; h < 3; h++)
		{
			xoaboxCot((vt + 3) * 7, 25, 5, A[vt].key);
			Sleep(200);
			boxCot((vt + 3) * 7, 25, 5, A[vt].key, 15, A[vt].mau);
			Sleep(200);
		}
		// nhap nhay cot max = cot thay the
		for (int h = 0; h < 3; h++)
		{
			xoaboxCot((vt + 3) * 7, 25, 5, A[vt].key);
			Sleep(200);
			boxCot((vt + 3) * 7, 25, 5, A[vt].key, 15, A[vt].mau);
			boxCot((j + 3) * 7, 25, 5, A[j].key, 15, A[j].mau);
			Sleep(200);
			xoaboxCot((vt + 3) * 7, 25, 5, A[vt].key);
			xoaboxCot((j + 3) * 7, 25, 5, A[j].key);
		}

		swap(A[j], A[vt]);
		// doi vi tri
		for (int h = 0; h < 5; h++)
		{
			xoaboxCot((j + 3) * 7, 25, 5, A[j].key);
			xoaboxCot((vt + 3) * 7, 25, 5, A[vt].key);
			Sleep(200);
			boxCot((j + 3) * 7, 25, 5, A[j].key, 15, A[j].mau);
			boxCot((vt + 3) * 7, 25, 5, A[vt].key, 15, A[vt].mau);
			Sleep(200);
		}
	}
	system("cls");
	// in ra day da sap xep

	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i < N; i++)
		{
			boxCot((i + 3) * 7, 25, 5, A[i].key, 15, A[i].mau);
			Sleep(100);
			xoaboxCot((i + 3) * 7, 25, 5, A[i].key);
			Sleep(100);
		}
	}
	for (int i = 0; i < N; i++)
	{
		boxCot((i + 3) * 7, 25, 5, A[i].key, 15, A[i].mau);
	}
}

//Merge
void MERGE_hopnhat()
{
	//Nhap
	int X[100]; int m;
	int Y[100]; int n;
	int Z[200];
	cout << "Nhap m: "; cin >> m;
	cout << "Nhap mang X: ";
	for (int i = 0; i < m; i++) cin >> X[i];
	cout << "Nhap n: "; cin >> n;
	cout << "Nhap mang Y: ";
	for (int i = 0; i < n; i++) cin >> Y[i];
	system("cls"); Sleep(500);
	int i, j, k;
	i = 0; j = 0; k = 0;

	//in ra mang X[]
	gotoxy(0, 1); 
	textcolor(7); cout << "Mang X:";
	Sleep(200);
	textcolor(7);
	for (int i = 0; i < m; i++)
	{
		box((i + 1) * 15, 0, 2, 11, X[i], 0, 1);
		Sleep(200);
	}
	//in ra mang Y[]
	gotoxy(0, 8);
	textcolor(7); cout << "Mang Y:";
	Sleep(200);
	textcolor(7);
	for (int j = 0; j < n; j++)
	{
		box((j + 1) * 15, 7, 2, 11, Y[j], 0, 1);
		Sleep(200);
	}

	while (i < m && j < n)
	{
		//Nhap nhay X[i] va Y[j] de so sanh
		for (int dem = 0; dem < 4; dem++)
		{
			box((i + 1) * 15, 0, 2, 11, X[i], 0, 1);
			box((j + 1) * 15, 7, 2, 11, Y[j], 0, 0);
			Sleep(200);
			xoabox((i + 1) * 15, 0, 2, X[i]);
			xoabox((j + 1) * 15, 7, 2, Y[j]);
			Sleep(200);
		}
		box((i + 1) * 15, 0, 2, 11, X[i], 0, 1);
		box((j + 1) * 15, 7, 2, 11, Y[j], 0, 0);
		if (X[i] <= Y[j]) {
			Z[k] = X[i];
			Sleep(500);
			gotoxy(15, 12); printf("%d <= %d", X[i], Y[j]);Sleep(500);
			gotoxy(15, 13); printf("Z[k] = X[i]");Sleep(500);
			gotoxy(15, 12); printf("                                       ");
			gotoxy(15, 13); printf("                                       ");
			box((i + 1) * 15, 0, 2, 11, X[i], 0, 0);
			box((k + 1) * 15, 16, 2, 11, Z[k], 0, 0);
			//Nhap nhay gia tri X[i] va xuat ra Z[k]
			for (int dem = 0; dem < 4; dem++)
			{
				box((i + 1) * 15, 0, 2, 11, X[i], 0, 0);
				box((k + 1) * 15, 16, 2, 11, Z[k], 0, 0);
				Sleep(200);
				xoabox((i + 1) * 15, 0, 2, X[i]);
				xoabox((k + 1) * 15, 16, 2, Z[k]);
				Sleep(200);
			}
			box((i + 1) * 15, 0, 2, 11, X[i], 1, 1);
			box((k + 1) * 15, 16, 2, 11, Z[k], 1, 1);
			i++;
		}
		else {
			Z[k] = Y[j];
			Sleep(500);
			gotoxy(15, 12); printf("%d > %d", X[i], Y[j]); Sleep(500);
			gotoxy(15, 13); printf("Z[k] = Y[j] "); Sleep(500);
			gotoxy(15, 12); printf("                                       ");
			gotoxy(15, 13); printf("                                       ");
			box((j + 1) * 15, 7, 2, 11, Y[j], 0, 0);
			box((k + 1) * 15, 16, 2, 11, Z[k], 0, 0);
			//Nhap nhay gia tri Y[j] va xuat ra Z[k]
			for (int dem = 0; dem < 4; dem++)
			{
				box((j + 1) * 15, 7, 2, 11, Y[j], 0, 0);
				box((k + 1) * 15, 16, 2, 11, Z[k], 0, 0);
				Sleep(200);
				xoabox((j + 1) * 15, 7, 2, Y[j]);
				xoabox((k + 1) * 15, 16, 2, Z[k]);
				Sleep(200);
			}
			box((j + 1) * 15, 7, 2, 11, Y[j], 1, 0);
			box((k + 1) * 15, 16, 2, 11, Z[k], 1, 0);
			j++;
		}
		k++;
	}
	// Khi da in het mang X hoac mang Y
	// In cac phan tu con lai
	while (i < m) {
		Z[k] = X[i];
		for (int dem = 0; dem < 3; dem++)
		{
			box((i + 1) * 15, 0, 2, 11, X[i], 0, 0);
			box((k + 1) * 15, 16, 2, 11, Z[k], 0, 0);
			Sleep(100);
			xoabox((i + 1) * 15, 0, 2, X[i]);
			xoabox((k + 1) * 15, 16, 2, Z[k]);
			Sleep(100);
		}
		box((i + 1) * 15, 0, 2, 11, X[i], 1, 1);
		box((k + 1) * 15, 16, 2, 11, Z[k], 1, 1);
		i++;
		k++;
	}
	while (j < n) {
		Z[k] = Y[j];
		for (int dem = 0; dem < 3; dem++)
		{
			box((j + 1) * 15, 7, 2, 11, Y[j], 0, 0);
			box((k + 1) * 15, 16, 2, 11, Z[k], 0, 0);
			Sleep(100);
			xoabox((j + 1) * 15, 7, 2, Y[j]);
			xoabox((k + 1) * 15, 16, 2, Z[k]);
			Sleep(100);
		}
		box((j + 1) * 15, 7, 2, 11, Y[j], 1, 0);
		box((k + 1) * 15, 16, 2, 11, Z[k], 1, 0);
		j++;
		k++;
	}
}

//MergeSort
void merge(Record A[], int l, int m, int r, int size)
{
	//nhap nhay left-right
	for (int i = 0; i < 2; i++)
	{
		for (int i = l; i <= r; i++)
		{
			xoaboxCot((i + 3) * 7, 25, 5, A[i].key);
		}
		Sleep(200);
		for (int i = l; i <= m; i++)
		{
			boxCot((i + 3) * 7, 25, 5, A[i].key, 15, 25 * (m + 2));
		}
		for (int i = m+1; i <= r; i++)
		{
			boxCot((i + 3) * 7, 25, 5, A[i].key, 15, 25 * (m + 2));
		}
		Sleep(200);
	}

	int n1 = m - l + 1;
	int n2 = r - m;
	Record L[100], M[100];

	for (int i = 0; i < n1; i++)
		L[i] = A[l + i];

	for (int j = 0; j < n2; j++)
		M[j] = A[m + 1 + j];

	int i, j, k;
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i].key <= M[j].key) {
			// A[k] = L[i]
			xoaboxCot((k + 3) * 7, 25, 5, A[k].key);
			A[k] = L[i];
			boxCot((k + 3) * 7, 25, 5, A[k].key, 15, 25 * (m + 2));
			i++;
		}
		else {
			// A[k] = M[j]
			xoaboxCot((k + 3) * 7, 25, 5, A[k].key);
			A[k] = M[j];
			boxCot((k + 3) * 7, 25, 5, A[k].key, 15, 25 * (m + 2));
			j++;
		}
		k++;
	}
	while (i < n1) {
		xoaboxCot((k + 3) * 7, 25, 5, A[k].key);
		A[k] = L[i];
		boxCot((k + 3) * 7, 25, 5, A[k].key, 15, 25 * (m + 2));
		i++;
		k++;
	}

	while (j < n2) {
		xoaboxCot((k + 3) * 7, 25, 5, A[k].key);

		A[k] = M[j];
		boxCot((k + 3) * 7, 25, 5, A[k].key, 15, 25 * (m + 2));

		j++;
		k++;
	}
	// in  ra sau khi da sap xep
	for (int i = 0; i < 2; i++)
	{
		for (int i = l; i <= r; i++)
		{
			xoaboxCot((i + 3) * 7, 25, 5, A[i].key);
		} Sleep(200);
		for (int i = l; i <= r; i++)
		{
			boxCot((i + 3) * 7, 25, 5, A[i].key, 15, 25 * (m + 2));
		} Sleep(200);
	}
	Sleep(1000);
}
void mergeSort(Record A[], int l, int r, int size) {
	if (l < r) {
		int m = l + (r - l) / 2;
		// chia ra 2 nua nhap nhay voi mau khac nhau
		for (int i = 0; i < 2; i++)
		{
			for (int i = l; i <= m; i++)
			{
				xoaboxCot((i + 3) * 7, 25, 5, A[i].key);
			} Sleep(200);
			for (int i = l; i <= m; i++)
			{
				boxCot((i + 3) * 7, 25, 5, A[i].key, 15, 25 * (m + 2));
			} Sleep(200);
		}
		for (int i = 0; i < 2; i++)
		{
			for (int i = m + 1; i <= r; i++)
			{
				xoaboxCot((i + 3) * 7, 25, 5, A[i].key);
			} Sleep(200);
			for (int i = m + 1; i <= r; i++)
			{
				boxCot((i + 3) * 7, 25, 5, A[i].key, 15, 25 * (r + 4));
			} Sleep(200);
		}
		mergeSort(A, l, m, size);

		mergeSort(A, m + 1, r, size);

		merge(A, l, m, r, size);
	}
}
void MERGE(Record A[], int N)
{
	//Nhap
	cout << "Nhap n: "; cin >> N;
	cout << "Nhap Key[]: ";
	for (int i = 0; i < N; i++)
	{
		cin >> A[i].key;
	}
	for (int i = 0; i < N; i++)
	{
		A[i].mau = (i + 1) * 25;
	}

	int size = N;
	system("cls");
	Sleep(500);
	ShowCur(0);
	//in ra Key[] nhap nhay
	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i <= size - 1; i++)
		{
			boxCot((i + 3) * 7, 25, 5, A[i].key, 15, (i + 2) * 25);
			Sleep(100);
			xoaboxCot((i + 3) * 7, 25, 5, A[i].key);
			Sleep(100);
		}
	}
	for (int i = 0; i < size; i++)
	{
		boxCot((i + 3) * 7, 25, 5, A[i].key, 15, (i + 2) * 25);
	} Sleep(2000);

	//mergeSort
	mergeSort(A, 0, size - 1, size);

	for (int i = 0; i < size; i++)
	{
		xoaboxCot((i + 3) * 7, 25, 5, A[i].key);
	}
	for (int i = 0; i < size; i++)
	{
		boxCot((i + 3) * 7, 25, 5, A[i].key, 15, (i + 2) * 25);
		Sleep(100);
		xoaboxCot((i + 3) * 7, 25, 5, A[i].key);
		Sleep(100);
	}
	for (int i = 0; i < size; i++)
	{
		boxCot((i + 3) * 7, 25, 5, A[i].key, 15, (i + 2) * 25);
	}
}

//QuickSort
bool check(Record R[], int N) {
	for (int i = 2; i <= N; ++i)
		if (R[i - 1].key > R[i].key) return false;
	return true;
}

void QuickSort(Record R[], int N)
{
	//Nhap
	cout << "Nhap n: "; cin >> N;
	cout << "Nhap Key[]: ";
	for (int i = 1; i <= N; i++)
	{
		cin >> R[i].key;
	}
	for (int i = 1; i <= N; i++)
	{
		R[i].mau = (i + 1) * 25;
	}
	system("cls");
	Sleep(500);
	//In ra R[i] ban dau
	for (int i = 1; i <=N; i++)
	{
		boxCot((i + 3) * 7, 25, 5, R[i].key, 15, R[i].mau);
	}
	int M = 1, l = 1, r = N;
	gotoxy(95, 20); cout << "l = " << l << "    ";
	gotoxy(95, 21); cout << "r = " << r << "    ";
	Sleep(200);
	STACK s;
	s.init();
	s.insertNode(1, N);

	int dem = 0;
	while (!s.isEmpty())
	{
		int i = l, j = r + 1;
		gotoxy(95, 25); cout << "i = l = " << i <<"    ";
		gotoxy(95, 26); cout << "j = r+1 = " << j << "    ";
		Sleep(200);
		Record P = R[l];

		while (j > i)
		{
			gotoxy(95, 27); cout << "          "; Sleep(200);
			gotoxy(95, 27); cout << "i < j "; Sleep(500);
			i++;
			gotoxy(95, 25); cout << "                   ";
			gotoxy(95, 26); cout << "                   ";
			Sleep(200);
			gotoxy(95, 25); cout << "i = i+1 = " << i << "    ";
			gotoxy(95, 26); cout << "j = " << j << "    ";
			Sleep(200);
			while (R[i].key < P.key && i <= N)
			{
				gotoxy(95, 28); cout << "R[i].key < P.key";
				Sleep(200);
				i++;
				gotoxy(95, 25); cout << "                   ";
				gotoxy(95, 26); cout << "                   ";
				Sleep(200);
				gotoxy(95, 25); cout << "i = i+1 = " << i << "    ";
				gotoxy(95, 26); cout << "j = " << j << "    ";
				Sleep(200);
				gotoxy(95, 28); cout << "                      "; Sleep(200);
			}

			j--;
			gotoxy(95, 25); cout << "                   ";
			gotoxy(95, 26); cout << "                   "; Sleep(200);
			gotoxy(95, 25); cout << "i = " << i << "    ";
			gotoxy(95, 26); cout << "j = j-1 = " << j << "    ";
			Sleep(200);

			while (P.key < R[j].key)
			{
				gotoxy(95, 28); cout << "P.key < R[j].key";
				Sleep(200);
				j--;
				gotoxy(95, 25); cout << "                   ";
				gotoxy(95, 26); cout << "                   ";
				Sleep(200);
				gotoxy(95, 25); cout << "i = " << i << "    ";
				gotoxy(95, 26); cout << "j = j-1 = " << j << "    ";
				Sleep(200);
				gotoxy(95, 28); cout << "                      "; Sleep(200);
			}

			if (j > i)
			{
				//Nhap nhay R[i], R[j]
				gotoxy(95, 27); cout << "i < j "; Sleep(200);
				gotoxy(95, 15); cout << "         ";
				gotoxy(95, 16); cout << "         ";  Sleep(200);
				gotoxy(95, 15); cout << "i = " << i << "    ";
				gotoxy(95, 16); cout << "j = " << j << "    ";	Sleep(200);
				for (int h = 0; h < 3; h++)
				{

					boxCot((i + 3) * 7, 25, 5, R[i].key, 15, R[i].mau);
					boxCot((j + 3) * 7, 25, 5, R[j].key, 15, R[j].mau);
					Sleep(200);
					xoaboxCot((i + 3) * 7, 25, 5, R[i].key);
					xoaboxCot((j + 3) * 7, 25, 5, R[j].key);
					Sleep(200);
				}
				swap(R[i], R[j]);
				// In ra sau khi hoan doi 
				for (int h = 0; h < 3; h++)
				{
					xoaboxCot((j + 3) * 7, 25, 5, R[j].key);
					xoaboxCot((i + 3) * 7, 25, 5, R[i].key);
					Sleep(200);
					boxCot((j + 3) * 7, 25, 5, R[j].key, 15, R[j].mau);
					boxCot((i + 3) * 7, 25, 5, R[i].key, 15, R[i].mau);
					Sleep(200);
				}
				gotoxy(95, 15); cout << "           ";
				gotoxy(95, 16); cout << "           ";  Sleep(200);
				gotoxy(95, 27); cout << "           ";  Sleep(200);
			}
		}
		gotoxy(95, 27); cout << "          "; Sleep(200);
		gotoxy(95, 27); cout << "i >= j "; Sleep(500);
		gotoxy(95, 25); cout << "                   ";
		gotoxy(95, 26); cout << "                   ";
		Sleep(200);
		gotoxy(95, 25); cout << "i = " << i << "    ";
		gotoxy(95, 26); cout << "j = " << j << "    ";
		Sleep(200);

		//nhap nhay R[l], R[j]
		gotoxy(95, 15); cout << "         ";
		gotoxy(95, 16); cout << "         ";  Sleep(200);
		gotoxy(95, 15); cout << "l = " << l << "    ";
		gotoxy(95, 16); cout << "j = " << j << "    ";	Sleep(200);
		for (int h = 0; h < 3; h++)
		{
			boxCot((l + 3) * 7, 25, 5, R[l].key, 15, R[l].mau);
			boxCot((j + 3) * 7, 25, 5, R[j].key, 15, R[j].mau);
			Sleep(200);
			xoaboxCot((l + 3) * 7, 25, 5, R[l].key);
			xoaboxCot((j + 3) * 7, 25, 5, R[j].key);
			Sleep(200);
		}
		swap(R[l], R[j]);
		// In ra sau khi hoan doi 
		for (int h = 0; h < 3; h++)
		{
			xoaboxCot((j + 3) * 7, 25, 5, R[j].key);
			xoaboxCot((l + 3) * 7, 25, 5, R[l].key);
			Sleep(200);
			boxCot((j + 3) * 7, 25, 5, R[j].key, 15, R[j].mau);
			boxCot((l + 3) * 7, 25, 5, R[l].key, 15, R[l].mau);
			Sleep(200);
		}
		gotoxy(95, 15); cout << "         ";
		gotoxy(95, 16); cout << "         ";  Sleep(100);
		for (int i = 1; i <= N; i++)
		{
			boxCot((i + 3) * 7, 25, 5, R[i].key, 15, R[i].mau);
		}
		//gotoxy(95, 27); cout << "          "; Sleep(1000);

		if (r - j >= j - l && j - l > M) {
			s.insertNode(j + 1, r);
			r = j - 1;
			continue;
		}
		if (j - l > r - j && r - j > M) {
			s.insertNode(l, j - 1);
			l = j + 1;
			continue;
		}
		if (r - j > M && M >= j - l) {
			l = j + 1;
			continue;
		}
		if (j - l > M && M >= r - j) {
			r = j - 1;
			continue;
		}
		gotoxy(95, 20); cout << "l = " << l << "    ";
		gotoxy(95, 21); cout << "r = " << r << "    ";
		gotoxy(95, 25); cout << "i = " << i << "    ";
		gotoxy(95, 26); cout << "j = " << j << "    ";
		Sleep(200);
		if (s.isEmpty()) break;
		Data* top = s.deleteNode();
		l = top->l, r = top->r;
		gotoxy(95, 20); cout << "         ";
		gotoxy(95, 21); cout << "         ";
		gotoxy(95, 20); cout << "l = " << l << "    ";
		gotoxy(95, 21); cout << "r = " << r << "    ";
		Sleep(200);
		delete top;
	}
	system("cls");

	for (int k = 0; k < 2; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			boxCot((i + 3) * 7, 25, 5, R[i].key, 15, R[i].mau);
			Sleep(100);
			xoaboxCot((i + 3) * 7, 25, 5, R[i].key);
			Sleep(100);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		boxCot((i + 3) * 7, 25, 5, R[i].key, 15, R[i].mau);
	}
}

//Menu
void Menu()
{
	int N = 10;
	Record MANG[10];
	int x = 40, y = 12, w = 40, h = 2;
	int t_color = 12, b_color = 3;
	int b_color_sang = 112;//63;// 180;//79;// 135;
	string nd = "";
	int sl = 5;
	gotoxy(15, 4);
	textcolor(15);
	cout << endl << "    	 				    ____             _   _";
	cout << endl << " 	    				   / ___|  ___  _ __| |_(_)_ __   ___";
	cout << endl << " 	 	   			   \\___ \\ / _ \\| '__| __| | '_ \\ / _ \\ ";
	cout << endl << " 	 		   		    ___) | (_) | |  | |_| | | | | (_) |";
	cout << endl << "  				   	   |____/ \\___/|_|   \\__|_|_| |_|\\__, | ";
	cout << endl << "                                                                         |___/";
	Khung_Menu(x, y, w, h, t_color, b_color, nd, sl);
	textcolor(7);
	int xp = x;
	int yp = y;
	int xcu = xp;
	int ycu = yp;
	bool flag = true;
	while (true)
	{
		if (flag == true)
		{
			if ((ycu - y) / 2 == 0) nd = "ComparisonCounting";
			if ((ycu - y) / 2 == 1) nd = "ShellSort";
			if ((ycu - y) / 2 == 2) nd = "QuickSort";
			if ((ycu - y) / 2 == 3) nd = "SelectionSort";
			if ((ycu - y) / 2 == 4) nd = "MergeSort";
			gotoxy(xcu, ycu);
			thanh_sang(xcu, ycu, w, h, b_color, nd);
			xcu = xp; ycu = yp;

			//----------------
			if ((yp - y) / 2 == 0) nd = "ComparisonCounting";
			if ((yp - y) / 2 == 1) nd = "ShellSort";
			if ((yp - y) / 2 == 2) nd = "QuickSort";
			if ((yp - y) / 2 == 3) nd = "SelectionSort";
			if ((yp - y) / 2 == 4) nd = "MergeSort";
			thanh_sang(xp, yp, w, h, b_color_sang, nd);
			flag = false;
		}
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				flag = true;
				c = _getch();
				if (c == 72)
				{
					if (yp != y)
						yp -= 2;
					else
						yp = y + h * (sl - 1);
				}
				else if (c == 80)
				{
					if (yp != y + h * (sl - 1))
						yp += 2;
					else
						yp = y;
				}
			}
			if (c == '\r')//enter
			{
				setcolor(7);
				textcolor(7);
				SetColor(7);
				if ((yp - y) / 2 == 0)
				{
					system("cls");
					ComparisionCounting(MANG, N);
					_getch();
					system("cls");
					Menu();
				}
				if ((yp - y) / 2 == 1)
				{
					system("cls");
					ShellSort(MANG, N);
					_getch();
					system("cls");
					Menu();
				}
				if ((yp - y) / 2 == 2)
				{
					system("cls");
					QuickSort(MANG, N);
					_getch();
					system("cls");
					Menu();
				}
				
				if ((yp - y) / 2 == 3)
				{
					system("cls");
					SelectionSort(MANG, N);
					_getch();
					system("cls");
					Menu();
				}
				if ((yp - y) / 2 == 4)
				{
					system("cls");
					MERGE_hopnhat();
					_getch();
					system("cls");
					MERGE(MANG, N);
					_getch();
					system("cls");
					Menu();
				}
			}
		}

	}
}

//Batdau
void batdau()
{
	ShowCur(0);
	for (int i = 0; i < 15; i++)
	{
		gotoxy(15, 9);
		textcolor(i);
		cout << endl << "    	 				    ____             _   _";
		cout << endl << " 	    				   / ___|  ___  _ __| |_(_)_ __   ___";
		cout << endl << " 	 	   			   \\___ \\ / _ \\| '__| __| | '_ \\ / _ \\ ";
		cout << endl << " 	 		   		    ___) | (_) | |  | |_| | | | | (_) |";
		cout << endl << "  				   	   |____/ \\___/|_|   \\__|_|_| |_|\\__, | ";
		cout << endl << "                                                                         |___/";
		Sleep(150);
	}
	Sleep(300);
	system("cls");
	Sleep(300);
}

int main()
{
	//cout << "Nhom 6 Lop 08 DETAI2";
    char ini[] = "C:\\TURBOC3\\BGI";
    initgraph();

	batdau();
	Menu();
    _getch();
    return 0;
}

