#include "linkedListOfMusic.h"

int main()
{
  List musicsList = readMusics("music.csv");
  // showList_r(musicsList);

  List sortedMusicsList = bubbleSortByYear(musicsList);
  showList_i(sortedMusicsList);
  return 0;
}
