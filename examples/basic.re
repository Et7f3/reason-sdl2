external hello_sdl: unit => unit = "hello_sdl";

external resdl_internal_init: (
                  bool,
                  bool,
                  bool,
                  bool,
                  bool,
                  bool,
                  bool,
                  bool) => int = "resdl_init_bytecode"
                                 "resdl_init_native";

let resdl_init = (~audio: bool=false,
                  ~video: bool=true,
                  ~events: bool=true,
                  ~haptic: bool=false,
                  ~timer: bool=false,
                  ~gamecontroller: bool=false,
                  ~joystick: bool=false,
                  ~everything: bool=false,
                  ()) : int => {

    let ret:int = resdl_internal_init(audio, video, events, haptic, timer, gamecontroller, joystick, everything);

    ret
}

external resdl_quit: unit => unit = "resdl_quit";

external resdl_wasinit: int => int = "resdl_wasinit";

module resdl_m_SDL_GLattr = {
  type contents = {
    SDL_GL_RED_SIZE,
    SDL_GL_GREEN_SIZE,
    SDL_GL_BLUE_SIZE,
    SDL_GL_ALPHA_SIZE,
    SDL_GL_BUFFER_SIZE,
    SDL_GL_DOUBLEBUFFER,
    SDL_GL_DEPTH_SIZE,
    SDL_GL_STENCIL_SIZE,
    SDL_GL_ACCUM_RED_SIZE,
    SDL_GL_ACCUM_GREEN_SIZE,
    SDL_GL_ACCUM_BLUE_SIZE,
    SDL_GL_ACCUM_ALPHA_SIZE,
    SDL_GL_STEREO,
    SDL_GL_MULTISAMPLEBUFFERS,
    SDL_GL_MULTISAMPLESAMPLES,
    SDL_GL_ACCELERATED_VISUAL,
    SDL_GL_RETAINED_BACKING,
    SDL_GL_CONTEXT_MAJOR_VERSION,
    SDL_GL_CONTEXT_MINOR_VERSION,
    SDL_GL_CONTEXT_EGL,
    SDL_GL_CONTEXT_FLAGS,
    SDL_GL_CONTEXT_PROFILE_MASK,
    SDL_GL_SHARE_WITH_CURRENT_CONTEXT,
    SDL_GL_FRAMEBUFFER_SRGB_CAPABLE,
    SDL_GL_CONTEXT_RELEASE_BEHAVIOR,
    SDL_GL_CONTEXT_RESET_NOTIFICATION,
    SDL_GL_CONTEXT_NO_ERROR
  }
}

let run = () => {
  /*let _ = hello_sdl();*/
  let _ = resdl_init(~audio=true, ~video=true, ());

  let _ = resdl_wasinit(0);

  let _ = resdl_quit(());
};
