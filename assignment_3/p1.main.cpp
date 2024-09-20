#include <iostream>
#include <string>

// I dislike using buffers. I would prefer to use strings and string iterators, or at least vectors and vector iterators, but here is the array-based solution.

int main()
{
    const std::string::size_type buffer_length{20}; // The maximum length of the two numbers

    std::string num1_str, num2_str;
    std::cout << "Enter two large numbers:\n";
    std::cin >> num1_str >> num2_str;

    // Length of the two numbers
    std::string::size_type num1_length{num1_str.size()};
    std::string::size_type num2_length{num2_str.size()};

    // Carry flag.
    // Using char instead of bool because they both take 1 byte,
    //  and char facilitates the addition of more than 2 numbers,
    //  if that feature were to be added in the future.
    // In addition, in certain suboptimized compilations,
    //  using char may save anywhere from 1 to 10 clock cycles in the hot loop.
    // This comes from the elimination of a branch.
    // In an optimized scenario, the bool should be treated by the computer as a char and added.
    // If the compiler doesn't optimize the bool, the char will permit a branchless addition.
    // Depending on the scenario, this may save up to 10 cycles per loop,
    //  though likely the branch prediction will train after only a couple loops, making the timesave only 1 cycle.
    char carry = 0;

    // Char buffers. The numbers are stored in reverse order(0 - units digit, 1 - tens digit, etc.)
    // Numerical values are stored: '0' -> 0, '1' -> 1, ..., '9' -> 9
    char* result = new char[buffer_length];
    char* num1 = new char[buffer_length];
    char* num2 = new char[buffer_length];

    std::string::reverse_iterator num1_it = num1_str.rbegin();
    std::string::reverse_iterator num2_it = num2_str.rbegin();

    // Initialization loop
    for (std::string::size_type i = 0; i < buffer_length; ++i)
    {
        if (num1_it != num1_str.rend()) // Copy the first number to an array of integers
        {
            num1[i] = *num1_it - '0';
            ++num1_it;
        }
        else // If the first number is shorter than the second number, fill the remaining digits with 0
        {
            num1[i] = 0;
        }

        if (num2_it != num2_str.rend()) // Copy the second number to an array of integers
        {
            num2[i] = *num2_it - '0';
            ++num2_it;
        }
        else // If the second number is shorter than the first number, fill the remaining digits with 0
        {
            num2[i] = 0;
        }
    }

    // Adder loop
    for (std::string::size_type i = 0; i < buffer_length; ++i)
    {
        char sum = num1[i] + num2[i] + carry;
        if (sum >= 10)
        {
            carry = 1;
            sum -= 10;
        }
        else
        {
            carry = 0;
        }
        result[i] = sum;
    }

    // Print the result
    std::cout << "Sum: ";
    for (std::string::size_type i = buffer_length - 1; i != static_cast<std::string::size_type>(-1); --i) // Static cast the type instead of using "i < buffer_length" in order to the future switching of types without risk of bug. No performance loss.
    {
        // Cycle through leading zeros
        if (result[i] != 0)
        {
            for (std::string::size_type j = i; j != static_cast<std::string::size_type>(-1); --j) // Print Loop (from the first non-zero digit to the last digit)
            {
                std::cout << (char)(result[j] + '0');
            }
            break; // Exit the loop
        }
    }
    std::cout << "\n";

    delete[] num1;
    delete[] num2;
    delete[] result;

    return 0;
}