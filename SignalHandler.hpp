#ifndef SIGNAL_HANDLER_HPP
#define SIGNAL_HANDLER_HPP

#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include <boost/log/trivial.hpp>

#include <signal.h>

namespace KDetTestArea
{
  const std::vector<int> allSignalsDefine {
    //this is a quick copy from the system header
    {SIGHUP},
    {SIGINT},
    {SIGQUIT},
    {SIGILL},
    {SIGTRAP},
    {SIGABRT},
    {SIGIOT},
    {SIGBUS},
    {SIGFPE},
    {SIGKILL},
    {SIGUSR1},
    {SIGSEGV},
    {SIGUSR2},
    {SIGPIPE},
    {SIGALRM},
    {SIGTERM},
    {SIGSTKFLT},
    {SIGCLD},
    {SIGCHLD},
    {SIGCONT},
    {SIGSTOP},
    {SIGTSTP},
    {SIGTTIN},
    {SIGTTOU},
    {SIGURG},
    {SIGXCPU},
    {SIGXFSZ},
    {SIGVTALRM},
    {SIGPROF},
    {SIGWINCH},
    {SIGPOLL},
    {SIGIO},
    {SIGPWR},
    {SIGSYS},
    {SIGUNUSED}

  };

  const std::map<int, std::string> allSignals {
    //this is a quick copy from the system header
    {SIGHUP, "SIGHUP"},
    {SIGINT, "SIGINT"},
    {SIGQUIT, "SIGQUIT"},
    {SIGILL, "SIGILL"},
    {SIGTRAP, "SIGTRAP"},
    {SIGABRT, "SIGABRT"},
    {SIGIOT, "SIGIOT"},
    {SIGBUS, "SIGBUS"},
    {SIGFPE, "SIGFPE"},
    {SIGKILL, "SIGKILL"},
    {SIGUSR1, "SIGUSR1"},
    {SIGSEGV, "SIGSEGV"},
    {SIGUSR2, "SIGUSR2"},
    {SIGPIPE, "SIGPIPE"},
    {SIGALRM, "SIGALRM"},
    {SIGTERM, "SIGTERM"},
    {SIGSTKFLT, "SIGSTKFLT"},
    {SIGCLD, "SIGCLD"},
    {SIGCHLD, "SIGCHLD"},
    {SIGCONT, "SIGCONT"},
    {SIGSTOP, "SIGSTOP"},
    {SIGTSTP, "SIGTSTP"},
    {SIGTTIN, "SIGTTIN"},
    {SIGTTOU, "SIGTTOU"},
    {SIGURG, "SIGURG"},
    {SIGXCPU, "SIGXCPU"},
    {SIGXFSZ, "SIGXFSZ"},
    {SIGVTALRM, "SIGVTALRM"},
    {SIGPROF, "SIGPROF"},
    {SIGWINCH, "SIGWINCH"},
    {SIGPOLL, "SIGPOLL"},
    {SIGIO, "SIGIO"},
    {SIGPWR, "SIGPWR"},
    {SIGSYS, "SIGSYS"},
    {SIGUNUSED, "SIGUNUSED"}

  };

  class signalBlockingHandler
  {

    sigset_t m_signalSet;

  public :
    
    signalBlockingHandler()
      {
        sigemptyset(&m_signalSet);

        auto glambda = [&](int addSignal){sigaddset(&m_signalSet, addSignal);};
        std::for_each(allSignalsDefine.begin(), allSignalsDefine.end(), glambda);
      };

    void wait(){

      int daSignal = 0;
      sigwait(&m_signalSet, &daSignal);

      BOOST_LOG_TRIVIAL(trace) << allSignals.find(daSignal)->second;

    };

  };

}

#endif
 
