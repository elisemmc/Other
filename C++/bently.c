#include <algorithm>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cctype>



using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        cout << line << endl;
        
        line.erase( remove_if(line.begin(), line.end(), isspace), line.end());
        transform( line.begin(), line.end(), line.begin(), ::tolower);
        
        std::sort(line.begin(), line.end());
        line.erase(unique(line.begin(), line.end()), line.end());
        
        for( int i = 0; i < line.length(); i++)
        {
            printf("%s,", line[i]);
        }
    }
}
