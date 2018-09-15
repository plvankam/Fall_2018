#include<iostream>
#include<fstream>

using std::endl;

int main()
{

    std::ofstream writeToFile;
    std::ifstream readFromFile;
    std::string txtToWrite = "";
    std::string txtFromFile; 

    // ios::app : Append to the end of file
    // ios::trunc : If file exists delete content 
    // ios::in : Open file for reading
    // ios::out : Open file for writing 
    // ios::ate : Open writing and move to the end of the file 

    writeToFile.open("test.txt",std::ios_base::out | 
                                std::ios_base::trunc);
    if(writeToFile.is_open()){
        writeToFile << "Beginning of file" << endl;
        std::cout << "Enter data to write to file: ";
        getline(std::cin, txtToWrite);
        writeToFile << txtToWrite;
        writeToFile.close();
    }

    readFromFile.open("test.txt", std::ios_base::in);
    if(readFromFile.is_open()){
        while(readFromFile.good()) {
            getline(readFromFile, txtFromFile);
            std::cout << txtFromFile << endl;
        }
    }
    readFromFile.close();


    return 0;
}
