#include <stdlib.h>
#include <stdio.h>

int main() {
    int grid_x = 40;
    int grid_y = 40;
    int grid[grid_x][grid_y];
    int buffergrid[grid_x][grid_y];
    
    int number;
    scanf("%d", &number);

    int iterations = number;

    int mask[8][2] = {{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};

    for (int i = 0; i < grid_x; i++) {
        for (int j = 0; j < grid_y; j++) {
            grid[i][j] = 0;
        }
    }
    grid[20][20] = 1;
    buffergrid[20][20] = 1;
    
    for (int n = 1; n < iterations + 1; n++) {
        for (int i = 0; i < grid_x; i++) {
            for (int j = 0; j < grid_y; j++) {
                if (grid[i][j] > 0) {
                    for (int m = 0; m < 8; m++) {
                        buffergrid[i+mask[m][0]][j+mask[m][1]]++;
                    }
                }
            }
        }
        for(int c = 0; c < grid_x; c++){
            for(int p = 0; p < grid_y; p++) {
                grid[c][p] = buffergrid[c][p];
            }
        }
    }

    int count = 0;
    for (int i = 0; i < grid_x; i++) {
        for (int j = 0; j < grid_y; j++) {
            if (grid[i][j] > 0) { count++; };
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
    printf("Total unique spaces: %d", count);
}
