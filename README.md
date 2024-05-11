# PixGround
Your Pixel Playground!

[![PixGround](https://github.com/s1nisteR/PixGround/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/s1nisteR/PixGround/actions/workflows/cmake-multi-platform.yml)

## Usage
```c++
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
