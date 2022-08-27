#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string palavra;
    cin >> palavra;
    cout << palavra;
    int vogais[5] = {}; // a e i o u;
    for (int i = 0; i < palavra.size(); i++)
    {
        if (palavra[i] == 'a') {

            vogais[0]++;
        
        } else if (palavra[i] == 'e') {
            
             vogais[1]++;

        } else if (palavra[i] == 'i') {

             vogais[2]++;

        } else if (palavra[i] == 'o') {

             vogais[3]++;

        } else if (palavra[i] == 'u') {
             vogais[4]++;
        }

    }
    cout << "\n";

    for (int i = 0; i < 5; i++)
    {
        
        if (vogais[i] > 0) {

           if (i == 0) {

               cout << "a " <<  vogais[i] << endl;
           } else if (i == 1){

                cout << "e " <<  vogais[i]  << endl;

           } else if (i == 2){
               
                cout << "i " <<  vogais[i]  << endl;

           } else if (i == 3){
               
                cout << "o " <<  vogais[i]  << endl;

           } else if (i == 4){

                cout << "u " <<  vogais[i]  << endl;
               
           } 
        } 

    }
    
    return 0;
}