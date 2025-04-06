# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "BookParser_autogen"
  "CMakeFiles\\BookParser_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\BookParser_autogen.dir\\ParseCache.txt"
  )
endif()
