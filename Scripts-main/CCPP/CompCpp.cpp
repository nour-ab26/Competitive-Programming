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
    
    int l = strlen(argv[1]);
    string s="", arg=argv[1];

    if (portion(arg, l-4, l) != ".cpp")
    {
        cout << "[!] Please enter the filename extension (.cpp)\n";
        return 1;
    }
    
    for (int i=0; i<l-3; i++)
    {
        int car = arg[i];
        if ((car > 64 && car < 123) || (car > 47 && car < 58))
        {
            s+=arg[i];
        }
    }
    s+=".cpp";
    
    string vs = "g++ -Wall ./" + s;
    const char *runVS = vs.c_str();
    cout << "[-] Compiling ...\n";
    int err = system(runVS);
    if (err) {cout << "[!] Compilation Error.\n"; exit(1);}
    cout << "\n[+] Compiled Successfully.\n";
    string exe = "./a.out";
    const char *runCmp = exe.c_str();
    cout << "[*] Running ...\n";
    system(runCmp);
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