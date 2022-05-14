//
//  Controller.hpp
//  City Map
//
//  Created by Kaloyan Dimov on 13.05.22.
//

#ifndef Controller_hpp
#define Controller_hpp

#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "CityMap.hpp"
#include "Command.hpp"
#include "CommandParser.hpp"
#include "Intersection.hpp"

class Controller {
 public:
    Controller(const std::string&, const std::string&, std::istream& = std::cin, std::ostream& = std::cout, std::ostream& = std::cerr);
    Controller(const Controller&) = delete;
    Controller& operator=(const Controller&) = delete;
    Controller(Controller&&) = delete;
    Controller& operator=(Controller&&) = delete;
    ~Controller() = default;
    
    void run();
    void stop();
    
 private:
    CityMap map;
    Intersection* position;
    std::vector<std::string> closed_intersections;
    bool running;
    
    std::istream& in;
    std::ostream& out;
    std::ostream& err;
    
    static std::unordered_map<std::string, Command> commands;
    static bool init;
    
    static void register_command(const std::string&, const std::string&, const Function&);
    static bool init_commands();
};

#endif /* Controller_hpp */