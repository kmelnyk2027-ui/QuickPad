# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QuickPad_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QuickPad_autogen.dir\\ParseCache.txt"
  "QuickPad_autogen"
  )
endif()
