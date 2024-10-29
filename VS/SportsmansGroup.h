#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include <vector>

#include "Sportsman.h"
#include "Footballer.h"
#include "Addition.h"

class SportsmansGroup
{
public:
	void AddSportsman();
	void AddFootballer();
	void ShowSportsmans() const;
	void Save(std::ofstream& fout) const;
	void Load(std::ifstream& fin);
	void Clear();
	bool ObjectExist() const;

private:
	friend class boost::serialization::access;
	template <class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& group;
	}

	std::vector<std::shared_ptr<Sportsman>> group;
};

