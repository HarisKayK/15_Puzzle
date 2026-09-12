#include <ios>
#include <iostream>
#include <limits>

constexpr int g_consoleLines{ 15 };

class Tile
{

private:
    int m_tileValue{ 0 };

public:
    // Default Constructor
    Tile() = default;

    // Constructor
    explicit Tile(int value) : m_tileValue(value) {}

    // Overloader
    friend std::ostream& operator<<(std::ostream& out, const Tile& tile)
    {
        if (tile.getNum() > 9)
        {
            out << " " << tile.getNum() << " ";
        }
        else if (tile.getNum() > 0)
        {
            out << "  " << tile.getNum() << " ";
        }
        else if (tile.isEmpty())
        {
            out << "   ";
        }

        return out;
    }


    // Member Functions
    bool isEmpty() const
    {
        return m_tileValue == 0;
    }

    int getNum() const { return m_tileValue; }
};

class Board
{

private:
    static constexpr int m_size{4};
    Tile m_grid[m_size][m_size]
    {
        Tile{1}, Tile{2}, Tile{3}, Tile{4},
        Tile{5}, Tile{6}, Tile{7}, Tile{8},
        Tile{9}, Tile{10}, Tile{11}, Tile{12},
        Tile{13}, Tile{14}, Tile{15}, Tile{0},
    };

public:

    // Constructor
    Board() = default;

    // Overloaded Operator
    friend std::ostream& operator<<(std::ostream& out, const Board& board)
    {
        for (int i{ 0 }; i < g_consoleLines; ++i)
        {
            out << '\n';
        }

        for (int row{ 0 }; row < m_size; ++row)
        {
            for (int col{ 0 }; col < m_size; ++col)
            {
                out << board.m_grid[row][col];
            }

            out << '\n';
        }

        return out;
    }

};

namespace UserInput
{
    char getCommand()
    {
        char user_input{};
        std::cin >> user_input;
        return user_input;
    }
}

int main()
{
    Board board{};
    std::cout << board;

    while (true)
    {
        char command{ UserInput::getCommand() };

        if (command == 'q') break;
        
        switch (command)
        {
            case 'w':
            case 'a':
            case 's':
            case 'd':
            std::cout << "Valid command: " << command << '\n';
            break;
            default: continue;
        }
    }

    std::cout << "\n\nBye!\n";

    return 0;
}
