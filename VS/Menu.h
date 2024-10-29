#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <format>


#include "SportsmansGroup.h"
#include "Addition.h"


void MenuAddSportsman(SportsmansGroup& group);
void MenuAddFootballer(SportsmansGroup& group);
void MenuShowSportsmans(const SportsmansGroup& group);
void MenuSave(const SportsmansGroup& group);
void MenuLoad(SportsmansGroup& group);
void MenuClear(SportsmansGroup& group);
