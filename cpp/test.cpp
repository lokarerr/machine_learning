#include <iostream>  // pre-processor directive: Include the iostream library with macros and functions for input/output
#include <unordered_map>

//using namespace std;

void calculate_square(int &num) {
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
        // Operator Overloading
        // Only existing operators can be overloaded. The number of arguments it can take depends on the type of operator
        // Some operators can't be overloaded: .*, ., ::, ?: etc.
        OrderedMapAccessor operator+(const OrderedMapAccessor &other_map);
};

OrderedMapAccessor OrderedMapAccessor::operator+(const OrderedMapAccessor &other_map) {
    for (auto it = other_map.data.begin(); it != other_map.data.end(); ++it) {
        data[it->first] = it->second;
    }
    return data;
}

void OrderedMapAccessor::print_map() {
    std::cout << "Unordered Map contents:" << std::endl;
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

class alpha {
    private: 
        // members that are accessible only to members and are not inherited
        int ax, bx;
    protected: 
        // members that are inherited and be used by children of the class
        // when child class is public, these get inherited as 'protected'
        // when child class is private, these get inherited as 'private'
        int px, qx;
    public:
        // members that are inherited and are available outside the class
        alpha(int x, int y) {
            ax = x;
            bx = y;
        }
        void display() {
            std::cout << "contents: " << ax << " " << bx << std::endl;
        }
};

class beta {
    private: 
        // members that are accessible only to members and are not inherited
        int ax, bx;
    protected: 
        // members that are inherited and be used by children of the class
        // when child class is public, these get inherited as 'protected'
        // when child class is private, these get inherited as 'private'
        int px, qx;
    public:
        // members that are inherited and are available outside the class
        beta(int x, int y) {
            ax = x;
            bx = y;
        }
        void display() {
            std::cout << "contents: " << ax << " " << bx << std::endl;
        }
};

// Gamma inherits from alpha and beta
class gamma:public alpha, public beta {
    public:
        void display_gamma();
};

void gamma::display_gamma() {
    alpha::display();
    beta::display();
}

int main() {
    int x;  
    int *p; //integer type pointer
    p = &x; // pointer points to address of variable x
    *p = 10;
    std::cout << "Value of x is " << x << std::endl;
    calculate_square(x);
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

    std::unordered_map<std::string, int> mymap2 = {
        {"tool.xx", 53},
        {"tool.yy", 44},
    };
    OrderedMapAccessor map2_access(mymap2);
    map_access + map2_access;
    map_access.print_map();

}