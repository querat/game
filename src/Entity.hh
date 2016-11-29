//
// Entity.hh for  in /home/querat_g/code/oxygine/ship/src
//
// Made by querat_g
//
// Started on  Tue Nov  8 09:57:51 2016 querat_g
// Last update Mon Nov 14 15:47:50 2016 querat_g
//

#ifndef ENTITY_HH
# define ENTITY_HH

# include "Oxygine.h"

using namespace oxygine;
DECLARE_SMART(Entity, spEntity);

class Entity : public Object
{
public:
  Entity();
  ~Entity();

public:
  virtual void  updateStatus(const UpdateState &us) = 0;

private:
  bool  _shouldBeDeleted;
};


#endif  // !Entity.hh
