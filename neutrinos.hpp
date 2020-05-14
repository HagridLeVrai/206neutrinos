/*
** EPITECH PROJECT, 2018
** character.hpp
** File description:
** day09
*/

#ifndef NEUTRINOS_HPP_
#define NEUTRINOS_HPP_

#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <cmath>

using namespace std;

class Values
{
public:
    Values(int ac, char **av);
    ~Values();

    //funcs
    void loop();
    void calc(double input);
    void print_result(double z);

    //ressources
    double n;
    double a;
    double h;
    double sd;
};

#endif
