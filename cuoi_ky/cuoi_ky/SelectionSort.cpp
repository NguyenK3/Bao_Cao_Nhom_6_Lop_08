#include <iostream>
using namespace std;
struct Record
{
	int key;
	int data;
};

void SelectionSort(Record A[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << A[i].key << " ";
	}
	cout << endl;
	int i, j;
	Record temp;

	for (j = N - 1; j >= 1; j--)
	{
		int max = A[j].key;
		int vt = j;
		for (i = j - 1; i >= 0; i--)
		{
			if (max < A[i].key)
			{
				max = A[i].key;
				vt = i;
			}
		}
		swap(A[j], A[vt]);
	}
	for (int i = 0; i < N; i++)
	{
		cout << A[i].key << " ";
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
	SelectionSort(Mang, 7);
	return 0;
}