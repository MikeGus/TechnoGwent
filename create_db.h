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


void create_db(std::ostream& output);


#endif // CREATE_DB_H
