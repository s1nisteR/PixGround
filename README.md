# PixGround
Your Pixel Playground!

A _dead simple_ way to access pixels on your screen. PixGround provides you with a _digital sketchbook_ where you have complete control over every pixel displayed inside the viewport. Great for implementing and playing with Computer Graphics Algorithms!  

[![PixGround](https://github.com/s1nisteR/PixGround/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/s1nisteR/PixGround/actions/workflows/cmake-multi-platform.yml)

## Usage
This will set all pixels to white and draw three vertical lines with different colors. Scroll below to see what it looks like!
```cpp
// - YOUR PIXEL PLAYGROUND

//the height and width of our window
#define WIDTH 640
#define HEIGHT 480

void playground(Application *pApp)
{
    //get access to the buffer that we have the control of
    //buf[x][y] where x is the x-coordinate, y is the y-coordinate
    uint32_t **buf = pApp->getBuffer();

    for(int y = 0; y < HEIGHT; y++)
    {
        for(int x = 0; x < WIDTH; x++)
        {
            buf[x][y] = 0xFFFFFFFF;
        }
    }

    for(int i = 0; i < HEIGHT; i++)
    {
        buf[50][i] = 0xFF0000FF;
        buf[100][i] = 0x00FF00FF;
        buf[150][i] = 0x0000FFFF;
    }

}
```

In the ```playground.h``` file, first define the height and width of your window. Next, use ```pApp->getBuffer()``` to get access to the raw buffer. Now you can set the pixel values for each pixel in the buffer. You can access an individual pixel by accessing ```buf[i][j]``` where i is your x-coordinate and j is your y-coordinate.

Each pixel value is represented by an ```uint32_t```, following the RGBA standard. 
```0xFF0000FF``` would represent a red pixel(FF for Red, 00 for Green, 00 for Blue, FF for Alpha).

## Compile
You will need:
1. Git
2. CMake
3. Any Modern Compiler with C++20 Support

Dependencies:
1. SDL3

Clone the project:\
```git clone https://github.com/s1nisteR/PixGround.git --recurse-submodules```

Switch into the cloned directory:\
```cd PixGround```

Create the build directory:\
```mkdir build```

Switch to the build directory:\
```cd build```

Run CMake:\
```cmake ..```

If you are on Linux you could now use ```make``` and then execute the program. If you're on Windows, you could open the generated solution files in Visual Studio and then compile and run.

## Demo
All pixels set to white and drawing colored lines from bottom to top.
![demo1](https://raw.githubusercontent.com/s1nisteR/PixGround/main/img/demo1.png)

The following example demonstrates how to implement a simple DDA Line Drawing Algorithm:
```cpp
// - YOUR PIXEL PLAYGROUND
//DDA - Example
#include <cmath>
#include <cstdlib>
#include <cmath>

//the height and width of our window
#define WIDTH 640
#define HEIGHT 480

// DDA Function for line generation
void DDA(int X0, int Y0, int X1, int Y1, uint32_t **buf)
{
    // calculate dx & dy
    int dx = X1 - X0;
    int dy = Y1 - Y0;

    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // calculate increment in x & y for each steps
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;

    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++) {
        buf[std::lround(X)][std::lround(Y)] = 0xFF0000FF; //put red pixel at (X,Y)
        X += Xinc; // increment in x at each step
        Y += Yinc; // increment in y at each step
    }
}


void playground(Application *pApp)
{
    //get access to the buffer that we have the control of
    //buf[x][y] where x is the x-coordinate, y is the y-coordinate
    uint32_t **buf = pApp->getBuffer();

    for(int y = 0; y < HEIGHT; y++)
    {
        for(int x = 0; x < WIDTH; x++)
        {
            buf[x][y] = 0xFFFFFFFF;
        }
    }


    // Function call
    DDA(2, 2, 200, 250, buf);
    DDA(70, 50, 20, 200, buf);
    DDA(450, 40, 60, 340, buf);
}
```
![demo2](https://raw.githubusercontent.com/s1nisteR/PixGround/main/img/demo2.png)