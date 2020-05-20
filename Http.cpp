#pragma comment(lib, "urlmon.lib")

#include <urlmon.h>
#include <sstream>
#include <iostream>

using namespace std;

int main() {

    IStream* stream;
    HRESULT result = URLOpenBlockingStream(0, L"https://swenenzy.com/test.json", &stream, 0, 0); // Any Url
    if (result != 0)
    {
        return 1;
    }
    char buffer[100];
    unsigned long bytesRead;
    stringstream ss;
    stream->Read(buffer, 100, &bytesRead);
    while (bytesRead > 0U)
    {
        ss.write(buffer, (long long)bytesRead);
        stream->Read(buffer, 100, &bytesRead);
    }
    string resultString = ss.str();
    std::cout << "Data : \n"<< resultString << std::endl;
    
}