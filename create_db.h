#ifndef CREATE_DB_H
#define CREATE_DB_H

#include <iostream>
#include <fstream>

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

#include "commander.h"
#include "fighter.h"
#include "modificator.h"
#include "maniac.h"

#include <ctime>
#include <random>


void generate_db(std::ostream& output)
{
    pt::ptree root;
    pt::ptree array;

    srand(time(NULL));

    // pass
    for (int i = 0; i < 1; ++i) {
        pt::ptree child;
        child.put("id", 0);
        child.put("role", 0);
        child.put("alliance", 0);
        child.put("row", 0);

        array.push_back(std::make_pair("", child));
    }

    // modificators
    for (int i = 1; i <= 6; ++i) {
        pt::ptree child;
        child.put("id", i);
        child.put("role", 1);
        child.put("alliance", 0);
        child.put("row", 0);

        if (i == 6) {
            child.put("multiplicator", 2);
        }
        else {
            child.put("multiplicator", 0);
        }

        array.push_back(std::make_pair("", child));
    }
    // fighters
    for (int i = 7; i <= 27; ++i) {
        pt::ptree child;

        child.put("id", i);
        child.put("role", 2);
        child.put("alliance", i % 3 + 1);
        child.put("row", i % 4 + 1);

        child.put("strength", rand() % 15 + 1);
        child.put("golden", (i % 3 == 0));
        child.put("rat", false);
        child.put("effect", 0);

        array.push_back(std::make_pair("", child));
    }
    // maniacs
    for (int i = 28; i < 34; ++i) {
        pt::ptree child;

        child.put("id", i);
        child.put("role", 3);
        child.put("alliance", i % 3 + 1);
        child.put("row", i % 2 + 1);

        child.put("strength", rand() % 15 + 1);
        child.put("min_strength", rand() % 4);

        array.push_back(std::make_pair("", child));
    }

    // commander
    for (int i = 34; i < 37; ++i) {
        pt::ptree child;

        child.put("id", i);
        child.put("role", 4);
        child.put("alliance", i % 3 + 1);
        child.put("row", 0);

        child.put("ability", i % 3);

        array.push_back(std::make_pair("", child));
    }

    root.add_child("cards", array);

    pt::write_json(output, root);

}

#endif // CREATE_DB_H
