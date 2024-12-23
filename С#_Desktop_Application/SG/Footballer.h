#pragma once
#include "Sportsman.h"

class Footballer : public Sportsman
{
public:

	Footballer()
	{
		number = 0;
		position = "";
	};

	SportsmanData GetStruct() const override
	{
		SportsmanData SD = Sportsman::GetStruct();
		SD.is_footballer = true;
		SD.number = number;
		strcpy_s(SD.position, sizeof(SD.position), position.c_str());

		return SD;
	}

	void SetStruct(SportsmanData& SD) override
	{
		Sportsman::SetStruct(SD);
		number = SD.number;
		position.assign(SD.position);
	}

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

