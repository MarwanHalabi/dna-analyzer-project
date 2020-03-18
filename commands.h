#ifndef DNA_ANALYZERNAVIGATER_H
#define DNA_ANALYZERNAVIGATER_H

#include <vector>

#include <sstream>
#include <fstream>
#include "dataBase.h"

typedef std::vector<std::string> VStr;

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDCYAN    "\033[1m\033[36m"

/////// COMMAND INTERFACE ///////
class Icommand{
public:
    virtual void execute(VStr) = 0;
};

/////// Sequence Creation Commands ///////

///NEW
class New: public Icommand{
public:
    static int ID;
    int currentID;

    void execute(VStr commandV);
};


///Load
class Load: public Icommand{
private:
    int currentID;
public:

    void execute(VStr commandV);
};

///Dup
class Dup: public Icommand{
private:
    int currentID;
public:

    void execute(VStr commandV);
};

/////// Sequence Manipulation Commands ///////

///Save
class Save: public Icommand{
public:
    void execute(VStr commandV);
};

///Slice
class Slice: public Icommand{
private:
    int currentID;

public:
    void execute(VStr commandV);
};

/////// Sequence Analysis Commands ///////

///len
class Len: public Icommand{
public:
    void execute(VStr commandV);
};

///find
class Find: public Icommand{
public:
    void execute(VStr commandV);
};

///count
class Count: public Icommand{
public:
    void execute(VStr commandV);
};

///find all
class findAll: public Icommand{
public:
    void execute(VStr commandV);
};

/////// Batch Commands ///////

///batch create
class batch: public Icommand{
public:
    void execute(VStr commandV);
};

///save batch
class batchSave: public Icommand{
public:
    void execute(VStr commandV);
};

/////load batch
class batchLoad: public Icommand{
public:
    void execute(VStr commandV);
};

///show batch
class batchShow: public Icommand{
public:
    void execute(VStr commandV);
};

///list batch
class batchList: public Icommand{
public:
    void execute(VStr commandV);
};

#endif //DNA_ANALYZERNAVIGATER_H
