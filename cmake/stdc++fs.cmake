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

add_library(GCC::stdcxxfs STATIC IMPORTED)
if(HAVE_LIBSTDCXXFS)
    set_target_properties(GCC::stdcxxfs
            PROPERTIES IMPORTED_LOCATION ${HAVE_LIBSTDCXXFS})
elseif(CMAKE_CXX_COMPILER_ID MATCHES "^(GNU)$" AND "${CMAKE_CXX_COMPILER_VERSION}" VERSION_LESS "10")
    message(STATUS "Looking for library stdc++fs")

    string(REGEX MATCH "^([0-9]+)" gcc_major_version "${CMAKE_CXX_COMPILER_VERSION}")
    math(EXPR bits "8*${CMAKE_SIZEOF_VOID_P}")

    if(WIN32)
        if(MINGW)
            set(path_hint "C:\\msys64\\mingw64\\lib\\gcc\\x86_64-w64-mingw32\\${CMAKE_CXX_COMPILER_VERSION}")
        endif()
    else()
        set(path_hint "/usr/lib/gcc/x86_64-linux-gnu/${gcc_major_version}")
        if(bits EQUAL 32)
            set(path_hint_32 "/usr/lib/gcc/x86_64-linux-gnu/${gcc_major_version}/32")
        endif()
    endif()

    find_library(HAVE_LIBSTDCXXFS stdc++fs
            PATHS "${path_hint}" "${path_hint_32}")
    if(HAVE_LIBSTDCXXFS)
        set_target_properties(GCC::stdcxxfs
                PROPERTIES IMPORTED_LOCATION ${HAVE_LIBSTDCXXFS})
        message(STATUS "Looking for library stdc++fs - found")
    endif()
endif()
