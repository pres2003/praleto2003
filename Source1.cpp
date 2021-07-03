#include "Header.h"
void randomgen(int A[])
{
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		A[i] = 100 + rand() % (999 - 100 + 1);
	}
}
void quicksort(int a[], int low, int high)
{
	int middle;
	if (low >= high) return;
	middle = split(a, low, high);
	quicksort(a, low, middle - 1);
	quicksort(a, middle + 1, high);
}
int split(int a[], int low, int high)
{
	int part_element = a[low];
	for (;;)
	{
		while (low < high && part_element <= a[high])
			high--;
		if (low >= high) break;
		a[low++] = a[high];
		while (low < high && a[low] <= part_element)
			low++;
		if (low >= high)break;
		a[high--] = a[low];
	}
	a[high] = part_element;
	return high;
}
int proxod(int A[], int AA[])
{
	int r, t, y, u;
	r = 0;
	t = 100;
	y = 0;
	u = 0;
	while (r < N)
	{
		/*
		Если текущий элемент массива не равен t а также это не 0-й элемент массива,
		или текущий элемент массива не равен t а также предыдущий элемент тоже не ровнялся текущему t,
		тогда мы заносим текущее значение t в массив АА, увеличуем t на 1 а также количство элементов
		массива АА, которые нужно вывести увеличилось на 1. Выполняется снова проверка условия цикла
		*/
		if ((A[r] != t && r == 0) || (A[r] != t && A[r - 1] != t))
		{
			AA[y] = t;
			t++;
			y++;
			u++;
			continue;
		}
		// Если текущий элемент массива А равен t, переходим к следующему элементу массива, иначе увеличиваем t на 1
		if (A[r] == t)
			r++;
		else
			t++;
		if (r == N && t < 999)
		{
			while (t < 999)
			{
				t++;
				AA[y] = t;
				y++;
				u++;
			}
		}

	}
	return y;
}