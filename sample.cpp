 
/******************************************************************************Alarm Clock with RFID and piptagwhen piptag sends back light data that is > 100(ex.),
turn on 'alarm'alarm can be audio file on laptop
//https://stackoverflow.com/questions/22253074/how-to-play-or-open-mp3-or-wav-sound-file-in-c-programto
turn off alarm,
move piptag close to reciever: magnitude of wireless signal should become low(as its negative)
**need to be able to get alarm to run in parallel while still sensing, which is a bit annoying due to the while loop running sensors* *
https://askubuntu.com/questions/384991/how-do-i-play-an-audio-file-using-c-in-linux*
*******************************************************************************/
#include <iostream>
#include <unistd.h>
//these two headers are already included in the <Windows.h> header
#include <thread>
using namespace std;
void play()
{
      system("xterm -e \"play alarm.wav\"");

}
void stop()
{
      system("xterm -e \"pkill play\"");

}
int main()
{
      thread first(play);
      sleep(3);

      thread second(stop);

      first.join();

      second.join();
      return 0;
}
