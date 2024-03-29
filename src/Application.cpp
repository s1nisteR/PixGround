//
// Created by s1nister on 3/7/24.
//

#include "Application.h"
#include "./utils.h"

Application::Application(const uint32_t width, const uint32_t height, const char* windowTitle)
{
    //member variable initialization
    m_width = width;
    m_height = height;
    m_windowTitle = windowTitle;
    pPixels = new uint32_t[m_width * m_height];
    memset(pPixels, 0, m_width * m_height * sizeof(uint32_t));
    isRunning = true;

    //initialize video subsystem of SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0) logError();

    //create the window
    pWindow = SDL_CreateWindow(m_windowTitle, static_cast<int>(m_width), static_cast<int>(m_height), NULL);
    if(pWindow == nullptr)
    {
        logError();
        SDL_Quit();
    }
    log("Window Opened Successfully!");

    //create the renderer
    pRenderer = SDL_CreateRenderer(pWindow, nullptr, SDL_RENDERER_ACCELERATED);
    if(pRenderer == nullptr)
    {
        logError();
        SDL_DestroyWindow(pWindow);
        SDL_Quit();
    }
    log("Renderer Created Successfully!");

    //create the texture that is used to represent our framebuffer
    pTexture = SDL_CreateTexture(pRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, static_cast<int>(m_width), static_cast<int>(m_height));
    if(pTexture == nullptr)
    {
        logError();
        SDL_DestroyRenderer(pRenderer);
        SDL_DestroyWindow(pWindow);
        SDL_Quit();
    }
    SDL_SetTextureBlendMode(pTexture, SDL_BLENDMODE_BLEND); //set blendmode for alpha values to work

    //initialize our raw pixel buffer that is under the control of the user
    buffer = new uint32_t *[m_width];
    for(int i = 0; i < m_width; i++)
    {
        buffer[i] = new uint32_t[m_height];
    }

    log("Texture Created Successfully!");

    log("Initialization Successful!");
}

void Application::run()
{
    for(int i = 0; i < m_width; i++)
    {
        for(int j = 0; j < m_height; j++)
        {
            pPixels[i * m_height + j] = buffer[i][j];
        }
    }

    while(isRunning)
    {
        SDL_UpdateTexture(pTexture, nullptr, pPixels, static_cast<int>(m_width * sizeof(uint32_t)));

        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_EVENT_QUIT:
                isRunning = false;
                break;
            default:
                break;
        }

        //render the texture
        SDL_RenderClear(pRenderer);
        SDL_RenderTexture(pRenderer, pTexture, nullptr, nullptr);
        SDL_RenderPresent(pRenderer);
    }
}

Application::~Application()
{
    SDL_DestroyTexture(pTexture);
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    free(pPixels);
    free(buffer);
    SDL_Quit();
}
