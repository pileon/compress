// Copyright 2019 Joachim Pileborg
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>
#include <fstream>

// This program is to practice Huffman encoding

void huffer(std::istream& input, std::ostream& output);

int main(int argc, char *argv[])
{
    std::cout << "Huffing and a puffing down on Venice Beach...\n";

    // The program can be called in three different ways:
    // 1. Without arguments, input is read from `std::cin` and output is written to `std::cout`
    // 2. With one argument, which is the input file to read, and output is written to `std::cout`
    // 3. With two arguments, which are the input and output files, respectively

    if (argc == 1)
    {
        // No arguments, use standard input and output
        huffer(std::cin, std::cout);
    }
    else if (argc == 2)
    {
        // One argument, naming the input file
        std::ifstream input{argv[1]};
        if (!input)
        {
            std::cerr << "Could not open open input file " << argv[1] << '\n';
            return 1;
        }

        huffer(input, std::cout);
    }
    else if (argc == 3)
    {
        // Two arguments, naming the input and output files
        std::ifstream input{argv[1]};
        if (!input)
        {
            std::cerr << "Could not open open input file " << argv[1] << '\n';
            return 1;
        }

        std::ofstream output{argv[2]};
        if (!input)
        {
            std::cerr << "Could not open open output file " << argv[2] << '\n';
            return 1;
        }

        huffer(input, output);
    }
    else
    {
        std::cerr << "Usage: huffer [input-file] [output-file]\n";
    }
}

void huffer(std::istream& input, std::ostream& output)
{

}
