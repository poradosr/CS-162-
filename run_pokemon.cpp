#include <iostream>
#include <fstream>
#include <string>
#include "pokemon.h"

using namespace std;

/********************************************************************* 
** Program Filename: run_pokemon.cpp
** Author: Raz Poradosu
** Date: 10.23.22
** Description: A program allowing the user to search through and add Pokemons to a Pokedex struct
    that is initially populated by a user provided file. The search results are then 
    displayed either on the console or to a file provided by the user. 
** Input: Name of input file and if chosen also an output file, Numbers that depict how the user
    wants to navigate the program.
** Output: A Pokemon with a name, dex number, type, and number and names of moves, is chosen    
    a file with all the searched information.
*********************************************************************/

int main()
{
    Pokedex pokedex;
    Pokemon pokemon;
    // Ask user to input name of file
    ifstream infile; // input file object
    string file_name;
    cout << "Enter name of file: ";
    cin >> file_name;
    infile.open(file_name.c_str()); //Opening file
   
    // Check if file is successfully open
    if (!infile.is_open()) {
        cout << "Error opening the file." << endl;
        return 1;
    }

    // Ask user if they want ouput on screen or file
    char output_to;
    cout << "Would you like to output on the screen or in a file (s/f): ";
    cin >> output_to;
    ofstream outfile;
    string output_filename;

    if (output_to == 'f') { // user wants to output to file
        cout << "Enter name of output file: ";
        cin >> output_filename;
        outfile.open(output_filename.c_str(), ios::app); // opening output file
        
        if (!outfile.is_open()) { // Check if file is successfully open
            cout << "Error opening the file." << endl;
            return 1;
    } 
    }
    populate_pokedex_data(pokedex, infile); // populating pokedex from file
    infile.close();

    int search_info;
    display_pokedex_info(); // displaying pokedex info
    cin >> search_info;

    while (search_info != 5) { // will continue to prompt user to search until they choose to quit
        search_pokedex_info(pokedex, outfile, output_to, search_info, pokemon, file_name);
        display_pokedex_info(); // displaying pokedex info
        cin.clear();
        cin >> search_info;
    }

        cout << "Quitting program" << endl;

        // closing all open files
        outfile.close();
    
        // Freeing all dynamically allocated memory
        delete_info(pokedex);
}
