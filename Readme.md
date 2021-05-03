# fileStat Shark

## Compile:

- <strong>Windows:</strong> you need Visual Studio and CMake
- <strong>Linux:</strong> you need make, cmake and a c++ compiler installed

- Use `cmake -S <path to the folder where this readme is> -D <where you want that cmake create the files, must be a empty folder>` to create os specific build files.

- <strong>Windows:</strong> Enter with Devloper Command Prompt the folder where cmake created the files, and type `msbuild <path to the .sln file in the folder>`
- <strong>Linux:</strong> Enter the folder where cmake created the files and type `make`

## Command Line Arguments: 

Argument	|  Description
----------  |  ---------------------------------------------------------------------------
`-json`		| The app will format output as json
`-ext`		| Print extended informations
`-cpath`	| The next argument should be a string to the folder/file about that you like the information

Allowed is only 1 arg of each argument, if you have a duplicated arg, the others will ignored (`-cpath`)



---

Do not be irritated by the name of the main folder, originally I did not know what I want to code

---

## Donate

Our Ethereum Donation Address: `0xC09EE37963E11100ce6354F5ABd2aa76dB3eB109`

---

&copy; Sharkbyteprojects
