SET( srcs test.cpp )
LIST(APPEND srcs basictests.cpp)

SET( Sierpinski_Lib sierpinski )

ADD_EXECUTABLE(TestSierpinski ${srcs})

INCLUDE_DIRECTORIES( ${Sierpinski_SOURCE_DIR}/include )

TARGET_LINK_LIBRARIES( TestSierpinski ${Boost_LIBRARIES} ${Sierpinski_Lib})
