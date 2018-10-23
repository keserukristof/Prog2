#include <iostream>
using namespace std;
 
class Alma
{
    public:
        const char* korte;
        Alma(const char* korte){this->korte=korte;}
        // copy ctor
        Alma(const Alma &A2){
            korte=A2.korte;
            cout << "copy" << endl;
        }
 
 
        // move assign  ctor
        Alma& operator= (Alma&& A2){
                korte = A2.korte;
                A2.korte = nullptr;
                cout << "move" << endl;
                return *this;
        }
       
};
 
int main(){
    Alma a("korte korte korte korte korte");
    cout <<a.korte <<endl;
    Alma a2(a);
    cout << a2.korte  << endl;
    a = move(a2) ;
    return 0;
 
}
