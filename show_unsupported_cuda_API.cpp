#include <iostream>
#include <fstream>
#include <map>
using namespace std;



int main(int argc, char *argv[])
{
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <file_name>" << endl;
        return 1;
    } 

    ifstream file(argv[1]); // Replace with your file name
    string line;
    std::map<std::string, int> unsupported_api_map;

    if (file.is_open()) {
        while (getline(file, line)) {
            // Process the line
            if (line.find("DPCT1007") != std::string::npos) {
              int start = line.find("Migration of") + 12;
              int end = line.rfind("is not supported.") - 1;
              int length = end - start + 1;

              string unsupported_api_name = line.substr(start, length);
              unsupported_api_map[unsupported_api_name] += 1;
            }
        }
        file.close();
    } else {
        cerr << "Unable to open file" << endl;
    }

    // Open a file in write mode
    string filename = (string)argv[1]; 
    int lastindex = filename.find_last_of("."); 
    string csvname = filename.substr(0, lastindex) + ".csv";
    std::ofstream csv_file(csvname);
    if (!csv_file.is_open()) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return 1;
    }

    // Write the header row (optional)
    csv_file << "Unsupported API, Counts\n";
    // Iterate over the map and write key-value pairs to the file
    for (const auto& pair : unsupported_api_map) {
        cout << pair.first << ", " << pair.second << endl;
        csv_file << pair.first << "," << pair.second << "\n";
    }

    return 0;
}
