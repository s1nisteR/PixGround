//
// Created by s1nister on 3/7/24.
//

#ifndef APPLICATION_H
#define APPLICATION_H

#include "../vendor/SDL/include/SDL3/SDL.h"
#include <utility>


class Application {
public:
    Application(uint32_t width, uint32_t height, const char* windowTitle);
    void run();
    [[nodiscard]] uint32_t **getBuffer() { return buffer; }
    ~Application();

private:
    uint32_t m_width;
    uint32_t m_height;
    bool isRunning;
    const char* m_windowTitle;
    uint32_t *pPixels;
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
    SDL_Texture *pTexture;
    uint32_t **buffer; //raw buffer that is under the control of the user
    SDL_Event event{};
};



#endif //APPLICATION_H
