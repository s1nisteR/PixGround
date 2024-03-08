void playground(Application *pApp)
{
    uint32_t** buf = pApp->getBuffer(); //get the 2D buffer that we can manipulate


    //fill buffer with RED RGBA pixel values
    for(int i = 0; i < 640 / 2; i++)
    {
        for(int j = 0; j < 480; j++)
        {
            buf[i][j] = 0xff0000ff;
        }
    }
}