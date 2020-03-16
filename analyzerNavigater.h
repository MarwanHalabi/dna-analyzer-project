#ifndef DNA_ANALYZERNAVIGATER_H
#define DNA_ANALYZERNAVIGATER_H

#include "DNAsequence.h"
#include <vector>
#include <map>
#include <sstream>
#include <fstream>

typedef std::vector<std::string> VStr;
typedef std::map<int, DnaSequence> MIdDna;
typedef std::map<int, std::string> MNameDna;


///////  DATA BASE  ///////

class DataBase{
public:
    static MIdDna MapIdDna;
    static MNameDna MapIdName;
};

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

/////// PARSER ///////
typedef std::map<std::string,Icommand*> strCommands ;

class Navigate{
private:
    VStr commandV;
    strCommands doCommandsV;
public:
    explicit Navigate(strCommands SC, const std::string& = "");
    ~Navigate();
    void doCommands();

};

inline Navigate::Navigate(strCommands SC, const std::string& CL){
    std::stringstream ss(CL);
    std::string temp;
    while (ss >> temp)
        commandV.push_back(temp);
    doCommandsV = SC;
    doCommands();
}

inline Navigate::~Navigate(){

}

inline void Navigate::doCommands(){
    doCommandsV[commandV[0]]->execute(commandV);
}


/////// CONTROLLER ///////
class Controller{
public:
    static void start() {
        strCommands SC;
        New NEW;
        Save SAVE;
        Load LOAD;
        Dup DUP;
        SC.insert(std::pair<std::string, Icommand *>("new", &NEW));
        SC.insert(std::pair<std::string, Icommand *>("save", &SAVE));
        SC.insert(std::pair<std::string, Icommand *>("load", &LOAD));
        SC.insert(std::pair<std::string, Icommand *>("dup", &DUP));

        for (std::string line; std::getline(std::cin, line);) {
            Navigate parser(SC,line);
        }
    }
};

#endif //DNA_ANALYZERNAVIGATER_H
