#include<stdio.h>
#include<stdlib.h>
#define students 3
#define exams 4

void minimum(int grades[][exams], int pupils, int tests);
void maximum(int grades[][exams], int pupils, int tests);
void average(int grades[][exams], int pupils, int tests);
void printArray(int grades[][exams], int pupils, int tests);
void printMenu(void);

int main()
{
	void(*processGrages[4])(int[][exams], int, int)
		= {printArray,minimum,maximum,average };
	int choice = 0;

	int studentGrades[students][exams] = { {77,68,86,73},
										   {96,87,89,78},
										   {70,90,86,81} };

	while (choice != 4)
	{
		do
		{
			printMenu();
			scanf_s("%d", &choice);
		} while (choice < 0 || choice>4);

		if (choice != 4)
		{
			(*processGrages[choice])(studentGrades, students, exams);
		}
		else
		{
			printf("Project Ended. \n");
		}
	}
	system("pause");
	return 0;
}


void minimum(int grades[][exams], int pupils, int tests)
{
	int i, j;
	int lowGrade = 100;
	for (i = 0; i <= pupils - 1; i++)
	{
		for (j = 0; j <= tests - 1; j++)
		{
			if (grades[i][j] < lowGrade)
			{
				lowGrade = grades[i][j];
			}
		}
	}
	printf("\n\tThe lowest grade is %d\n", lowGrade);
}

void maximum(int grades[][exams], int pupils, int tests)
{
	int i, j;
	int highGrade = 0;
	for (i = 0; i <= pupils - 1; i++)
	{
		for (j = 0; j <= tests - 1; j++)
		{
			if (grades[i][j] > highGrade)
			{
				highGrade = grades[i][j];
			}
		}
	}
	printf("\n\tThe highest grade is %d\n", highGrade);
}

void average(int grades[][exams], int pupils, int tests)
{
	int i, j;
	int total;
	printf("\n");

	for (i = 0; i <= pupils - 1; i++)
	{
		total = 0;
		for (j = 0; j <= tests - 1; j++)
		{
			total += grades[i][j];
		}
		printf("\tThe average grade for student %d is %.1f\n", i + 1, (double)total / tests);
	}
}

void printArray(int grades[][exams], int pupils, int tests)
{
	int i, j;
	printf("\n\t                [0]    [1]    [2]    [3]");
	for(i=0;i<=pupils-1;i++)
	{
		printf("\n\tstudentGrades[%d]", i);
		for (j = 0; j <= tests - 1; j++)
		{
			printf("%-7d", grades[i][j]);
		}
	}
	printf("\n");
}
void printMenu(void)
{
	printf("\n\tEnter a choice:\n"
		"\t 0 Print the array of grades\n"
		"\t 1 Find the minimum grade\n"
		"\t 2 Find the maximum grade\n"
		"\t 3 Print the average on all"
		"tests for each student\n"
		"\t 4 End program\n"
		"\t?");
}
