#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <string>

using namespace std;

/*
PID - the process identifier is a number used by Linux kernel to uniquely identify an active process.
      When a process (program) is started it gets a unique PID number.
*/

int main()
  {
  //The fork() function creates a new process
  //Return value:
  // 0 - zero is returned to the newly created child process
  // positive value - is returned to the parent. The value contains the process ID of the newly created child process.
  if (fork() == 0)
    {
    // child #1
    cout << "Process: C1 - pid: "<< getpid() << " (parent pid: " << getppid() << ")" << "\n";
    sleep(1);
    return 0;
    }
  // parent
  cout << "Process: Pa - pid: "<< getpid() << " (parent pid: " << getppid() << ")" << "\n";
  // wait for children to end
  if (wait(NULL) == -1)
    {
    perror("Error waiting for a child.");
    exit(EXIT_FAILURE);
    }
  cout << "Process: Pa - pid: "<< getpid() << " (parent pid: " << getppid() << ")" << " - all children finished.\n";
  return 0;
  }
