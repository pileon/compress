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

set(SOURCE_FILES huffer.cpp)

add_executable(huffer ${SOURCE_FILES})
target_compile_definitions(huffer PRIVATE BOOST_LOG_DYN_LINK)
target_compile_options(huffer PRIVATE ${COMPILER_OPTIONS} -Werror -Wno-error=unused-parameter)
target_compile_features(huffer PRIVATE cxx_range_for cxx_std_20)
target_include_directories(huffer PRIVATE ${CMAKE_SOURCE_DIR}/src/include Boost::headers)
target_link_libraries(huffer Threads::Threads Boost::program_options GCC::stdcxxfs)
