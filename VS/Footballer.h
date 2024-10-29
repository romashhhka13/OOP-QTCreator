#pragma once
#include <string>
#include <iostream>

#include "Sportsman.h"
#include "Addition.h"

class Footballer : public Sportsman
{
public:
	void Input() override;
	void Output() const override;

	Footballer();

private:
	friend class boost::serialization::access;
	template <class Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar& boost::serialization::base_object<Sportsman>(*this);
		ar& number;
		ar& position;
	}

	std::string position;
	int number;
};

