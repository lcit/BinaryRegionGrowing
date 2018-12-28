# Binary Region Growing

C++ - Simple yet effective Region Growing implementation for binary mesh segmentation.

### Prerequisites

-

### Run example
```
./clean.sh; ./build.sh
./run.sh
```

### Example usage

![alt tag](https://raw.githubusercontent.com/lcit/BinaryRegionGrowing/master/BinaryRegionGrowing_example.png)

```C++
#include "BinaryRegionGrowing.hpp"
#include <iostream>

int main(int argc, char* argv[]){

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

    Array1D<bool,16> values = {  false,false,true, false,
                                 false,false,true, false,
                                 true, true, true, true,
                                 false,false,false,false
                              };

    BinaryRegionGrowing<16,5> brg(neighbour_indexes);
    Array1D<int,16> regions = brg.run(values);

	std::cout << "Total number of regions: " << brg.get_nb_regions() << "\n";

    return 0;
}
```

## Performance

Tests effectuated on a single thread of an Intel quad-core hyperthreading i7-4700MQ 2.4GHz 64 bits architecture.
The time required to segment a mesh of 92 nodes is 13 [us].
The time required to segment a mesh of 252 nodes is 92 [us].


## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments
