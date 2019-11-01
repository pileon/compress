# Copyright 2019 Joachim Pileborg
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    check_cxx_compiler_flag(-D_DEBUG HAVE_FLAG_DDEBUG)
    if(HAVE_FLAG_DDEBUG)
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")
    endif()
    check_cxx_compiler_flag(-O0 HAVE_FLAG_O0)
    if(HAVE_FLAG_O0)
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
    endif()
endif()

# Check for supported warning flags
check_cxx_compiler_flag(-Wall HAVE_FLAG_WALL)
if(HAVE_FLAG_WALL)
    list(APPEND COMPILER_OPTIONS -Wall)
endif()
check_cxx_compiler_flag(-Wextra HAVE_FLAG_WEXTRA)
if(HAVE_FLAG_WEXTRA)
    list(APPEND COMPILER_OPTIONS -Wextra)
endif()
#check_cxx_compiler_flag(-Weffc++ HAVE_FLAG_WEFFCXX)
#if(HAVE_FLAG_WEFFCXX)
#    list(APPEND COMPILER_OPTIONS -Weffc++)
#endif()
check_cxx_compiler_flag(-Wpedantic HAVE_FLAG_WPEDANTIC)
if(HAVE_FLAG_WPEDANTIC)
    list(APPEND COMPILER_OPTIONS -Wpedantic)
else()
    check_cxx_compiler_flag(-pedantic HAVE_FLAG_PEDANTIC)
    if(HAVE_FLAG_PEDANTIC)
        list(APPEND COMPILER_OPTIONS -pedantic)
    endif()
endif()
check_cxx_compiler_flag(-Wimplicit-fallthrough HAVE_FLAG_WIMPLICIT_FALLTHROUGH)
if(HAVE_FLAG_WIMPLICIT_FALLTHROUGH)
    list(APPEND COMPILER_OPTIONS -Wimplicit-fallthrough)
endif()

# Check for other miscellaneous flags
check_cxx_compiler_flag(-pipe HAVE_FLAG_PIPE)
if(HAVE_FLAG_PIPE)
    list(APPEND COMPILER_OPTIONS -pipe)
endif()

option(enable_concepts "set to ON to enable C++ concepts TS" OFF)
if(${enable_concepts})
    # This flag is for enable the concept TS
    check_cxx_compiler_flag(-fconcepts HAVE_FLAG_FCONCEPTS)
    if(HAVE_FLAG_FCONCEPTS)
        list(APPEND COMPILER_OPTIONS -fconcepts)
    endif()
endif()

# TODO: Modules?
