#include <iostream>
using std::cout;

void mostraArr2DInt(const int gradesArray[][3]);
void emFormaTabular(const int arrei[][3]);
int main(){
    const int arraySize=3;
    int table [arraySize][arraySize];

    for (int i=0;i<arraySize;i++)
        for (int j=0; j<arraySize; j++)
            table[i][j] = i + j;
    
    mostraArr2DInt(table);
    emFormaTabular(table);

    int table2 [arraySize][arraySize]={{1,8},{2,4,6},{5}};
    emFormaTabular(table2);

}


void mostraArr2DInt(const int arrei[][3]){
    cout << "\n";
    for ( int student = 0; student < 3; student++ ) {
        for ( int test = 0; test < 3; test++ )
            cout << "[" << student << "," << test << "]=" << arrei[ student ][ test ] << " ";

        cout << "\n";
    }
    cout << "\n";

}

void emFormaTabular(const int arrei[][3]){
    cout << "\t[0]\t[1]\t[2]\n";
    for (int i=0;i<3;i++) {
        cout << "[" << i << "]\t";
        for (int j=0; j<3; j++)
            cout << arrei[i][j] << "\t";

        cout << "\n";
    }

    cout << "\n";
}