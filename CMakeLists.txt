cmake_minimum_required (VERSION 2.6)
project (hello)

add_subdirectory(./lib/oxygine-framework/ oxygine-framework)
add_definitions(${OXYGINE_DEFINITIONS})
include_directories(${OXYGINE_INCLUDE_DIRS})
link_directories(${OXYGINE_LIBRARY_DIRS})

set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OXYGINE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# 3 hours lost because cmake decided it would be a piece of s***
CMAKE_POLICY(SET CMP0012 NEW)
CMAKE_POLICY(SET CMP0013 NEW)
CMAKE_POLICY(SET CMP0014 NEW) 

# debug options
if( "${MY_DEBUG}" )
  message("Adding -DMY_DEBUG flag")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DMY_DEBUG")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused -Wno-unused-parameter")
else()
  message("Release Build: Removing Assertions")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNDEBUG")
endif()

add_executable(  
  hello  

  src/Definitions.h

  src/main.cpp

  src/Game.hh
  src/Game.cpp

  src/Entity.hh
  src/Entity.cpp

  src/Player.cpp
  src/Player.hh

  src/Controls.hh
  src/Controls.cpp

  )

target_link_libraries(hello ${OXYGINE_CORE_LIBS})

if (WIN32) #disable console mode for VC++
	set_target_properties(hello PROPERTIES WIN32_EXECUTABLE TRUE)
endif(WIN32)

if (EMSCRIPTEN)
	SET(CMAKE_EXECUTABLE_SUFFIX ".html")	
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s NO_EXIT_RUNTIME=1 -s WARN_ON_UNDEFINED_SYMBOLS=1 --memory-init-file 0 -s TOTAL_MEMORY=50331648")
	em_link_pre_js(hello  ${OXYGINE_JS_LIBRARIES}  ${CMAKE_CURRENT_SOURCE_DIR}/data.js)
endif(EMSCRIPTEN)