#include <iostream>

// Manually declare the extern function to ensure the linker finds the C-style name
extern "C" float get_sonar_intensity_at_range(float range);

int main() {
    float range = 10.5;
    std::cout << "C++: Requesting sonar intensity for range: " << range << "m" << std::endl;
    
    // Call the direct C-style export
    float intensity = get_sonar_intensity_at_range(range);
    
    std::cout << "C++: Received intensity from Rust: " << intensity << std::endl;
    return 0;
}