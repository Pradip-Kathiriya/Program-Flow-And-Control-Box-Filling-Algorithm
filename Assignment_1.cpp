/**
 * @file Assignment_1.cpp
 * @author Pradip (pradip@umd.edu)
 * @brief RWA1 : Program Flow Control and Function
 * @version 0.1
 * @date 2021-09-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<iostream>
#include<string>

/**
 * @brief to check wether the input is positive integer or not
 * 
 * @param s
 * @return true 
 * @return false 
 */

bool isInteger(std::string s);

/**
 * @brief Get the total numbers of parts to be placed in the boxes
 * 
 * @return unsigned Number of parts enter by the user
 */

unsigned int get_total_parts();

/**
 * @brief Get the total number of boxes of each type
 * 
 * @param struct data  structure to hold box/part information
 */

void get_total_boxes(struct s1 & var1);

/**
 * @brief Get the number of parts for each box type
 * 
 * @param struct s2 data structure to hold box/part information
 */

void get_part_per_boxes(struct s2 & var2);

/**
 * @brief Fill up boxes from user inputs
 * 
 * @param struct s data structure to hold box/part information
 */

void fill_up_boxes(const struct s & var);

 //  initializing struct data structure

struct s1 {             
    unsigned int small_boxes{}; // How many boxes for small
    unsigned int medium_boxes{}; // How many boxes for medium
    unsigned int large_boxes{}; // How many boxes for large
    unsigned int extra_large_boxes{}; // How many boxes for extra large
};

struct s2 {
    unsigned int parts_small_boxes{}; // How many parts can be placed in small boxes
    unsigned int parts_medium_boxes{}; // How many parts can be placed in medium boxes
    unsigned int parts_large_boxes{}; // How many parts can be placed in large boxes
    unsigned int parts_extra_large_boxes{}; // How many parts can be placed in extra large boxes
};

struct s {
    struct s1 member1{};
    struct s2 member2{};
    unsigned int total_boxes{};
};

/**
 * @brief Main function
 * 
 * @return return the part distribution for each box type
 */

int main(){
    unsigned int t;
    t = get_total_parts();
    struct s1 var1{};
    get_total_boxes(var1);
    struct s2 var2{};
    get_part_per_boxes(var2);
    struct s var = {var1, var2,t};
    fill_up_boxes(var);

}

bool isInteger(std::string s){
    for(int i=0; i < s.length();i++)
        if (isdigit(s[i])==false)
            return false;
        else if (std::stoi(s)==0)
            return false;
        else
            return true;
}

unsigned int get_total_parts(){ 
    std::string total_parts{};
    while (true){
        std::cout << "How many parts in total? : ";
        std::getline(std::cin >> std::ws,total_parts);
        if (isInteger(total_parts)){ // to check wether the input is positive integer or not
            return std::stoi(total_parts);
            break;
        }
    }   
}

void get_total_boxes(struct s1 & var1){
    std::string s{}; 
    std::string m{};
    std::string l{};
    std::string xl{};
    while (true){
        std::cout << "How many boxes for S/M/L/XL? : ";
        std::cin >> s >> m >> l >> xl ;
        if (isInteger(s) && isInteger(m) && isInteger(l) && isInteger(xl)) // to check wether the input is positive integer or not
            {var1.small_boxes = (unsigned int)std::stoi(s); // Assign the value of user input to struct s1
            var1.medium_boxes = (unsigned int)std::stoi(m);
            var1.large_boxes = (unsigned int)std::stoi(l);
            var1.extra_large_boxes = (unsigned int)std::stoi(xl);
            break; 
            }
    }

}

void get_part_per_boxes(struct s2 & var2){
    std::string s{};
    std::string m{};
    std::string l{};
    std::string xl{};
    while (true) {
        std::cout << "How many parts per boxes for S/M/L/XL? : ";
        std::cin >> s >> m >> l >> xl ;
        if (isInteger(s) && isInteger(m) && isInteger(l) && isInteger(xl) && std::stoi(s) < std::stoi(m) && std::stoi(m) < std::stoi(l) && std::stoi(l) < std::stoi(xl) )  // check the condition given in the statements
            {var2.parts_small_boxes = (unsigned int)std::stoi(s); // Assign the value of user input to struct s2
             var2.parts_medium_boxes = (unsigned int)std::stoi(m);
             var2.parts_large_boxes = (unsigned int)std::stoi(l);
             var2.parts_extra_large_boxes = (unsigned int)std::stoi(xl);
             break;
             }
    }

}

void fill_up_boxes(const s & var){
    int j{0}; // initialize the varible to count the number of filled boxes
    int total = var.total_boxes;
    std::cout << "Boxes that can be build with " << total << " pegs" << '\n';
    std::cout << "----------------------------------------------------------------------------" << '\n';
    for (int i{1} ; var.member1.extra_large_boxes >= i; i++){ // check the availbility of  empty boxes
        if (total >= var.member2.parts_extra_large_boxes){  // check wether the number of part is sufficient to fill the box fully 
            total = total - var.member2.parts_extra_large_boxes;
            j++;
        }
    }
    std::cout << "XL box " << "(" << var.member1.extra_large_boxes << " X " <<var.member2.parts_extra_large_boxes << ") : " << j << " -- remaining parts: " << total << '\n';
    int k{0}; // initialize the varible to count the number of filled boxes
    for (int i{1} ; var.member1.large_boxes >= i; i++){ // check the availbility of  empty boxes
        if (total >= var.member2.parts_large_boxes){ // check wether the number of part is sufficient to fill the box fully
            total = total - var.member2.parts_large_boxes;
            k++;
        }
    }
    std::cout << "XL box " << "(" << var.member1.large_boxes << " X " <<var.member2.parts_large_boxes << ") : " << k << " -- remaining parts: " << total << '\n';
    int l{0}; // initialize the varible to count the number of filled boxes
    for (int i{1} ; var.member1.medium_boxes >= i; i++){ // check the availbility of  empty boxes
        if (total >= var.member2.parts_medium_boxes){ // check wether the number of part is sufficient to fill the box fully
            total = total - var.member2.parts_medium_boxes;
            l++;
        }
    }
    std::cout << "XL box " << "(" << var.member1.medium_boxes << " X " <<var.member2.parts_medium_boxes<< ") : " << l << " -- remaining parts: " << total << '\n';
    int m{0}; // initialize the varible to count the number of filled boxes
    for (int i{1} ; var.member1.small_boxes >= i; i++){ // check the availbility of  empty boxes
        if (total >= var.member2.parts_small_boxes){ // check wether the number of part is sufficient to fill the box fully
            total = total - var.member2.parts_small_boxes;
            m++;
        }
    }
    std::cout << "XL box " << "(" << var.member1.small_boxes << " X " <<var.member2.parts_small_boxes<< ") : " << m << " -- remaining parts: " << total << '\n';
    std::cout << "Parts not in boxes: " << m << '\n';
}

