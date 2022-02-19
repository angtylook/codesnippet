#include <iostream>

#include "nlohmann/json.hpp"

int main() {
    nlohmann::json js = nlohmann::json::parse(R"({"obj":12, "info": [{"id": 1, "label": "a"}, {"id": 2, "label": "b"}, {"id": 3, "label": "c"}]})");
    for(auto& it : js["info"]) {
        if(it.contains("label")) {
            std::cout << it["label"] << std::endl;
        }
    }
    return 0;
}