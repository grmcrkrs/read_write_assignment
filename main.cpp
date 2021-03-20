#include <iostream>
#include <fstream> //file io operations
#include <utility>
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

int main() {
    pair <string, int> cityAndTemp; //stuct holding a pair, like a tuple
    vector<pair<string, int>> holderVectorPair; //vector of pairs

    string myText;
    string cityName;
    int temperature;

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

            ss >> cityName >> temperature;
            //convert before writing to pair/vector
            temperature = farToCel(temperature);
            cityAndTemp = make_pair(cityName, temperature);
            holderVectorPair.push_back(cityAndTemp);

        }

        for (auto &i : holderVectorPair) {
            cout << i.first << " " << i.second << endl;
        }

        ReadFile.close();
    }
    return 0;
}
