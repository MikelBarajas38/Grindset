#include <string>
#include <iostream>
#include <vector>
#include "raylib.h"

#define SCREEN_WIDTH 450
#define SCREEN_HEIGHT 450
#define SCREEN_FPS 10

void createGrid(auto &grid, int gridHeight, int gridWidth, int tileSize)
{
    int yOffset = SCREEN_HEIGHT/2 - gridHeight * tileSize/2;
    int xOffset = SCREEN_WIDTH/2 - gridWidth * tileSize/2;

    for(int i=0;i<gridHeight;++i)
    {
        std::vector<Rectangle> temp;
        for(int j=0; j<gridWidth; ++j)
        {
            Rectangle r = { i*(float)tileSize + xOffset, j*(float)tileSize + yOffset, tileSize, tileSize};
            temp.push_back(r);
        }
        grid.push_back(temp);
        temp.clear(); 
    }
}

void fillOctopuses(auto &octopuses)
{
    freopen("src/data.in","r",stdin);
    std::string line;
    std::vector<int> lineV;

    while(getline(std::cin,line))
    {
        for(char c : line) lineV.push_back(c-48);
        octopuses.push_back(lineV);
        lineV.clear();
    }
}

bool isValidIndex(int i, int j)
{
    return (j<10 && j>=0 && i<10 && i>=0);
}

int flashOct(auto &octopuses, auto &flashed, int n, int m)
{
    int nFlashes = 1;
    octopuses[n][m] = 0;
    flashed[n][m] = true;

    for(int i=n-1;i<n+2;++i)
    {
        for(int j=m-1;j<m+2;++j)
        {
            if(isValidIndex(i,j))
            {
                if(!flashed[i][j]) ++octopuses[i][j];
                else octopuses[i][j]=0;
                
                if(octopuses[i][j]>9) nFlashes += flashOct(octopuses,flashed,i,j);
            }
        }
    }
    return nFlashes;
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "ADVENT OF CODE 2021 (DAY 11)");

    //Game Objects

    const int tileSize = 25;
    const int gridHeight = 10;
    const int gridWidth = 10;

    std::vector<std::vector<Rectangle>> grid;
    createGrid(grid, gridHeight, gridWidth, tileSize);

    std::vector<std::vector<int>> octopuses;
    fillOctopuses(octopuses);

    std::vector<std::vector<bool>> flashed(10,std::vector<bool>(10));

    int flashes = 0, steps = 0, partOne, partTwo;
    bool isSync = 0;

    unsigned char alpha;

    SetTargetFPS(SCREEN_FPS);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        //Cellular automata
        for(auto &v : flashed) fill(begin(v),end(v),0);

        for(int i=0;i<10;++i)
            for(int j=0;j<10;++j)
                ++octopuses[i][j];    

        for(int i=0;i<10;++i)
            for(int j=0;j<10;++j)
            {
                if(octopuses[i][j]>9 && !flashed[i][j])
                    flashes += flashOct(octopuses,flashed,i,j);
            }

        ++steps;

        //part one
        if(steps==100) partOne=flashes;

        //part two
        if(!isSync)
        {
        isSync = true;
        for(int i=0;i<10;++i)
            for(int j=0;j<10;++j)
                isSync = isSync && flashed[i][j];
     
        if(isSync) partTwo=steps;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground({10,73,136,255});

            //text
            DrawText(TextFormat("STEPS: %i", steps), 100, 55, 20, {255, 253, 208, 255});
            DrawText(TextFormat("FLASHES: %i", flashes), 100, 75, 20, {255, 253, 208, 255});

            if(steps>=100) DrawText(TextFormat("PART 1: %i", partOne), 100, 355, 20, {255, 253, 208, 255});
            if(isSync) DrawText(TextFormat("PART 2: %i", partTwo), 100, 375, 20, {255, 253, 208, 255});

            //grid
            for(int i=0;i<gridHeight; ++i)
                for(int j=0; j<gridWidth; ++j)
                {
                    if(octopuses[i][j]) alpha = 255*(octopuses[i][j])/9;
                    else alpha = 255;

                    DrawRectangleRec(grid[i][j],{255, 253, 208, alpha});
                }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}