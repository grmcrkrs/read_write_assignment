#include <iostream>
#include <string> //string manipulation
#include <fstream> //file io operations
#include <vector> //needed for vector
#include <sstream> //string stream, makes input stream from string

using namespace std; //saves my typing fingers from typing std:: over and over


//function that converts Fahrenheit to Celcius
//takes one int argument, the temperature in Fahrenheit
//returns an int (the converted temperature in Celcius)
int farToCel(int cityTempFahrenheit){
    double tempCelcius;
    tempCelcius = (cityTempFahrenheit - 32) * (5.0 / 9.0); //equation to calculate celcius
    return tempCelcius;

}

//function to read a file, and output it's contents
//into a vector of pairs. void return, updates variables in main()
//for more intense use, a vector of maps would be better
void readStringIntPairFile(const string& readFileName, string& myText,
                           vector<pair<string, int>>& holderVectorPair,
                           pair<string, int>& cityAndTemp){
    
    string cityName; //expected 1st item on line
    int temperature; //expected 2nd item on line

    cout << "Searching for: \"" << readFileName << "\""<< endl;

    //opens file, assumes file is in same directory
    ifstream ReadFile(readFileName);

    try { //error catching, try the following

        //checks if file opened or not
        if (ReadFile.is_open()) {

            cout << "File: " << readFileName << " is successfully open" << endl;

            //goes line by line in ReadFile
            //puts text into myText
            while (getline(ReadFile, myText)) {

                //puts each line myText
                //into an input stream name ss (StringStream)
                istringstream ss(myText);

                ss >> cityName >> temperature;
//                //convert before writing to pair/vector
//                temperature = farToCel(temperature);
                cityAndTemp = make_pair(cityName, temperature); //put pair together
                holderVectorPair.push_back(cityAndTemp); //put pair in vector

            }

            ReadFile.close(); //close file, free up memory

        } else{ //if file not found
            throw 505; //throw this error (number has no meaning)
        }
    }catch(int exceptionNumber){ //print error, stop program
        cout << "Error " << exceptionNumber << ":     \"" << readFileName <<"\" not found";
    }
}

//function to convert the temperature inside a pair in a vector
//void return type, updates the variables in main()
void convertTempsInVector(pair <string, int>& cityAndTemp, vector<pair<string, int>>& holderVectorPair){
        for (auto &i : holderVectorPair) { //iterate through vector
            i.second =  farToCel(i.second); //rewrite temperature to celcius
        }
}

//function to print the vector's contents
//void return type
void printVectorOfPairs(const vector<pair<string, int>>& holderVectorPair) {
    cout << endl << "Contents of vector NOW:" << endl;
    for (auto &i : holderVectorPair) { //iterate through vector
        cout << i.first << " " << i.second << endl; //print pair
    }
}

//function to write the finished vector of pairs to a file
//void return type
void writeFile(string& writeFileName, pair<string, int> p, vector<pair<string, int>> v){
    ofstream WriteFile(writeFileName); //writing the file

    //loop through vector
    for (auto &i : v) {
        WriteFile << i.first << " " << i.second << endl; //write each vector pair with newline
    }
    cout << endl << "File: \"" << writeFileName << "\" was successfully written" << endl;
    WriteFile.close(); //close the file to free memory

}

//the one and only main()
int main() {
    pair <string, int> cityAndTemp; //stuct holding a pair, like a tuple
    vector<pair<string, int>> holderVectorPair; //vector of pairs
    
    string myText; //string to hold the entire file's worth of data as a string
    string readFileName = "FahrenheitTemperature.txt"; //name of file to be read
    string writeFileName = "CelsiusTemperature.txt"; //name of file to be written

    //read the lines into pairs, pairs into a vector, then print
    readStringIntPairFile(readFileName, myText, holderVectorPair, cityAndTemp);

    //print contents of vector for testing
    printVectorOfPairs(holderVectorPair);
    cout << endl;

    //convert the temperatures to celcius
    convertTempsInVector(cityAndTemp, holderVectorPair);

    //print contents of vector to std out for testing
    printVectorOfPairs(holderVectorPair);

    //write data to new file
    writeFile(writeFileName, cityAndTemp, holderVectorPair);

    return 0;
}
