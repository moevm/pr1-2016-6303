#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 1000

int compare(const void* arg_1, const void* arg_2);

int main() {
	int exist = 0;
	int low = 0;
	int high = ARR_SIZE-1;
	int count;
	int nums[ARR_SIZE];
	for (int i = 0; i<ARR_SIZE; i++)
	{
		scanf("%d", &nums[i]);
	}
	qsort(nums, ARR_SIZE, sizeof(int), compare);

	time_t time_start = time(NULL);

	while (low != high)
	{
		count = (low + high) / 2;
		if (nums[count] > 0)
		{
			high = count;
			continue;
		}
		if (nums[count] < 0)
		{
			low = count;
			continue;
		}
		if (nums[count] == 0)
		{
			exist = 1;
			break;
		}
	}

	time_t time_finish = time(NULL);

	if (exist == 1)
		printf("exists\n");
	else
		printf("doesn't exist\n");
	exist = 0;

	printf("%f\n", difftime(time_finish, time_start));

	time_start = time(NULL);

	for (count = 0; count<ARR_SIZE; count++)
	{
		if (nums[count] == 0)
		{
			exist = 1;
			break;
		}
	}

	time_finish = time(NULL);

	if (exist == 1)
		printf("exists\n");
	else
		printf("doesn't exist\n");
 
 	printf("%f\n", difftime(time_finish, time_start));
 	return 0;
 }
 
 int compare(const void* arg_1, const void* arg_2)
 {
 	return (*(int*)arg_1 - *(int*)arg_2);
 }
