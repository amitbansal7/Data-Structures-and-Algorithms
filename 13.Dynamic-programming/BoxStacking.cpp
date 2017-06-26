/* Amit Bansal - @amitbansal7 */
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
// Box stacking.

struct Box
{
	int l, w, h;
};

bool compare(struct Box a, struct Box b)
{
	return a.l * a.w > b.l * b.w;
}

void CreateAllRoataions(int dimensions[][3], struct Box Boxes[], int n)
{
	int index = 0;

	for (int i = 0; i < n; i++)
		for (int l = 0; l < 3; l++)
			for (int w = 0; w < 3; w++)
				for (int h = 0; h < 3; h++)
				{
					if (h != l && w != l && w != h && dimensions[i][l] > dimensions[i][w])
					{
						Boxes[index].l = dimensions[i][l];
						Boxes[index].w = dimensions[i][w];
						Boxes[index].h = dimensions[i][h];
						index++;
					}
				}

}

int main()
{
	const int n = 2;
	int dimensions[n][3] = {{1, 2, 4}, {3, 2, 5}};
	int t = 3*n;
	//t = Total number of possible boxes.
	struct Box Boxes[t];
	//Create all the combinations of boxes.
	CreateAllRoataions(dimensions, Boxes, 2);
	//Sort them in decreasing order according to l*h
	sort(Boxes, Boxes + t, compare);

	int maxh[t];
	int result[t];

	for(int i=0;i<t;i++)
	{
		maxh[i] = Boxes[i].h;
		result[i] = i;
	}

	for(int i=1;i<t;i++)
		for(int j=0;j<i;j++)
			if(Boxes[i].l < Boxes[j].l && Boxes[i].w < Boxes[j].w)
				if(maxh[i] < maxh[j] + Boxes[i].h)
				{
					maxh[i] = maxh[j] + Boxes[i].h;
					result[i] = j;
				}

	int idx;
	int maxheight = INT_MIN;

	for(int i=0;i<t;i++)
		if(maxheight < maxh[i])
		{
			idx = i;
			maxheight = maxh[i];
		}

	printf("Maximum height is %d\n",maxh[idx]);
	printf("Boxes used are \n");

	while(result[idx]  != idx)
	{
		printf("%d %d %d\n",Boxes[idx].l,Boxes[idx].w,Boxes[idx].h);
		idx = result[idx];
	}
	printf("%d %d %d\n",Boxes[idx].l,Boxes[idx].w,Boxes[idx].h);

}
