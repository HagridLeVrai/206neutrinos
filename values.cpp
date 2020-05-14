/*
** EPITECH PROJECT, 2019
** [name]
** File description:
** main.c for the [name]
*/

#include "neutrinos.hpp"

static void err(string error_txt)
{
    cerr << "ERROR: " << error_txt << endl;
    exit (84);
}

static void print_help()
{
    cout << "USAGE" << endl << "\t./206neutrinos n a h sd" << endl << endl;
    cout << "DESCRIPTION" << endl << "\tn\t\tnumber of values" << endl;
    cout << "\ta\t\tarithmetic mean" << endl;
    cout << "\th\t\tharmonic mean" << endl;
    cout << "\tsd\t\tstandard deviation" << endl;
    exit(84);
}

static void satod(double *result, const char *string)
{
    char *error;

    *result = strtod(string, &error);
    if (*error != '\0' || errno != 0)
        err("Your value is not an integer.");
}

Values::Values(int ac, char **av)
{
    if (ac != 5)
        print_help();
    satod(&this->n, av[1]);
    satod(&this->a, av[2]);
    satod(&this->h, av[3]);
    satod(&this->sd, av[4]);
    if (this->n <= 0 || this->a <= 0 || this->h <= 0 || this->sd <= 0)
        err("Incorrect value(s), should be > 0.");
}

int get_input(double *new_value)
{
    string input;
    cout << "Enter next value: ";
    cin >> input;
    if (input == "END" || input.empty())
        return (1);
//    if (input.empty())
//        err("New value should not be empty.");
    satod(new_value, input.c_str());
    if (input.at(0) == '-')
        err("New value should be > 0.");
    return (0);
}

void Values::calc(double input)
{
    double x = this->n * this->a;
    double y = (pow(a, 2) + pow(this->sd, 2)) * this->n;
    double z = sqrt((y + pow(input, 2)) / (this->n + 1));
    this->n = this->n + 1;
    this->a = (x + input) / this->n;
    this->h = this->n / ((1 / input) + ((this->n - 1) / this->h));
    this->sd = sqrt(((y + pow(input, 2)) / this->n) - pow(this->a, 2));
    print_result(z);
}

void Values::print_result(double z)
{
    cout << "\t" << "Number of values:" << "\t" << this->n << endl;
    cout << fixed << setprecision(2);
    cout << "\t" << "Standard deviation:" << "\t" << this->sd << endl;
    cout << "\t" << "Arithmetic mean:" << "\t" << this->a << endl;
    cout << "\t" << "Root mean square:" << "\t" << z << endl;
    cout << "\t" << "Harmonic mean:" << "\t\t" << this->h << endl << endl;
    cout << setprecision(0);
}

void Values::loop()
{
    double new_value;
    while (get_input(&new_value) == 0) {
        calc(new_value);
    }
}

Values::~Values()
{
}

//------------Funcs-------------//
