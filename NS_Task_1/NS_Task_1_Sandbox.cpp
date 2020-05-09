



#include "NS_Task_1_Sandbox.h"
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <deque>
#define V 24
unsigned char c1, c2, c3;		//stores ADC values
unsigned int n = 0, p, x, q, r, g, b, f, R = 0, G = 0;	// flags
using namespace std;
vector <int> a = {};
int graph[V][V] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,231,0,0},
					   {0,0,0,713,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					   {0,0,0,0,713,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					   {0,713,0,0,0,713,0,0,0,19741,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					   {0,0,713,0,0,0,713,0,0,0,0,19741,0,0,0,0,0,0,0,0,0,0,0,0},
					   {0,0,0,713,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,713,0},
					   {0,0,0,0,713,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,713},
					   {0,0,0,0,0,0,0,0,0,0,0,2333,0,0,0,0,0,0,0,0,1219,0,1219,0},
					   {0,0,0,0,0,0,0,0,0,0,0,0,2333,0,0,0,0,0,0,0,1219,0,0,1219},
					   {0,0,0,19741,0,0,0,0,0,0,0,1086,0,20911,0,0,0,0,0,0,0,0,0,0},
					   {0,0,0,0,19741,0,0,0,0,0,0,0,1086,0,20911,0,0,0,0,0,0,0,0,0},
					   {0,0,0,0,0,0,0,2333,0,1086,0,0,0,0,0,1712,0,0,0,0,0,0,0,0},
					   {0,0,0,0,0,0,0,0,2333,0,1086,0,0,0,0,0,1712,0,0,0,0,0,0,0},
					   {0,0,0,0,0,0,0,0,0,20911,0,0,0,0,0,713,0,0,0,0,0,0,0,0},
					   {0,0,0,0,0,0,0,0,0,0,20911,0,0,0,0,0,713,0,0,0,0,0,0,0},
					   {0,0,0,0,0,0,0,0,0,0,0,1712,0,713,0,0,0,713,0,0,0,0,0,0},
					   {0,0,0,0,0,0,0,0,0,0,0,0,1712,0,713,0,0,0,713,0,0,0,0,0},
					   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,713,0,0,0,713,0,0,0,0},
					   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,713,0,0,713,0,0,0,0},
					   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,713,713,0,3396,0,0,0},
					   {0,0,0,0,0,0,0,1219,1219,0,0,0,0,0,0,0,0,0,0,3396,0,353,0,0},
					   {231,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,353,0,0,0},
					   {0,0,0,0,0,713,0,1219,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4876},
					   {0,0,0,0,0,0,713,0,1219,0,0,0,0,0,0,0,0,0,0,0,0,0,4876,0} };


int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
	{
		if (sptSet[v] == false && dist[v] <= min)
		{
			min = dist[v], min_index = v;
		}
	}
	return min_index;

}


int Path(int parent[], int j)
{
	if (parent[j] == -1)
	{
		return j;
	}

	Path(parent, parent[j]);
	a.push_back(j);
}


void printSolution(int dist[], int parent[], int src, int dest)
{

	int i = dest;
	Path(parent, i);
}


void dijkstra(int src, int dest)
{
	a.push_back(src);
	int dist[V];
	bool sptSet[V];
	int parent[V];
	for (int i = 0; i < V; i++)
	{
		parent[src] = -1;
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}
	dist[src] = 0;
	for (int count = 0; count < V - 1; count++)
	{
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
		{
			if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}

	printSolution(dist, parent, src, dest);

	/*  for (x = 1; x < (a.size() - 1); x++)
	  {
		  _delay_ms(3);
		  //line_follow();
		  printf("\n%d", a[x]);
		  _delay_ms(25);
		  run(a[(x - 1)], a[x], a[(x + 1)]);
		  p = a[x];
		  q = a[x + 1];
	  }
	  a.clear();
	  a.push_back(p);
	*/

}




void left_turn_wls(void)
{
	forward();
	_delay_ms(230);
	//left();
	//_delay_ms(50);
	c1 = ADC_Conversion(1);
	while (!c1)
	{
		left();
		velocity(100, 100);
		c1 = ADC_Conversion(1);
		printf("\nleft  %d", ADC_Conversion(1));
	}
}


void right_turn_wls(void)
{
	forward();
	_delay_ms(230);
	//right();
	//_delay_ms(50);
	c3 = ADC_Conversion(3);
	while (!c3)
	{
		right();
		velocity(100, 100);
		c3 = ADC_Conversion(3);
		printf("\nright  %d", ADC_Conversion(3));
	}
}


/*
*
* Function Name: line_follow
* Input: void
* Output: void
* Logic: follows black line till a node is detected
* Example Call: line_follow(); //follows line
*/


void line_follow(void)
{
	//t = 0;
	//forward();
	_delay_ms(5);
	//d1 = ADC_Conversion(FRONT_IR_ADC_CHANNEL);
	_delay_ms(5);
	c1 = ADC_Conversion(1);
	c2 = ADC_Conversion(2);
	c3 = ADC_Conversion(3);

	while (((c1&&c2&&c3) == 0)/*&&(ADC_Conversion(FRONT_IR_ADC_CHANNEL)>40)*/)
	{
		if (!c1 && c2 && !c3)
		{
			forward();
		}
		else if (!c1 && c2 && c3)
		{
			soft_right();
		}
		else if (c1 && c2 && !c3)
		{
			soft_left();
		}
		else if (!c1 && !c2 && c3)
		{
			soft_right();
		}
		else if (c1 && !c2 && !c3)
		{
			soft_left();
		}
		else if (!c1 && !c2 && !c3)					//All sensors are white i.e. bot is out of line
		{
			stop();
			n = 1;
		}
		//d1 = ADC_Conversion(4);
		_delay_ms(5);
		c1 = ADC_Conversion(1);
		c2 = ADC_Conversion(2);
		c3 = ADC_Conversion(3);

		if (n == 0)
			printf("\n %d  %d  %d ", ADC_Conversion(1), ADC_Conversion(2), ADC_Conversion(3)/*,ADC_Conversion(FRONT_IR_ADC_CHANNEL)*/);
		//_delay_ms(5);
		//t++;
	}
	/*	if (ADC_Conversion(FRONT_IR_ADC_CHANNEL) <= 40)
		{
			printf("/nNo Path Ahead");
			right();
			_delay_ms(2000);
			right_turn_wls();
			line_follow();
		}
		*/

}


void run(int i, int j, int k)
{
	_delay_ms(3);

	if (((i == 5) && (j == 22) && (k == 7)) || ((i == 22) && (j == 7) && (k == 11)) || ((i == 7) && (j == 11) && (k == 9)) || ((i == 11) && (j == 15) && (k == 13)) ||
		(((i - 1) == 1) && ((j - 1) == 3) && ((k - 1) == 5)) || (((i - 1) == 3) && ((j - 1) == 9) && ((k - 1) == 11)) || (((i - 1) == 9) && ((j - 1) == 13) && ((k - 1) == 15)) || (((i - 1) == 11) && ((j - 1) == 15) && ((k - 1) == 17)) ||
		((k == 1) && (j == 3) && (i == 5)) || ((k == 3) && (j == 9) && (i == 11)) || ((k == 9) && (j == 13) && (i == 15)) || ((k == 11) && (j == 15) && (i == 17)) ||
		(((k - 1) == 5) && ((j - 1) == 22) && ((i - 1) == 7)) || (((k - 1) == 22) && ((j - 1) == 7) && ((i - 1) == 11)) || (((k - 1) == 7) && ((j - 1) == 11) && ((i - 1) == 9)) || (((k - 1) == 11) && ((j - 1) == 15) && ((i - 1) == 13)))
	{
		left_turn_wls();
		printf("LEFT");
		line_follow();
	}

	else if (((i == 7) && (j == 20) && (k == 19)) || ((i == 20) && (j == 19) && (k == 17)) || ((i == 21) && (j == 20) && (k == 7)) || ((i == 20) && (j == 8) && (k == 12)) ||
		((k == 8) && (j == 20) && (i == 19)) || ((k == 20) && (j == 19) && (i == 18)) || ((k == 21) && (j == 20) && (i == 8)) || ((k == 20) && (j == 7) && (i == 11)))
	{
		left_turn_wls();
		printf("LEFT");
		line_follow();
	}

	else if (((i == 8) && (j == 20) && (k == 19)) || ((i == 20) && (j == 19) && (k == 18)) || ((i == 21) && (j == 20) && (k == 8)) || ((i == 20) && (j == 7) && (k == 11)) ||
		((k == 7) && (j == 20) && (i == 19)) || ((k == 20) && (j == 19) && (i == 17)) || ((k == 21) && (j == 20) && (i == 7)) || ((k == 20) && (j == 8) && (i == 12)))
	{
		right_turn_wls();
		printf("RIGHT");
		line_follow();
	}

	else if (((i == 1) && (j == 3) && (k == 5)) || ((i == 3) && (j == 9) && (k == 11)) || ((i == 9) && (j == 13) && (k == 15)) || ((i == 11) && (j == 15) && (k == 17)) ||
		(((i - 1) == 5) && ((j - 1) == 22) && ((k - 1) == 7)) || (((i - 1) == 22) && ((j - 1) == 7) && ((k - 1) == 11)) || (((i - 1) == 7) && ((j - 1) == 11) && ((k - 1) == 9)) || (((i - 1) == 11) && ((j - 1) == 15) && ((k - 1) == 13)) ||
		((k == 5) && (j == 22) && (i == 7)) || ((k == 22) && (j == 7) && (i == 11)) || ((k == 7) && (j == 11) && (i == 9)) || ((k == 11) && (j == 15) && (i == 13)) ||
		(((k - 1) == 1) && ((j - 1) == 3) && ((i - 1) == 5)) || (((k - 1) == 3) && ((j - 1) == 9) && ((i - 1) == 11)) || (((k - 1) == 9) && ((j - 1) == 13) && ((i - 1) == 15)) || (((k - 1) == 11) && ((j - 1) == 15) && ((i - 1) == 17)))
	{
		right_turn_wls();
		printf("RIGHT");
		line_follow();
	}

	/*else if (((j == 13) && (k == 15)) || ((j == 15) && (k == 17)) || ((j == 17) && (k == 19)) || ((j == 19) && (k == 18)) || ((j == 18) && (k == 16)) || ((j == 16) && (k == 14)))
	{
		left_turn_wls();
		printf("LEFT");
	}

	else if (((k == 13) && (j == 15)) || ((k == 15) && (j == 17)) || ((k == 17) && (j == 19)) || ((k == 19) && (j == 18)) || ((k == 18) && (j == 16)) || ((k == 16) && (j == 14)))
	{
		right_turn_wls();
		printf("RIGHT");
	}
	*/
	else
	{
		forward();
		_delay_ms(300);
		printf("FORWARD");
		line_follow();
	}
	//pick_place_zone(j, k);
}
void node_logic(int j, int k) {
	if (((j == 13) && (k == 15)) || ((j == 15) && (k == 17)) || ((j == 17) && (k == 19)) || ((j == 19) && (k == 18)) || ((j == 18) && (k == 16)) || ((j == 16) && (k == 14)))
	{
		forward();
		_delay_ms(300);
		right();
		_delay_ms(475);
		//left_turn_wls();
		printf("right");
		stop();
		_delay_ms(100);
	}

	else if(((k == 13) && (j == 15)) || ((k == 15) && (j == 17)) || ((k == 17) && (j == 19)) || ((k == 19) && (j == 18)) || ((k == 18) && (j == 16)) || ((k == 16) && (j == 14)))
	{
		forward();
		_delay_ms(300);
		right();
		_delay_ms(475);
		//right_turn_wls();
		printf("RIGHT");
		stop();
		_delay_ms(100);
	}
	//else if()
	else
	{
		left();
		_delay_ms(950);
	}

}

void colour_sense()
{
	_delay_ms(2);
	filter_red();
	r = color_sensor_pulse_count;
	filter_green();
	g = color_sensor_pulse_count;
	filter_blue();
	b = color_sensor_pulse_count;
	filter_clear();
	f = color_sensor_pulse_count;
	printf("\n%d   %d   %d   %d", r, g, b, f);
	_delay_ms(1000);
	if (r > g&&r > b) {
		printf("red");
	}
	else if (r < g&&g > b) {
		printf("green");
	}
	else if (b > g&&r < b) {
		printf("blue");
	}
}
void Task_1_2(void)
{
	line_follow();
	//_delay_ms(10);
	dijkstra(0, 13);
	//printf("%d", a.size());
	_delay_ms(20);
	//dijkstra(12, 0);
	//printf("%d", a.size());
	for (x = 1; x < (a.size() - 1); x++)
	{
		//_delay_ms(3);
		//line_follow();
		_delay_ms(2);
		printf("\n%d", a[x]);
		run(a[(x - 1)], a[x], a[(x + 1)]);
		_delay_ms(3);
		q = a[x + 1];
	}
	x--;
	node_logic(a[x], a[x + 1]);
	_delay_ms(5);
	colour_sense();
	_delay_ms(5);
	pick();
	a.clear();
	//a.push_back(q);

	if (r > g&&r > b)
	{
		if (R == 0)
			dijkstra(q, 1);
		if (R == 1)
			dijkstra(q, 5);

	}
	else if (r < g&&g > b)
	{
		if (G == 0)
			dijkstra(q, 2);
		if (G == 1)
			dijkstra(q, 6);
	}
	back();
	_delay_ms(300);
	node_logic(a[1], q);
	_delay_ms(2);
	line_follow();
	for (x = 1; x < (a.size() - 1); x++)
	{
		printf("\n%d", a[x]);
	}
	for (x = 1; x < (a.size() - 1); x++)
	{
		//_delay_ms(3);
		//line_follow();
		_delay_ms(2);
		printf("\n%d", a[x]);
		run(a[(x - 1)], a[x], a[(x + 1)]);
		_delay_ms(3);
		q = a[x + 1];
	}
	place();
	stop();
	_delay_ms(500000);

	//int j = a[(a.size() - 1)];
	//int k = a[(a.size())];
	//pick_place_zone(a[(a.size() - 1)], a[(a.size())]);*/
	/*if (((j == 13) && (k == 15)) || ((j == 15) && (k == 17)) || ((j == 17) && (k == 19)) || ((j == 19) && (k == 18)) || ((j == 18) && (k == 16)) || ((j == 16) && (k == 14)))
	{
		left_turn_wls();
	}
	else if (((k == 13) && (j == 15)) || ((k == 15) && (j == 17)) || ((k == 17) && (j == 19)) || ((k == 19) && (j == 18)) || ((k == 18) && (j == 16)) || ((k == 16) && (j == 14)))
	{
		right_turn_wls();
	}

	*/
}
