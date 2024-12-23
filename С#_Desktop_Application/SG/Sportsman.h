#pragma once

struct SportsmanData
{
	bool is_footballer = false;

	int id;
	char surname[100];
	char name[100];
	int age;
	int height;
	int number;
	char position[100];
};


class Sportsman
{
public:
	
	static void ResetMaxID() { max_id = 1; };

	virtual SportsmanData GetStruct() const
	{
		SportsmanData SD;
		SD.id = id;
		strcpy_s(SD.surname, sizeof(SD.surname), surname.c_str());
		strcpy_s(SD.name, sizeof(SD.name), name.c_str());
		SD.age = age;
		SD.height = height;

		return SD;
	}

	virtual void SetStruct(SportsmanData& SD)
	{
		id = SD.id;
		surname.assign(SD.surname);
		name.assign(SD.name);
		age = SD.age;
		height = SD.height;
	}

	Sportsman()
	{
		surname = "";
		name = "";
		age = 0;
		height = 0;
		id = max_id++;
	};

	virtual ~Sportsman() = default;

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

int Sportsman::max_id = 1;
