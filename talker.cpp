#include "ros/ros.h"
#include <iostream>
#include <sstream>

using namespace std;

//funkcja uruchamiana gdy nadejdzie komunikat
void chatterCallback(const /*tutaj typ odbieranej wiadomosci*/::ConstPtr& msg)
{
  ROS_INFO("Ulyszalem: [%s], [%d]", msg->tresc.c_str(), msg->numer);
}

int main(int argc, char **argv)
{
  //inicjalizacja węzła i jego nazwa
  ros::init(argc, argv, "listener");

  //uchwyt do węzła
  ros::NodeHandle n;
  
  /*określenie typu (odbieranie subscribe czy wysyłanie publish), 
  nazwy topicu, rozmiaru kolejki i uruchamianej funkcji callback*/
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  //pętla ros
  ros::spin();

  return 0;
}
