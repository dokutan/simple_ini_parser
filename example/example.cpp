/*
 * Example to show the usage of simple_ini_parser
 * Dual licensed CC0 or 0BSD
 * 
 * Compile and run with:
 * g++ example.cpp -o example
 * ./example
 */

#include <iostream>

// you only need to include this header file
#include "../simple_ini_parser.h"

int main(){
	
	simple_ini_parser ini;
	
	// parse test.ini
	// (this does not clear any previously stored keys, only overwrites them
	if( ini.read( "example.ini" ) != 0 ){
		std::cerr << "Couldn't parse test.ini\n";
		return 1;
	}
	
	// const_map() returns a const reference to the internal key-value map
	std::cout << ini.const_map().size() << " keys\n";
	
	std::cout << "\n---\n\n";
	
	// print all key-value pairs to cout
	ini.print_all( std::cout );
	
	std::cout << "\n---\n\n";
	
	// check if key "section1.key1" exists
	if( ini.has( "section1.key1" ) )
		std::cout << "key \"section1.key1\" exists\n";
	else
		std::cout << "key \"section1.key1\" does not exist\n";
	
	// get the value of "section1.key1"
	std::cout << "key section1.key1 has value ";
	std::cout << ini.get( "section1.key1", "default (fallback) value" );
	std::cout << "\n";
	
	std::cout << "\n---\n\n";
	
	// map() returns a reference to the internal key-value map
	ini.map().clear();
	std::cout << ini.const_map().size() << " keys\n";
	
	return 0;
}
