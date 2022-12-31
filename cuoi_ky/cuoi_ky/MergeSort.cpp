#include <iostream>
using namespace std;
struct Record
{
	int key;
	int data;
};
//thuat toan merge trong slide bai hoc
void MERGE_hopnhat()
{
	int X[100]; int m;
	int Y[100]; int n;
	int Z[200];
	cout << "Nhap m: "; cin >> m;
	cout << "Nhap mang X: ";
	for (int i = 0; i < m; i++) cin >> X[i];
	cout << "Nhap n: "; cin >> n;
	cout << "Nhap mang Y: ";
	for (int i = 0; i < n; i++) cin >> Y[i];
	int i, j, k;
	i = 0; j = 0; k = 0;

	while (i < m && j < n)
	{
		if (X[i] <= Y[j]) {
			Z[k] = X[i];
			i++;
		}
		else {
			Z[k] = Y[j];
			j++;
		}
		k++;
	}
	while (i < m) {
		Z[k] = X[i];
		i++; k++;
	}
	while (j < n) {
		Z[k] = Y[j];
		j++; k++;
	}
	for (int i = 0; i < m+n; i++)
	{
		cout << Z[i] << " ";
	}
	cout << endl;
}

//
void merge(Record A[], int l, int m, int r, int size)
{
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
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = M[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		A[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		A[k] = M[j];
		j++;
		k++;
	}
}

void mergeSort(Record A[], int l, int r, int size) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(A, l, m, size);

		mergeSort(A, m + 1, r, size);

		merge(A, l, m, r, size);
	}
}

void MERGE(Record A[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << A[i].key << " ";
	}
	cout << endl;
	int size = N;
	mergeSort(A, 0, size - 1, size);
	for (int i = 0; i < N; i++)
	{
		cout << A[i].key << " ";
	}
	cout << endl;

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
	//MERGE_hopnhat();
	MERGE(Mang, 7);
	return 0;
}