#include <iostream>
using namespace std;
namespace fs = std::filesystem;

void searchFile(const fs::path& directory, const std::string& filename) {
    try {
        for (const auto& entry : fs::recursive_directory_iterator(directory)) {
            if (entry.is_regular_file() && entry.path().filename() == filename) {
                std::cout << "Found: " << entry.path() << std::endl;
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    std::string directoryPath;
    std::string filename;

    std::cout << "Enter the directory path to search: ";
    std::getline(std::cin, directoryPath);
    std::cout << "Enter the filename to search for: ";
    std::getline(std::cin, filename);

    fs::path dirPath(directoryPath);

    if (fs::exists(dirPath) && fs::is_directory(dirPath)) {
        searchFile(dirPath, filename);
    } else {
        std::cerr << "The provided path is not a valid directory." << std::endl;
    }

    return 0;
}
