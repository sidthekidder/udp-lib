#include <stdio.h>
#include <time.h>

int main()
{
	struct timespec t_start, t_end;
	clock_gettime(CLOCK_REALTIME, &t_start);

	long long int sum = 0;
	for(long long int i = 0 ; i < 10000000 ; i++)
	{
		sum += i+32*2;
	}
	clock_gettime(CLOCK_REALTIME, &t_end);
	
	double secs = (double)((t_end.tv_sec + t_end.tv_nsec*1e-9) - (double)(t_start.tv_sec + t_start.tv_nsec*1e-9));
	printf("\nTime taken: %lfs\n", secs);

	return 0;
}