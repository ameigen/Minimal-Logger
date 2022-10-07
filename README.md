# Minimal-Logger
A very naïve and minimal logger implementation in C++. Originally made as a simple logger for a personal project game engine.

Will it ever be extended? We'll See. a screenshot of text

![a screenshot of text](https://i.imgur.com/YnWHSSF.png)

# How to Use
For general ease of use all you have to to is #include "Logger.h" A minimal working example can be found in LoggerTest.cpp or below

```c++
#include "Logger.h"
int main()
{
  Logger logger;
  logger.log(INFO, "You", " can", " log", " any", " number", " of", " things");;
  logger.log(DEBUG, "You", " can", " log", " ints", 21, " floats", 125.02, " have fun!");
  return 0;
}
```

#To-dos and Other Notes
### Todo
- [ ] Add functions for setting debug levels and names.

### In Progress
- [ ] Wait for people to suggest things
Done ✓
- [x] Do initial commit.
- [x] Add functions for setting output color codes.
