//
// Game.cpp for  in /home/querat_g/code/test/src
//
// Made by querat_g
//
// Started on  Tue Oct 18 11:21:41 2016 querat_g
// Last update Mon Nov 28 14:22:08 2016 querat_g
//

#include <cassert>

#include "Oxygine.h"
#include "Definitions.h"
#include "Game.hh"
#include "Entity.hh"
#include "Player.hh"

static Game *g_game = 0;

Game *
getGame(){
  ASSERTMSG(g_game != 0x0,
            "No Game object was instanciated "
            "before calling getGame()");
  return (g_game);
}

void
game_init(){
  spGame game = new Game();

  game->attachTo(oxygine::getStage());
}

void game_unload(){}
void game_update(){}

Game::Game(){
  g_game = this;
  oxygine::key::init();

  this->_resources.loadXML("res.xml");

  this->unitList.push_back(new Player());

  // spSprite sprite = new oxygine::Sprite();
  // sprite->setResAnim(this->_resources.getResAnim("anim"));
  // this->addChild(sprite);

  // oxygine::intrusive_ptr<MainAct> actor = new MainAct;

  // oxygine::getStage()->addChild(actor);

}

Game::~Game(){
  this->_resources.free();
}

oxygine::Resources *
Game::getResources(){
  return (&this->_resources);
}

void
Game::doUpdate(const UpdateState &us)
{

#ifdef MY_DEBUG
  COUT("tick: " << us.dt << " ms");
#endif

  for (t_entitiesList::iterator it = Game::unitList.begin();
       it != Game::unitList.end();
       ++it)
    {
      (*it)->updateStatus(us);
    }

} // !Game::update()
