#pragma once

#include "Sportsman.h"
#include "Footballer.h"

class SportsmansGroup
{
public:

	void Save(std::ofstream& fout) const
	{
		boost::archive::binary_oarchive oa(fout);
		oa << *this;
	};

	void Load(std::ifstream& fin)
	{

		this->Clear();
		boost::archive::binary_iarchive ia(fin);
		ia >> *this;
	};

	void Clear()
	{
		Sportsman::ResetMaxID();
		group.clear();
	};

	bool ObjectExist() const { return !group.empty(); };
	int GetSize() const { return group.size(); }
	const std::vector<std::shared_ptr<Sportsman>>& GetGroup() const { return group; }
	void AddSportsman(std::shared_ptr<Sportsman>& s) { group.push_back(s); }
	void AddFootballer(std::shared_ptr<Footballer>& f) { group.push_back(f); }

	SportsmansGroup() = default;
	~SportsmansGroup() = default;

private:
	friend class boost::serialization::access;
	template <class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& group;
	}

	std::vector<std::shared_ptr<Sportsman>> group;
};

