#include <iostream>
#include <string>

using namespace std;

int main() {
    const int MAX_FILES = 100;
    string files[MAX_FILES];
    int fileCount;

    cout << "Enter number of files to scan: ";
    cin >> fileCount;
    cin.ignore(); // Clear newline from input buffer

    if (fileCount > MAX_FILES) fileCount = MAX_FILES;

    // Input file paths
    for (int i = 0; i < fileCount; ++i) {
        cout << "Enter file path #" << (i + 1) << ": ";
        getline(cin, files[i]);
    }

    // Input filename to search for
    string target;
    cout << "Enter filename to search for: ";
    getline(cin, target);

    // Search for filename in the paths
    bool found = false;
    for (int i = 0; i < fileCount; ++i) {
        string path = files[i];
        size_t pos = path.find_last_of("/\\");
        string name = (pos == string::npos) ? path : path.substr(pos + 1);

        if (name == target) {
            cout << "Found: " << path << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "File not found." << endl;
    }

    return 0;
}



