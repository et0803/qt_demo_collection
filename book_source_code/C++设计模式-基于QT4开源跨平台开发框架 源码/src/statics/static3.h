#ifndef _STATIC_3_H_
#define _STATIC_3_H_

#include <string>
using namespace std;

class Client {
 public:
    Client(string name) : m_Name(name), m_ID(sm_SavedID++)
        { }
    static int getSavedID() {
        if(sm_SavedID > m_ID) return sm_SavedID;
        else return 0;
    }
    string getName() {return m_Name;}
    int getID() {return m_ID; }
 private:
    string m_Name;
    int m_ID;
    static int sm_SavedID ;
};

#endif
