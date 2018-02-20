#include<iostream>
using namespace std;

namespace Verbose {
    bool verbose = false;
    void confirmVerbose(int argc ,char **argv){
        for(int i = 0; i < argc; i++){
            if((string)argv[i] == "-v" || (string)argv[i] == "--verbose")
                verbose = true;
        }
    }
    class Verb {
        ostream *output;
        template<typename T>
        Verb verbOut(T flow)const{
            if(verbose)
                (*output) << flow;
            return *this;
        }
    public:
        Verb(ostream& output){
            this->output = &output;
        }
        template<typename T>
        Verb operator<<(T flow)const{
            return verbOut<T>(flow);
        }
        ostream& operator<<(ostream& flow)const{
            return flow;
        }
        //friend ostream operator<<(ostream& output ,Verb& flow);
    };
    Verb operator<<(ostream& output ,Verb& flow){
        return flow;
    }
    Verb verb(cout);
    char vendl = '\n';
};

//EXAMPLE:
/*
using namespace Verbose;
int main(){
    verbose = false;
    cout << "a" << verb << "b" << cout << "c" << verb << "d" << cout << '\n';
    verb << "a" << cout << "b" << verb << "c" << cout << "d" << verb << '\n';
    verbose = true;
    cout << '\n';
    cout << "a" << verb << "b" << cout << "c" << verb << "d" << cout << '\n';
    
    ofstream file;
    file.open("./log");
    Verb verbToFile(file);
    verbToFile << "from Verb\n";
    file.close();
}
*/