// /*

// 	The following program solves the L-shape blocks problem

// 	 Given
// 		A 2^N x 2^N array (In this assignment, we restrict the value N as 1, 2 and 3 )
// 		 The location of the empty cell (x,y)
// 			The legal (x,y) coordinates of the empty cell:

// 				For a 2 x 2 block, the legal range is 0-1
// 				For a 4 x 4 block, the legal range is 0-3
// 				For a 8 x 8 block, the legal range is 0-7
// 		 You can assume all the input values are correct

// 	Output:

// 		The empty cell (x,y) remains empty
// 		All other cells are filled by non-overlapping L-shape blocks

// 	Output mode:
// 		(0) Console output without normalization
// 		(1) Console output with normalization

// 		 Author: Peter, Brian, Tommy
// */

// #include <iostream>
// using namespace std;

// // Constants in global scope
// const int MAX_WIDTH = 8;
// const int LOCATEQUADRANT_NOT_IMPLEMENTED = 0;

// int locateQuadrant(int width, int x, int y)
// {
// 	int halfWidth = width / 2;

// 	if (x < halfWidth && y < halfWidth)
// 		return 1;
// 	else if (x >= halfWidth && y < halfWidth)
// 		return 2;
// 	else if (x >= halfWidth && y >= halfWidth)
// 		return 3;
// 	else if (x < halfWidth && y >= halfWidth)
// 		return 4;

// 	return -1;
// }

// void visualizePuzzleByText(int width, char puzzleMap[][MAX_WIDTH])
// {

// 	cout << "  ";
// 	for (int x = 0; x < width; x++)
// 		cout << x << " ";
// 	cout << endl;

// 	for (int y = 0; y < width; y++)
// 	{
// 		cout << y << ":";
// 		for (int x = 0; x < width; x++)
// 			cout << puzzleMap[x][y] << " ";
// 		cout << endl;
// 	}
// }

// void initializePuzzleMap(int width, char puzzleMap[][MAX_WIDTH])
// {
// 	for (int x = 0; x < width; x++)
// 		for (int y = 0; y < width; y++)
// 			puzzleMap[x][y] = ' ';
// }

// void fillPuzzleRecursive(int width, char puzzleMap[][MAX_WIDTH], int x, int y, int px, int py, char &nextChar)
// {
// 	if (width == 2)
// 	{
// 		for (int i = 0; i < 2; i++)
// 		{
// 			for (int j = 0; j < 2; j++)
// 			{
// 				if (i != px || j != py)
// 				{
// 					puzzleMap[y + i][x + j] = nextChar;
// 				}
// 			}
// 		}
// 		nextChar++;
// 	}
// 	else
// 	{
// 		int halfWidth = width / 2;
// 		int quadrant = locateQuadrant(x + px, y + py, halfWidth);
// 		int subX = (quadrant % 2 == 0) ? 0 : halfWidth;
// 		int subY = (quadrant < 2) ? 0 : halfWidth;
// 		int newPx = (quadrant % 2 == 0) ? px : px - halfWidth;
// 		int newPy = (quadrant < 2) ? py : py - halfWidth;
// 		fillPuzzleRecursive(halfWidth, puzzleMap, x + subX, y + subY, newPx, newPy, nextChar);

// 		for (int i = 0; i < 4; i++)
// 		{
// 			if (i != quadrant)
// 			{
// 				int subX = (i % 2 == 0) ? 0 : halfWidth;
// 				int subY = (i < 2) ? 0 : halfWidth;
// 				fillPuzzleRecursive(halfWidth, puzzleMap, x + subX, y + subY, halfWidth - 1, halfWidth - 1, nextChar);
// 			}
// 		}
// 	}
// }

// void normalizePuzzleMap(int width, char puzzleMap[][MAX_WIDTH])
// {
// 	for (int i = 0; i < width; i++)
// 	{
// 		for (int j = 0; j < width - 1; j++)
// 		{
// 			if (puzzleMap[i][j] > puzzleMap[i][j + 1])
// 			{
// 				char temp = puzzleMap[i][j];
// 				puzzleMap[i][j] = puzzleMap[i][j + 1];
// 				puzzleMap[i][j + 1] = temp;
// 			}
// 		}
// 	}

// 	for (int i = 0; i < width - 1; i++)
// 	{
// 		for (int j = 0; j < width; j++)
// 		{
// 			if (puzzleMap[i][j] > puzzleMap[i + 1][j])
// 			{
// 				char temp = puzzleMap[i][j];
// 				puzzleMap[i][j] = puzzleMap[i + 1][j];
// 				puzzleMap[i + 1][j] = temp;
// 			}
// 		}
// 	}
// }

// void checkInput(int &width, int &emptyXPos, int &emptyYPos)
// {
// 	while (true)
// 	{
// 		cout << "Enter the width/height of the puzzle (2, 4, 8): ";
// 		cin >> width;
// 		cout << endl;

// 		if (width == 2 || width == 4 || width == 8)
// 			break;

// 		cout << "Invalid width. Please enter a valid width (2, 4, 8)." << endl;
// 	}

// 	while (true)
// 	{
// 		cout << "Enter the x-coordinate of the empty cell (0-" << width - 1 << "): ";
// 		cin >> emptyXPos;
// 		cout << endl;

// 		if (emptyXPos >= 0 && emptyXPos < width)
// 			break;

// 		cout << "Invalid x-coordinate. Please enter a valid x-coordinate (0-" << width - 1 << ")." << endl;
// 	}

// 	while (true)
// 	{
// 		cout << "Enter the y-coordinate of the empty cell (0-" << width - 1 << "): ";
// 		cin >> emptyYPos;
// 		cout << endl;

// 		if (emptyYPos >= 0 && emptyYPos < width)
// 			break;

// 		cout << "Invalid y-coordinate. Please enter a valid y-coordinate (0-" << width - 1 << ")." << endl;
// 	}
// }

// int main()
// {

// 	int width = 0;
// 	int emptyXPos = 0;
// 	int emptyYPos = 0;

// 	checkInput(width, emptyXPos, emptyYPos);

// 	char puzzleMap[MAX_WIDTH][MAX_WIDTH];

// 	// initialize
// 	initializePuzzleMap(width, puzzleMap);

// 	int modeOfOperation = 0;
// 	do
// 	{
// 		cout
// 				<< "0: Exit directly (for testing checkInput function), 1: Output Quadrant of the empty cell,"
// 				<< endl
// 				<< "2: Output without normalization (for student's debug only), 3: Output with normalization"
// 				<< endl;
// 		cout << "Enter the output mode: ";
// 		cin >> modeOfOperation;
// 		cout << endl;
// 	} while (modeOfOperation < 0 || modeOfOperation > 3);

// 	if (modeOfOperation == 0)
// 	{
// 		return 0;
// 	}
// 	if (modeOfOperation == 1)
// 	{
// 		int quad = locateQuadrant(width, emptyXPos, emptyYPos);
// 		cout << "Quadrant for the empty cell: " << quad << endl;
// 		return 0;
// 	}
// 	char nextChar = 'A';

// 	fillPuzzleRecursive(width, puzzleMap, 0, 0, emptyXPos, emptyYPos, nextChar);

// 	int quad = locateQuadrant(width, emptyXPos, emptyYPos);
// 	cout << "Quadrant for the empty cell: " << quad << endl;
// 	if (modeOfOperation == 2)
// 	{
// 		visualizePuzzleByText(width, puzzleMap);
// 	}
// 	else
// 	{
// 		normalizePuzzleMap(width, puzzleMap);
// 		visualizePuzzleByText(width, puzzleMap);
// 	}
// 	return 0;
// }

/*

	The following program solves the L-shape blocks problem

	 Given
		A 2^N x 2^N array (In this assignment, we restrict the value N as 1, 2 and 3 )
		 The location of the empty cell (x,y)
			The legal (x,y) coordinates of the empty cell:

				For a 2 x 2 block, the legal range is 0-1
				For a 4 x 4 block, the legal range is 0-3
				For a 8 x 8 block, the legal range is 0-7
		 You can assume all the input values are correct

	Output:

		The empty cell (x,y) remains empty
		All other cells are filled by non-overlapping L-shape blocks

	Output mode:
		(0) Console output without normalization
		(1) Console output with normalization

		 Author: Peter, Brian, Tommy
*/

#include <iostream>
using namespace std;

// Constants in global scope
const int MAX_WIDTH = 8;
const int LOCATEQUADRANT_NOT_IMPLEMENTED = 0;

int locateQuadrant(int width, int x, int y)
{
	int halfWidth = width / 2;

	if (x < halfWidth && y < halfWidth)
		return 1;
	else if (x >= halfWidth && y < halfWidth)
		return 2;
	else if (x >= halfWidth && y >= halfWidth)
		return 3;
	else if (x < halfWidth && y >= halfWidth)
		return 4;

	return -1;
}

void visualizePuzzleByText(int width, char puzzleMap[][MAX_WIDTH])
{

	cout << "  ";
	for (int x = 0; x < width; x++)
		cout << x << " ";
	cout << endl;

	for (int y = 0; y < width; y++)
	{
		cout << y << ":";
		for (int x = 0; x < width; x++)
			cout << puzzleMap[x][y] << " ";
		cout << endl;
	}
}

void initializePuzzleMap(int width, char puzzleMap[][MAX_WIDTH])
{
	for (int x = 0; x < width; x++)
		for (int y = 0; y < width; y++)
			puzzleMap[x][y] = ' ';
}

void normalizePuzzleMap(int width, char puzzleMap[][MAX_WIDTH])
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < width - 1; j++)
		{
			if (puzzleMap[i][j] > puzzleMap[i][j + 1])
			{
				char temp = puzzleMap[i][j];
				puzzleMap[i][j] = puzzleMap[i][j + 1];
				puzzleMap[i][j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < width - 1; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (puzzleMap[i][j] > puzzleMap[i + 1][j])
			{
				char temp = puzzleMap[i][j];
				puzzleMap[i][j] = puzzleMap[i + 1][j];
				puzzleMap[i + 1][j] = temp;
			}
		}
	}
}
void fillPuzzleRecursive(int width, char puzzleMap[][MAX_WIDTH], int x, int y, int px, int py, char &nextChar)
{
	if (width == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (i != px || j != py)
				{
					puzzleMap[y + i][x + j] = nextChar;
				}
			}
		}
		nextChar++;
	}
	else
	{
		int halfWidth = width / 2;
		int quadrant = locateQuadrant(x + px, y + py, halfWidth);
		int subX = (quadrant % 2 == 0) ? 0 : halfWidth;
		int subY = (quadrant < 2) ? 0 : halfWidth;
		int newPx = (quadrant % 2 == 0) ? px : px - halfWidth;
		int newPy = (quadrant < 2) ? py : py - halfWidth;
		fillPuzzleRecursive(halfWidth, puzzleMap, x + subX, y + subY, newPx, newPy, nextChar);

		for (int i = 0; i < 4; i++)
		{
			if (i != quadrant)
			{
				int subX = (i % 2 == 0) ? 0 : halfWidth;
				int subY = (i < 2) ? 0 : halfWidth;
				fillPuzzleRecursive(halfWidth, puzzleMap, x + subX, y + subY, halfWidth - 1, halfWidth - 1, nextChar);
			}
		}
	}
}

void checkInput(int &width, int &emptyXPos, int &emptyYPos)
{
	while (true)
	{
		cout << "Enter the width/height of the puzzle (2, 4, 8): ";
		cin >> width;
		cout << endl;

		if (width == 2 || width == 4 || width == 8)
			break;

		cout << "Invalid width. Please enter a valid width (2, 4, 8)." << endl;
	}

	while (true)
	{
		cout << "Enter the x-coordinate of the empty cell (0-" << width - 1 << "): ";
		cin >> emptyXPos;
		cout << endl;

		if (emptyXPos >= 0 && emptyXPos < width)
			break;

		cout << "Invalid x-coordinate. Please enter a valid x-coordinate (0-" << width - 1 << ")." << endl;
	}

	while (true)
	{
		cout << "Enter the y-coordinate of the empty cell (0-" << width - 1 << "): ";
		cin >> emptyYPos;
		cout << endl;

		if (emptyYPos >= 0 && emptyYPos < width)
			break;

		cout << "Invalid y-coordinate. Please enter a valid y-coordinate (0-" << width - 1 << ")." << endl;
	}
}

int main()
{

	int width = 0;
	int emptyXPos = 0;
	int emptyYPos = 0;

	checkInput(width, emptyXPos, emptyYPos);

	char puzzleMap[MAX_WIDTH][MAX_WIDTH];

	// initialize
	initializePuzzleMap(width, puzzleMap);

	int modeOfOperation = 0;
	do
	{
		cout
				<< "0: Exit directly (for testing checkInput function), 1: Output Quadrant of the empty cell,"
				<< endl
				<< "2: Output without normalization (for student's debug only), 3: Output with normalization"
				<< endl;
		cout << "Enter the output mode: ";
		cin >> modeOfOperation;
		cout << endl;
	} while (modeOfOperation < 0 || modeOfOperation > 3);

	if (modeOfOperation == 0)
	{
		return 0;
	}
	if (modeOfOperation == 1)
	{
		int quad = locateQuadrant(width, emptyXPos, emptyYPos);
		cout << "Quadrant for the empty cell: " << quad << endl;
		return 0;
	}
	char nextChar = 'A';

	fillPuzzleRecursive(width, puzzleMap, 0, 0, emptyXPos, emptyYPos, nextChar);

	int quad = locateQuadrant(width, emptyXPos, emptyYPos);
	cout << "Quadrant for the empty cell: " << quad << endl;
	if (modeOfOperation == 2)
	{
		visualizePuzzleByText(width, puzzleMap);
	}
	else
	{
		normalizePuzzleMap(width, puzzleMap);
		visualizePuzzleByText(width, puzzleMap);
	}
	return 0;
}