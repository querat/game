//
// Player.cpp for  in /home/querat_g/code/oxygine/hello/src
//
// Made by querat_g
//
// Started on  Wed Nov 23 14:13:23 2016 querat_g
// Last update Wed Nov 23 16:27:57 2016 querat_g
//

#include "Oxygine.h"
#include "Definitions.h"
#include "Game.hh"
#include "Player.hh"

Player::Player()
{
  this->setSize(oxygine::Vector2(32, 32));
  this->setPosition(oxygine::Vector2(0, oxygine::getStage()->getSize().y / 2));
  this->setResAnim(getGame()->getResources()->getResAnim("button"));
  getGame()->addChild(this);
}

Player::~Player() {

}

void
Player::updateStatus(const UpdateState &us){
  const uint8_t *keyStateArray = SDL_GetKeyboardState(0);

  if (keyStateArray[SDL_SCANCODE_W]){
    COUT(SDL_GetKeyName(SDL_GetKeyFromScancode(SDL_SCANCODE_W)));
    this->_direction = Player::UP;
  }
  else if (keyStateArray[SDL_SCANCODE_S]){
    COUT(SDL_GetKeyName(SDL_GetKeyFromScancode(SDL_SCANCODE_S)));
    this->_direction = Player::DOWN;
  }
  else if (keyStateArray[SDL_SCANCODE_A]){
    COUT(SDL_GetKeyName(SDL_GetKeyFromScancode(SDL_SCANCODE_A)));
    this->_direction = Player::LEFT;
  }
  else if (keyStateArray[SDL_SCANCODE_D]){
    COUT(SDL_GetKeyName(SDL_GetKeyFromScancode(SDL_SCANCODE_D)));
    this->_direction = Player::RIGHT;
  }

  bool  neg = (this->_direction == Player::UP || this->_direction == Player::LEFT);
  bool  vertical = (this->_direction == Player::UP || this->_direction == Player::DOWN);

  if (vertical){
    this->setPosition(this->getPosition() + oxygine::Vector2(0, neg ? (-this->_speed) : (this->_speed)));
  }
  else {
    this->setPosition(this->getPosition() + oxygine::Vector2((neg ? (-this->_speed) : (this->_speed)), 0));
  }
  //this->doUpdate(us);
}
