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

// TODO:
// function locateQuadrant:
// @param x:  x coordinate of the empty cell
// @param y:  y coordinate of the empty cell
//
// If x < half width, y < half width, then return 1
// If x >= half width, y < half width, then return 2
// If x >= half width, y >= half width, then return 3
// If x < half width, y >= half width, then return 4
//
// @return: int
// The function returns after getting valid values for width, emptyXPos and emptyYPos
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

	return -1; // This line is only reached if the input is invalid
}
/**
	Given the puzzleMap (2D array from the recursive function),
	Generate the console output
 */
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

/**
 * Initialize the whole puzzleMap using by a space character: ' '
 */
void initializePuzzleMap(int width, char puzzleMap[][MAX_WIDTH])
{
	for (int x = 0; x < width; x++)
		for (int y = 0; y < width; y++)
			puzzleMap[x][y] = ' ';
}

void normalizePuzzleMap(int width, char puzzleMap[][MAX_WIDTH])
{
	int count = 1;
	char nextChar = 'A';

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (puzzleMap[i][j] != ' ')
			{
				puzzleMap[i][j] = nextChar++;
				count++;
			}
		}
	}
}

// TODO:
// [The most important function in this program]
// The recursive function to fill up the character array: puzzleMap
// You need to figure out the parameters of the fillPuzzleRecursive function by yourself
//
void fillPuzzleRecursive(int width, char puzzleMap[][MAX_WIDTH], int tx,
												 int ty, int x, int y, char &nextChar)
{
	if (width == 2)
	{
		puzzleMap[tx][ty] = nextChar++;
		puzzleMap[tx + 1][ty] = nextChar++;
		puzzleMap[tx + 1][ty + 1] = nextChar++;
		puzzleMap[tx][ty + 1] = nextChar++;
		return;
	}

	int halfWidth = width / 2;

	int quad = locateQuadrant(width, x, y);

	if (quad == 1)
	{
		fillPuzzleRecursive(halfWidth, puzzleMap, tx, ty, x, y, nextChar);
		fillPuzzleRecursive(halfWidth, puzzleMap, tx + halfWidth, ty, tx + halfWidth, ty + halfWidth - 1, nextChar);
		fillPuzzleRecursive(halfWidth, puzzleMap, tx + halfWidth, ty + halfWidth, tx + halfWidth, ty + halfWidth, nextChar);
		fillPuzzleRecursive(halfWidth, puzzleMap, tx, ty + halfWidth, tx + halfWidth - 1, ty + halfWidth, nextChar);
	}
	else if (quad == 2)
	{
		fillPuzzleRecursive(halfWidth, puzzleMap, tx, ty, tx + halfWidth - 1, ty + halfWidth - 1, nextChar);
		fillPuzzleRecursive(halfWidth, puzzleMap, tx + halfWidth, ty, x, y, nextChar);
		fillPuzzleRecursive(halfWidth, puzzleMap, tx + halfWidth, ty + halfWidth, tx + halfWidth, ty + halfWidth, nextChar);
		fillPuzzleRecursive(halfWidth, puzzleMap, tx, ty + halfWidth, tx + halfWidth - 1, ty + halfWidth, nextChar);
	}
	else if (quad == 3)
	{
		fillPuzzleRecursive(halfWidth, puzzleMap, tx, ty, tx + halfWidth - 1, ty + halfWidth - 1, nextChar);
		fillPuzzleRecursive(halfWidth, puzzleMap, tx + halfWidth, ty, tx + halfWidth, ty + halfWidth - 1, nextChar);
		fillPuzzleRecursive(halfWidth, puzzleMap, tx + halfWidth, ty + halfWidth, x, y, nextChar);
		fillPuzzleRecursive(halfWidth, puzzleMap, tx, ty + halfWidth, tx + halfWidth - 1, ty + halfWidth, nextChar);
	}
	else if (quad == 4)
	{
		fillPuzzleRecursive(halfWidth, puzzleMap, tx, ty, tx + halfWidth - 1, ty + halfWidth - 1, nextChar);
		fillPuzzleRecursive(halfWidth, puzzleMap, tx + halfWidth, ty, tx + halfWidth, ty + halfWidth - 1, nextChar);
		fillPuzzleRecursive(halfWidth, puzzleMap, tx + halfWidth, ty + halfWidth, tx + halfWidth, ty + halfWidth, nextChar);
		fillPuzzleRecursive(halfWidth, puzzleMap, tx, ty + halfWidth, x, y, nextChar);
	}
}

// TODO:
// function checkInput:
//
// @param width: the width of the square. Valid values: 2, 4, 8
// You can assume inputs are always integers.
// @param emptyXPos: the x-axis of the empty position.
// Valid range: [0, width-1].
// You can assume inputs are always integers.
// @param emptyYPos: the y-axis of the empty position.
// Valid range: [0, width-1].
// You can assume inputs are always integers.
//
//  Note: The pass-by-reference variables will be used in the main function.
// @return: void
// The function returns after getting valid values for width, emptyXPos and emptyYPos
void checkInput(int &width, int &emptyXPos, int &emptyYPos)
{
	while (true)
	{
		cout << "Enter the width/height of the puzzle (2, 4, 8): ";
		cin >> width;

		if (width == 2 || width == 4 || width == 8)
			break;

		cout << "Invalid width. Please enter a valid width (2, 4, 8)." << endl;
	}

	while (true)
	{
		cout << "Enter the x-coordinate of the empty cell (0-" << width - 1 << "): ";
		cin >> emptyXPos;

		if (emptyXPos >= 0 && emptyXPos < width)
			break;

		cout << "Invalid x-coordinate. Please enter a valid x-coordinate (0-" << width - 1 << ")." << endl;
	}

	while (true)
	{
		cout << "Enter the y-coordinate of the empty cell (0-" << width - 1 << "): ";
		cin >> emptyYPos;

		if (emptyYPos >= 0 && emptyYPos < width)
			break;

		cout << "Invalid y-coordinate. Please enter a valid y-coordinate (0-" << width - 1 << ")." << endl;
	}
}

// You are NOT ALLOWED to modify the main function
int main()
{

	int width = 0;
	int emptyXPos = 0;
	int emptyYPos = 0;

	checkInput(width, emptyXPos, emptyYPos);

	// initialized with empty spaces..
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

	// invoke the recursive call here...
	// Result: puzzleMap will be filled by characters
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
