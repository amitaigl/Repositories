#pragma managed (extern "C")
#include <string>
#include "../Core/pch.h" // Assuming your DLL header

#include <msclr/marshal.h> // For .NET marshalling#pragma managed (extern "C")


// Function declaration using P/Invoke attributes
//extern "C" __declspec(dllimport) int open(int a);
//__declspec(dllimport) int open(int a);

public ref class Amitai
{
public:
    int check(int a)
    {
        int result = open(a); // Call the exported function
        //Console::WriteLine("Result: {0}", result);

        // ...

        return 0;
    }
};


/*using namespace std;
public ref class MyCppCliWrapper
{
public:
    void OpenFile(string filePath)
    {
        // Convert .NET string to C++ std::string for P/Invoke
        std::string cppFilePath = msclr::interop::marshal_as<std::string>(filePath);
        std::string cppFilePath = "sshsh";

        // Call the C++ DLL function using P/Invoke
        open(cppFilePath.c_str());
    }
};*/