#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <format>


//#include <boost/archive/text_oarchive.hpp>;
//#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/export.hpp>

//#include <boost/archive/text_woarchive.hpp>
//#include <boost/archive/text_wiarchive.hpp>

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/shared_ptr.hpp>

#include <boost/serialization/version.hpp>
#include <boost/serialization/split_member.hpp>



template <typename T>
T GetCorrectNumber(T min, T max)
{
    T x;
    while ((std::cin >> x).fail() || std::cin.peek() != '\n' || x < min || x > max)
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << std::format("Введите коректное число ({} - {}): ", min, max);
    }
    return x;
}


int ChooseActionMenu(std::vector<std::string>& menu, bool with_exit = true,
    std::string action_text = "Выберете действие: ");