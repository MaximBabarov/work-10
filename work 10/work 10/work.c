#define _CRT_SECURE_NO_WARNINGS

#define _USE_MATH_DEFINES 

#include <locale.h>

#include <stdio.h>

#include <math.h>

double fa(double x);
double fb(double x);
double arcctg_math(double x);
double arcctg_n(double x, int N);
double arcctg_eps(double x, double eps);
int work3(char sym, int s1, int s2, int s3);
float area(float s1, float s2, float s3);
int print_definition();

int main()
{
	char sym;
	int s1, s2, s3;
	double x;
	int state;
	setlocale(LC_ALL, "RUS");
	state = 1;
	int choice, N;
	choice = 0;
	double eps;
	do
	{
		printf("задание 1\n");
		printf("Введите значение X - ");
		scanf("%lf", &x);
		printf("\n");
		printf("введите что хотите вывести:\n 1 - fa(x)\n 2 - fb(x)\n 3 - Произведение\n 4 - разность квадратов\n 5 - удвоенная сумма\n Выбор:");
		scanf("%d", &choice);
		printf("\n");
		switch (choice)
		{
		case 1:
			printf("fa(x) = %lf", fa(x));
			break;
		case 2:
			printf("fb(x) = %lf", fb(x));
			break;
		case 3:
			printf("Произведение = %lf", fa(x) * fb(x));
			break;
		case 4:
			printf("Разность квадратов = %lf", pow(fa(x), 2) - pow(fb(x), 2));
			break;
		case 5:
			printf("Удвоенная сумма = %lf", (fa(x) + fb(x)) * 2);
			break;
		default:
			printf("Нераспознанная команда");
			break;
		}
		printf("\n");
		printf("желаете повторить задание 1?(1 - да, остальные числа - нет):");
		scanf("%d", &state);
		printf("\n");
	} while (state == 1);
	state = 1;
	do
	{
		printf("задание 2\n");
		printf("Введите X - ");
		scanf("%lf", &x);
		if (fabs(x) > 1)
		{
			printf("модуль X не может быть больше 1");
			return 0;
		}
		printf("\n");
		printf("Введите количество N - ");
		scanf(" %d", &N);
		printf("\n");
		if (N < 1)
		{
			printf("N не может быть меньше 1 так как это число суммируемых");
			return 0;
		}
		printf("Введите точность Эпсилон - ");
		scanf(" %lf", &eps);
		printf("\n");
		if (eps <= 0)
		{
			printf("Точность не может быть нулевой или меньше");
			return 0;
		}
		int choice_func;
		printf("Введите, какую функциб хотите вывести: \n1) Стандартная функция\n2) Ряд (число членов N)\n3) Ряд (точность eps)\n");
		printf("Выбор: ");
		scanf("%d", &choice_func);
		switch (choice_func)
		{
		case 1:
			printf("Результаты вычислений\n");
			printf("Стандартная функция:       %.15f\n", arcctg_math(x));
			break;
		case 2:
			printf("Результаты вычислений\n");
			printf("|&3c|%20s|%25s|\n", "N", "Arcctg_N", "Отклонение");
			for (int i = 1; i < N + 1; i++)
			{
				printf("|%3d|%20.15f|%30e|\n", N, arcctg_n(x, N), fabs(arcctg_math(x) - arcctg_n(x, N)));
			}
			break;
		case 3:
			printf("Ряд (точность eps = %e): %.15f (Отклонение: %e)\n", eps, arcctg_eps(x, eps), fabs(arcctg_n(x, N) - arcctg_eps(x, eps)));
			break;
		}
		printf("желаете повторить задание 2?(1 - да, остальные числа - нет):");
		scanf("%d", &state);
		printf("\n");
	} while (state == 1);
	state = 1;
	do
	{
		printf("задание 3\n");
		printf("Введите первую сторону - ");
		scanf(" %d", &s1);
		printf("\n");
		printf("Введите вторую сторону - ");
		scanf(" %d", &s2);
		printf("\n");
		printf("Введите третью сторону - ");
		scanf(" %d", &s3);
		printf("\n");
		printf("Введите каким символом нарисовать - ");
		scanf(" %c", &sym);
		printf("\n");
		printf("что вы хотите узнать?\n1)Нарисовать фигуру\n2)найти площадь фигуры\n3)Узнать определение фигуры\n");
		scanf(" %d", &choice);
		switch (choice)
		{
		case 1:
			work3(sym,s1,s2,s3);
			break;
		case 2:
			printf("Площадь фигуры равна %f", area((float)s1, (float)s2, (float)s3));
			break;
		case 3:
			print_definition();
			break;
		}
		printf("\n");
		printf("желаете повторить задание 3?(1 - да, остальные числа - нет):");
		scanf("%d", &state);
	} while (state == 1);
	return 0;
}

double fa(double x)
{
	double y;
	if (x <= 3)
	{
		y = pow(x, 2) - 3 * x + 9;
	}
	else
	{
		y = 1.0 / (pow(x, 3) + 3);
	}
	return y;
}
double fb(double x)
{
	double y;
	y = x * exp(sin(pow(x, 2)));
	return y;
}
double arcctg_math(double x) 
{
	return (M_PI / 2.0) - atan(x);
}
double arcctg_n(double x, int N) {
	double sum = M_PI / 2.0;
	double term = -x;
	sum += term;
	for (int n = 1; n < N; n++) {
		term *= (-x * x * (2 * n - 1)) / (2 * n + 1);
		sum += term;
	}
	return sum;
}
double arcctg_eps(double x, double eps) {
	double sum = M_PI / 2.0;
	double term = -x;
	sum += term;
	int n = 1;
	while (fabs(term) > eps) {
		term *= (-x * x * (2 * n - 1)) / (2 * n + 1);
		sum += term;
		n++;
	}
	return sum;
}
int work3(char sym, int s1, int s2, int s3)
{
	printf("\n");
	int total_width = s1 + s3;
	int total_height = s1 + s3;
	for (int y = 0; y < total_height; y++)
	{
		for (int x = 0; x < total_width; x++)
		{
			int in_square1 = (x < s1 && y < s1);
			int in_square2 = (x >= (s1 - s2) && x < total_width && y >= (s1 - s2) && y < total_height);
			int in_intersection = (x >= (s1 - s2) && x < s1 && y >= (s1 - s2) && y < s1);
			if ((in_square1 || in_square2) && !in_intersection)
			{
				printf("%c", sym);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
float area(float s1, float s2, float s3) {
	float a1 = s1 * s1;
	float a2 = s2 * s2;
	float s_overlap = s3 * s3;
	return a1 + a2 - s_overlap;
}
int print_definition() {
	printf("Определение фигуры\n");
	printf("Геометрическая фигура представляет собой два квадрата с пересечением посередине.\n");
	printf("Область их пересечения и пустое пространство незакрашены.\n");
	return 0;
}