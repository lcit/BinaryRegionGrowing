/*  =========================================================================
    Author: Leonardo Citraro
    Company:
    Filename: test_functional.cpp
    Last modifed:   03.04.2017 by Leonardo Citraro
    Description:    Functional test

    =========================================================================

    =========================================================================
*/
#include "BinaryRegionGrowing.hpp"
#include <iostream>
#include <cassert>

bool check(const std::string& test, const Array1D<int,16>& output, const Array1D<int,16>& truth) {
    if( output==truth ) {
        std::cout << test << " passed!\n";
        return true;
    } else {
        std::cout << test << " failed!\n";
        std::cout << "output: [";
        for(const auto& e:output)
            std::cout << e << ",";
        std::cout << "]\n";
        std::cout << "truth:  [";
        for(const auto& e:truth)
            std::cout << e << ",";
        std::cout << "]\n";
        return false;
    }
}

int main(int argc, char* argv[]){
    
    //--------------------------------------------
    // Setting up indexes and the objects
    //--------------------------------------------
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
    BinaryRegionGrowing<16,5> brg(neighbour_indexes);
    
    //--------------------------------------------
    // Test 1
    //--------------------------------------------
    {
        Array1D<bool,16> values = {  false,false,true,false,
                                     false,false,true,false,
                                     true,true,true,true,
                                     false,false,false,false
                                  };
        Array1D<int,16> truth =   {  0,0,1,2,
                                     0,0,1,2,
                                     1,1,1,1,
                                     3,3,3,3
                                  };
        Array1D<int,16> output = brg.run(values);
        assert( check("Test 1", output, truth) );
    }
    
    //--------------------------------------------
    // Test 2
    //--------------------------------------------
    {
        Array1D<bool,16> values = {  false,false,false,false,
                                     false,false,false,false,
                                     false,false,false,false,
                                     false,false,false,false
                                  };
        Array1D<int,16> truth =   {  0,0,0,0,
                                     0,0,0,0,
                                     0,0,0,0,
                                     0,0,0,0
                                  };
        Array1D<int,16> output = brg.run(values);
        assert( check("Test 2", output, truth) );
    }
    
    //--------------------------------------------
    // Test 3
    //--------------------------------------------
    {
        Array1D<bool,16> values = {  true,true,true,true,
                                     true,true,true,true,
                                     true,true,true,true,
                                     true,true,true,true
                                  };
        Array1D<int,16> truth =   {  0,0,0,0,
                                     0,0,0,0,
                                     0,0,0,0,
                                     0,0,0,0
                                  };
        Array1D<int,16> output = brg.run(values);
        assert( check("Test 3", output, truth) );
    }
    
    //--------------------------------------------
    // Test 4
    //--------------------------------------------
    {
        Array1D<bool,16> values = {  true,false,true,true,
                                     true,true,true,true,
                                     true,true,true,true,
                                     true,true,true,true
                                  };
        Array1D<int,16> truth =   {  0,1,0,0,
                                     0,0,0,0,
                                     0,0,0,0,
                                     0,0,0,0
                                  };
        Array1D<int,16> output = brg.run(values);
        assert( check("Test 4", output, truth) );
    }

    //--------------------------------------------
    // Test 5
    //--------------------------------------------
    {
        Array1D<bool,16> values = {  false,true,true,true,
                                     true,true,true,true,
                                     true,true,true,true,
                                     true,true,true,true
                                  };
        Array1D<int,16> truth =   {  0,1,1,1,
                                     1,1,1,1,
                                     1,1,1,1,
                                     1,1,1,1
                                  };
        Array1D<int,16> output = brg.run(values);
        assert( check("Test 5", output, truth) );
    }
    
    //--------------------------------------------
    // Test 6
    //--------------------------------------------
    {
        Array1D<bool,16> values = {  true,true,true,false,
                                     true,true,false,true,
                                     true,false,true,true,
                                     false,true,true,true
                                  };
        Array1D<int,16> truth =   {  0,0,0,1,
                                     0,0,2,3,
                                     0,4,3,3,
                                     5,3,3,3
                                  };
        Array1D<int,16> output = brg.run(values);
        assert( check("Test 6", output, truth) );
    }
    
    return 0;
}
