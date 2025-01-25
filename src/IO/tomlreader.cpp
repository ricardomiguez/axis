#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <stdexcept>

class TOMLReader {
private:
    std::unordered_map<std::string, std::string> properties;

    void parseLine(const std::string& line) {
        // Skip empty lines or comments
        if (line.empty() || line[0] == '#') {
            return;
        }

        // Find the '=' separator
        size_t equalsPos = line.find('=');
        if (equalsPos == std::string::npos) {
            throw std::runtime_error("Invalid line format: " + line);
        }

        // Extract key and value, trimming whitespace
        std::string key = line.substr(0, equalsPos);
        std::string value = line.substr(equalsPos + 1);

        trim(key);
        trim(value);

        // Remove quotes from value if present
        if (!value.empty() && (value[0] == '"' || value[0] == ''')) {
            value = value.substr(1, value.size() - 2);
        }

        properties[key] = value;
    }

    void trim(std::string& str) {
        size_t first = str.find_first_not_of(" 	");
        if (first == std::string::npos) {
            str = "";
            return;
        }
        size_t last = str.find_last_not_of(" 	");
        str = str.substr(first, (last - first + 1));
    }

public:
    // Reads the .toml file and loads properties into memory
    void readPropertyFile(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + filePath);
        }

        std::string line;
        while (std::getline(file, line)) {
            parseLine(line);
        }

        file.close();
    }

    // Checks if a specific property exists
    bool propertyExists(const std::string& propertyName) const {
        return properties.find(propertyName) != properties.end();
    }

    // Retrieves the value of a property, throws if not found
    std::string getBasicProperty(const std::string& propertyName) const {
        auto it = properties.find(propertyName);
        if (it == properties.end()) {
            throw std::runtime_error("Property not found: " + propertyName);
        }
        return it->second;
    }

    // Optionally, retrieves the value with a default fallback
    std::string getBasicPropertyOrDefault(const std::string& propertyName, const std::string& defaultValue) const {
        auto it = properties.find(propertyName);
        if (it == properties.end()) {
            return defaultValue;
        }
        return it->second;
    }
};

// Example usage
int main() {
    try {
        TOMLReader reader;
        reader.readPropertyFile("example.toml");

        std::string key = "username";
        if (reader.propertyExists(key)) {
            std::cout << key << ": " << reader.getBasicProperty(key) << std::endl;
        } else {
            std::cout << key << " not found." << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

