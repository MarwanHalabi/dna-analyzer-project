#include "parser.h"

Navigate::Navigate(strCommands SC, const std::string& CL){
    std::stringstream ss(CL);
    std::string temp;
    while (ss >> temp)
        commandV.push_back(temp);
    doCommandsV = SC;
    doCommands();
}

Navigate::~Navigate(){

}

void Navigate::batchMode(){
    std::string batchName = commandV[1];
    for(int i = 0; i< DataBase::batchCommands[batchName].size();i++){
        std::string batchLine = DataBase::batchCommands[batchName][i];
        Navigate batch(doCommandsV,batchLine);
    }
}

void Navigate::doCommands(){
    if(commandV[0]=="run"){
        batchMode();
    }
    else{
        doCommandsV[commandV[0]]->execute(commandV);
    }
}