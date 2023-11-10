#include "lab5_functions.h" // Include the declearation of the function


// detect corner points of the possible rectangle
// corner points are inclusive to the possible rectangle
// corner_points[0]: row index of the top left corner
// corner_points[1]: column index of the top left corner
// corner_points[2]: row index of the bottom right corner
// corner_points[3]: column index of the bottom right corner
void detect_corner(const int arr[][MAX_DIMENSION], int row, int col, int corner_points[]) {
    /***************Start your code here***************/
    int topLeftRow = -1, topLeftCol = -1, bottomRightRow = -1, bottomRightCol = -1;

    // Find top left corner
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] == 1) {
                topLeftRow = i;
                topLeftCol = j;
                break;
            }
        }
        if (topLeftRow != -1) {
            break;
        }
    }

    // Find bottom right corner
    for (int i = row - 1; i >= 0; i--) {
        for (int j = col - 1; j >= 0; j--) {
            if (arr[i][j] == 1) {
                bottomRightRow = i;
                bottomRightCol = j;
                break;
            }
        }
        if (bottomRightRow != -1) {
            break;
        }
    }

    corner_points[0] = topLeftRow;
    corner_points[1] = topLeftCol;
    corner_points[2] = bottomRightRow;
    corner_points[3] = bottomRightCol;
    /***************End your code here***************/
}