#include <iostream>  // pre-processor directive: Include the iostream library with macros and functions for input/output
#include <unordered_map>

//using namespace std;

void calculate_suare(int &num) {
    //The symbol '&' is also used as a reference variable or alias. 
    // its a pointer to a variable that is being passed to this function.
    // So this function can directly change the value of that variable 
    num = num*num;
}

struct tool {
    std::string name;
    std::string version;
};


class OrderedMapAccessor {
    private:
        std::unordered_map<std::string, int> data;

    public:
        // Constructor: function with same name as of the class. 
        // Should be public, gets called when an object is created
        // Cannot be inherited
        // Has no return type
        OrderedMapAccessor(const std::unordered_map<std::string, int>& map) : data(map) {}
        // Using const in the args makes sure that the function cannot change the contents of the input.
        void print_map();
        void find_key_return_val(std::string key_to_find);
};

void OrderedMapAccessor::print_map() {
    std::cout << "Ordered Map contents:" << std::endl;
    for (const auto& pair : data) {
        std::cout << "Key: " << pair.first << " -> Value: " << pair.second << std::endl;
    }
}

void OrderedMapAccessor::find_key_return_val(std::string key_to_find) {
    auto it = data.find(key_to_find);
    if (it != data.end()) {
        std::cout << "Element with key " << key_to_find << ": " << it->second << std::endl;
    } else {
        std::cout << "Key " << key_to_find << " not found." << std::endl;
    }

}

int main() {
    int x;  
    int *p; //integer type pointer
    p = &x; // pointer points to address of variable x
    *p = 10;
    std::cout << "Value of x is " << x << std::endl;
    calculate_suare(x);
    std::cout << "Value of x squared is " << x << std::endl;

    // Memory allocation and dellocation
    float *fp = new float;
    *fp = 2.05;
    delete fp;

    // Created unordered_map (dict)
    std::unordered_map<std::string, int> mymap = {
        {"tool1", 1},
        {"tool2", 4},
        {"tool", 5}
    };
    OrderedMapAccessor map_access(mymap);
    map_access.print_map();
    map_access.find_key_return_val("tool");

}