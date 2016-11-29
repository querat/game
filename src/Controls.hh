//
// Controls.hh for  in /home/querat_g/code/oxygine/hello/src
//
// Made by querat_g
//
// Started on  Mon Nov 21 11:05:48 2016 querat_g
// Last update Tue Nov 29 11:23:12 2016 querat_g
//

#ifndef CONTROLS_HH
# define CONTROLS_HH

# include <string>
# include <iostream>
# include <map>
# include "Oxygine.h"

class Controls
{
public:
  Controls();
  ~Controls();

private:
  Controls(Controls const &);

private:
  typedef std::map<SDL_Scancode, int>   t_scanCodeToEventMap;
  t_scanCodeToEventMap                  _map;

public:
  int           loadFromFile(std::string const & path);
  int           saveToFile(std::string const & path);

};

#endif  // !Controls.hh
