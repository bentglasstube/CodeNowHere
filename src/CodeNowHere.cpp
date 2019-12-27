//******************************************************************************************
// File: CodeNowHere.cpp
// Author: Sergio Ortiz Paz
// Created: Mon Dec 23 22:18:25 2019
// Description: Classes in charge of process the input data from console and showing output
//******************************************************************************************
#include "../headers/CodeNowHere.h"

CodeNowHere::CodeNowHere() {
    blowExtensions();
}


void CodeNowHere::blowExtensions() {
    commentMap[".py"] = "#";
    commentMap[".cpp"] = "//";
    commentMap[".c"] = "//";
    commentMap[".java"]  = "//";
    commentMap[".ada"] = "--";
    commentMap[".js"] = "//";
    commentMap[".php"] = "#";
    commentMap[".rb"] = "#";
}


void CodeNowHere::captureConsoleInput(int argc, char * argv[]) {
    // Capture input from console and process it
    author = "";
    description = "";
    fileName = argv[1];
    for (int i = 0; i < argc; i++) {
        string param = argv[i];
        if (param == "-a"){
            // Author param specified
            //cout << "Author of the file specified" << endl;
            author = argv[i+1];

        } else if (param == "-d") {
            // Description param specified
            //cout << "Description of the file specified" << endl;
            description = argv[i+1];
        } else if (param == "-h") {

        }
    }
}

string CodeNowHere::getExtension(string fileName) {
    string ext;
    size_t dotPosition = fileName.find(".");
    ext = fileName.substr(dotPosition);
    return ext;
}

void CodeNowHere::createCode() {
    string ext = getExtension(fileName);
    string comment = commentMap[ext];
    // file name validation here
    time_t now = time(0);
    char* dt = ctime(&now);
    dateOfCreation = string(dt);

    ofstream file;
    file.open(fileName);
    file << comment << " **************************************************************************** " << endl;
    file << comment << " File: " << fileName << endl;
    file << comment << " Author: " << author << endl;
    file << comment << " Created: " << dateOfCreation;
    file << comment << " Description: " << description << endl;
    file << comment << " **************************************************************************** " << endl;
    file.close();

}

Helper::Helper() {
    version = "1.0";
    blowMessages();
}

void Helper::blowMessages() {
    messages["badInput"] = "Some option is missing or some parameters are invalid! \nCheck help typing cnw -help";
    static const char USAGE[] =
    R"(CodeNowHere (cnh).

        Usage:
            cnh (<file name with extension>) [-option <argument>]...
            cnh (-h | --help)
            cnh --version
        
        Options:
            -h --help       Show this screen.
            --version       Show version.
            -a --author     Specify the author of the code.
            -d --desc       Specify a brief description of the file.
    )";
    messages["usage"] = string(USAGE);
}

string Helper::getBadInput(){
    return messages["badInput"];
}

string Helper::getUsage(){
    return messages["usage"];
}

string Helper::getVersion(){
    return version;
}
