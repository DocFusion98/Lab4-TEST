#include <person_database.h>
#include <string>
#include <fstream>


example::PersonDatabase::PersonDatabase(std::string fileName) {
	//Creates a person database object
	file = fileName;

	std::ifstream fin(file);

	if (!fin.is_open()) {
		throw std::runtime_error("File " + file + " was not found!!!!");
	}

	my_array = nullptr;
	array_length = 0;

	int temp_id;
	std::string temp_fname, temp_lname;
	float temp_hourly_rate;
	unsigned int temp_hours_worked;


	while (true) {


		fin >> temp_id;
		if (fin.eof()) {
			break;
		}
		fin >> temp_fname;
		fin >> temp_lname;
		fin >> temp_hourly_rate;
		fin >> temp_hours_worked;


		example::Person temp_person(temp_id, temp_fname, temp_lname);
		temp_person.set_hourly_rate(temp_hourly_rate);
		temp_person.set_hours_worked(temp_hours_worked);


		add_person(temp_person);
	}
	fin.close();
};

example::PersonDatabase::~PersonDatabase() {
	std::ofstream fout(file);

	for (int i = 0; i < array_length; i++) {
		fout << my_array[i].get_id() << " ";
		fout << my_array[i].get_first_name() << " ";
		fout << my_array[i].get_last_name() << " ";
		fout << my_array[i].get_hourly_rate() << " ";
		fout << my_array[i].get_hours_worked() << " ";
	}

	fout.close();

}


int example::PersonDatabase::get_num_people() {
	return array_length;
}


void example::PersonDatabase::add_person(example::Person p) {
	//appends a new person object to the array in the database object
	if (!my_array)
	{
		my_array = new Person[1];
		my_array[0] = p;
		array_length++;
	}
	// my_array with data already in it
	else
	{

		Person* temp_array = new Person[array_length + 1];

		array_length++;
		int last_i = array_length - 1;

		for (int i = 0; i < last_i; i++)
		{
			temp_array[i] = my_array[i];
		}

		temp_array[last_i] = p;

		delete[] my_array;
		my_array = temp_array;
	}
}


void example::PersonDatabase::remove_person(int id) {
	//pops a person object out of the database object based upon their id number, given by the user
	Person* temp_array = new Person[array_length - 1];
	int temp_i = 0;

	unsigned int array_size = array_length;

	for (int i = 0; i < array_size; i++)
	{
		if (my_array[i].get_id() == id)
		{
			array_length--;
			continue;
		}

		temp_array[temp_i] = my_array[i];
		temp_i++;
	}

	delete[] my_array;
	my_array = temp_array;
}

std::string example::PersonDatabase::to_string() {
	//Formats the object as a string
	return std::string();
}