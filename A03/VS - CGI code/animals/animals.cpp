/*
* FILE          :   animals.cpp
* PROJECT       :   PROG2001 - Assignment 03
* PROGRAMMER    :   Paul Smith and Amy Dayasundara
* FIRST VERSION :   2019-09-27
* DESCRIPTION   :   Contains the behind code for the Text Editor program.
																			*/
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <map>

#pragma warning(disable : 4996)		// need to do this to be able to use getenv()

																			//function prototypes for parsing of info
std::string parseName(std::string input);
std::string parseAnimal(std::string input);


int main(void)
{
	std::string data;
	std::string nameChoice;		// local variables to hold the values passed in through the environment variables
	std::string animalChoice;

	std::map<std::string, std::string> textFiles = {	//container for text file names associated with key
		{"AO", "theZoo/armadillo.txt"},
		{"DN", "theZoo/dolphin.txt"},
		{"MO", "theZoo/moth.txt"},
		{"QU", "theZoo/quokka.txt"},
		{"SR", "theZoo/samRockwell.txt"},
		{"TR", "theZoo/tiger.txt"}, };

	std::map<std::string, std::string> animalNames = {	//container for animal names associated with key
		{"AO", "armadillo"},
		{"DN", "dolphin"},
		{"MO", "moth"},
		{"QU", "quokka"},
		{"SR", "samRockwell"},
		{"TR", "tiger"}, };

	// get the information passed into the CGI program and scanf it out
	data = getenv("QUERY_STRING");

	//functions called to parse content from passed info
	nameChoice = parseName(data);
	animalChoice = parseAnimal(data);

	//iterators created to parse for correct value/key pair for both name and file names
	std::map<std::string, std::string>::iterator it;
	it = textFiles.find(animalChoice);
	std::map<std::string, std::string>::iterator itCH2;
	itCH2 = animalNames.find(animalChoice);

	//output is generated for html file
	std::cout << "Content-type:text/html\n\n";
	std::cout << "<html><head><title>animals.cgi</title><link href= 'animalStyle.css' rel='stylesheet' type='text/css'</head>\n";
	std::cout << "<body><div class='row'><div class='column'></div><div class= 'column'>";

	if (animalChoice != "SR") //exception for Sam Rockwell, because he is special (just to deal with both first and last name capitalization)
	{
		std::cout << "<h2 align='center' id='rcorners1'>Hi " << nameChoice << ", welcome to the " << itCH2->second << " page!</h2>\n";
	}
	else if (animalChoice == "SR")
	{
		std::cout << "<h3>Hi " << nameChoice << ", welcome to the Sam Rockwell page!</h3>\n";
	}


	//text file containing animal info is opened
	FILE* f = fopen(it->second.c_str(), "r");
	int ch;
	if (f == NULL) {
		std::cout << "<TITLE>Failure</TITLE>\n";
		std::cout << "<P><EM>Unable to open data file, sorry!</EM>";
	}
	else {
		std::cout << "<img src='theZoo/" << itCH2->second << ".jpg' max-width='400' height='auto'>";

		while ((ch = getc(f)) != EOF)
			putchar(ch);
		fclose(f);	//file is closed after ino is pulled
	}

	std::cout << "</div></div></body></html>";
	return 0;
}

/*
 * NAME     :   parseName
* PURPOSE	:   parses input for name value
 * INPUTS   :
*   std::string input	: value result of query_string
* OUTPUTS	:
*   NONE
* RETURNS	:
*   std::string name	: string containing parsed out name value
*/
std::string parseName(std::string input)
{
	int nameLength = 0;
	std::string name;
	char buffer[100] = ""; //buffer set high for impossibly large names
	size_t first = input.find("name=");	//position of name value located
	first += 5;

	size_t second = input.find("&animal=");	//end of name value position located
	nameLength = (second - first);

	input.copy(buffer, nameLength, first);	//name copied into buffer
	name = buffer;	//buffer copied into name string

	return name;
}

/*
 * NAME     :   parseAnimal
* PURPOSE	:   parses input for animal value
 * INPUTS   :
*   std::string input	: value result of query_string
* OUTPUTS	:
*   NONE
* RETURNS	:
*   std::string name	: string containing parsed out animal value
*/
std::string parseAnimal(std::string input)
{
	int animalLength = 0;
	std::string animal;
	char buffer[30] = "";
	size_t first = input.find("&animal="); //position of animal value located
	first += 8;

	size_t second = input.length(); //end of animal value position located
	animalLength = (second - first);

	input.copy(buffer, animalLength, first); //animal thrown into buffer
	animal = buffer; //buffer copied into animal string

	return animal;
}