#include <iostream>
using namespace std;
struct Record
{
	int key;
	int data;
};

void ComparisionCounting(Record M[], int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("%d ", M[i].key);
	}
	cout << endl;

	int* COUNT = (int*)malloc(sizeof(int));
	for (int i = 0; i < N; i++)
	{
		COUNT[i] = 0;
	}
	for (int i = N - 1; i >= 1; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (M[i].key <= M[j].key)
			{
				COUNT[j]++;
			}
			else
			{
				COUNT[i]++;
			}
		}
	}

	Record A[100];
	for (int i = 0; i < N; i++)
	{
		A[COUNT[i]].key = M[i].key;
	}
	for (int i = 0; i < N; i++)
	{
		cout << A[i].key <<" ";
	}
}

int main()
{
	//cout << "Nhom 6 Lop 08 DETAI2";
	Record Mang[7];
	Mang[0].key = 1;
	Mang[1].key = 10;
	Mang[2].key = 3;
	Mang[3].key = 5;
	Mang[4].key = 2;
	Mang[5].key = 7;
	Mang[6].key = 2;
	ComparisionCounting(Mang, 7);
	return 0;
}