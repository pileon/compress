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

cmake_minimum_required(VERSION 3.13)
project(compress
        LANGUAGES CXX
        VERSION 0.0.1
        DESCRIPTION "Simple compress library and front-end program"
        HOMEPAGE_URL "https://github.com/pileon/compress")

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

include(CheckIncludeFileCXX)
include(CheckCXXSourceCompiles)

include(cmake/build-flags.cmake)
include(cmake/boost.cmake)
include(cmake/stdc++fs.cmake)

option(use_doxygen "use Doxygen for code reference documentation" ON)
if (${use_doxygen})
    find_package(Doxygen REQUIRED dot)
    if(DOXYGEN_FOUND)
        set(DOXYGEN_PROJECT_NAME "Compress")
        # set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "${PROJECT_SOURCE_DIR}/reference.md")
        set(DOXYGEN_DOT_MULTI_TARGETS YES)
        set(DOXYGEN_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/docs/reference")
        set(DOXYGEN_GENERATE_HTML YES)
        set(DOXYGEN_GENERATE_MAN NO)
        doxygen_add_docs(
                compress-doxygen
                # src src/include "${PROJECT_SOURCE_DIR}/reference.md"
                src src/include
                ALL)
    endif()
endif()
