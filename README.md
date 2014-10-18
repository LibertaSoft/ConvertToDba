# ConvertToDba

### Intro

**ConvertToDba** - is program for convert export format other program to format *DatabaseAnime*
now work for one program - AnimeList

### Help info
Use:
  ConvertToDba -i /path/to/file/AnimeList.anime -o /path/to/new/file.xml

Options:
  -i 	Input file. The file exported from the program AnimeList
  -o 	Output file. The file in which you want to export data
  -e 	Endoding. The encoding of the input file
  -h 	Help. Pring help and exit with program
  -v 	Version. Print version and exit with program


### Usage
1. Use export from AnineList
2. Make sure what file encoding: `Windows-1251` or (?`UTF8`?)
3. Enter in command line: `ConvertToDba -i /path/to/file/AnimeList.anime -o /path/to/new/file.xml`
4. Use import in DatabaseAnime for file.xml
