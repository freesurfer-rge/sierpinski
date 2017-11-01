CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(Sierpinski)

# -----------

SET(CMAKE_CXX_FLAGS "-g -std=c++11 -Wall -Wextra -Werror -Wno-unused-local-typedef -Wno-unused-parameter")

# -----------

set(Boost_USE_STATIC_LIBS ON)
FIND_PACKAGE( Boost 1.59.0 REQUIRED )
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

# ------------

INCLUDE_DIRECTORIES( ./include )

ADD_SUBDIRECTORY( src )
ADD_SUBDIRECTORY( tst )
