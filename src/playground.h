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