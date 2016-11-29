//
// Definitions.h for  in /home/querat_g/code/oxygine/hello/src
//
// Made by querat_g
//
// Started on  Tue Nov 15 09:09:02 2016 querat_g
// Last update Tue Nov 29 11:43:31 2016 querat_g
//

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# include <iostream>

# define COUT(...)              std::cout << __VA_ARGS__ << std::endl
# define CERR(...)              std::cerr << __VA_ARGS__ << std::endl

# ifdef MY_DEBUG
#  define DEBUG(...)            std::cerr << __VA_ARGS__ << std::endl
# else
#  define DEBUG(...)            {}
# endif  // MY_DEBUG

# define ASSERTMSG(a, ...)      assert(a && __VA_ARGS__)

#endif  // !Definitions.h
