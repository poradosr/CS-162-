#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Pokemon {
    int dex_num;
    string name;
    string type;
    int num_moves;
    string* moves;
};

struct Pokedex {
    string trainer;
    int num_pokemon;
    Pokemon* dex;
};


Pokemon* create_pokemons(int num_pokemon);
void populate_pokedex_data(Pokedex & pokedex_object, ifstream & infile);
string* create_moves(int num_moves);
void populate_pokemon(Pokemon & pokemon_object, ifstream & infile);
void delete_moves(Pokemon & pokemon_object);
void delete_info(Pokedex & pokedex_object);
void display_pokedex_info();
void search_pokedex_info(Pokedex & pokedex_object, ofstream& outfile, char output_to, int search_info, Pokemon & pokemon_object, string inputfile_name);
void search_by_name(Pokedex & pokedex_object, ofstream& outfile, char output_to);
void search_by_dex_num(Pokedex & pokedex_object, ofstream& outfile, char output_to);
void search_by_type(Pokedex & pokedex_object, ofstream& outfile, char output_to);
void add_pokemon(Pokemon & new_p);
void new_pokemon_array(Pokedex & dex_object, Pokemon & pokemon_object, string inputfile, char print_to);