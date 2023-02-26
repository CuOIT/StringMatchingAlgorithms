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
        int random_num = i % 10; // generate a random number between 0 and 3
        char nucleotide;
		if(random_num%10==11) nucleotide='a';
		else nucleotide='b';
        if(i%1000==0) nucleotide='a';
        dna_string += nucleotide; // add the nucleotide to the DNA string
    }
    ofstream outfile("Duplicated_Alphabet.txt", ios::trunc);

    // check if the file was opened successfully
    if (!outfile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    // write the message to the file
    outfile << dna_string << endl;

	ifstream infile("Duplicated_Alphabet.txt");
	
    string text((istreambuf_iterator<char>(infile)),
                		(istreambuf_iterator<char>()));
    cout<<text<<endl<<text.length();
    // close the file
    outfile.close();
    
    return 0;
}
