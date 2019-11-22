#include<stdio.h>
#include<stdlib.h>
#define issues 5
#define ratings 10

void recordResponse(int i,int response);
void highestRatings();
void lowestRatings();
float averageRating(int issue);
void displayResults();
int responses[issues][ratings];
const char *topics[issues] = { "Global Warming","The Economy","War","Health Care","Education" };
int main(void)
{
	int response;
	int i;
	do
	{
		printf("Please rate the following topics on a scale from 1 - 10\n 1=least important ,10=most important\n");

		for (i = 0; i < issues; i++)
		{
			do
			{
				printf("%s", topics[i]);
				printf("?");
				scanf_s("%d", &response);
			} while (response < 1 || response>10);
			recordResponse(i, response);
		}
		printf("Enter 1 to stop. Enter 0 to rate the issues again.");
		scanf_s("%d", &response);
	} while (response != 1);
	displayResults();

	system("pause");
	return 0;
}


void recordResponse(int issue, int rating)
{
	responses[issue][rating - 1]++;
}


void highestRatings(void)
{
	int hr = 0;
	int ht = 0;
	int i, j;

	for (i = 0; i < issues; i++)
	{
		int tr = 0;
		for (j = 0; j < ratings; j++)
		{
			tr += responses[i][j] * (j + 1);
		}
		if (hr < tr)
		{
			hr = tr;
			ht = i;
		}
	}
	printf("The highest rated topic was ");
	printf("%s", topics[ht]);
	printf("with a total rating of %d\n", hr);
}

void lowestRatings(void)
{
	int lr = 0;
	int lt = 0;
	int i, j;

	for (i = 0; i < issues; i++)
	{
		int tr = 0;
		for (j = 0; j < ratings; j++)
		{
			tr += responses[i][j] * (j + 1);
		}
		if (i==0)
		{
			lr = tr;
		}
		if (lr > tr)
		{
			lr = tr;
			lr = i;
		}
	}
	printf("The lowest rated topic was ");
	printf("%s", topics[lt]);
	printf(" with a total rating of %d\n", lr);
}

float averageRating(int issue)
{
	float total = 0;
	int counter = 0;
	int j;

	for (j = 0; j < ratings; j++)
	{
		if (responses[issue][j] != 0)
		{
			total += responses[issue][j] * (j + 1);
			counter += responses[issue][j];
		}
		
	}
	return total/counter;
}

void displayResults()
{
	int i, j;
	printf("%20s", "Topic");

	for (i = 1; i <= ratings; i++)
	{
		printf("%4d", i);
	}
	printf("%20s\n", "Average Rating");
	for (i = 0; i < issues; i++)
	{
		printf("%20s",topics[i]);
		for (j = 0; j < ratings; j++)
		{
			printf("%4d", responses[i][j]);
		}
		printf("%20.2f\n", averageRating(i));
	}
	highestRatings();
	lowestRatings();
}