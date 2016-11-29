//
// Attention!
// This file initializes the Oxygine engine.
// If you just started here and don't understand the code completely, feel free to come back later.
// You can start from example.cpp and example.h, which main functions are called from here.
//

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wreorder"
#include "core/oxygine.h"
#include "Stage.h"
#include "DebugActor.h"
#pragma GCC diagnostic pop

// #include "example.h"
#include "Game.hh"

// This function is called each frame
int mainloop()
{
  // Update engine-internal components
  // If input events are available, they are passed to Stage::instance.handleEvent
  // If the function returns true, it means that the user requested the application to terminate
  bool done = oxygine::core::update();

  // It gets passed to our example game implementation
  // example_update();
  game_update();

  // Update our stage
  // Update all actors. Actor::update will also be called for all its children
  oxygine::getStage()->update();

  if (oxygine::core::beginRendering())
    {
      oxygine::Color clearColor(0, 0, 0, 255);
      oxygine::Rect viewport(oxygine::Point(0, 0),
                             oxygine::core::getDisplaySize());
      // Render all actors inside the stage. Actor::render will also be called for all its children
      oxygine::getStage()->render(clearColor, viewport);

      oxygine::core::swapDisplayBuffers();
    }

  return done ? 1 : 0;
}

// Application entry point
void run()
{
  oxygine::ObjectBase::__startTracingLeaks();

  // Initialize Oxygine's internal stuff
  oxygine::core::init_desc desc;
  desc.title = "Oxygine Application";

#if OXYGINE_SDL || OXYGINE_EMSCRIPTEN
  // The initial window size can be set up here on SDL builds
  desc.w = 960;
  desc.h = 640;
  // Marmalade settings can be modified from the emulator's menu
#endif

  // example_preinit();
  oxygine::core::init(&desc);

  // Create the stage. Stage is a root node for all updateable and drawable objects
  oxygine::Stage::instance = new oxygine::Stage(true);
  oxygine::Point size = oxygine::core::getDisplaySize();
  oxygine::getStage()->setSize(size);

  // DebugActor is a helper actor node. It shows FPS, memory usage and other useful stuff
  oxygine::DebugActor::show();

  // Initializes our example game. See example.cpp
  game_init();
  // example_init();

#ifdef EMSCRIPTEN
  /*
    If you build for Emscripten, mainloop is called automatically and shouldn't be called here.
    See emscripten_set_main_loop in the EMSCRIPTEN section below
  */
  return;
#endif


#if TARGET_OS_IPHONE || TARGET_OS_SIMULATOR
  // On iPhone mainloop is called automatically by CADisplayLink, see int main() below
  return;
#endif

  // This is the main game loop.
  while (1)
    {
      int done = mainloop();
      if (done)
        break;
    }
  /*
    If we get here, the user has requested the Application to terminate.
    We dump and log all our created objects that have not been freed yet
  */
  oxygine::ObjectBase::dumpCreatedObjects();

  /*
    Let's clean up everything right now and call ObjectBase::dumpObjects() again.
    We need to free all allocated resources and delete all created actors.
    All actors/sprites are smart-pointer objects and don't need to be removed by hand.
    But now we want to delete it by hand.
  */

  // See example.cpp for the shutdown function implementation
  // example_destroy();
  game_unload();

  //renderer.cleanup();

  // Releases all internal components and the stage
  oxygine::core::release();

  // The dump list should be empty by now,
  // we want to make sure that there aren't any memory leaks, so we call it again.
  oxygine::ObjectBase::dumpCreatedObjects();

  oxygine::ObjectBase::__stopTracingLeaks();
  //end
}

#ifdef __S3E__
int main(int argc, char* argv[])
{
  run();
  return 0;
}
#endif

#ifdef OXYGINE_SDL

#include "SDL_main.h"
#include "SDL.h"

extern "C"
{

  void one(void* param){
    (void)param;
    mainloop();
  }

  void oneEmsc(){
    mainloop();
  }

  int main(int argc, char* argv[])
  {
    (void)argc, (void)argv;

    run();


#if TARGET_OS_IPHONE || TARGET_OS_SIMULATOR
    // If parameter 2 is set to 1, refresh rate will be 60 fps, 2 - 30 fps, 3 - 15 fps.
    SDL_iPhoneSetAnimationCallback(core::getWindow(), 1, one, nullptr);
#endif

#if EMSCRIPTEN
    emscripten_set_main_loop(oneEmsc, 0, 0);
#endif

    return 0;
  }
};
#endif
