#include "ros/ros.h"
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char **argv)
{
  //inicjalizacja węzła + jego nazwa
  ros::init(argc, argv, "talker");

  //uchwyt do węzła
  ros::NodeHandle n;

  /*inicjalizacja publishera, typ publikowanych danych oraz nazwa topiku z
    wielkością buffora danych (ile wiadomosci moze czekac w kolejce do
    przeslania)*/
  ros::Publisher chatter_pub = n.advertise</*tutaj typ wysylanej wiadomosci*/>("chatter", 1000);

  //czestotliwość w Hz uruchamiania
  ros::Rate loop_rate(10);

  int licznik = 0;
  
  //pętla powtarzająca się z częstotliwością loop_rate
   while(ros::ok())
    {
    /*tutaj typ wysylanej wiadomosci*/ msg;
    
    //zapisanie zmiennych do naszej wiadomosci
    std::stringstream ss;
    ss << "witaj smutny swiecie";
    msg.tresc = ss.str();
    msg.numer=licznik;

    ROS_INFO("%s po raz %d", msg.tresc.c_str(), msg.numer);
    
    //wyslanie wiadomosci
    chatter_pub.publish(msg);

    //wejście do petli ros
    ros::spinOnce();

    //zatrzymanie pętli na czas określony wcześniej
    loop_rate.sleep();
    ++licznik;
  }


  return 0;
}
