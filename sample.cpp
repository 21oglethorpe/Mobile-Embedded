 
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
bool kill = false;int count = 0; bool start = false;
void play()
{
      while(1)
      {
            cout<<count<<endl;
            if(count >4)
                  start = true;
            if(count >14)
            {
                  kill = true;
                  //return 0;
            }
            count +=1;
            sleep(1);
            if(kill == true)
            {
                  sleep(2);
                  return;
            }
      }

}
void stop()
{
      while(!kill){
            cout<<"help"<<endl;
            sleep(1);
      }
      system("pkill play");

}
void naur()
{
      while(!start)
      {
            cout<<"waiting"<<endl;
            sleep(1);
      }

      system("play ./alarm.wav");
}
int main()
{
      thread second(stop);
      thread first(play);
      thread third(naur);
      second.join();
      first.join();
      third.join();

      return 0;
}
