#include "backtraking.h"
#include <iostream>
#include <cstring>

using namespace std;
listBack ultimapath;



backTraking::backTraking(int arr[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = arr[i][j];
        }
    }
    shortestPathLength=9999;

}
void backTraking::backtrack(int x, int y, int distance, int end_x, int end_y, listBack path) {
    int value = grid[x][y];
    int row = N;
    int colum = N;

    int manhattanDist = abs(end_x - x) + abs(end_y - y);
    bool canMoveRight = (end_x > x && manhattanDist > abs(end_y - y));
    bool canMoveLeft = (end_x < x && manhattanDist > abs(end_y - y));
    bool canMoveDown = (end_y > y && manhattanDist > abs(end_x - x));
    bool canMoveUp = (end_y < y && manhattanDist > abs(end_x - x));



    if (canMoveRight && grid[x+1][y] != -1) {

        if (grid[x+1][y] > 0 ){

            int newValue = grid[x+1][y];

            grid[x+1][y] = -1;
            path.add(x+1, y);
            backtrack(x+1, y, distance + abs(value - newValue), end_x, end_y, path);
            path.deleteNode();
            grid[x+1][y] = newValue;

        }
        else {
            if (!canMoveLeft && x>0 ) {
                canMoveLeft=true;

            }

            if (!canMoveDown && y<row-1) {
                canMoveDown=true;
            }

            if (!canMoveUp && y>0) {
                canMoveUp=true;
            }
        }


    }
    if (canMoveLeft  && grid[x-1][y] != -1) {


        if (grid[x-1][y] > 0){

            int newValue = grid[x-1][y];
            grid[x-1][y] = -1;
            path.add(x-1, y);
            backtrack(x-1, y, distance + abs(value - newValue), end_x, end_y, path);
            path.deleteNode();
            grid[x-1][y] = newValue;
        }else {
            if (!canMoveRight && x < colum - 1) {
                canMoveRight=true;

            }

            if (!canMoveDown && y<row-1) {
                canMoveDown=true;
            }

            if (!canMoveUp && y>0) {
                canMoveUp=true;
            }
        }



    }
    if (canMoveDown && grid[x][y+1] != -1) {

        if(grid[x][y+1] > 0){
            int newValue = grid[x][y+1];
            grid[x][y+1] = -1;
            path.add(x, y+1);
            backtrack(x, y+1, distance + abs(value - newValue), end_x, end_y, path);
            path.deleteNode();
            grid[x][y+1] = newValue;
        }  else {
            if (!canMoveLeft && x>0) {
                canMoveLeft=true;

            }

            if (!canMoveRight && x < colum - 1) {
                canMoveRight=true;
            }

            if (!canMoveUp && y>0) {
                canMoveUp=true;
            }
        }


    }
    if (canMoveUp && grid[x][y-1] != -1) {

        if (grid[x][y-1] > 0 ){

            int newValue = grid[x][y-1];
            grid[x][y-1] = -1;
            path.add(x, y-1);
            backtrack(x, y-1, distance + abs(value - newValue), end_x, end_y, path);
            path.deleteNode();

            grid[x][y-1] = newValue;
        }else {
            if (!canMoveLeft && x>0) {
                canMoveLeft=true;

            }

            if (!canMoveDown && y<row-1) {
                canMoveDown=true;
            }

            if (!canMoveRight && x < colum - 1) {
                canMoveRight=true;
            }
        }


    }
    if (x == end_x && y == end_y ){    ;


        if ( distance < shortestPathLength){

            shortestPathLength = distance;
            shortestPath.addToGlobalList(path);


        }
        return ;


    }








}
listBack backTraking::findShortestPath(int start_x, int start_y, int end_x, int end_y) {
    listBack path;
    path.add(start_x, start_y);
    backtrack(start_x, start_y, 0, end_x, end_y, path);

    path.printPath(shortestPath);
    return shortestPath;




}
