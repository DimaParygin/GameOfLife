#include <iostream>
#include <stdlib.h>

#define HEIGHT 5																			// высота мира
#define WIDTH 5																				// ширина мира

void RandomWorld(int world[HEIGHT][WIDTH]){													// случайный мир
	for (int i = 0; i < HEIGHT; ++i){
		for (int j = 0; j < WIDTH; ++j)
			world[i][j] = rand() % 2;
	}
};


void GameOfLife(int world[HEIGHT][WIDTH]){
	int xCoord = 0;
	int yCoord = 0;
	int neighbors = 0;
	int WorldNeighbors[HEIGHT][WIDTH];
	for (xCoord = 0; xCoord < HEIGHT; ++xCoord){
		for (yCoord = 0; yCoord < HEIGHT; ++yCoord){
			for (int i = yCoord - 1; i <= yCoord + 1; i++) {
				for (int j = xCoord - 1; j <= xCoord + 1; j++) {
					if (i == yCoord && j == xCoord) {
						continue;
					}
					if (i > -1 && i < HEIGHT && j > -1 && j < WIDTH) {
						if (world[i][j] == 1) {
							neighbors++;
						}
					}
				}
				WorldNeighbors[xCoord][yCoord] = neighbors;
				neighbors = 0;
			}
		}
	}
	printf("\n");
	for (char i = 0; i < HEIGHT; i++) {
		for (char j = 0; j < WIDTH; j++) {
			std::cout << WorldNeighbors[i][j];
		}
		std::cout << std::endl;
	}
}

int main() {
	int world[HEIGHT][WIDTH];
	RandomWorld(world);
	for (char i = 0; i < HEIGHT; i++) {
		for (char j = 0; j < WIDTH; j++) {
			std::cout << world[i][j];
		}
		std::cout << std::endl;
	}

	GameOfLife(world);

	getchar();
}
