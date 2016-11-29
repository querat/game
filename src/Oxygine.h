//
// OxygineWrap.h for  in /home/querat_g/code/oxygine/hello/src
//
// Made by querat_g
//
// Started on  Mon Nov 14 15:16:16 2016 querat_g
// Last update Mon Nov 14 16:12:07 2016 querat_g
//

#ifndef OXYGINE_H
# define OXYGINE_H

// I don't want a sea of warnings in my code because of a framework
// Seems to be working for both clang++ and g++

// save context
# pragma GCC diagnostic push

// disable warnings in new context
# pragma GCC diagnostic ignored "-Wall"
# pragma GCC diagnostic ignored "-Wextra"
# pragma GCC diagnostic ignored "-Wunused-parameter"
# pragma GCC diagnostic ignored "-Wreorder"

// Incriminated framework file
# include "oxygine-framework.h"

// restore context, warnings enabled again for further code
# pragma GCC diagnostic pop

#endif // !Oxygine.h
