#include "SignalHandler.hpp"

//#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
// #include <boost/log/expressions.hpp>
// #include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
// #include <boost/log/utility/setup/common_attributes.hpp>
// #include <boost/log/sources/severity_logger.hpp>
// #include <boost/log/sources/record_ostream.hpp>

#include <unistd.h>

namespace KDetTestArea
{
  class RedShirt
  {

  public:

    RedShirt(){BOOST_LOG_TRIVIAL(trace) << this << " has been constructed!";};

    virtual ~RedShirt(){
      static const char msg[] = "SIGCHLD Recieved\n";
      write(STDERR_FILENO, msg, strlen(msg));
    };

  };

};


int main(int argumentCount, char **argumentVector)
{

// setup logging
  boost::log::add_file_log("sample.log");

  //start signal handler
  KDetTestArea::signalBlockingHandler daHandler;

//  daHandler.wait();// I guess this is a degenerate test of the handler construction

  //spawn my threads
  static KDetTestArea::RedShirt gonnaDieAtWeirdTimes;

  KDetTestArea::RedShirt mightLive;

  //detach from console
  pid_t processId = fork();

  if(0 != processId) {
    quick_exit(EXIT_SUCCESS);
  }

  daHandler.wait();// I guess this is a degenerate test of the handler construction

  //never reached with call to exit()

  BOOST_LOG_TRIVIAL(trace) << "WTF";
  return EXIT_FAILURE;

}
