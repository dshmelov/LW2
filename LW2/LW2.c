#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define HEADER ("Лабораторная работа №2\nВыполнили: Шмелёв Д.В. и Пантюшов Е.И.")

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void qs(int* items, int left, int right)
{
	int i, j;
	int x, y;

	i = left; j = right;

	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}

void shell(int* items, int count)
{
	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

void shell_minus(int* items, int count)
{
	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x > items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

int compare(const int* a, const int* b) {
	return *a - *b;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	//Задание 1
	/*int** mas_a = NULL;
	int** mas_b = NULL;
	int** mas_c = NULL;
	int razmer, elem_c;
	clock_t start, end; // объявляем переменные для определения времени выполнения
	printf("Ввведите размер матриц:");
	scanf("%d", &razmer);
	start = clock();
	mas_a = (int**)malloc(sizeof(*mas_a) * razmer);
	for (int i = 0; i < razmer; i++)
		mas_a[i] = (int*)malloc(sizeof(**mas_a) * razmer);
	mas_b = (int**)malloc(sizeof(*mas_b) * razmer);
	for (int i = 0; i < razmer; i++)
		mas_b[i] = (int*)malloc(sizeof(**mas_b) * razmer);
	mas_c = (int**)malloc(sizeof(*mas_c) * razmer);
	for (int i = 0; i < razmer; i++)
		mas_c[i] = (int*)malloc(sizeof(**mas_c) * razmer);
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	for (int i = 0; i < razmer; i++)
		for (int j = 0; j < razmer; j++)
			mas_a[i][j] = rand() % 10 * razmer + 1;
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	for (int i = 0; i < razmer; i++)
		for (int j = 0; j < razmer; j++)
			mas_b[i][j] = rand() % 10 * razmer + 1;
	for (int i = 0; i < razmer; i++)
	{
		for (int j = 0; j < razmer; j++)
		{
			elem_c = 0;
			for (int r = 0; r < razmer; r++)
			{
				elem_c = elem_c + mas_a[i][r] * mas_b[r][j];
				mas_c[i][j] = elem_c;
			}
		}
	}
	/*for (int i = 0; i < razmer; i++)
	{
	printf("\n");
	for (int j = 0; j < razmer; j++)
	printf("%d\t", mas_a[i][j]);
	}
	printf("\n\n");
	for (int i = 0; i < razmer; i++)
	{
	printf("\n");
	for (int j = 0; j < razmer; j++)
	printf("%d\t", mas_b[i][j]);
	}
	printf("\n\n");
	for (int i = 0; i < razmer; i++)
	{
	printf("\n");
	for (int j = 0; j < razmer; j++)
	printf("%d\t", mas_c[i][j]);
	}
	end = clock();
	float time = end - start;
	printf("Время выполнения работы программы=%.3f с\n", time / CLOCKS_PER_SEC);*/
	//Задание 2
	clock_t start, end;
	int count;
	printf("Введите размерность массива: ");
	scanf("%d", &count);
	int* items = (int*)malloc(count * sizeof(items));
	for (int i = 0; i < count; i++)
	{
		items[i] = rand() % 100;
	}
	//Пункт 1
	/*start = clock();
	shell(items, count);
	qs(items, 0, count - 1);
	end = clock();
	float res = end - start;
	printf("Время сортировки: %f\n", res / 1000);*/
	//Пункт 2
	/*qs(items, 0, count - 1);
	start = clock();
	shell(items, count);
	qs(items, 0, count - 1);
	end = clock();
	float res = end - start;
	printf("Время сортировки: %f\n", res / 1000);*/
	//Пункт 3
	/*shell_minus(items, count);
	start = clock();
	shell(items, count);
	qs(items, 0, count - 1);
	end = clock();
	float res = end - start;
	printf("Время сортировки: %f\n", res / 1000);*/
	//Пункт 4
	/*qs(items, count / 2, count - 1);
	shell_minus(items, count / 2);
	start = clock();
	shell(items, count);
	qs(items, 0, count - 1);
	end = clock();
	float res = end - start;
	printf("Время сортировки: %f\n", res / 1000);*/
	//Пункт 5
	/*start = clock();
	qsort(items, count, sizeof(int), (int(*)(const void*, const void*))compare);
	end = clock();
	float res = end - start;
	printf("Время сортировки: %f\n", res / 1000);*/
	/*shell(items, count);
	start = clock();
	qsort(items, count, sizeof(int), (int(*)(const void*, const void*))compare);
	end = clock();
	float res = end - start;
	printf("Время сортировки: %f\n", res / 1000);*/
	/*shell_minus(items, count);
	start = clock();
	qsort(items, count, sizeof(int), (int(*)(const void*, const void*))compare);
	end = clock();
	float res = end - start;
	printf("Время сортировки: %f\n", res / 1000);*/
	/*qs(items, count / 2, count - 1);
	shell_minus(items, count / 2);
	start = clock();
	qsort(items, count, sizeof(int), (int(*)(const void*, const void*))compare);
	end = clock();
	float res = end - start;
	printf("Время сортировки: %f\n", res / 1000);*/
	system("PAUSE");
	return 0;
}