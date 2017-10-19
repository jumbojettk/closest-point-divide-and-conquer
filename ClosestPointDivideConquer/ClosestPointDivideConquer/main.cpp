// Napon Krassner (Jett)
// CSC 3430
// HW 5
// Description: Compares the performance of the brute-force algorithm and the DivideConquer
//				algorithm for determining the closest Two Points in a 2D plain for an array
//				of unique points [x,y] with integer coordinates within the plane.
// Note: This solution follows the geeksforgeeks.org/closest-pair-of-points/ guidelines.

#include <time.h>
#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

// Structure to represent a Point in 2D plane
struct Point
{
	int x, y;
};


// Global variables
int CALC_COUNT;
Point P1 = { 0, 0 };
int P1_NUM = 0;
Point P2 = { 0,0 };
int P2_NUM = 0;;
Point P3 = { 0,0 };
int P3_NUM = 0;
Point P4 = { 0,0 };
int P4_NUM = 0;
int ORIG_MID = 0;



// Function Declaration
void initpoints(Point[], int, int, int);
int compareX(const void*, const void*);
int compareY(const void*, const void*);
float dist(Point, Point);
float bruteForce(Point[], int);
float min(float, float);
float stripClosest(Point[], int, float);
float closestUtil(Point[], int);
float closest(Point[], int);
void printFormattedOutPut(Point[], int, float, Point, Point, int, int, int);
int findPointIndex(Point[], int, Point);


// Main Program
int main()
{
	// Print header
	printf("----------Closest Points in a plane analysis: Napon Krassner (Jett)--------------\n");

	int go = 1;		// for the sake of scoping to keep testing simple
	if (go == 1)
	{
		//**************************************** TEST 1 ****************************************
		//******** Proccessing Brute Force ********
		// Print Points
		Point P[] = { { 2, 3 },{ 12, 30 },{ 40, 50 },{ 5, 1 },{ 12, 10 },{ 3, 4 } };

		int n = sizeof(P) / sizeof(P[0]);
		printf("Points[%i]\n", n);

		printf("[ %i, %i] ", P[0].x, P[0].y);
		for (int i = 1; i < n; i++)
		{
			// print the x and the y
			int x = P[i].x;
			int y = P[i].y;

			printf(",[ %i, %i]", x, y);
		}

		// Print result
		printf("\n\nBrute Force\n");
		CALC_COUNT = 0;
		float closestDistBF = bruteForce(P, n);
		printFormattedOutPut(P, n, closestDistBF, P1, P2, P1_NUM, P2_NUM, CALC_COUNT);


		//******** Processing Divide and Conquer ********
		// Original array, used to look for the original index
		Point unsortedP[] = { { 2, 3 },{ 12, 30 },{ 40, 50 },{ 5, 1 },{ 12, 10 },{ 3, 4 } };
		printf("\nDivide and Conquer\n");
		CALC_COUNT = 0;
		float closestDistDC = closest(P, n);

		// Print result
		P1_NUM = findPointIndex(unsortedP, n, P1);		// look for index
		P2_NUM = findPointIndex(unsortedP, n, P2);
		printFormattedOutPut(P, n, closestDistDC, P1, P2, P1_NUM, P2_NUM, CALC_COUNT);
		printf("\n--------------------------------------------------------------------------------\n");
		//**************************************** END TEST 1 ****************************************
	}

	if (go == 1)
	{
		//**************************************** TEST 2 ****************************************
		//******** Proccessing Brute Force ********
		// Print Points
		Point P[] = { { 1, 1 },{ 2, 5 },{ 15, 1 },{ 16, 1 },{ 36, 4 },{ 39, 1 } };

		int n = sizeof(P) / sizeof(P[0]);
		printf("Points[%i]\n", n);

		printf("[ %i, %i] ", P[0].x, P[0].y);
		for (int i = 1; i < n; i++)
		{
			// print the x and the y
			int x = P[i].x;
			int y = P[i].y;

			printf(",[ %i, %i]", x, y);
		}

		// Print result
		printf("\n\nBrute Force\n");
		CALC_COUNT = 0;
		float closestDistBF = bruteForce(P, n);
		printFormattedOutPut(P, n, closestDistBF, P1, P2, P1_NUM, P2_NUM, CALC_COUNT);


		//******** Processing Divide and Conquer ********
		// Original array, used to look for the original index
		Point unsortedP[] = { { 1, 1 },{ 2, 5 },{ 15, 1 },{ 16, 1 },{ 36, 4 },{ 39, 1 } };
		printf("\nDivide and Conquer\n");
		CALC_COUNT = 0;
		float closestDistDC = closest(P, n);

		// Print result
		P1_NUM = findPointIndex(unsortedP, n, P1);		// look for index
		P2_NUM = findPointIndex(unsortedP, n, P2);
		printFormattedOutPut(P, n, closestDistDC, P1, P2, P1_NUM, P2_NUM, CALC_COUNT);
		printf("\n--------------------------------------------------------------------------------\n");
		//**************************************** END TEST 2 ****************************************
	}
	
	if (go == 1)
	{
		//**************************************** TEST 3 ****************************************
		//******** Proccessing Brute Force ********
		// Print Points
		Point P[] = { { 1, 1 },{ 2, 5 },{ 15, 1 },{ 23, 1 },{ 36, 4 },{ 39, 1 } };

		int n = sizeof(P) / sizeof(P[0]);
		printf("Points[%i]\n", n);

		printf("[ %i, %i] ", P[0].x, P[0].y);
		for (int i = 1; i < n; i++)
		{
			// print the x and the y
			int x = P[i].x;
			int y = P[i].y;

			printf(",[ %i, %i]", x, y);
		}

		// Print result
		printf("\n\nBrute Force\n");
		CALC_COUNT = 0;
		float closestDistBF = bruteForce(P, n);
		printFormattedOutPut(P, n, closestDistBF, P1, P2, P1_NUM, P2_NUM, CALC_COUNT);


		//******** Processing Divide and Conquer ********
		// Original array, used to look for the original index
		Point unsortedP[] = { { 1, 1 },{ 2, 5 },{ 15, 1 },{ 23, 1 },{ 36, 4 },{ 39, 1 } };
		printf("\nDivide and Conquer\n");
		CALC_COUNT = 0;
		float closestDistDC = closest(P, n);

		// Print result
		P1_NUM = findPointIndex(unsortedP, n, P1);		// look for index
		P2_NUM = findPointIndex(unsortedP, n, P2);
		printFormattedOutPut(P, n, closestDistDC, P1, P2, P1_NUM, P2_NUM, CALC_COUNT);
		printf("\n--------------------------------------------------------------------------------\n");
		//**************************************** END TEST 3 ****************************************
	}

	if (go == 1)
	{
		//**************************************** TEST 4 ****************************************
		//******** Proccessing Brute Force ********
		// Print Points
		Point P[] = { {1, 1},{2, 24},{15, 1},{23, 1},{36, 4},{39, 1} };

		int n = sizeof(P) / sizeof(P[0]);
		printf("Points[%i]\n", n);

		printf("[ %i, %i] ", P[0].x, P[0].y);
		for (int i = 1; i < n; i++)
		{
			// print the x and the y
			int x = P[i].x;
			int y = P[i].y;

			printf(",[ %i, %i]", x, y);
		}

		// Print result
		printf("\n\nBrute Force\n");
		CALC_COUNT = 0;
		float closestDistBF = bruteForce(P, n);
		printFormattedOutPut(P, n, closestDistBF, P1, P2, P1_NUM, P2_NUM, CALC_COUNT);


		//******** Processing Divide and Conquer ********
		// Original array, used to look for the original index
		Point unsortedP[] = { { 1, 1 },{ 2, 24 },{ 15, 1 },{ 23, 1 },{ 36, 4 },{ 39, 1 } };
		printf("\nDivide and Conquer\n");
		CALC_COUNT = 0;
		float closestDistDC = closest(P, n);

		// Print result
		P1_NUM = findPointIndex(unsortedP, n, P1);		// look for index
		P2_NUM = findPointIndex(unsortedP, n, P2);
		printFormattedOutPut(P, n, closestDistDC, P1, P2, P1_NUM, P2_NUM, CALC_COUNT);
		printf("\n--------------------------------------------------------------------------------\n");
		//**************************************** END TEST 4 ****************************************

	}

	

	if (go == 1)
	{
		//**************************************** TEST 5 ****************************************
		//******** Proccessing Brute Force ********
		// Generate points and initialize into array
		Point P[100];
		initpoints(P, 100, 1000, 0);

		int n = sizeof(P) / sizeof(P[0]);
		printf("Points[%i]\n", n);

		printf("[ %i, %i] ", P[0].x, P[0].y);
		for (int i = 1; i < n; i++)
		{
			// print the x and the y
			int x = P[i].x;
			int y = P[i].y;

			printf(",[ %i, %i]", x, y);
		}

		// Print result
		printf("\n\nBrute Force\n");
		CALC_COUNT = 0;
		float closestDistBF = bruteForce(P, n);
		printFormattedOutPut(P, n, closestDistBF, P1, P2, P1_NUM, P2_NUM, CALC_COUNT);


		//******** Processing Divide and Conquer ********
		// Original array, used to look for the original index
		Point unsortedP[100];
		std::copy(P, P + n, unsortedP);
		printf("\nDivide and Conquer\n");
		CALC_COUNT = 0;
		float closestDistDC = closest(P, n);

		// Print result
		P1_NUM = findPointIndex(unsortedP, n, P1);		// look for index
		P2_NUM = findPointIndex(unsortedP, n, P2);
		printFormattedOutPut(P, n, closestDistDC, P1, P2, P1_NUM, P2_NUM, CALC_COUNT);
		printf("\n--------------------------------------------------------------------------------\n");
		//**************************************** END TEST 5 ****************************************

	}



	if (go == 1)
	{
		//**************************************** TEST 6 ****************************************
		//******** Proccessing Brute Force ********
		// Generate points and initialize into array
		Point P[1000];
		initpoints(P, 1000, 10000, 0);

		int n = sizeof(P) / sizeof(P[0]);
		printf("Points[%i]\n", n);

		printf("[ %i, %i] ", P[0].x, P[0].y);
		for (int i = 1; i < n; i++)
		{
			// print the x and the y
			int x = P[i].x;
			int y = P[i].y;

			printf(",[ %i, %i]", x, y);
		}

		// Print result
		printf("\n\nBrute Force\n");
		CALC_COUNT = 0;
		float closestDistBF = bruteForce(P, n);
		printFormattedOutPut(P, n, closestDistBF, P1, P2, P1_NUM, P2_NUM, CALC_COUNT);


		//******** Processing Divide and Conquer ********
		// Original array, used to look for the original index
		Point unsortedP[1000];
		std::copy(P, P + n, unsortedP);
		printf("\nDivide and Conquer\n");
		CALC_COUNT = 0;
		float closestDistDC = closest(P, n);

		// Print result
		P1_NUM = findPointIndex(unsortedP, n, P1);		// look for index
		P2_NUM = findPointIndex(unsortedP, n, P2);
		printFormattedOutPut(P, n, closestDistDC, P1, P2, P1_NUM, P2_NUM, CALC_COUNT);
		printf("\n--------------------------------------------------------------------------------\n");
		//**************************************** END TEST 6 ****************************************

	}

	return 0;
}

// Utility Functions

// Parameters:	Point array - to initialize
//				int - size of array
//				int - range to create random points in
// Return:	nothing
// Description:	initialize a large array with random unique points
void initpoints(Point P[], int n, int range, int seed = -1)
{
	if (seed < 0)
		seed = clock();
	
	srand(seed);

	// Fill array with unique points for i from 0 to n-1
	int i = 0;
	int j;

	// while i is less than the size of array
	while (i < n)
	{
		// Create random point within range
		Point p;
		p.x = rand() % range;
		p.y = rand() % range;

		// check if repeating point
		for (j = 0; j < i; ++j)
		{
			if (P[j].x == p.x && P[j].y == p.y)
				break;		// point exists
		}

		// Unique point so save it
		if (j >= i)
		{
			P[i] = p;
			i++;			// increment to next point
		}
	}
}


// Parameters:	const void* - array of points
//				const void* - another array of points
// Return:	int - 
// Description:	this function is needed for library function qsort()
//				to sort array of points according to X coordinate
int compareX(const void* a, const void* b)
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->x - p2->x);
}


// Parameters:	const void* - array of points
//				const void* - another array of points
// Return:	int -
// Description: this function is needed for library function qsort()
//				to sort array of points according to y coordinate
int compareY(const void* a, const void* b)
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->y - p2->y);
}


// Parameters:	Point - point 1
//				Point - point 2
// Return:	float - distance
// Description: finds distance between two points (with added float conversion)
float dist(Point p1, Point p2)
{
	// cont calculation each time it is executed
	CALC_COUNT++;	// global var
	return sqrt((float(p1.x) - float(p2.x)) * (float(p1.x) - float(p2.x)) +
				(float(p1.y) - float(p2.y)) * (float(p1.y) - float(p2.y)));
}


// Parameters:	Point[] - array of points
//				int - size of array
// Return:	float - smallest distance between the two points
// Description: brute force method to return smallest distance between two points
float bruteForce(Point P[], int n)
{
	float min = FLT_MAX;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			float minTemp = dist(P[i], P[j]);
			if (minTemp < min)
			{
					min = minTemp;
					P1 = P[i];
					P1_NUM = i;
					P2 = P[j];
					P2_NUM = j;
			}
		}
	}
	return min;
}


// Parameters:	float - a float
//				float - another float to compare
// Return:	float - the minimum of the 2 floats
// Description:	finds minimum of two float values
float min(float x, float y)
{
	return (x < y) ? x : y;
}


// Parameters:	Point[] - array of points sorted according to y axis
//				int - size of array of points
//				float - upper bound min distance
// Return:	float - distance between the closest points
// Description: finds the distance between the closest points of strip of given size.
//				All points in strip[] are sorted according to y coord.
//				All points have upper bound on min distance as d.
// Note: this is O(n) since inner loop runs at most 6 times.
float stripClosest(Point strip[], int size, float d)
{
	float min = d;	// Initialize min distance to d

	qsort(strip, size, sizeof(Point), compareY);	// sort according to y

	// pick all points and the next until diff between y coord is smaller than d
	for (int i = 0; i < size; ++i)
	{
		if (strip[i].x > 0 && strip[i].y > 0)
		{
			for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
			{
				if (dist(strip[i], strip[j]) < min)		// if dist is less than min (which was init to d the upper bound)
				{
					min = dist(strip[i], strip[j]);		// assign the smaller dist to min
					P3 = strip[i];
					P3_NUM = i;
					P4 = strip[j];
					P4_NUM = j;
				}
			}
		}
	}

	return min;
}


// Parameters:	Point[] - array of points sorted according to x axis
//				int - size of the array of points
// Return:	float - smallest distance
// Description:	finds the smallest distance using recursive.
float closestUtil(Point P[], int n)
{
	// if 3 points or less, use brute force
	if (n <= 3)
		return bruteForce(P, n);

	// Find mid point for vertical line
	int mid = n / 2;
	Point midPoint = P[mid];


	// calc smallest dist 
	float distL = closestUtil(P, mid);				// on left of mid point 
	float distR = closestUtil(P + mid, n - mid);	// and right of mid point
	

	
	float d;
	
	// Find the smaller of the calc two distances and extract the points to global var
	if (distL < distR)
	{
		d = distL;
		
	}
	else
	{
		d = distR;
	}

	// create array strip[] for points close to the line passing through the mid point (closer than d, the delta)
	Point *strip = new Point[n];
	// int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (abs(P[i].x - midPoint.x) < d)
		{
			strip[i] = P[i];			// only store the smaller ones corresponding to the i from P
										// to keep the original index from P[] into strip[]
		}
		else
		{
			strip[i] = { -1,-1 };		// store -1,-1 for the i that doesn't have smaller ones
										// this is a dummy value to be used to parse later
		}
	}

	// Find closest points in strip.
	// Return min of d and closest dist is strip[]
	float minStrip = stripClosest(strip, n, d);
	float closestFloat;

	if (minStrip < d)
	{
		closestFloat = minStrip;
		P1 = P3;				// point from the strip
		P1_NUM = P3_NUM;
		P2 = P4;
		P2_NUM = P4_NUM;

	}
	else
	{
		closestFloat = d;
	}
	

	// delete before returning
	delete[] strip;

	
	return closestFloat;
}


// Parameters:	Point[] - array of points
//				int - size of array
// Return:	float - smallest distance
// Description:	driver function to use closestUtil()
float closest(Point P[], int n)
{
	qsort(P, n, sizeof(Point), compareX);	// sort according to x

	// use recursive smallest distance function closestUtil()
	return closestUtil(P, n);
}


// Parameters:	Point[] - array of original points
//				int - size of array
//				float - closest distance
//				Point - one of the points for closest distance
//				Point - the other point for closest distance
//				int - p1 point number (global passed in)
//				int - p2 point number (global passed in)
//				int - count of calculation
// Return: nothing
// Description: prints the output in a formatted readable way
void printFormattedOutPut(Point P[], int size, float closestDist, Point point1, Point point2, int p1Num, int p2Num, int calcCount)
{
	printf("The smallest distance is %f --> P%i[%i,%i] : P%i[%i,%i]\n", closestDist, p1Num, point1.x, point1.y, p2Num, point2.x, point2.y);
	printf("-->\t%i Point-to-Point distance calculations\n", calcCount);
	
}

// Parameters:	Point[] - array of original points
//				int - size of array
//				Point - given point
// Return:	int - the index of the given point
// Description: looks for the index corresponding to the given point
int findPointIndex(Point P[], int n, Point pt)
{
	int index = -1;
	for (int i = 0; i < n; i++)
	{
		if (P[i].x == pt.x && P[i].y == pt.y)
		{
			return i;
		}
	}

	return index;
}