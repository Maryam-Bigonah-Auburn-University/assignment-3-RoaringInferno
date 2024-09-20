#include <iostream>
#include <string>
#include <array>


/**
 * I used a template. If I were writing this for a real-world application, I would not program a template.
 * I would use a vector, programming typedefs for the row and seat index types, both to be space-efficient
 *  and to make the code more readable and easier to maintain.
 * If space efficiency were of great concern, I would use a bitset or bitmasking with an array of unsigned ints.
 */
template<std::size_t Rows, std::size_t Seats>
class AirplaneSeatingChart
{
    // 2D array to store the seating chart
    // The array is initialized to false, indicating that all seats are empty.
    // True if taken
    std::array<std::array<bool, Seats>, Rows> seating_chart;
public:
    AirplaneSeatingChart()
    {
        for (std::size_t i = 0; i < Rows; ++i)
        {
            for (std::size_t j = 0; j < Seats; ++j)
            {
                seating_chart[i][j] = false;
            }
        }
    }
    void take_seat(std::size_t row, std::size_t seat)
    {
        seating_chart[row][seat] = true;
    }
    bool is_vacant(std::size_t row, std::size_t seat) const
    {
        return !seating_chart[row][seat];
    }
    bool no_seats_left() const
    {
        for (std::size_t i = 0; i < Rows; ++i)
        {
            for (std::size_t j = 0; j < Seats; ++j)
            {
                if (seating_chart[i][j] == false)
                {
                    return false;
                }
            }
        }
        return true;
    }

    std::string get_display_string()
    {
        std::string display_string;
        for (std::size_t i = 0; i < Rows; ++i)
        {
            display_string += std::to_string(i+1);
            for (std::size_t j = 0; j < Seats; ++j)
            {
                display_string += ' ';
                if (is_vacant(i, j))
                {
                    display_string += 'A' + j;
                }
                else
                {
                    display_string += 'X';
                }
            }
            display_string += '\n';
        }
        return display_string;
    }
};

int main()
{
    const unsigned int Rows = 7;
    const unsigned int Seats = 4;

    AirplaneSeatingChart<Rows, Seats> airplane_seating_chart;
    while (true)
    {
        std::cout << airplane_seating_chart.get_display_string();
        std::cout << "Enter the row and seat number (e.g. 1A) or 'q' to quit: ";
        std::string input;
        std::cin >> input;
        if (input == "q")
        {
            break;
        }
        if (input.size() != 2)
        {
            std::cout << "Invalid input. Please enter the row and seat number (e.g. 1A) or 'q' to quit." << std::endl;
            continue;
        }
        unsigned int row = input[0] - '1';
        unsigned int seat = input[1] - 'A';
        if (row >= Rows || seat >= Seats)
        {
            std::cout << "Invalid input. Please enter the row and seat number (e.g. 1A) or 'q' to quit." << std::endl;
            continue;
        }
        if (!airplane_seating_chart.is_vacant(row, seat))
        {
            std::cout << "Seat " << input << " is already taken. Please choose another seat." << std::endl;
            continue;
        }
        std::cout << "Seat " << input << " is successfully reserved." << std::endl;
        airplane_seating_chart.take_seat(row, seat);

        if (airplane_seating_chart.no_seats_left())
        {
            std::cout << "All seats are taken." << std::endl;
            break;
        }
    }

    return 0;
}