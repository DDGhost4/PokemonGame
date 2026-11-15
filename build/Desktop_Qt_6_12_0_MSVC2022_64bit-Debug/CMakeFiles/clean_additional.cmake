# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PokemonGame_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PokemonGame_autogen.dir\\ParseCache.txt"
  "PokemonGame_autogen"
  )
endif()
