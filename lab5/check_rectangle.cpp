#include "lab5_functions.h" // Include the declearation of the function

// You need to make sure the detected corner_points not form a line or point
bool check_rectangle(const int arr[][MAX_DIMENSION], int row, int col, int corner_points[]) {
    /***************Start your code here***************/
    int topLeftRow = corner_points[0];
    int topLeftCol = corner_points[1];
    int bottomRightRow = corner_points[2];
    int bottomRightCol = corner_points[3];

    if (topLeftRow == bottomRightRow || topLeftCol == bottomRightCol) {
        return false;
    }

    // Check if the rectangle area contains only "1"s
    for (int i = topLeftRow; i <= bottomRightRow; i++) {
        for (int j = topLeftCol; j <= bottomRightCol; j++) {
            if (arr[i][j] != 1) {
                return false;
            }
        }
    }

    // Check if the values outside the rectangle area are all "0"s
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i < topLeftRow || i > bottomRightRow || j < topLeftCol || j > bottomRightCol) {
                if (arr[i][j] != 0) {
                    return false;
                }
            }
        }
    }

    return true;

    /***************End your code here***************/
}