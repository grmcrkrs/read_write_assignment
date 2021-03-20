#include <iostream>
#include <fstream> //file io operations
#include <vector> //needed for vector
#include <sstream> //string stream, makes input stream from string

using namespace std;

//function that converts Fahrenheit to Celcius
//takes one int argument, the temperature in Fahrenheit
//returns an int (the converted temperature in Celcius)
int farToCel(int cityTempFahrenheit){
    double tempCelcius;
    tempCelcius = (cityTempFahrenheit - 32) * (5.0 / 9.0);
    return tempCelcius;

}

void readStringIntPairFile(const string& readFileName, string& myText,
                           vector<pair<string, int>>& holderVectorPair,
                           pair<string, int>& cityAndTemp){
    
    string cityName;
    int temperature;
    //opens file, assumes file is in same directory
    ifstream ReadFile(readFileName);

    try {

        //checks if file opened or not
        if (ReadFile.is_open()) {

            //goes line by line in ReadFile
            //puts text into myText
            while (getline(ReadFile, myText)) {

                //puts each line myText
                //into an input stream name ss (StringStream)
                istringstream ss(myText);

                ss >> cityName >> temperature;
//                //convert before writing to pair/vector
//                temperature = farToCel(temperature);
                cityAndTemp = make_pair(cityName, temperature);
                holderVectorPair.push_back(cityAndTemp);

            }
                //fixme remove
                //test print statement
//            for (auto &i : holderVectorPair) {
//                cout << i.first << " " << i.second << endl;
//            }

            ReadFile.close();
        }
    }catch(...){
        cout << "There was an error";
    }
}

void conversionOfTempsInVector(pair <string, int>& cityAndTemp, vector<pair<string, int>>& holderVectorPair){
        for (auto &i : holderVectorPair) {
            i.second =  farToCel(i.second);
        }
}

void printVectorOfPairs(const vector<pair<string, int>>& holderVectorPair) {
    for (auto &i : holderVectorPair) {
        cout << i.first << " " << i.second << endl;
    }
}

int main() {
    pair <string, int> cityAndTemp; //stuct holding a pair, like a tuple
    vector<pair<string, int>> holderVectorPair; //vector of pairs
    
    string myText; //string to hold the entire file's worth of data as a string
    string readFileName = "sampledata.txt"; //name of file to be read
    string writeFileName = "CelsiusTemperature.txt"; //name of file to be written

    //read the lines into pairs, pairs into a vector, then print
    readStringIntPairFile(readFileName, myText, holderVectorPair, cityAndTemp);

    //convert the temperatures to celcius
    conversionOfTempsInVector(cityAndTemp, holderVectorPair);
//    //opens file, assumes file is in same directory
//    ifstream ReadFile(readFileName);
//
//    try {
//
//        //checks if file opened or not
//        if (ReadFile.is_open()) {
//
//            //goes line by line in ReadFile
//            //puts text into myText
//            while (getline(ReadFile, myText)) {
//
//                //puts each line myText
//                //into an input stream name ss (StringStream)
//                istringstream ss(myText);
//
//                ss >> cityName >> temperature;
//                //convert before writing to pair/vector
//                temperature = farToCel(temperature);
//                cityAndTemp = make_pair(cityName, temperature);
//                holderVectorPair.push_back(cityAndTemp);
//
//            }
//
//            for (auto &i : holderVectorPair) {
//                cout << i.first << " " << i.second << endl;
//            }
//
//            ReadFile.close();
//        }
//    }catch(...){
//        cout << "There was an error";
//    }

//fixme uncomment

//    ofstream WriteFile(writeFileName);
//
//    for (auto &i : holderVectorPair) {
//        WriteFile << i.first << " " << i.second << endl;
//    }
//    WriteFile.close();
    return 0;
}
