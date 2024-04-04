// - YOUR PIXEL PLAYGROUND

void playground(Application *pApp)
{
    //get access to the buffer that we...
    uint32_t **buf = pApp->getBuffer();

    //...then modify by filling with all green pixels
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            //PIXEL FORMAT - 0x RR GG BB AA
            buf[i][j] = 0x00FF00FF;
        }
    }

    //and then we draw a line by filling those certain pixels as black
    for(int i = 0; i < WIDTH; i++)
    {
        buf[50][i] = 0x00000000;
    }
}