# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\mySamp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\mySamp_autogen.dir\\ParseCache.txt"
  "mySamp_autogen"
  )
endif()
