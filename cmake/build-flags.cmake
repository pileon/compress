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

include(CheckCXXCompilerFlag)

if(CMAKE_CXX_COMPILER_ID MATCHES "^(GNU)|(Clang)$")
    include(cmake/build-flags-clang-gcc.cmake)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "^MSVC$")
    # TODO: Implement this sometime
    # include(cmake/BuildFlags-msvc.cmake)
else()
    message(WARNING "Unknown compiler, do not know how to test for specific flags")
endif()

# add_compile_options(${COMPILER_OPTIONS})
string(REPLACE ";" " " CMAKE_REQUIRED_FLAGS "${COMPILER_OPTIONS}")
