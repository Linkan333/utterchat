# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\utterchat_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\utterchat_autogen.dir\\ParseCache.txt"
  "utterchat_autogen"
  )
endif()
