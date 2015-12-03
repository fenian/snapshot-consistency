#include <string>
#include <iostream>
#include <cstdio>
#include <memory>

std::string exec(const char* cmd);

int main() {
    // keep backing up.
    while (true) {
    	std::string result = exec("mongodump --quiet");
    }
}

std::string exec(const char* cmd) {
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while (!feof(pipe.get())) {
        if (fgets(buffer, 128, pipe.get()) != NULL)
            result += buffer;
    }
    return result;
}
