#include "lab5_functions.h" // Include the declearation of the function

int area_size(const int arr[][MAX_DIMENSION], int row, int col, const int corner_points[]) {
    /***************Start your code here***************/
    int topLeftRow = corner_points[0];
    int topLeftCol = corner_points[1];
    int bottomRightRow = corner_points[2];
    int bottomRightCol = corner_points[3];

    return (bottomRightCol - topLeftCol + 1) * (bottomRightRow - topLeftRow + 1);

    /***************End your code here***************/
}