#include <string>
#include <sstream>

using namespace std;

class Forditas{
    string angol;
    string magyar;

public:
    Forditas() {}

    Forditas(string& angol, string& magyar) {
        this->angol = angol;
        this->magyar = magyar;
    }

    friend class Szotar;
};

class Szotar {
    Forditas* szavak;
    int maximalis_meret;
    int aktualis_meret;

public:
    Szotar(int meret) {
        szavak = new Forditas[meret];
        maximalis_meret = meret;
        aktualis_meret = 0;
    }

    void frissit(string& mit, string& mire) {
        for(int i = 0; i < aktualis_meret; i++){
            if (szavak[i].magyar == mit) {
                szavak[i].angol= mire;
                return;
            }
        }

        hozzaad(mit, mire);
    }

    string lekerdez(string& magyar) {
        for (int i = 0; i < aktualis_meret; i++) {
            if (szavak[i].magyar == magyar){
                return szavak[i].angol;
            }
        }

        return "";
    }

    string tartalom(){
        stringstream s;
        for (int i = 0; i < aktualis_meret; i++) {
            s << szavak[i].magyar << " - " << szavak[i].angol << endl;
        }

        return s.str();
    }
    bool hozzaad(string& magyar, string& angol) {
        for(int i = 0; i < aktualis_meret; i++) {
            if (szavak[i].magyar == magyar) {
                frissit(magyar,angol);
                return true;
            }
        }

        if(aktualis_meret < maximalis_meret) {
            Forditas f(angol,magyar);
            szavak[aktualis_meret] = f;
            aktualis_meret++;
            return true;
        }

        return false;
    }
    void kiurit() {
        aktualis_meret = 0;
    }
};
