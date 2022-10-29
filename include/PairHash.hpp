#pragma once

/**
* Déclaration hash function pour clé std::pair
* \file   PairHash.hpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include <utility>

struct PairHash
{
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U>& x) const
    {
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};

/*namespace std
{
    template<> struct hash<pair<int, int>>
    {
        size_t operator()(const pair<int, int>& x) const
        {
            return hash<int>()(x.first) ^ hash<int>()(x.second);
        }
    };
}*/
