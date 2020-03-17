#ifndef DNA_ANALYZERNAVIGATER_H
#define DNA_ANALYZERNAVIGATER_H

#include <vector>

#include <sstream>
#include <fstream>
#include "dataBase.h"

typedef std::vector<std::string> VStr;


/////// COMMAND INTERFACE ///////
class Icommand{
public:
    virtual void execute(VStr) = 0;
};

/////// COMMANDS ///////

///NEW
class New: public Icommand{
public:
    static int ID;
    int currentID;

    void execute(VStr commandV){
        DnaSequence Dna(commandV[1]);
        currentID = ID++;

        std::ostringstream convert;
        convert << currentID;
        std::string Result = convert.str();

        std::string seq_name = "seq"+Result;
        if(commandV.size()>2 && commandV[2][0] == '@') {
            seq_name = commandV[2];
            seq_name.erase(0, 1);
        }
        DataBase::MapIdDna.insert(std::pair<int,DnaSequence>(currentID,Dna));
        DataBase::MapIdName.insert(std::pair<int,std::string>(currentID,seq_name));
        std::cout<<"["<<currentID<<"] "<< seq_name +" :"<<DataBase::MapIdDna[currentID]<<"\n";
    }
};


///Save
class Save: public Icommand{
public:
    void execute(VStr commandV){
        if(commandV[1][0] == '#'){
            std::ofstream new_file;
            std::string seq_id = commandV[1];
            int id;
            std::string path;
            seq_id.erase(0, 1);
            sscanf(seq_id.c_str(), "%d", &id);

            if(commandV.size() > 2){
                path = commandV[2];
            }
            else{
                path = DataBase::MapIdName[id]+".rawdna";
            }
            new_file.open(path.c_str(), std::ios_base::app);

            std::string data = commandV[1]+" @"+DataBase::MapIdName[id]+" "+DataBase::MapIdDna[id].get_str()+"\n";
            new_file << data;
            std::cout<<"file  saved\n";
            new_file.close();
        }
    }
};

///Load
class Load: public Icommand{
private:
    int currentID;
public:

    void execute(VStr commandV) {
        currentID = New::ID++;

        std::string line;
        std::string path = commandV[1];
        std::ifstream myfile(path.c_str());
        std::vector<std::string> words;
        std::string seq_name;

        if (myfile.is_open()) {
            getline(myfile, line);
            myfile.close();
        }
        std::stringstream ss(line);
        std::string temp;
        while (ss >> temp)
            words.push_back(temp);
        //std::cout<<words[1]<<"\n";

        if(commandV.size()>2 && commandV[2][0] == '@') {
            seq_name = commandV[2];
            seq_name.erase(0, 1);
        }
        else{
            seq_name = words[1];
        }

        std::cout<<words[2]<<"\n";
        DnaSequence Dna(words[2]);

        DataBase::MapIdDna.insert(std::pair<int,DnaSequence>(currentID,Dna));
        DataBase::MapIdName.insert(std::pair<int,std::string>(currentID,seq_name));

        std::cout<<"["<<currentID<<"] "<< seq_name +" :"<<DataBase::MapIdDna[currentID]<<"\n";
    }
};


///Dup
class Dup: public Icommand{
private:
    int currentID;
public:

    void execute(VStr commandV) {
        if(commandV[1][0] == '#') {
            std::ofstream new_file;
            std::string seq_id = commandV[1];
            int id;
            std::string seq_name;
            std::string path;
            seq_id.erase(0, 1);
            sscanf(seq_id.c_str(), "%d", &id);

            currentID = New::ID++;

            if (commandV.size() > 2 && commandV[2][0] == '@') {
                seq_name = commandV[2];
                seq_name.erase(0, 1);
            } else {
                std::ostringstream convert;
                convert << currentID;
                std::string Result = convert.str();

                seq_name = "seq" + Result;
            }
            DataBase::MapIdDna.insert(std::pair<int,DnaSequence>(currentID,DataBase::MapIdDna[id]));
            DataBase::MapIdName.insert(std::pair<int,std::string>(currentID,seq_name));

            std::cout<<"["<<currentID<<"] "<< seq_name +" :"<<DataBase::MapIdDna[currentID]<<"\n";
        }
    }
};


///Slice
class Slice: public Icommand{
private:
    int currentID;
public:

    void execute(VStr commandV) {
        if(commandV[1][0] == '#') {
            std::ofstream new_file;
            std::string seq_id = commandV[1];
            std::string seq_start = commandV[2];
            std::string seq_end = commandV[3];

            int id;
            size_t start;
            size_t end;

            std::string seq_name;
            std::string path;

            seq_id.erase(0, 1);
            sscanf(seq_id.c_str(), "%d", &id);

            sscanf(seq_start.c_str(), "%d", &start);

            sscanf(seq_end.c_str(), "%d", &end);

            currentID = New::ID++;

            if (commandV.size() > 4 && commandV[4][0] == '@') {
                seq_name = commandV[4];
                seq_name.erase(0, 1);
            } else {
                std::ostringstream convert;
                convert << currentID;
                std::string Result = convert.str();

                seq_name = "seq" + Result;
            }
            DnaSequence dna = DataBase::MapIdDna[id].makeSlice(start,end);

            DataBase::MapIdDna.insert(std::pair<int,DnaSequence>(currentID,dna));
            DataBase::MapIdName.insert(std::pair<int,std::string>(currentID,seq_name));

            std::cout<<"["<<currentID<<"] "<< seq_name +" :"<<DataBase::MapIdDna[currentID]<<"\n";
        }
    }
};

#endif //DNA_ANALYZERNAVIGATER_H
