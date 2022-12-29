#include <iostream>
#include <fstream>
#include <string>
#include "pokemon.h"

using namespace std;

/********************************************************************* 
** Function: create_pokemons
** Description: Dynamically allocates an array of Pokemons.
** Parameters: integer- number of pokemons in Pokedex struct.
** Pre-Conditions: Pokedex struct was populated with number of pokemons from file.
** Post-Conditions: Pokemons are stored in an array
*********************************************************************/
Pokemon* create_pokemons(int num_pokemon)
{
    Pokemon * pokemon_array = new Pokemon [num_pokemon];
    return pokemon_array;
}

/********************************************************************* 
** Function: populate_pokedex_data
** Description: Populates the Pokedex object from user, and file.
** Parameters: Struct address, an input file.
** Pre-Conditions: Dynamic array of pokemons was created and populated.
** Post-Conditions: Pokemon array is stored as an object of the Pokedex struct
*********************************************************************/
void populate_pokedex_data(Pokedex & pokedex_object, ifstream & infile)
{
    string trainer_name;
    cout << "Name of trainer: ";
    cin >> trainer_name;
    pokedex_object.trainer = trainer_name; // populating trainer
    infile >> pokedex_object.num_pokemon; // populating number of pokemons
    pokedex_object.dex = create_pokemons(pokedex_object.num_pokemon); // creating single pokemon object
    for (int i = 0; i < pokedex_object.num_pokemon; ++i) {
        populate_pokemon(pokedex_object.dex[i], infile);
    }
}

/********************************************************************* 
** Function: create_moves
** Description: Dynamically allocates an array of moves of a Pokemon
** Parameters: integer- number of moves in Pokemon struct.
** Pre-Conditions: Pokemon struct was populated with number of moves of each Pokemon from file.
** Post-Conditions: Pokemon moves are stored in an array located in each Pokemon object.
*********************************************************************/
string* create_moves(int num_moves)
{
    string* moves_array = new string [num_moves];
    return moves_array;
}

/********************************************************************* 
** Function: populate_pokemon
** Description: Populates a single Pokemon object with information from file
** Parameters: Pokemon struct address, input file address.
** Pre-Conditions: Move names array of each Pokemon was dynamically created and populated, user inputs
    correct file name, Pokemon array was dynamically allocated.
** Post-Conditions: Pokemon moves are stored in an array located in each Pokemon object. Pokemon objects
    are stored in an array located in the Pokedex struct.
*********************************************************************/
void populate_pokemon(Pokemon & pokemon_object, ifstream & infile)
{
    infile >> pokemon_object.dex_num >> pokemon_object.name >> pokemon_object.type >> pokemon_object.num_moves;
    pokemon_object.moves = create_moves(pokemon_object.num_moves);

    for (int i = 0; i < pokemon_object.num_moves; ++i) {
        infile >> pokemon_object.moves[i];
    }
}

/********************************************************************* 
** Function: delete_moves
** Description: Deletes dynamically allocated memory for Pokemon moves array.
** Parameters: address of Pokemon object.
** Pre-Conditions: Pokemon struct created and populated.
** Post-Conditions: Use of the moves array is terminated.
*********************************************************************/
void delete_moves(Pokemon & pokemon_object)
{
    delete [] pokemon_object.moves;
    pokemon_object.moves = NULL;

}

/********************************************************************* 
** Function: delete_info
** Description: Frees all the dynamically allocated memory of the program.
** Parameters: address of Pokedex object.
** Pre-Conditions: Pokedex struct was created and populated.
** Post-Conditions: Use of all dynamic arrays is terminated.
*********************************************************************/
void delete_info(Pokedex & pokedex_object)
{
    for (int i=0; i < pokedex_object.num_pokemon ; ++i) {
        delete_moves(pokedex_object.dex[i]);
    }

    delete [] pokedex_object.dex;
    pokedex_object.dex = NULL;
}

/********************************************************************* 
** Function: display_pokedex_info
** Description: Displays the options to search the Pokedex information.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void display_pokedex_info() {
    cout << "1. Search by dex number" << endl << "2. Search by name" << endl << "3. Search by type" << endl
    << "4. Add new Pokemon" << endl << "5. Quit" << endl << endl;
}

/********************************************************************* 
** Function: search_pokedex_info
** Description: Searches the Pokedex information.
** Parameters: adress of Pokedex object, output file, character signalling type of printing,
    integer depicting whta the user wants to do with the program, address of Pokemon object.
** Pre-Conditions: Pokedex and Pokemon structs were populates, output file was entered by user.
** Post-Conditions: 
*********************************************************************/
void search_pokedex_info(Pokedex & pokedex_object, ofstream& outfile, char output_to, int search_info, Pokemon & pokemon_object, string inputfile_name)
{
switch(search_info) {
    case 1: 
        search_by_dex_num(pokedex_object, outfile, output_to);
    
    break;
    case 2: 
        search_by_name(pokedex_object, outfile, output_to);
    
    break;
    case 3: 
        search_by_type(pokedex_object, outfile, output_to);
    
    break;
    case 4: 
        new_pokemon_array(pokedex_object, pokemon_object, inputfile_name, output_to);
    
    break;
    }

} 

/********************************************************************* 
** Function: search_by_name
** Description: Searches the Pokemon object by name.
** Parameters: address of Pokedex object, output file, character signaling how to output information.
** Pre-Conditions: Pokedex and Pokemon structs were created and populated, output and input files are valid.
** Post-Conditions: Displays either on screen or to a file.
*********************************************************************/
void search_by_name(Pokedex & pokedex_object, ofstream& outfile, char output_to)
{
string name;
cout << "Name of Pokemon: ";
cin >> name;
cout << endl;
for (int i=0; i < pokedex_object.num_pokemon ; ++i) {
    if (pokedex_object.dex[i].name == name) {
        if (output_to == 'f') {
            outfile << pokedex_object.dex[i].dex_num << " " << pokedex_object.dex[i].name << " " << pokedex_object.dex[i].type << " "
            << pokedex_object.dex[i].num_moves << " " << endl;
            for (int j = 0; j < pokedex_object.dex[i].num_moves; ++j) {
                outfile << pokedex_object.dex[i].moves[j] << " ";
            }
            outfile << endl << endl;
        }
        else if (output_to == 's') {
            cout << pokedex_object.dex[i].dex_num << " " << pokedex_object.dex[i].name << " " << pokedex_object.dex[i].type << " "
            << pokedex_object.dex[i].num_moves << " " << endl;
            for (int k = 0; k < pokedex_object.dex[i].num_moves; ++k) {
                cout << pokedex_object.dex[i].moves[k] << " ";                }
                cout << endl << endl;
        }
        return;
    }
}
    cout << "Error: No matching Pokemon" << endl;
}

/********************************************************************* 
** Function: search_by_dex_num
** Description: Searches the Pokemon object by dex number.
** Parameters: address of Pokedex object, output file, character signaling how to output information.
** Pre-Conditions: Pokedex and Pokemon structs were created and populated, output and input files are valid.
** Post-Conditions: Displays either on screen or to a file.
*********************************************************************/
void search_by_dex_num(Pokedex & pokedex_object, ofstream& outfile, char output_to)
{
int dex_number;
cout << "Dex Number of Pokemon: ";
cin >> dex_number;
cout << endl;
    for (int i=0; i < pokedex_object.num_pokemon ; ++i) {
        if (pokedex_object.dex[i].dex_num == dex_number) {
            if (output_to == 'f') {
                outfile << pokedex_object.dex[i].dex_num << " " << pokedex_object.dex[i].name << " " << pokedex_object.dex[i].type << " "
                << pokedex_object.dex[i].num_moves << " " << endl;
                for (int j = 0; j < pokedex_object.dex[i].num_moves; ++j) {
                    outfile << pokedex_object.dex[i].moves[j] << " ";
                }
                outfile << endl << endl;
            }
            else if (output_to == 's') {
                cout << pokedex_object.dex[i].dex_num << " " << pokedex_object.dex[i].name << " " << pokedex_object.dex[i].type << " "
                 << pokedex_object.dex[i].num_moves << " " << endl;
                for (int k = 0; k < pokedex_object.dex[i].num_moves; ++k) {
                    cout << pokedex_object.dex[i].moves[k] << " ";
                }
                cout << endl << endl;
            }    
            return;
        }
    }
    cout << "Error: No matching Pokemon" << endl;
}

/********************************************************************* 
** Function: search_by_type
** Description: Searches the Pokemon object by type.
** Parameters: address of Pokedex object, output file, character signaling how to output information.
** Pre-Conditions: Pokedex and Pokemon structs were created and populated, output and input files are valid.
** Post-Conditions: Displays either on screen or to a file.
*********************************************************************/
void search_by_type(Pokedex & pokedex_object, ofstream& outfile, char output_to)
{
string type;
cout << "Type of Pokemon: ";
cin >> type;
cout << endl;
int count = 0;
    for (int i=0; i < pokedex_object.num_pokemon ; ++i) {
        if (pokedex_object.dex[i].type == type) {
            if (output_to == 'f') {
                outfile << pokedex_object.dex[i].dex_num << " " << pokedex_object.dex[i].name << " " << pokedex_object.dex[i].type << " "
                << pokedex_object.dex[i].num_moves << " " << endl;
                for (int j = 0; j < pokedex_object.dex[i].num_moves; ++j) {
                    outfile << pokedex_object.dex[i].moves[j] << " ";
                }
                outfile << endl << endl;
            }
            else if (output_to == 's') {
                cout << pokedex_object.dex[i].dex_num << " " << pokedex_object.dex[i].name << " " << pokedex_object.dex[i].type << " "
                << pokedex_object.dex[i].num_moves << " " << endl;
                for (int k = 0; k < pokedex_object.dex[i].num_moves; ++k) {
                    cout << pokedex_object.dex[i].moves[k] << " ";
                }
                cout << endl << endl;
            }   
            count ++;     
        }
    }
   if (count == 0) {
        cout << "Error: No matching Pokemon" << endl;
   }

}

/********************************************************************* 
** Function: add_pokemon
** Description: Adds a new Pokemon to the Pokemon struct through user inputted data.
** Parameters: address of Pokemon object.
** Pre-Conditions: Pokemon struct was created and can be populated.
** Post-Conditions: New array of Pokemons must be created to hold another object.
*********************************************************************/
void add_pokemon(Pokemon & new_p)
{
    cout << "Enter dex number of new Pokemon: ";
    cin >> new_p.dex_num;
    cout << "Enter name of new Pokemon: ";
    cin >> new_p.name;
    cout << "Enter type of new Pokemon: ";
    cin >> new_p.type;
    cout << "Enter number of moves of new Pokemon: ";
    cin >> new_p.num_moves;
    new_p.moves = create_moves(new_p.num_moves);

    for (int i = 0; i < new_p.num_moves; ++i) {
    cout << "Enter move of new Pokemon: ";
    cin >> new_p.moves[i];
    }
}

/********************************************************************* 
** Function: new_pokemon_array
** Description: Createsn a new dynamic array of Pokemon objects and adds a new Pokemon object to it.
** Parameters: address of Pokemon object, address of Pokedex object.
** Pre-Conditions: Pokemon struct and Pokedex struct were created and can be populated, 
    add_pokemon function was written.
** Post-Conditions: New dynamically allocated memory must be deleted. 
*********************************************************************/
void new_pokemon_array(Pokedex & dex_object, Pokemon & pokemon_object, string inputfile, char print_to)
{
    /*updated_array[] = create_pokemons(dex_object.num_pokemon += 1); // create an array of pokemons sized greater by one
    for (int i=0; i < dex_object.num_pokemon; ++i) {
        updated_array[i] = dex_object.dex[i]; // set all elements of array equal to previous pokemon array
    } */
    
    Pokemon * updated_pokemons = new Pokemon [dex_object.num_pokemon + 1]; // create a new array of pokemons sized greater by one
    for (int i=0; i < dex_object.num_pokemon; ++i) {
        updated_pokemons[i] = dex_object.dex[i]; // set all elements of array equal to previous pokemon array
    }

    dex_object.num_pokemon += 1; // update number of pokemon 
    dex_object.dex = updated_pokemons; // set dex object to new array
    add_pokemon(dex_object.dex[dex_object.num_pokemon - 1]); // add new pokemon to end of new array

    ofstream outfile;
    outfile.open(inputfile.c_str(), ios::trunc);
    outfile << dex_object.num_pokemon << endl;

    for (int i=0; i < dex_object.num_pokemon; ++i) {
        outfile << dex_object.dex[i].dex_num << " " << dex_object.dex[i].name << " " << dex_object.dex[i].type << " "
        << dex_object.dex[i].num_moves << " " << endl;
        for (int j = 0; j < dex_object.dex[i].num_moves; ++j) {
            outfile << dex_object.dex[i].moves[j] << " ";
        }
        outfile << endl;
    } 
    
    //delete_info(dex_object);
}

// create new array of pokemons
// set all values equal to current array
// Nested for loop


