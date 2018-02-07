#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x, y, t, v[7] = {5, 7, 6, 4, 2, 3, 1};
	for(x = 6; x > 0; x--)
	{
		for(y = 0; y < x; y++)
		{
			if(v[y] > v[y + 1])
			{
				t = v[y];
				v[y] = v[y + 1];
				v[y + 1] = t;
			}
		}
	}
	for(x = 0; x < 7; x++)
	{
		printf("%d", v[x]);
	}
	printf("\n\n\n");
	system("pause");
	return 0;
}