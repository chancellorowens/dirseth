#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

using std::cout;
using std::endl;
using std::string;

void nope_out(const string & prefix);

/**
 * For this example, in addition to seeing the error message, you can always
 * run `echo $?` after the program terminates to see the exit code that is 
 * returned by the program.
 */
int main(const int argc, const char * argv []) {

  cout.setf(std::ios::unitbuf);

  const char * dirname = argv[1];
  DIR * dirp = nullptr;
  struct dirent * direntp;
  //open
  if ((dirp = opendir(dirname)) == nullptr ){
    nope_out("opendir");
  } 
  
  while((direntp = readdir(dirp)) != nullptr){
    cout << direntp->d_name << endl;
  }
    //close
  if (closedir(dirp) == -1){
    nope_out("closedir");
  }

  return EXIT_SUCCESS;
  
} // main

void nope_out(const string & prefix) {
  perror(prefix.c_str());
  exit(EXIT_FAILURE);
} // nope_out

