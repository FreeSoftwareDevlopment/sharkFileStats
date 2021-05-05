# fileStat Shark

[Releases](https://github.com/FreeSoftwareDevlopment/sharkFileStats/releases) (The Linux Version is automated build over GitHub Actions)

## Compile:

- <strong>Windows:</strong> you need Visual Studio and CMake
- <strong>Linux:</strong> you need make, cmake and a c++ compiler installed

- Use `cmake -S . -B <path to store the build>` then  `cmake --build <path to store the build> --config Release` to build the app (the main app is `sharkFsStats` (`sharkFsStats.exe` on windows)).

## Command Line Arguments: 

Argument	|  Description
----------  |  ---------------------------------------------------------------------------
`-json`		| The app will format output as json
`-ext`		| Print extended informations
`-cpath`	| The next argument should be a string to the folder/file about that you like the information

Allowed is only 1 arg of each argument, if you have a duplicated arg, the others will ignored (`-cpath`)

## Example Usages

To get only "Free Disk Space":

![./sharkFsStats -json|jq .currentFreeSpace](https://user-images.githubusercontent.com/40953479/116979217-0194dd00-acc5-11eb-94a5-e3b26c6fc413.png)



---

Do not be irritated by the name of the main folder, originally I did not know what I want to code

---

## Donate

Our Ethereum Donation Address: `0xC09EE37963E11100ce6354F5ABd2aa76dB3eB109`

---


&copy; Sharkbyteprojects
