#include <stdio.h>

int const SIZE = 7;

int main()
{
    int array[SIZE][SIZE];
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            array[i][j] = j + 1;
        }
    }
    int coordinate_x = SIZE / 2, coordinate_y = SIZE / 2, circle = 0;
    printf("%d", array[coordinate_y][coordinate_x]);
    while (coordinate_x != 0 && coordinate_y != SIZE - 1) {
        if (circle < SIZE - 1) {
            circle++;
        }
        for (int i = 0; i < circle; ++i) {
            coordinate_y++;
            printf("%d", array[coordinate_y][coordinate_x]);
        }
        for (int i = 0; i < circle; ++i) {
            coordinate_x++;
            printf("%d", array[coordinate_y][coordinate_x]);
        }
        circle++;
        for (int i = 0; i < circle; ++i) {
            coordinate_y--;
            printf("%d", array[coordinate_y][coordinate_x]);
        }
        for (int i = 0; i < circle; ++i) {
            coordinate_x--;
            printf("%d", array[coordinate_y][coordinate_x]);
        }
    }
    for (int i = 0; i < circle; ++i) {
        coordinate_y++;
        printf("%d", array[coordinate_y][coordinate_x]);
    }
    return 0;
}
