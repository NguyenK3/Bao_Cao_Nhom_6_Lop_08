#include <iostream>
using namespace std;
struct Record
{
	int key;
	int data;
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
void QuickSort(Record R[], int N)
{
	int M = 1, l = 1, r = N;
	STACK s;
	s.init();
	s.insertNode(1, N);

	while (!s.isEmpty())
	{
		int i = l, j = r + 1;
		Record P = R[l];

		while (j > i)
		{
			i++;
			while (R[i].key < P.key)
			{
				i++;
			}
			j--;
			while (P.key < R[j].key)
			{
				j--;
			}
			if (j > i)
			{
				swap(R[i], R[j]);
			}
		}
		swap(R[l], R[j]);
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

		if (s.isEmpty()) break;

		Data* top = s.deleteNode();
		l = top->l, r = top->r;
		delete top;
	}
	for (int i = 1; i <= N; i++)
	{
		cout << R[i].key << " ";
	}
}
int main()
{
	//cout << "Nhom 6 Lop 08 DETAI2";
	Record Mang[7];
	Mang[1].key = 10;
	Mang[2].key = 3;
	Mang[3].key = 5;
	Mang[4].key = 2;
	Mang[5].key = 7;
	Mang[6].key = 2;
	QuickSort(Mang, 6);
	return 0;
}