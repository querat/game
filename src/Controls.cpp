//
// Controls.cpp for  in /home/querat_g/code/oxygine/hello/src
//
// Made by querat_g
//
// Started on  Mon Nov 21 11:12:10 2016 querat_g
// Last update Tue Nov 29 11:44:31 2016 querat_g
//

#include <fstream>
#include "Definitions.h"
#include "Controls.hh"

Controls::Controls()
{}

Controls::~Controls(){}

Controls::Controls(Controls const & other){
  // private
}

int
loadFromFile(std::string const & path) {

  std::fstream  file(path.c_str());

  if (file)
    {
      DEBUG("opened file '" << path << "'");

      return (0);
    }

  CERR("Couldn't open file '" << path << "'");
  return (-1);
}

int saveToFile(std::string const & path) {


  return (0);
}
