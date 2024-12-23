// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include "Footballer.h"
#include "SportsmansGroup.h"


BOOST_CLASS_EXPORT(Sportsman)
BOOST_CLASS_EXPORT(Footballer)


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


extern "C"
{

    __declspec(dllexport) int GetGroupSize(char* filename)
    {

        SportsmansGroup SG;
        std::ifstream fin(filename, std::ios::binary);

        if (fin)
            SG.Load(fin);
        else
        {
            std::cout << "Error in the opening file" << std::endl;
            return 0;
        }
        fin.close();

        return SG.GetSize();
    }

    __declspec(dllexport) void Save(char* filename, SportsmanData* sportsmans, int size)
    {
        SportsmansGroup SG;
        std::ofstream fout(filename, std::ios::binary);

        if (fout)
        {

            for (size_t i = 0; i < size; i++)
            {
                if (!sportsmans[i].is_footballer)
                {
                    std::shared_ptr<Sportsman> s = std::make_shared<Sportsman>();
                    s->SetStruct(sportsmans[i]);
                    SG.AddSportsman(s);
                }
                else
                {
                    std::shared_ptr<Footballer> f = std::make_shared<Footballer>();
                    f->SetStruct(sportsmans[i]);
                    SG.AddFootballer(f);
                }
                std::cout << std::endl;
            }
            SG.Save(fout);
        }
        else
        {
            std::cout << "Error in the opening file" << std::endl;
            return;
        }

        fout.close();
    }


    __declspec(dllexport) void Load(char* filename, SportsmanData* sportsmans)
    {
        SportsmansGroup SG;
        std::ifstream fin(filename, std::ios::binary);

        if (fin)
        {
            SG.Load(fin);
            for (size_t i = 0; i < SG.GetSize(); ++i)
            {
                std::cout << i << std::endl;
                sportsmans[i] = SG.GetGroup()[i]->GetStruct();
            }
        }
        else
        {
            std::cout << "Error in the opening file" << std::endl;
            return;
        }
        fin.close();
    }
}