#include "SportsmansGroup.h"


using namespace std;
using namespace boost::archive;



void SportsmansGroup::AddSportsman(){
	shared_ptr<Sportsman> s = make_shared<Sportsman>();
	s->Input();
	group.push_back(s);
}


void SportsmansGroup::AddFootballer()
{
	shared_ptr<Footballer> f = make_shared<Footballer>();
	f->Input();
	group.push_back(f);
}


void SportsmansGroup::ShowSportsmans() const
{
	for (const auto& s : group)
		s->Output();
}


void SportsmansGroup::Save(ofstream& fout) const
{
	binary_oarchive oa(fout);
	oa << *this;
}


void SportsmansGroup::Load(ifstream& fin){

	std::cout << "Size" << fin.tellg() << std::endl;
	this->Clear();
	binary_iarchive ia(fin);
	ia >> *this;
}

void SportsmansGroup::Clear()
{
	Sportsman::ResetMaxID();
	group.clear();
}

bool SportsmansGroup::ObjectExist() const
{
	return !group.empty();
}

