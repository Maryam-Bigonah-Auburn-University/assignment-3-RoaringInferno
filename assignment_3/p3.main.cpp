#include <iostream>
#include <string>
#include <vector>
#include <map>

/**
 * std::map was tailor-made for this problem, and makes the solution trivial.
 * 
 * A solution without using a map would be solved as follows:
 * - Read into the buffer
 * - Sort the buffer, ideally shrinking it at the same time.
 * - Iterate through the buffer with a counter, incrementing every number
 * - Every time a number is different from the previous number, print the previous number and the counter
 * * In the case that the formatting is dependent on the list, simply store the numbers and the counts in a vector, holding order.
 * * Gather data simultaneous to the accounting loop, and print at the end.
 * - Flush output buffer, if necessary. Free memory.
 */

std::string generate_left_justified(std::string str, std::size_t width)
{
    if (str.size() >= width)
    {
        return str;
    }
    return str + std::string(width - str.size(), ' ');
}

int main()
{
    std::map<int, unsigned int> numbers;
    while (true) // Get numbers from the user
    {
        std::cout << "Enter a number or 'q' to quit: ";
        std::string input;
        std::cin >> input;
        if (input == "q")
        {
            break;
        }
        numbers[stoi(input)]++;
    }

    // Table string generation
    std::vector<std::string> rows(numbers.size());
    std::vector<std::string>::iterator row_it = rows.begin();
    for (const auto &pair : numbers)
    {
        *row_it = generate_left_justified(std::to_string(pair.first), 10) + "|" + generate_left_justified(std::to_string(pair.second), 10);
        ++row_it;
    }

    // Print the rows in reverse(descending) order
    std::vector<std::string>::reverse_iterator it = rows.rbegin();
    for (; it != rows.rend(); ++it)
    {
        std::cout << *it << "\n";
    }

    return 0;
}