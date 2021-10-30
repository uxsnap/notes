#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

/**
 * The most important thing here is a struct tm, which holds a bunch 
 * of fields containing all king of time-related info from 1970  
*/

long fib(unsigned n)
{
  if (n < 2)
    return n;
  return fib(n - 1) + fib(n - 2);
}

int main() {
  int n;
  long ans;

  cout << "Input n: ";
  cin >> n;
   
  auto start = chrono::system_clock::now();
  ans = fib(n);
  auto end = chrono::system_clock::now();
  chrono::duration<double> elapsed = end - start;
  cout << "Answer: " << ans << ", Elapsed time: " << elapsed.count();


  time_t now = time(0); // gives us time is mls from epoch

  cout << "Number of sec since Jan 1, 1970 is:: " << now << endl;
  
  tm *ltm = localtime(&now);
  cout << "year: " << ltm->tm_year << endl; 
  return 0;
}