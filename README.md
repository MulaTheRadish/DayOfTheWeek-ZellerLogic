# Day Of The Week

## Challenge
Find which day of the week a given date lands on. 

### Input/ Output Examples:
```
$ Enter a date (dd/mm/yy): 13 / 12/ 2022
$ The day of the week on the given date is: Friday
```
```
$ Enter a date (dd/mm/yy): 15/4/2023
$ The day of the week on the given date is: Saturday
```
## How To Solve The Challenge
### 1. Parsing a String Input
First we have to parse the string input into its respective time components; dd, mm, yy. In order to do that, the code erases all the `' '` characters in the input and uses the `'/'` characters as a deliminator. The code expects **ONLY** 3 deliminators in the input. The code then turns the tokens generated from parsing the string into integers using the `.stoi` function. Afterwards, we have our required times under the variables `dd`, `mm`, `yy` representing the day, month and year respectively. 

### 2. Zeller's Algorithm
Zeller's Algorithm is a formula used to obtain an index of a list or case which can provide the day of the week given the date. More information about the algorithm can be found [here.](https://www.geeksforgeeks.org/zellers-congruence-find-day-date/)

### 3. Using The Index
The number gained from Zeller's Algorithm provides an index number, which we can use to sort through a predetermined list: 
`const string weekday[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};`
