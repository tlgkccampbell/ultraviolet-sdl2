/*
 SDL_dynamic_main.c
 */
#include "../../SDL_internal.h"

/* Include the SDL main definition header */
#include "SDL_main.h"

#ifdef SDL_DYNAMIC_MAIN

static SDL_DynamicMain SDL_dynamic_main_fn;

void 
SDL_SetDynamicMain(SDL_DynamicMain proc)
{
    SDL_dynamic_main_fn = proc;
}

SDL_DynamicMain
SDL_GetDynamicMain()
{
    return SDL_dynamic_main_fn;
}

int
SDL_RunDynamicMain()
{
    if (SDL_dynamic_main_fn)
    {
        return SDL_dynamic_main_fn();
    }
    return 1;
}

#ifdef __cplusplus
extern "C"
#endif
int SDL_main(int argc, char *argv[])
{
    /*
     * Note that we don't pass any arguments to our main; this is because
     * it's safe to assume, given that you're using the dynamic main at all,
     * that you already have access to them in whatever code initialized this.
     */
    SDL_RunDynamicMain();
}

#endif /* SDL_DYNAMIC_MAIN */

/* vi: set ts=4 sw=4 expandtab: */
