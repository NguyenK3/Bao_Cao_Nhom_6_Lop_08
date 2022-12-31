#include <iostream>
using namespace std;
struct Record
{
	int key;
	int data;
};

void ShellSort(Record A[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << A[i].key << " ";
	}
	cout << endl;
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

	for (s = t - 1; s >= 1; s--)
	{
		h = arrH[s];
		for (j = h; j < N; j++)
		{
			i = j - h;
			K = A[j].key;
			R = A[j];
			while (K < A[i].key && i >= 0)
			{
				A[i + h] = A[i];
				i = i - h;
			}
			A[i + h] = R;
		}
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
	ShellSort(Mang, 7);
	return 0;
}