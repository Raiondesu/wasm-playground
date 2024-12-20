#include "segmented_sieve.cpp"

#include <cheerp/client.h> //Misc client side stuff
#include <cheerp/clientlib.h> //Complete DOM/HTML5 interface

[[cheerp::genericjs]]
void outputNumberOfElementsToTheConsole()
{
  double number = client::document.getElementsByTagName("*")->get_length();
  client::console.log("Live elements = ", number);
}

//This function will be called only after the DOM is fully loaded
[[cheerp::genericjs]]
void loadCallback()
{
  client::console.log("Hi from loadCallback!");

  //Do something with the document
  outputNumberOfElementsToTheConsole();
  client::console.log("Bye from loadCallback!");
}

[[cheerp::genericjs]]
void webMain()
{
  client::document.addEventListener("DOMContentLoaded", cheerp::Callback(loadCallback));

  client::console.log("Hi from webMain!");

  outputNumberOfElementsToTheConsole();

  client::console.log("Bye from webMain!");

  main();
}