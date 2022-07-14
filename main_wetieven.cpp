#include <iostream> // for testing
#include <cassert> // for testing

//#include "pair.hpp"
#include "inc/ft_utility.hpp"

const std::string bool_to_str(const bool result)
{
    return (result ? "TRUE" : "FALSE");
}

template <typename any_pair>
void print_pair(any_pair p)
{
    std::cout << '|' << p.first << "| : |" << p.second << '|' << std::endl;
}

int main(int argc, char *argv[]) {

    (void)argc;
    (void)argv;

    std::cout << "[ PAIR ]\n" << std::endl;

    std::cout << "--- Parametric constructor ---\n" << std::endl;

    std::cout << "pair<int, float> a(42, 3.14);" << std::endl;
    std::cout << "v" << std::endl;
    ft::pair<int, float> a(42, 3.14);
    std::cout << std::endl;

    std::cout << "print_pair(a);" << std::endl;
    std::cout << "v" << std::endl;
    print_pair(a);
    std::cout << std::endl;

    std::cout << "--- Copy constructor ---\n" << std::endl;

    std::cout << "pair<float, double> b(a);" << std::endl;
    std::cout << "v" << std::endl;
    ft::pair<float, double> b(a);
    std::cout << std::endl;

    std::cout << "print_pair(b);" << std::endl;
    std::cout << "v" << std::endl;
    print_pair(b);
    std::cout << std::endl;

    std::cout << "pair<char, double> c(a);" << std::endl;
    std::cout << "v" << std::endl;
    ft::pair<char, double> c(a);
    std::cout << std::endl;

    std::cout << "print_pair(c);" << std::endl;
    std::cout << "v" << std::endl;
    print_pair(c);
    std::cout << std::endl;

    std::cout << "--- Default constructor ---\n" << std::endl;

    std::cout << "pair<int, float> dflt;" << std::endl;
    std::cout << "v" << std::endl;
    ft::pair<int, float> dflt;
    std::cout << std::endl;

    std::cout << "--- Assignment operator ---\n" << std::endl;

    std::cout << "dflt = c;" << std::endl;
    std::cout << "v" << std::endl;
    dflt = c;
    std::cout << std::endl;

    std::cout << "print_pair(dflt);" << std::endl;
    std::cout << "v" << std::endl;
    print_pair(dflt);
    std::cout << std::endl;

    std::cout << "--- Comparison operators ---\n" << std::endl;

    std::cout << "assert(dflt == a);" << std::endl;
    std::cout << "v" << std::endl;
    assert(dflt == a);
    std::cout << std::endl;

    std::cout << "pair<char, char> ab('a', 'b');" << std::endl;
    std::cout << "v" << std::endl;
    ft::pair<char, char> ab('a', 'b');
    std::cout << std::endl;

    std::cout << "pair<char, char> ab2('a', 'b');" << std::endl;
    std::cout << "v" << std::endl;
    ft::pair<char, char> ab2('a', 'b');
    std::cout << std::endl;

    std::cout << "pair<char, char> ac('a', 'c');" << std::endl;
    std::cout << "v" << std::endl;
    ft::pair<char, char> ac('a', 'c');
    std::cout << std::endl;

    std::cout << "pair<char, char> bb('b', 'b');" << std::endl;
    std::cout << "v" << std::endl;
    ft::pair<char, char> bb('b', 'b');
    std::cout << std::endl;

    std::cout << "assert(ab != ac);" << std::endl;
    assert(ab != ac);

    std::cout << "assert(ab < ac);" << std::endl;
    assert(ab < ac);

    std::cout << "assert(!(ab2 < ab));" << std::endl;
    assert(!(ab2 < ab));

    std::cout << "assert(!(ac < ab));" << std::endl;
    assert(!(ac < ab));

    // std::cout << "std::cout << bool_to_str(ab > ac) << std::endl;" << std::endl;
    // std::cout << "v" << std::endl;
    // std::cout << bool_to_str(ab > ac) << std::endl;
    // std::cout << std::endl;

    std::cout << "assert(bb > ab);" << std::endl;
    assert(bb > ab);

    std::cout << "assert(ab <= ac);" << std::endl;
    assert(ab <= ac);

    std::cout << "assert(ab <= ab2);" << std::endl;
    assert(ab <= ab2);

    std::cout << "assert(ac <= bb);" << std::endl;
    assert(ac <= bb);

    std::cout << "assert(ab >= ab2);" << std::endl;
    assert(ab >= ab2);

    std::cout << "assert(bb >= ab);" << std::endl;
    assert(bb >= ab);

    return 0;
}