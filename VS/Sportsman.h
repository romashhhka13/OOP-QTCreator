#pragma once

#include <string>
#include <iostream>
#include <fstream>

#include "Addition.h"

class Sportsman
{
public:
	
	static void ResetMaxID();
	int GetID() const;
	virtual void Input();
	virtual void Output() const;

	Sportsman();

private:

	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar& id;
		ar& surname;
		ar& name;
		ar& age;
		ar& height;
	}

	std::string surname;
	std::string name;
	int id;
	int age;
	int height;
	static int max_id;
};


