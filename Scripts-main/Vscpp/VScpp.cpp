#include <bits/stdc++.h>
using namespace std;




string portion(string s, int start, int end); // Used for slicing


int main(int argc, char *argv[]) 
{
    cout << "\n";
    if (argc > 2 || argc == 1)
    {
        cout << "[!] Please Enter one command line argument.\n";
        return 1;
    }
    
    string s="", arg=argv[1];
    int l = arg.length();


    if (portion(arg, l-4, l) != ".cpp")
    {
        cout << "[!] Please enter the filename extension (.cpp)\n";
        return 1;
    }

    ofstream outFile("input.txt");

    for (int i=0; i<l-3; i++)
    {
        int car = arg[i];
        if ((car > 64 && car < 123) || (car > 47 && car < 58))
        {
            s+=arg[i];
        }
    }
    s+=".cpp";

    std::string userProfile;
    std::string sourceFilePath;

    string path = "";

    //Get the path of the executed file to locate cpp.cpp easily
    //The location needs to be detected automatically

    #ifdef _WIN32
        path = "Documents\\zdo\\Vscpp";
        userProfile = std::getenv("USERPROFILE");
        cout << userProfile + "\\" + path + "\\cpp.cpp" << endl;
        sourceFilePath = userProfile + "\\" + path + "\\cpp.cpp";
    #else
        path = "Documents/Projects/Scripts/Vscpp";
        userProfile = std::getenv("HOME");
        sourceFilePath = userProfile + "/" + path + "/cpp.cpp";
    #endif

    std::ifstream sourceFile(sourceFilePath, std::ios::binary);
    std::ofstream destFile(s, std::ios::binary);
    
    if (sourceFile && destFile) {
        destFile << sourceFile.rdbuf();  // Copy the contents of the source file to the destination file
        std::cout << "File copied successfully!" << std::endl;
    } else {
        std::cout << "Failed to open files for copying." << std::endl;
    }

    sourceFile.close();
    destFile.close();
    outFile.close();
    
    string vs = "code ./" + s;
    const char *runVS = vs.c_str();
    system("code input.txt");
    system(runVS);
    cout << "\n[+] Done.\n";
}




string portion(string s, int start, int end)
{
    string st="";
    for (int i=start; i<end; i++)
    {
        st+=s[i];
    }
    return st;
}