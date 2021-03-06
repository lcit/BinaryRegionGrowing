/*  =========================================================================
    Author: Leonardo Citraro
    Company:
    Filename: main.cpp
    Last modifed:   03.04.2017 by Leonardo Citraro
    Description:    Binary Region Growing example

    =========================================================================

    =========================================================================
*/
#include "BinaryRegionGrowing.hpp"
#include <iostream>

int main(int argc, char* argv[]){

    //      indexes
    // |---------------|  
    // | 0 | 1 | 2 | 3 | 
    // |---------------| 
    // | 4 | 5 | 6 | 7 |
    // |---------------|
    // | 8 | 9 | 10| 11| 
    // |---------------| 
    // | 12| 13| 14| 15|
    // |---------------|
    Array2D<int,16,5> neighbour_indexes = {{    {0 ,1 ,4 ,-1,-1},
                                                {1 ,0 ,2 , 5,-1},
                                                {2 ,1 ,6 , 3,-1},
                                                {3 ,2 ,7 ,-1,-1},
                                                {4 ,0 ,5 , 8,-1},
                                                {5 ,1 ,4 , 6, 9},
                                                {6 ,2 ,5 , 7,10},
                                                {7 ,3 ,6 ,11,-1},
                                                {8 ,4 ,9 ,12,-1},
                                                {9 ,5 ,8 ,10,13},
                                                {10,6 ,9 ,11,14},
                                                {11,7 ,10,15,-1},
                                                {12,8 ,13,-1,-1},
                                                {13,9 ,12,14,-1},
                                                {14,10,13,15,-1},
                                                {15,11,14,-1,-1}
                                            }};
    
    //      values
    // |---------------|  
    // | 0 | 0 | 1 | 0 | 
    // |---------------| 
    // | 0 | 0 | 1 | 0 |
    // |---------------|
    // | 1 | 1 | 1 | 1 | 
    // |---------------| 
    // | 0 | 0 | 0 | 0 |
    // |---------------|
    Array1D<bool,16> values = {  false,false,true,false,
                                false,false,true,false,
                                true,true,true,true,
                                false,false,false,false
                            };
    
    BinaryRegionGrowing<16,5> brg(neighbour_indexes);
    Array1D<int,16> regions = brg.run(values);
    
    std::cout << "|---------------|" << std::endl;
    for(size_t i=0; i<4; i++){
        std::cout << "|";
        for(size_t j=0; j<4; j++)
            std::cout << " " << regions[i*4+j] << " |";
        std::cout << "\n|---------------|" << std::endl;
    }
    
    //      result
    // |---------------|
    // | 0 | 0 | 1 | 2 |
    // |---------------|
    // | 0 | 0 | 1 | 2 |
    // |---------------|
    // | 1 | 1 | 1 | 1 |
    // |---------------|
    // | 3 | 3 | 3 | 3 |
    // |---------------|
    
    std::cout << "Total number of regions: " << brg.get_nb_regions() << "\n";
    
    return 0;
}
