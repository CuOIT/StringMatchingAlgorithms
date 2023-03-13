#include <iostream>
#include <fstream>
#include <string>
#include "BruteForce.cpp"
#include "KMP.cpp"
#include "RabinKarp.cpp"
string text1,text2,text3;
 void getFile(){
    ifstream file1("alice.txt");
    string t1((istreambuf_iterator<char>(file1)),(istreambuf_iterator<char>()));
    text1=t1;
    cout<<t1.length()<<endl;
    ifstream file2("ADN_gens.txt");
    string t2((istreambuf_iterator<char>(file2)),(istreambuf_iterator<char>()));
    text2=t2;
    cout<<t2.length()<<endl;
    ifstream file3("Duplicated_Alphabet.txt");
    string t3((istreambuf_iterator<char>(file3)),(istreambuf_iterator<char>()));
    text3=t3;
    cout<<t3.length()<<endl;
}
using namespace std;

int main() {

    getFile();

	do{
		fflush(stdin);
        int fileChoose=0;
        int aChoose=0;
        string text,pat;
        vector<int> indices;
		cout<<endl<<"\t\t----------------------STRING MATCHING ALGORITHMS----------------------"<<endl;
		cout<<endl<<"Choose 1 file:"<<endl;
		cout<<"1. Alice.txt"<<endl;
		cout<<"2. ADN_gens.txt"<<endl;
		cout<<"3. Duplicated_Alphabet.txt"<<endl;
		cout<<"\033[1;31m0. Exit\033[0m"<<endl<<endl;
		while(!(fileChoose==1 || fileChoose==2 || fileChoose==3))
			{
						cout<<">>";cin>>fileChoose;
						if(fileChoose==0) exit(0);
			}
		if(fileChoose==1) {
			text=text1;
		}else if(fileChoose==2){
			text=text2;
		}else if(fileChoose==3){
			text=text3;
		}
		fflush(stdin);
		cout<<"Input the pattern to find:";getline(cin,pat);
		cout<<endl<<"Choose algorithms:"<<endl;
		cout<<"1. KMP Algorithm"<<endl;
		cout<<"2. BruteForce Algorithm"<<endl;
		cout<<"3. RabinKarp Algorithm"<<endl;
		while(!(aChoose==1 || aChoose==2|| aChoose==3))
			{
						cout<<">>";cin>>aChoose;
			}
		if(aChoose==1){
			indices=KMPSearch(text,pat);
		}
		else if(aChoose==2){
			indices=BruteForceSearch(text,pat);
		}else if(aChoose==3){
			indices=RabinKarpSearch(text,pat);
		}
		string yes;
		cout<<"Do you want to show the result(type y):";cin>>yes;
		if(yes=="y")		
        for(int i=0;i<text.length();i++)
		if(find(indices.begin(), indices.end(), i) != indices.end())
			cout << "\033[31m" << text[i] << "\033[0m";
		else cout<<text[i];
		text="";
		pat="";
		indices.clear();
	}while(true);

    return 0;
}

