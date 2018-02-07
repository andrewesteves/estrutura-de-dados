#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x, y, t, v[7] = {5, 7, 6, 4, 2, 3, 1};
	for(x = 0; x < 6; x++)
	{
		for(y = x + 1; y < 7; y++)
		{
			if(v[y] < v[x])
			{
				t = v[x];
				v[x] = v[y];
				v[y] = t;
			}
		}
	}
	for(x = 0; x < 7; x++)
		printf("%i", v[x]);
	printf("\n\n");
	system("pause");
	return 0;
}