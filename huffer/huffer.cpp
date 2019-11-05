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
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>
#include <sstream>
#include <deque>
#include <queue>

// This program is to practice Huffman encoding

void huffer(std::istream& input, std::ostream& output);

int main(int argc, char *argv[])
{
    std::cout << "Huffing and a puffing down on Venice Beach...\n";

#if 1
    // For debugging purposes, use a fixed string
    std::istringstream input("A_DEAD_DAD_CEDED_A_BAD_BABE_A_BEADED_ABACA_BED");
    huffer(input, std::cout);
#else
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
#endif

}

struct node
{
    unsigned weight;
    bool isleaf;  // True if this is a leaf node
    unsigned index;  // Index in the collections of nodes

    union
    {
        struct
        {
            char data;
        } leaf;
        struct
        {
            unsigned left;
            unsigned right;
        } interior;
    };
};

std::ostream& operator<<(std::ostream& out, node const& n)
{
    if (n.isleaf)
        return out << "{ " << n.weight << ", " << n.index << ", '" << n.leaf.data << "' }";
    else
        return out << "{ " << n.weight << ", " << n.index  << ", " << n.interior.left << ", " << n.interior.right << '}';
}

inline bool operator<(node const& n1, node const& n2)
{
    return n1.weight > n2.weight;
}

void huffer(std::istream& input, std::ostream& output)
{
    // Lets hope the input file is small enough to fit in memory, because we read it all into memory in one go
    std::vector<char> in((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());

    // Frequency table
    std::unordered_map<char, unsigned> histogram;

    for (auto const ch : in)
        ++histogram[ch];

    // Container of all nodes in the tree
    std::deque<node> nodes;

    // Begin by adding all the leaves
    std::transform(begin(histogram), end(histogram), std::back_inserter(nodes), [&nodes](auto const& pair)
    {
        return node{ .weight = pair.second, .isleaf = true, .index = static_cast<unsigned>(nodes.size()), .leaf = { pair.first }};
    });

    // Debug, print the nodes
    std::cout << "Leaf nodes (not sorted):\n";
    std::copy(begin(nodes), end(nodes), std::ostream_iterator<node>(std::cout, "\n"));

    // Now create the tree with all interior nodes
    std::priority_queue<node> tree(begin(nodes), end(nodes));

    while (tree.size() > 1)
    {
        auto first  = tree.top(); tree.pop();
        auto second = tree.top(); tree.pop();

        node n{ .weight = first.weight + second.weight,
            .isleaf = false,
            .index = static_cast<unsigned>(nodes.size()),
            .interior = { .left = first.index, .right = second.index }
        };

        nodes.push_back(n);

        tree.push(n);
    }

    // Debug, print the nodes
    std::cout << "All nodes (not sorted):\n";
    std::copy(begin(nodes), end(nodes), std::ostream_iterator<node>(std::cout, "\n"));

    // node root = tree.top();

    // Now walk the tree to create the binary left-right data
}
