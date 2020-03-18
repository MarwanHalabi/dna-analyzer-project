#include "commands.h"

int New::ID = 1;

void New::execute(std::vector <std::string> commandV) {
    DnaSequence Dna(commandV[1]);
    currentID = ID++;

    std::ostringstream convert;  //convert int id to string (Result)
    convert << currentID;
    std::string Result = convert.str();

    std::string seq_name = "seq"+Result;
    if(commandV.size()>2 && commandV[2][0] == '@') {
        seq_name = commandV[2];
        seq_name.erase(0, 1);
    }
    DataBase::MapIdDna.insert(std::pair<int,DnaSequence>(currentID,Dna));
    DataBase::MapIdName.insert(std::pair<int,std::string>(currentID,seq_name));
    std::cout<<"["<<currentID<<"] "<< seq_name +": "<<DataBase::MapIdDna[currentID]<<"\n";
}

void Load::execute(std::vector <std::string> commandV) {
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

    std::cout<<"["<<currentID<<"] "<< seq_name +": "<<DataBase::MapIdDna[currentID]<<"\n";

}

void Dup::execute(std::vector <std::string> commandV) {
    if (commandV[1][0] == '#') {
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
        DataBase::MapIdDna.insert(std::pair<int, DnaSequence>(currentID, DataBase::MapIdDna[id]));
        DataBase::MapIdName.insert(std::pair<int, std::string>(currentID, seq_name));

        std::cout << "[" << currentID << "] " << seq_name + ": " << DataBase::MapIdDna[currentID] << "\n";

    }
}
void Save::execute(std::vector <std::string> commandV) {
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

void Slice::execute(std::vector <std::string> commandV) {
    if(commandV[1][0] == '#') {
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

        std::cout<<"["<<currentID<<"] "<< seq_name +": "<<DataBase::MapIdDna[currentID]<<"\n";
    }
}

void Len::execute(std::vector <std::string> commandV) {
    if(commandV[1][0] == '#') {
        std::ofstream new_file;
        std::string seq_id = commandV[1];
        int id;

        seq_id.erase(0, 1);
        sscanf(seq_id.c_str(), "%d", &id);

        int length = DataBase::MapIdDna[id].getLen();

        std::cout<<length<<"\n";
    }
    else{
        std::cout<<"handle DNA\n";
    }
}

void Find::execute(std::vector <std::string> commandV) {
    if(commandV[1][0] == '#') {
        std::ofstream new_file;
        std::string seq_id = commandV[1];
        int id;
        int id2;
        size_t index;

        seq_id.erase(0, 1);
        sscanf(seq_id.c_str(), "%d", &id);

        if(commandV[2][0] == '#'){
            std::string seq_id2 = commandV[2];
            seq_id2.erase(0, 1);
            sscanf(seq_id2.c_str(), "%d", &id2);
            std::string dna_seq = DataBase::MapIdDna[id2].get_str();
            index = DataBase::MapIdDna[id].find_dna(dna_seq);
        }
        else{
            index = DataBase::MapIdDna[id].find_dna(commandV[2]);
        }
        std::cout<<index<<"\n";
    }
}

void Count::execute(std::vector <std::string> commandV) {
    if(commandV[1][0] == '#') {
        std::ofstream new_file;
        std::string seq_id = commandV[1];
        int id;
        int id2;
        std::vector<size_t> index;

        seq_id.erase(0, 1);
        sscanf(seq_id.c_str(), "%d", &id);

        if(commandV[2][0] == '#'){
            std::string seq_id2 = commandV[2];
            seq_id2.erase(0, 1);
            sscanf(seq_id2.c_str(), "%d", &id2);
            std::string dna_seq = DataBase::MapIdDna[id2].get_str();
            index = DataBase::MapIdDna[id].find_all(dna_seq);
        }
        else{
            index = DataBase::MapIdDna[id].find_all(commandV[2]);
        }
        std::cout<<index.size()<<"\n";
    }
}

void findAll::execute(std::vector <std::string> commandV) {
    if(commandV[1][0] == '#') {
        std::ofstream new_file;
        std::string seq_id = commandV[1];
        int id;
        int id2;
        std::vector<size_t> index;

        seq_id.erase(0, 1);
        sscanf(seq_id.c_str(), "%d", &id);

        if(commandV[2][0] == '#'){
            std::string seq_id2 = commandV[2];
            seq_id2.erase(0, 1);
            sscanf(seq_id2.c_str(), "%d", &id2);
            std::string dna_seq = DataBase::MapIdDna[id2].get_str();
            index = DataBase::MapIdDna[id].find_all(dna_seq);
        }
        else{
            index = DataBase::MapIdDna[id].find_all(commandV[2]);
        }
        for (int i =0; i<index.size();i++){
            std::cout<<index[i]<<" ";
        }
        std::cout<<"\n";
    }
}

void batch::execute(std::vector <std::string> commandV) {
    std::string batchName;
    std::vector<std::string> commands;
    batchName = commandV[1];
    std::cout<<BOLDCYAN<<"(batch)"<<GREEN<<" > cmd >>> "<<RESET;
    for (std::string line; std::getline(std::cin, line);std::cout<<BOLDCYAN<<"(batch)"<<GREEN<<" > cmd >>> "<<RESET) {
        if(line == "end"){
            break;
        }
        DataBase::batchCommands[batchName].push_back(line);
    }
}

void batchSave::execute(std::vector <std::string> commandV) {
    std::ofstream new_file;
    new_file.open((commandV[1]+".dnabatch").c_str(), std::ios_base::app);
    for(int i = 0; i<DataBase::batchCommands[commandV[1]].size();i++){
        new_file << DataBase::batchCommands[commandV[1]][i]+"\n";
    }
    new_file.close();
}

void batchLoad::execute(std::vector <std::string> commandV) {
    std::string line;
    std::string batchName = commandV[1];

    if(commandV[1][0] == '@') {
        batchName.erase(0, 1);
    }


    std::ifstream myfile((batchName+".dnabatch").c_str());
    if(commandV.size()>2 && commandV[2][0] == '@') {
        batchName = commandV[2];
        batchName.erase(0, 1);
    }

    if (myfile.is_open()) {
        while ( getline (myfile,line) )
        {
            DataBase::batchCommands[batchName].push_back(line);
        }
        myfile.close();
    }
}

void batchShow::execute(std::vector <std::string> commandV) {
    std::string line;
    std::string batchName = commandV[1];
    batchName.erase(0, 1);
    for(int i = 0; i<DataBase::batchCommands[batchName].size();i++){
        std::cout << DataBase::batchCommands[batchName][i]+"\n";
    }
}

void batchList::execute(std::vector <std::string> commandV) {
    for(bCommands::iterator it = DataBase::batchCommands.begin(); it != DataBase::batchCommands.end(); ++it){
        std::cout << it->first <<"\n";
    }
}
