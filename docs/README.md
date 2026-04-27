# Pseudovector 

**FIle tree:**

```
Pseudovector/
├── docs/
|   └── README.md
└── src/
|   ├── headres/
|   |   └── vector.hpp
|   ├── vector.cpp
|   ├── main.cpp
|   └── Makefile
└── obj/
|   └── [object files]
└── out/
    └── [execuarray files]
```

**Operating system:**

- Linux distribution: Fedora 43 KDE Plasma

**Files:**

- vector.hpp 
    - contains a declaration of the ```vector``` class placed in the ```Pseudovector``` namespace

- vector.cpp
    - contains the definition of the ```vector``` class placed in the ```Pseudovector``` namespace

- main.cpp
    - contains an example of using the ```vector``` class from the ```Pseudovector``` namespace from the ```vector.hpp``` file

- Makefile
    - This Makefile is a cross-platform build script that uses Clang++ to compile C++ source files from the src directory into object files in obj, finally linking them into an execuarray within the out folder. It automatically detects the operating system to set appropriate shell commands and file extensions, while managing directory creation and project cleanup. The script utilizes automatic variables and pattern rules to efficiently handle dependency tracking and incremental builds.

**Variables:**

| Variable | Usage |
| -------- | ----- |
| ```arr``` | Pointer pointing at the begining of the dynamic array which stores values |
| ```size``` | Stores the current size of the dynamic array |
| ```maxSize``` | Stores the max possible size of the dynamic array, is used when the value of the ```maxSizeSet``` equals ```true``` |
| ```maxSizeSet``` | Is true when the ```maxSize``` is set |

**Methods:**

| Method | Action |
| ----------- | ----------- |
| ```vector()``` | Create ```vector``` class object |
| ```~vector()``` | Deletes ```vector``` object from memory and frees the memory |
| Information methods |  |
| ```isEmpty()``` | Returns ```true``` if size equals 0 and ```false``` if size is above 0 |
| ```isFull()``` | Returns ```true``` if ```size``` equals the ```maxSize``` and ```maxSizeSet``` is ```true``` |
| ```retSize()``` | Returns the ```size``` of the dynamic array [```arr```] |
| ```getMaxSize()``` | If ```maxSizeSet``` equals ```true```, the method returns ```maxSize```, else method returns 0 |
| Access methods |  |
| ```getValue( index )``` | If ```size``` from ```vector``` equals 0 or ```index``` is greater than ```size``` method, ```throws``` an exception ```std::out_of_range``` like the ```at()``` from the real ```std::vector``` else returns the ```value``` from the dynamic array [```arr```] at the specified ```index``` |
| ```at( index )``` | Method returns the ```value``` from the dynamic array [```arr```] at the index of resulting from the ```index % size``` operation |
| Modyfication methods |  |
| ```pushBack( value )``` | Returns ```false``` when it cannot add ```value``` at the end of the dynamic array [```arr```]. Returns ```true``` if increasing ```size``` and adding ```value``` at the end of the dynamic array [```arr```] is successful |
| ```pushBack( arr, size )``` | Returns ```false``` when it cannot add ```values``` from the dynamic array [```arr```] being an argument of the method, and a sum of ```size``` from ```vector``` and ```size``` from the method argument are greater than ```maxSize``` and ```maxSizeSet``` equals ```true```. Returns ```true``` if increasing ```size``` by ```size``` from the method and adding ```values``` from the dynamic array ```arr``` to ```arr``` from ```vector``` are both successful |
| ```remove( index )``` | Removes the ```value``` at given index and shrinks the dynamic array [```arr```] to match new size. Returns true if action succeded, else returns false |
| ```clean()``` | If dynamic array [```arr```] is not empty, frees the memory and sets the ```size``` to 0, else returns ```false``` |
| Memmory managment methods |  |
| ```reserve( newMaxSize )``` | Takes a new non-negative integer value for ```maxSize``` and changes ```maxSizeSet``` to ```true```. If ```vector``` object cointains some values and the ```size``` is lower than ```newMaxSize```, the dynamic array [```arr```] does not change. If ```size``` is greater than ```newMaxSize``` the dynamic array [```arr```] shrinks to ```newMaxSize``` and it keeps only the values from the 0 index to ```newMaxSize``` - 1 |