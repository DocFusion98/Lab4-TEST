#include <iostream>
#include <person.h>
//Sets up the class and methods for PersonDatabase
namespace example {

	class PersonDatabase {


	private:
		example::Person* my_array;
		unsigned int array_length;
		std::string file;
		


	public:

		

		PersonDatabase(std::string fileName);


		~PersonDatabase();


		int get_num_people();


		void add_person(example::Person p);

		void remove_person(int id);


		std::string to_string();




	};
}











