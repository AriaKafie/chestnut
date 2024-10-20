
#include "debug.h"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <random>

#include "movegen.h"
#include "moveordering.h"
#include "position.h"
#include "transpositiontable.h"
#include "uci.h"

extern RepInfo repetition_table[];

template<bool Root, Color SideToMove>
uint64_t PerfT(int depth)
{
    if (depth == 0)
        return 1;

    MoveList<SideToMove> moves;

    if (depth == 1 && !Root)
        return moves.size();

    uint64_t count, nodes = 0;
    
    for (Move m : moves)
    {
        do_move<SideToMove>(m);
        count = PerfT<false, !SideToMove>(depth - 1);
        undo_move<SideToMove>(m);

        nodes += count;

        if (Root)
            std::cout << move_to_uci(m) << ": " << count << std::endl;
    }

    return nodes;
}

void Debug::perft(std::istringstream& is)
{
    int   depth;
    is >> depth;

    auto start = std::chrono::steady_clock::now();
    uint64_t result = Position::white_to_move() ? PerfT<true, WHITE>(depth)
                                                : PerfT<true, BLACK>(depth);
    auto end   = std::chrono::steady_clock::now();

    std::cout << "\nnodes searched: " << result << "\nin "
              << (std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000) << " ms\n" << std::endl;
}

std::string Debug::rep_table_to_string()
{
    std::stringstream ss;
    std::string s = "+------------------+------+----+";

    ss << s << "\n| key              | loc  | #  |\n" << s << "\n";

    for (int i = 0; i < RT_SIZE; i++)
        if (RepInfo& ri = repetition_table[i]; ri.occurrences)
        {
            ss << "| " << std::setw(16) << std::setfill('0') << std::hex << std::uppercase << ri.key;
            ss << " | " << std::setw(4) << std::setfill('0') << std::hex << std::uppercase << i;
            ss << " | " << std::setw(2) << std::setfill('0') << std::dec << (int(ri.occurrences)) << " |\n" << s << "\n";
        }

    return ss.str();
}

void Debug::go()
{
    std::cout << rep_table_to_string() << std::endl;
}

void Debug::gameinfo() {

    if (RepetitionTable::draw())
    {
        std::cout << "draw" << std::endl;
        return;
    }

    for (int i = 0, count = 0; i < RT_SIZE; i++)
    {
        const RepInfo& ri = repetition_table[i];
    
        if (ri.occurrences)
            count += ri.occurrences;

        if (count >= 100)
        {
            std::cout << "draw" << std::endl;
            return;
        }
    }

    if (Position::white_to_move())
    {
        MoveList<WHITE> moves;

        if      (moves.size())     std::cout << "nonterminal" << std::endl;
        else if (moves.in_check()) std::cout << "mate"        << std::endl;
        else                       std::cout << "draw"        << std::endl;
    }
    else
    {
        MoveList<BLACK> moves;

        if      (moves.size())     std::cout << "nonterminal" << std::endl;
        else if (moves.in_check()) std::cout << "mate"        << std::endl;
        else                       std::cout << "draw"        << std::endl;
    }
}
