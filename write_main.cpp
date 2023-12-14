#include <iostream>
#include <fstream>
#include <map>
#include <string>

enum MODE {
    LED,
    TACTILE,
    BUZZER,
    TIME,
    LDR,
    PIR
};

std::map<std::string, MODE> mode_map = {
    {std::string("led"), LED},
    {std::string("tact"), TACTILE},
    {std::string("buz"), BUZZER},
    {std::string("time"), TIME},
    {std::string("ldr"), LDR},
    {std::string("pir"), PIR}
};

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: make <file>" << std::endl;
        return 1;
    }
    if (mode_map.find(argv[1]) == mode_map.end()) {
        std::cout << "Invalid mode: " << argv[1] << std::endl;
        return 1;
    }

    std::ofstream ofs("./src/main.cpp");
    std::string diagram;
    switch(mode_map[argv[1]]){
        case LED:
            ofs << "#include \"../lib/LED.cpp\"" << std::endl;
            break;
        case TACTILE:
            ofs << "#include \"../lib/Tactile.cpp\"" << std::endl;
            break;
        case BUZZER:
            ofs << "#include \"../lib/Buzzer.cpp\"" << std::endl;
            break;
        case TIME:
            ofs << "#include \"../lib/Time.cpp\"" << std::endl;
            break;
        case LDR:
            ofs << "#include \"../lib/LDR.cpp\"" << std::endl;
            break;
        case PIR:
            ofs << "#include \"../lib/PIR.cpp\"" << std::endl;
            break;
        default:
            break;
    }
    ofs.close();

    return 0;
}