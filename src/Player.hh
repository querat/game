//
// Created by querat_g on 12/11/16.
//

#ifndef player_hh
#define player_hh

#include "Oxygine.h"
#include "Entity.hh"

class Player : public Entity, public oxygine::Sprite
{
public:
  Player();
  ~Player();

public:
  enum Direction {
    UP
    , DOWN
    , LEFT
    , RIGHT
  };

private:
  const static int      _speed = 2;
  enum Direction        _direction;

public:
  void                  updateStatus(const UpdateState &us);

};


#endif // ! Player.hh
