#include <iostream>
#include <fstream> //file io operations
#include <utility>
#include <vector> //needed for vector
#include <sstream> //string stream, makes input stream from string

using namespace std;

int main() {
    pair <string, int> cityAndSize; //stuct holding a pair, like a tuple
    vector<pair<string, int>> holderVectorPair; //vector of pairs

    string myText;
    string cityName;
    int size;
    int iterator = 0;

    //opens file, assumes file is in same directory
    ifstream ReadFile("sampledata.txt");

    //checks if file opened or not
    if(ReadFile.is_open()) {

        //goes line by line in ReadFile
        //puts text into myText
        while (getline(ReadFile, myText)) {

            //puts each line myText
            //into an input stream name ss (StringStream)
            istringstream ss(myText);

            ss >> cityName >> size;
            cityAndSize = make_pair(cityName, size);
            holderVectorPair.push_back(cityAndSize);

        }

        for (auto &i : holderVectorPair) {
            cout << i.first << " " << i.second << endl;
        }

        ReadFile.close();
    }
    return 0;
}
