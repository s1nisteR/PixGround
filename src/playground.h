void playground(Application *pApp)
{
    uint32_t** buf = pApp->getBuffer(); //get the 2D buffer that we can manipulate


    //fill buffer with RED RGBA pixel values for half the screen width
    for(int i = 0; i < WIDTH / 2; i++)
    {
        for(int j = 0; j < HEIGHT; j++)
        {
            buf[i][j] = 0xff0000ff;
        }
    }

    //fill bottom half with green pixels
    for(int i = WIDTH / 2; i < WIDTH; i++)
    {
        for(int j = 0; j < HEIGHT; j++)
        {
            buf[i][j] = 0x00ff00ff;
        }
    }
}