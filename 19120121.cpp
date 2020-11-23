#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

// Nguyễn Lê Quang
//19120121

void selectionSort(int a[], int n) {
	int min_index = 0;
	for (int i = 0; i < n - 1; i++)
	{
		min_index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min_index])
				min_index = j;
		}
		swap(a[i], a[min_index]);
	}
}

void merge(int a[], int left, int right)
{
	int mid = (left + right) / 2;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* b1 = new int[n1];
	int* b2 = new int[n2];
	for (int i = left; i <= mid; i++)
		b1[i - left] = a[i];
	for (int i = mid + 1; i <= right; i++)
		b2[i - mid - 1] = a[i];

	int k = left;
	int i=0,j = 0;
	while (i < n1 && j < n2) {
		if (b1[i] < b2[j]) {
			a[k] = b1[i];
			i++;
		}
		else {
			a[k] = b2[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		a[k] = b1[i];
		k++; i++;
	}
	while (j < n2)
	{
		a[k] = b2[j];
		j++; k++;
	}
}

void mergeSort(int a[], int left, int right)
{
	int mid = (left + right) / 2;
	if (left < right) {
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, right);
	}
}

int partition(int a[], int left, int right)
{
	int value = a[right];
	int pivot = left - 1;
	for (int i = left; i < right; i++)
	{
		if (a[i] < value) {
			pivot++;
			swap(a[i], a[pivot]);
		}
	}
	pivot++;
	swap(a[right], a[pivot]);
	return pivot;
}

void quickSort(int a[], int left, int right)
{
	if (left < right)
	{
		int pivot = partition(a, left, right);
		quickSort(a, left, pivot - 1);
		quickSort(a, pivot + 1, right);
	}
}

void printArr(int a[], int n) {
	cout << "\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

int thirdMaxValue(int a[], int n)
{
	selectionSort(a, n);
	int maxThird = a[n - 1];
	int len = n - 1;
	int k = 2;
	while (k > 0&&len>0)
	{
		if (a[len] != a[len - 1])
		{
			k--;
			maxThird = a[len - 1];
		}
		len--;
	}
	return maxThird;
}

int countMaxValue(int a[], int n)
{
	quickSort(a, 0, n - 1);
	int count = 1;
	int len = n - 1;
	while (a[len] == a[len - 1]) {
		count++;
		len--;
	}
	return count;
}

void selectionSortABS(int a[], int n)
{
	int min_index = 0;
	for (int i = 0; i < n - 1; i++)
	{
		min_index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (abs(a[j]) < abs(a[min_index]))
				min_index = j;
		}
		swap(a[i], a[min_index]);
	}
}
int main()
{
	int a[] = { 12, 2 ,15, -3, 8, 5, 1, 15,-8, 6, 0, 4, 15 };
	int n = sizeof(a) / sizeof(a[0]);
	int left = 0;
	quickSort(a, left, n - 1);
	//selectionSort(a, n);
	//mergeSort(a, 0, n - 1);
	cout << "\nArray aftet sorted\n";
	printArr(a, n);
	cout << "\nMax third Value is " << thirdMaxValue(a, n)<<"\n";
	cout << "\nNumber of max value is " << countMaxValue(a, n) << "\n";
	cout << "\nArray sorted ABS is \n";
	selectionSortABS(a, n);
	printArr(a, n);

	// các thuật toán sắp xếp theo trị tuyệt đối gần giống như nhau chỉ có điều
	// ta thay đổi điều kiện swap if(a[i]<a[j]) thành if(abs(a[i])<abs(a[j])) thì sẽ được kết quả
}
