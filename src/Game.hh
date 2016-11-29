//
// Game.hh for  in /home/querat_g/code/test/src
//
// Made by querat_g
//
// Started on  Tue Oct 18 11:20:17 2016 querat_g
// Last update Tue Nov 15 15:09:20 2016 querat_g
//

#ifndef GAME_HH
# define GAME_HH

# include "Oxygine.h"
# include <list>

using namespace oxygine;

DECLARE_SMART(Entity, spEntity);
DECLARE_SMART(Game, spGame);

void game_init();
void game_unload();
void game_update();
Game *getGame(void);

class Game : public Actor
{

public:
  Game();
  ~Game();

private:
  typedef std::list<spEntity> t_entitiesList;
  t_entitiesList        unitList;

  oxygine::Resources    _resources;

public:
  void                          doUpdate(const UpdateState &us);
  oxygine::Resources *          getResources(void);

}; // !Game


#endif  // !Game.hh
