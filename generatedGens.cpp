#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int main() {
    srand(time(NULL)); // set the random seed based on current time

    string dna_string = "";
    for (int i = 0; i < 400000; i++) {
        int random_num = rand() % 4; // generate a random number between 0 and 3
        char nucleotide;
        switch (random_num) {
            case 0:
                nucleotide = 'A';
                break;
            case 1:
                nucleotide = 'T';
                break;
            case 2:
                nucleotide = 'G';
                break;
            case 3:
                nucleotide = 'X';
                break;
        }
        dna_string += nucleotide; // add the nucleotide to the DNA string
    }
    ofstream outfile("ADN_gens.txt", ios::trunc);

    // check if the file was opened successfully
    if (!outfile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    // write the message to the file
    outfile << dna_string << endl;

	ifstream infile("ADN_gens.txt");

    string text((istreambuf_iterator<char>(infile)),
                		(istreambuf_iterator<char>()));
    cout<<text<<endl<<text.length();
    // close the file
    outfile.close();
    
    return 0;
}
