#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(const std::vector<int>& angka, int target) {
    std::unordered_map<int, int> angka_to_index;
    
    for (int index = 0; index < angka.size(); ++index) {
        int angka = angka[index];
        int complement = target - angka;
        
        if (angka_to_index.find(complement) != angka_to_index.end()) {
            return {angka_to_index[complement], index};
        }
        
        angka_to_index[angka] = index;
    }
    
    return {};
}

int main() {
    std::vector<int> angka = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = twoSum(angka, target);
    
    if (!result.empty()) {
        std::cout << "Output: {" << result[0] << ", " << result[1] << "}\n";
    } else {
        std::cout << "tidak ditemukan.\n";
    }
    
    return 0;
}